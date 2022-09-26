#include <iostream>
#include "GraphController.h"
#include "GraphRepository.h"
#include "GraphService.h"

using namespace std;

int main()
{
	auto graphRepository = new GraphRepository();
	auto graphService = new GraphService(graphRepository);
	GraphController serv("127.0.0.1", "8090", graphService);
	serv.setEndpoint("/api");
	serv.accept().wait();
	while(true)
	{
		
	}
	return 0;
}