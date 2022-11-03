#include<iostream>
#include "ApiController.h"
#include "../Common/KeyboardInterruptHandler.h"
#include "../Common/defines.h"

using namespace std;

int main()
{
	ApiController serv(ADDRESS, "8094");
	serv.setEndpoint("");
	serv.accept().wait();
	return KeyboardInterruptHandler::handleKeyboardInterrupt();
}