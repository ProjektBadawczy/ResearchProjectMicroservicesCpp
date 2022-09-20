#pragma once
#include "../Common/BFSResult.h"
#include "../Common/Graph.h"
#include "../Common/BFSRequest.h"
class BFSService
{
public:
	BFSService();
	~BFSService();
	BFSResult* bfs(Graph* graph, int source, int t);
	BFSResult* bfs(BFSRequest* request);
};