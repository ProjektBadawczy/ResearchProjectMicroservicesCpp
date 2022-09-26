#include "EdmondsKarpService.h"
#include <stdexcept>
#include <climits>
using namespace utility;


EdmondsKarpService::EdmondsKarpService()
{
}
EdmondsKarpService::~EdmondsKarpService()
{
}
int EdmondsKarpService::calculateMaxFlow(Graph* graph, int source, int destination)
{
	if (!areSourceAndGraphParametersValid(graph, source, destination))
	{
		throw std::invalid_argument("arguments are invalid");
	}
	int u, v;
	auto residualGraph = graph->clone();
	int maxFlow = 0;
	string_t address = BFS_SERVICE_URL + string_t(U("bfs"));
	auto bfsRequest = new BFSRequest(residualGraph, source, destination);
	web::json::value body;
	body[U("request")] = web::json::value::string(bfsRequest->toString());
	auto response = sendPostRequest(address, body);
	auto bfsResult = new BFSResult(response);
	while (bfsResult->getSuccess())
	{
		int pathFlow = INT_MAX;
		for (v = destination; v != source; v = bfsResult->getParents()[v])
		{
			u = bfsResult->getParents()[v];
			pathFlow = std::min(pathFlow, residualGraph->getAdjacencyMatrix()[u][v]);
		}
		for (v = destination; v != source; v = bfsResult->getParents()[v])
		{
			u = bfsResult->getParents()[v];
			residualGraph->getAdjacencyMatrix()[u][v] -= pathFlow;
			residualGraph->getAdjacencyMatrix()[v][u] += pathFlow;
		}
		maxFlow += pathFlow;
		delete bfsResult;
		delete bfsRequest;
		bfsRequest = new BFSRequest(residualGraph, source, destination);
		body[U("request")] = web::json::value::string(bfsRequest->toString());
		response = sendPostRequest(address, body);
		bfsResult = new BFSResult(response);
	}
	delete bfsResult;
	delete residualGraph;
	return maxFlow;
}
bool EdmondsKarpService::areSourceAndGraphParametersValid(Graph* graph, int source, int destination)
{
	return source >= 0 && source < graph->getNumberOfVertices() && destination >= 0 && destination < graph->getNumberOfVertices();
}