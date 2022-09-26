#include<iostream>
#include "EdmondsKarpController.h"
#include "EdmondsKarpService.h"

using namespace std;

int main()
{
	auto edmondsKarpService = new EdmondsKarpService();
	EdmondsKarpController serv("127.0.0.1", "8092", edmondsKarpService);
	serv.setEndpoint("/api");
	serv.accept().wait();
	while(true)
	{
		
	}
	return 0;
}