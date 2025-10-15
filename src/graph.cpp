#include <vector>

#include "../include/graph.h"

using std::vector;
using std::pair;

Graph::Graph() : _numOfNode(0), _numOfEdge(0), _adjList() {}

explicit Graph::Graph(int numOfNode, int numOfEdge) 
    : _numOfNode(numOfNode), _numOfEdge(numOfEdge), _adjList(numOfNode + 1) {}

/**
 * 根据节点数是否为0来判断是否为空
 */
bool Graph::isEmpty()
{
    return _numOfNode == 0;
}

/**
 * 返回_numOfNode
 */
int Graph::getNumOfNode()
{
    return _numOfNode;
}

/**
 * 返回_numOfEdge
 */
int Graph::getNumOfEdge()
{
    return _numOfEdge;
}

const vector<pair<int, int>>& Graph::getNeighbors(int nodeNumber)
{
    return _adjList[nodeNumber];
}

void Graph::addEdge(int start, int end, int weightOfEdge)
{
    /* 如果邻接表太小了，进行扩容 */
    int maxNum = std::max(start, end);
    if (_numOfNode < maxNum) 
    {
        _adjList.resize(maxNum + 1);
        _numOfNode = maxNum;
    }

    _adjList[start].emplace_back(pair<int, int>(start, weightOfEdge));
    
    return;
}

/**
 * for循环遍历start的全部邻居
 */
int Graph::getEdgeWeight(int start, int end)
{
    for (auto& edge : _adjList[start])
    {
        if (edge.first == end)
        {
            return edge.second;
        }
    }
    return -1;
}

bool Graph::isConnected(int start, int end)
{
    int weight = getEdgeWeight(start, end);
    if (weight == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
