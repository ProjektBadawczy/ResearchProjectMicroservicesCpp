#pragma once
#include "Graph.h"

class BFSRequest
{
private:
	Graph* graph;
	int source;
	int destination;
public:
	BFSRequest(Graph* graph, int source, int destination);
	BFSRequest(utility::string_t text);
	~BFSRequest();
	Graph* getGraph();
	int getSource();
	int getDestination();
	utility::string_t toString();
};