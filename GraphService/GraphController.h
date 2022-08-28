#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include "BasicController.h"
#include <vector>
#include "GraphService.h"


class GraphController : public BasicController {
public:
    GraphController(const string& address, const string& port, GraphService* graphService);
    ~GraphController();
    void handleGet(http_request message);
    void initRestOpHandlers() override;
private:
    GraphService* graphService;
};

#endif // SERVICE_H_INCLUDED