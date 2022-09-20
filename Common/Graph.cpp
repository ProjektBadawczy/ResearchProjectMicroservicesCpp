#include "Graph.h"

using namespace std;

Graph::Graph(int id, int numberOfVertices, int** adjacencyMatrix)
{
	this->id = id;
	this->numberOfVertices = numberOfVertices;
	this->adjacencyMatrix = adjacencyMatrix;
}

// Creates new graph entity from its string version
Graph::Graph(string text)
{
    size_t pos = 0;
    size_t nextCommaPos = 0;
    string idName = "id: ";
    string numberOfVerticesName = "numberOfVertices: ";
    string adjacencyMatrixName = "adjacencyMatrix: ";
    // find id value
    pos = text.find(idName, pos);
    nextCommaPos = text.find(",", pos);
    int newId = stoi(text.substr(pos+idName.length(), nextCommaPos - (pos + idName.length())));
    // find numberOfVertices value
    pos = text.find(numberOfVerticesName, pos);
    nextCommaPos = text.find(",", pos);
    int newNumberOfVertices = stoi(text.substr(pos+adjacencyMatrixName.length(),
                                               nextCommaPos - (pos + numberOfVerticesName.length())));
    int** newAdjacencyMatrix = new int*[newNumberOfVertices];
    for(int i = 0; i < newNumberOfVertices; i++)
    {
        newAdjacencyMatrix[i] = new int[newNumberOfVertices];
    }
    // find adjacency matrix
    pos = text.find(adjacencyMatrixName, pos);
    // set pos variable to the beginning of the first number in adjacency matrix
    pos += adjacencyMatrixName.length() + 2;
    string stringNumber;
    for(int i = 0; i < newNumberOfVertices; i++)
    {
        for(int j = 0; j < newNumberOfVertices; j++)
        {
            if (i < newNumberOfVertices - 1)
            {
                nextCommaPos = text.find(",", pos);
            } else
            {
                nextCommaPos = text.find("]", pos);
            }
            stringNumber = text.substr(pos, nextCommaPos - pos);
            newAdjacencyMatrix[i][j] = stoi(stringNumber);
            pos = nextCommaPos + 1;
        }
        pos = pos + 2;
    }
    this->id = newId;
    this->numberOfVertices = newNumberOfVertices;
    this->adjacencyMatrix = newAdjacencyMatrix;
}

Graph::~Graph()
{
	for (int i = 0; i < this->numberOfVertices; i++)
	{
		delete[] this->adjacencyMatrix[i];
	}
	delete[] this->adjacencyMatrix;
}

Graph* Graph::clone()
{
	int** matrix = new int* [numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
	{
		matrix[i] = new int[numberOfVertices];
	}
	for (int i = 0; i < numberOfVertices; i++)
	{
		for (int j = 0; j < numberOfVertices; j++)
		{
			matrix[i][j] = adjacencyMatrix[i][j];
		}
	}
	return new Graph(id, numberOfVertices, matrix);
}

int Graph::getId()
{
	return id;
}

int Graph::getNumberOfVertices()
{
	return numberOfVertices;
}

int** Graph::getAdjacencyMatrix()
{
	return adjacencyMatrix;
}

string Graph::toString()
{
	string result = "";
	result += "{";
	result += "id: ";
	result += to_string(id);
	result += ",";
	result += "numerOfVertices: ";
	result += to_string(numberOfVertices);
	result += ",";
	result += "adjacencyMatrix: [";
	for (int i = 0; i < numberOfVertices; i++)
	{
		result += "[";
		for (int j = 0; j < numberOfVertices; j++)
		{
			result += to_string(adjacencyMatrix[i][j]);
			if (j != numberOfVertices - 1)
			{
				result += ",";
			}
		}
		result += "]";
		if (i != numberOfVertices - 1)
		{
			result += ",";
		}
	}
	result += "]";
	result += "}";
	return result;
}