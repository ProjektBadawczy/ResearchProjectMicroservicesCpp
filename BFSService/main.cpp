#include<iostream>
#include "BFSController.h"
#include "BFSService.h"

using namespace std;

int main()
{
	auto bfsService = new BFSService();
	BFSController serv("127.0.0.1", "8091", bfsService);
	serv.setEndpoint("/api");
	serv.accept().wait();
	while(true)
	{
		
	}
	return 0;
}