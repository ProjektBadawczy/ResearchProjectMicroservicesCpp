#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include "../Common/BasicController.h"
#include <vector>
#include "BFSService.h"


class BFSController : public BasicController {
public:
    BFSController(const string& address, const string& port, BFSService* bfsService);
    ~BFSController();
    void handlePost(http_request message);
    void initRestOpHandlers() override;
private:
    BFSService* bfsService;
};

#endif // SERVICE_H_INCLUDED