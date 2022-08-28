#include "BFSController.h"
#include <string>
using std::string;

BFSController::BFSController(const string& address, const string& port, BFSService* bfsService) : BasicController(address, port)
{
    this->bfsService = bfsService;
}
BFSController::~BFSController()
{
    delete bfsService;
}

void BFSController::initRestOpHandlers()
{
    listener.support(methods::GET, std::bind(&BFSController::handleGet, this, std::placeholders::_1));
}

void BFSController::handleGet(http_request message)
{
    vector<utility::string_t> path = requestPath(message);
    if (path.empty()) 
    {
        message.reply(status_codes::BadRequest);
    }
    else 
    {
        if (path[0] == to_string_t("bfs")) 
        {
            int id = stoi(path[1]);
            int* tab = new int[2];
            tab[0] = 1;
            tab[1] = 1;
            BFSResult* result = new BFSResult(tab, false);
            json::value bfsJson;
            bfsJson[to_string_t("bfs")] = json::value::string(to_string_t(result->getSuccess() == true ? "true" : "false"));
            message.reply(status_codes::OK, bfsJson);
            delete result;
        }
        else
        {
            message.reply(status_codes::BadRequest);
        }
    }
}