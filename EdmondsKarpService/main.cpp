#include<iostream>
#include "EdmondsKarpController.h"
#include "EdmondsKarpService.h"
#include "../Common/KeyboardInterruptHandler.h"
#include "../Common/defines.h"

using namespace std;

int main()
{
	auto edmondsKarpService = new EdmondsKarpService();
	EdmondsKarpController serv(ADDRESS, "8092", edmondsKarpService);
	serv.setEndpoint("/api");
	serv.accept().wait();
	return KeyboardInterruptHandler::handleKeyboardInterrupt();
}