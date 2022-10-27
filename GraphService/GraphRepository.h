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
	const string filenames[5] = {"graphs/big_dense_set.json", 
		"graphs/big_sparse_set.json", 
		"graphs/random_set.json",
		"graphs/small_dense_set.json",
		"graphs/small_sparse_set.json"};
	void readGraphsFromJson(string path);
	int size;
};