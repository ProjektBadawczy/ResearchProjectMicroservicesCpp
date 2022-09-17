#include "EdmondsKarpController.h"
#include <string>
using std::string;
using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;

EdmondsKarpController::EdmondsKarpController(const string& address, const string& port, EdmondsKarpService* edmondsKarpService) : BasicController(address, port)
{
    this->edmondsKarpService = edmondsKarpService;
}
EdmondsKarpController::~EdmondsKarpController()
{
    delete edmondsKarpService;
}

void EdmondsKarpController::initRestOpHandlers()
{
    listener.support(methods::GET, std::bind(&EdmondsKarpController::handleGet, this, std::placeholders::_1));
}

void EdmondsKarpController::handleGet(http_request message)
{
    vector<utility::string_t> path = requestPath(message);
    if (path.empty()) 
    {
        message.reply(status_codes::BadRequest);
    }
    else 
    {
        if(path[0] == to_string_t("edmonds-karp"))
        {
            int id = stoi(path[1]);
            int source = stoi(path[2]);
            int destination = stoi(path[3]);
            // TODO
            // add actual communication to graph service
            string request = GRAPH_SERVICE_URL + to_string(id);
            string response = sendGetRequest(request);
            auto graph = new Graph(response);
            auto result = edmondsKarpService->calculateMaxFlow(graph, source, destination);
            json::value resultJson;
            resultJson[to_string_t("result")] = json::value::number(result);
            message.reply(status_codes::OK, resultJson);
            delete graph;
        }
        else
        {
            message.reply(status_codes::BadRequest);
        }
    }
}