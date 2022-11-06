#include "GraphRepository.h"

GraphRepository::GraphRepository()
{
	// set initial size of array to 100
	// expand when necessary
	// leave current size as 0
	// until graphs are actually inserted
	size = 0;
	graphs.resize(100);
	directedGraphs.resize(100);
	initRepository();
}

GraphRepository::~GraphRepository()
{
	for (auto graph : graphs)
	{
		if (graph != nullptr)
		{
			delete graph;
		}
	}
	graphs.clear();
	for (auto directedGraph : directedGraphs)
	{
		if (directedGraph != nullptr)
		{
			delete directedGraph;
		}
	}
	directedGraphs.clear();
}

void GraphRepository::initRepository()
{
	readGraphsFromJson(filenames[0]);
}

Graph* GraphRepository::getGraph(int id)
{
	auto predicate = [=](Graph* graph)
	{
		return graph != nullptr ? graph->getId() == id : false;
	};
	auto result = find_if(graphs.begin(), graphs.end(), predicate);
	return result != graphs.end() ? (*result)->clone() : nullptr;
}

DirectedGraph* GraphRepository::getDirectedGraph(int id)
{
	auto predicate = [=](DirectedGraph* directedGraph)
	{
		return directedGraph != nullptr ? directedGraph->getId() == id : false;
	};
	auto result = find_if(directedGraphs.begin(), directedGraphs.end(), predicate);
	return result != directedGraphs.end() ? (*result)->clone() : nullptr;
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
		this->graphs.push_back(graph);
		pos = buffer.str().find(directedGraphName, nextStopPos);
		if (pos == string::npos) break;
		// directed graphs always end with "}}"
		nextStopPos = buffer.str().find("}}", pos);
		directedGraph = new DirectedGraph(utility::conversions::to_string_t(buffer.str().substr(pos, nextStopPos - pos + 1)));
		this->directedGraphs.push_back(directedGraph);
		size++;
	}
}

