#include <iostream>
#include "GraphController.h"
#include "GraphRepository.h"
#include "GraphService.h"
#include "../Common/KeyboardInterruptHandler.h"
#include "../Common/defines.h"

using namespace std;

int main()
{
	auto graphRepository = new GraphRepository();
	auto graphService = new GraphService(graphRepository);
	GraphController serv(ADDRESS, "8090", graphService);
	serv.setEndpoint("/api");
	serv.accept().wait();
	return KeyboardInterruptHandler::handleKeyboardInterrupt();
}