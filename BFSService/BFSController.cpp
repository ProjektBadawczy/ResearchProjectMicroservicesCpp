#include "BFSController.h"
#include "../Common/utils.h"
#include <string>
using std::string;
using namespace utility;

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
    listener.support(methods::POST, std::bind(&BFSController::handlePost, this, std::placeholders::_1));
}

void BFSController::handlePost(http_request message)
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
            string_t requestBody = message.extract_string().get();
            size_t n = 0;
            utility::string_t slash = U("\\\"");
            n = requestBody.find(slash, n);
            while (n != utility::string_t::npos)
            {
                requestBody.replace(n, slash.length(), U("\""));
                n++;
                n = requestBody.find(slash, n);
            }
            BFSRequest* request = new BFSRequest(requestBody);
            BFSResult* result = bfsService->bfs(request);
            json::value bfsJson;
            bfsJson[to_string_t("bfs")] = json::value::string(result->toString());
            message.reply(status_codes::OK, bfsJson);
            delete result;
            delete request;
        }
        else
        {
            message.reply(status_codes::BadRequest);
        }
    }
}