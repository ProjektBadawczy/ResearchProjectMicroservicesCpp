#include<iostream>
#include "BFSController.h"
#include "BFSService.h"
#include "../Common/KeyboardInterruptHandler.h"
#include "../Common/defines.h"

using namespace std;

int main()
{
	auto bfsService = new BFSService();
	BFSController serv(ADDRESS, "8091", bfsService);
	serv.setEndpoint("/api");
	serv.accept().wait();
	return KeyboardInterruptHandler::handleKeyboardInterrupt();
}