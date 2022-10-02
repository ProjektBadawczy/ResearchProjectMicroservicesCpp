#include "GraphController.h"
#include <string>
using std::string;

GraphController::GraphController(const string& address, const string& port, GraphService* graphService) : BasicController(address, port)
{
    this->graphService = graphService;
}
GraphController::~GraphController()
{
    delete graphService;
}

void GraphController::initRestOpHandlers() 
{
    listener.support(methods::GET, std::bind(&GraphController::handleGet, this, std::placeholders::_1));
}

void GraphController::handleGet(http_request message)
{
    vector<utility::string_t> path = requestPath(message);
    if (path.empty()) 
    {
        message.reply(status_codes::BadRequest);
    }
    else 
    {
        if (path[0] == to_string_t("graph"))
        {
            auto queries = requestQuery(message);
            int id = stoi(queries[to_string_t("id")]);
            auto graph = graphService->getGraph(id);
            json::value graphJson;
            graphJson[to_string_t("graph")] = json::value::string(graph->toString());
            message.reply(status_codes::OK, graphJson);
            delete graph;
        }
        else if (path[0] == to_string_t("directed-graph"))
        {
            auto queries = requestQuery(message);
            int id = stoi(queries[to_string_t("id")]);
            auto directedGraph = graphService->getDirectedGraph(id);
            json::value graphJson;
            graphJson[to_string_t("directepGraph")] = json::value::string(directedGraph->toString());
            message.reply(status_codes::OK, graphJson);
            delete directedGraph;
        }
        else
        {
            message.reply(status_codes::BadRequest);
        }
    }
}