#include "ApiController.h"
#include "../Common/utils.h"
#include "../Common/defines.h"
#include <string>
using std::string;
using namespace utility;

ApiController::ApiController(const string& address, const string& port) : BasicController(address, port)
{

}
ApiController::~ApiController()
{

}

void ApiController::initRestOpHandlers()
{
    listener.support(methods::POST, std::bind(&ApiController::handlePost, this, std::placeholders::_1));
    listener.support(methods::GET, std::bind(&ApiController::handleGet, this, std::placeholders::_1));
}

void ApiController::handlePost(http_request message)
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
            
        }
        else
        {
            message.reply(status_codes::BadRequest);
        }
    }
}

void ApiController::handleGet(http_request message)
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
            string_t address = GRAPH_SERVICE_URL + string_t(U("graph?id=")) + queries[U("id")];
            auto response = sendGetRequestAsJson(address);
            message.reply(status_codes::OK, response);
        }
        if (path[0] == to_string_t("directedGraph"))
        {
            auto queries = requestQuery(message);
            string_t address = GRAPH_SERVICE_URL + string_t(U("directed-graph?id=")) + queries[U("id")];
            auto response = sendGetRequestAsJson(address);
            message.reply(status_codes::OK, response);
        }
        if (path[0] == to_string_t("edmondsKarpMaxGraphFlow"))
        {
            auto queries = requestQuery(message);
            string_t address = EDMONDSKARP_SERVICE_URL +
                string_t(U("edmonds-karp?id=")) +
                queries[U("id")] +
                string_t(U("&source=")) + 
                queries[U("source")] + 
                string_t(U("&destination=")) + 
                queries[U("destination")];
            auto response = sendGetRequestAsJson(address);
            message.reply(status_codes::OK, response);
        }
        if (path[0] == to_string_t("pushRelabelMaxGraphFlow"))
        {
            auto queries = requestQuery(message);
            string_t address = PUSHRELABEL_SERVICE_URL +
                string_t(U("push-relabel?id=")) +
                queries[U("id")] +
                string_t(U("&source=")) +
                queries[U("source")] +
                string_t(U("&destination=")) +
                queries[U("destination")];
            auto response = sendGetRequestAsJson(address);
            message.reply(status_codes::OK, response);
        }
        else
        {
            message.reply(status_codes::BadRequest);
        }
    }
}