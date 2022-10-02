#pragma once
#include "../Common/Graph.h"
#include "../Common/DirectedGraph.h"
using namespace std;
class GraphRepository
{
public:
	GraphRepository();
	~GraphRepository();
	Graph* getGraph(int id);
	DirectedGraph* getDirectedGraph(int id);
private:
	void initRepository();
	Graph** graphs;
	DirectedGraph** directedGraphs;
	int size;
};