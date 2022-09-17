#pragma once
#include "../Common/BFSResult.h"
#include "../Common/Graph.h"
class BFSService
{
public:
	BFSService();
	~BFSService();
	BFSResult* bfs(Graph* graph, int source, int t);
};