#pragma once
#include "../Common/BasicController.h"
#include "PushRelabelService.h"
#include "../Common/defines.h"


class PushRelabelController : public BasicController {
public:
    PushRelabelController(const string& address, const string& port, PushRelabelService* pushRelabelService);
    ~PushRelabelController();
    void handleGet(http_request message);
    void initRestOpHandlers() override;
private:
    PushRelabelService* pushRelabelService;
};
