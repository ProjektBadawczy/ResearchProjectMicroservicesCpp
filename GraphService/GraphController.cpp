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
            int id = stoi(path[1]);
            auto graph = graphService->getGraph(id);
            json::value graphJson;
            graphJson[to_string_t("graph")] = json::value::string(to_string_t(graph->toString()));
            message.reply(status_codes::OK, graphJson);
            delete graph;
        }
        else
        {
            message.reply(status_codes::BadRequest);
        }
    }
}