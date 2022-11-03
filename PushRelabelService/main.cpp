#include<iostream>
#include "PushRelabelController.h"
#include "PushRelabelService.h"
#include "../Common/KeyboardInterruptHandler.h"
#include "../Common/defines.h"

using namespace std;

int main()
{
	auto pushRelabelService = new PushRelabelService();
	PushRelabelController serv(ADDRESS, "8093", pushRelabelService);
	serv.setEndpoint("/api");
	serv.accept().wait();
	return KeyboardInterruptHandler::handleKeyboardInterrupt();
}