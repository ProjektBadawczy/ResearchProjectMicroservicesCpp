#include "PushRelabelController.h"
#include <string>
using std::string;
using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;

PushRelabelController::PushRelabelController(const string& address, const string& port, PushRelabelService* pushRelabelService) : BasicController(address, port)
{
    this->pushRelabelService = pushRelabelService;
}
PushRelabelController::~PushRelabelController()
{
    delete pushRelabelService;
}

void PushRelabelController::initRestOpHandlers()
{
    listener.support(methods::GET, std::bind(&PushRelabelController::handleGet, this, std::placeholders::_1));
}

void PushRelabelController::handleGet(http_request message)
{
    vector<utility::string_t> path = requestPath(message);
    if (path.empty())
    {
        message.reply(status_codes::BadRequest);
    }
    else
    {
        if (path[0] == to_string_t("push-relabel"))
        {
            auto queries = requestQuery(message);
            int id = stoi(queries[to_string_t("id")]);
            int source = stoi(queries[to_string_t("source")]);
            int destination = stoi(queries[to_string_t("destination")]);
            string_t address = GRAPH_SERVICE_URL + string_t(U("directed-graph?id=")) + to_string_t(to_string(id));
            string_t response = sendGetRequest(address);
            auto graph = new DirectedGraph(response);
            auto result = pushRelabelService->calculateMaxFlow(graph, source, destination);
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