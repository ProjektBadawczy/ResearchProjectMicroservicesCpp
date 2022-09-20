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
	BFSRequest(std::string text);
	~BFSRequest();
	Graph* getGraph();
	int getSource();
	int getDestination();
	std::string toString();
};