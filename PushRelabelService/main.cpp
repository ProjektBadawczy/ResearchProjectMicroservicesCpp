#include<iostream>
#include "PushRelabelController.h"
#include "PushRelabelService.h"

using namespace std;

int main()
{
	auto pushRelabelService = new PushRelabelService();
	PushRelabelController serv("127.0.0.1", "8093", pushRelabelService);
	serv.setEndpoint("/api");
	serv.accept().wait();
	while (true)
	{

	}
	return 0;
}