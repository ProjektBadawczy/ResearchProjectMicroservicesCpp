#pragma once
#include "Graph.h"
#include "BFSResult.h"
#include <stdexcept>
#include <cpprest/http_client.h>

class EdmondsKarpService
{
public:
	EdmondsKarpService();
	~EdmondsKarpService();
	int calculateMaxFlow(Graph* graph, int source, int destination);
private:
	bool areSourceAndGraphParametersValid(Graph* graph, int source, int destination);
};