#pragma once
#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include "../Common/BasicController.h"
#include <vector>


class ApiController : public BasicController {
public:
    ApiController(const string& address, const string& port);
    ~ApiController();
    void handlePost(http_request message);
    void handleGet(http_request message);
    void initRestOpHandlers() override;
};

#endif // SERVICE_H_INCLUDED