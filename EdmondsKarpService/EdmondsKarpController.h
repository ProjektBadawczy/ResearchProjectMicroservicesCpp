#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include "BasicController.h"
#include <vector>
#include "EdmondsKarpService.h"
#include "defines.h"


class EdmondsKarpController : public BasicController {
public:
    EdmondsKarpController(const string& address, const string& port, EdmondsKarpService* edmondsKarpService);
    ~EdmondsKarpController();
    void handleGet(http_request message);
    void initRestOpHandlers() override;
private:
    EdmondsKarpService* edmondsKarpService;
    string sendGetRequest(const wchar_t* address);
};

#endif // SERVICE_H_INCLUDED