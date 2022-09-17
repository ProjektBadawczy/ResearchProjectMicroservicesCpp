#include "EdmondsKarpService.h"
#include <stdexcept>
#include <climits>


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
	// TODO
	// add actual communication with BFS microservice


	auto intDummy = new int[4];
	auto bfsResult = new BFSResult(intDummy, true);
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
		// TODO
		// add actual communication with BFS microservice
		bfsResult = new BFSResult(intDummy, true);
	}
	delete bfsResult;
	delete residualGraph;
	return maxFlow;
}
bool EdmondsKarpService::areSourceAndGraphParametersValid(Graph* graph, int source, int destination)
{
	return source >= 0 && source < graph->getNumberOfVertices() && destination >= 0 && destination < graph->getNumberOfVertices();
}