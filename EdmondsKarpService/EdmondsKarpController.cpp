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
            auto queries = requestQuery(message);
            int id = stoi(queries[to_string_t("id")]);
            int source = stoi(queries[to_string_t("source")]);
            int destination = stoi(queries[to_string_t("destination")]);
            string address = GRAPH_SERVICE_URL + string("graph?id=") + to_string(id);
            string response = sendGetRequest(address);
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