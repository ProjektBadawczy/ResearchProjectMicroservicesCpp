#include "GraphRepository.h"

GraphRepository::GraphRepository()
{
	// set initial size of array to 100
	// expand when necessary
	size = 100;
	graphs = new Graph* [size];
	directedGraphs = new DirectedGraph * [size];
	for (int i = 0; i < size; i++)
	{
		graphs[i] = nullptr;
		directedGraphs[i] = nullptr;
	}
	initRepository();
}

GraphRepository::~GraphRepository()
{
	for (int i = 0; i < size; i++)
	{
		if (graphs[i] != nullptr)
		{
			delete graphs[i];
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (directedGraphs[i] != nullptr)
		{
			delete directedGraphs[i];
		}
	}
	delete[] graphs;
	delete[] directedGraphs;
}

void GraphRepository::initRepository()
{
	readGraphsFromJson(filenames[0]);
}

Graph* GraphRepository::getGraph(int id)
{
	return graphs[id]->clone();
}

DirectedGraph* GraphRepository::getDirectedGraph(int id)
{
	return directedGraphs[id]->clone();
}

void GraphRepository::readGraphsFromJson(string path)
{
	ifstream t(path);
	stringstream buffer;
	buffer << t.rdbuf();
	string graphName = "\"graph\": ";
	string directedGraphName = "\"directedGraph\": ";
	size_t pos = 0;
	size_t nextStopPos = 0;
	Graph* graph;
	DirectedGraph* directedGraph;
	
	// read graphs from json
	// graphs should be formatted as [{graph, directedGraph}, {graph, directedGraph}, ...]
	while (true)
	{
		pos = buffer.str().find(graphName, pos);
		if (pos == string::npos) break;
		// graphs always end with "},"
		nextStopPos = buffer.str().find("},", pos);
		graph = new Graph(utility::conversions::to_string_t(buffer.str().substr(pos, nextStopPos - pos + 1)));
		this->graphs[graph->getId()] = graph;
		pos = buffer.str().find(directedGraphName, nextStopPos);
		if (pos == string::npos) break;
		// directed graphs always end with "}}"
		nextStopPos = buffer.str().find("}}", pos);
		directedGraph = new DirectedGraph(utility::conversions::to_string_t(buffer.str().substr(pos, nextStopPos - pos + 1)));
		this->directedGraphs[directedGraph->getId()] = directedGraph;
	}
}

