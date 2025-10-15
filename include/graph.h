#pragma once

#include <vector>

/**
 * @brief 图的类，有基本的功能
 * 
 * 负责存储图，存储的方式是邻接表（adjacency list）
 * 
 */
class Graph
{

private:    
    int _numOfNode;
    int _numOfEdge;

    /**
     * @brief 邻接表
     * 
     * @details
     * - first: 顶点的id
     * - second: 当前节点到顶点的权重
     * 
     * @note 节点序号从 1 开始!!
     * 
     * 示例：
     * {
     *      {(2, 7), (3, 6)},   // 节点1与2相连，权重为7;节点1与3相连，权重为6
     *      {(1, 7)},           // 节点2与1相连，权重为7
     *      {(1, 6)}            // 节点3与1相连，权重为6
     * }
     * 
     */
    std::vector<std::vector<std::pair<int, int>>> _adjList; 

public:

    /**
     * @brief 默认构造函数
     * 
     * @details 创建一个空的adjList，numOfNode和numOfEdge赋值为0
     */
    Graph();

    /**
     * @brief 含参构造函数
     * 
     * @param numOfNode 总节点数量
     * @param numOfEdge 总的边数量
     * 
     * @details 创建一个大小为numOfNode + 1的adjList
     */
    explicit Graph(int numOfNode, int numOfEdge);

    ~Graph() = default;

    /**
     * @brief 检测图是否为空
     * 
     * @return true为空 false为非空
     */
    bool isEmpty();

    /**
     * @brief 返回总节点数
     * 
     * @return 总结点数
     */
    int getNumOfNode();

    /**
     * @brief 返回总边数
     * 
     * @return 总边数
     */
    int getNumOfEdge();

    /**
     * @brief 返回指定节点的全部邻居，以vector形式存储
     * 
     * @param nodeNumber 指定节点的编号
     * 
     * @return 以vector的引用形式返回该指定节点的全部邻居
     * 
     * @note 返回的是const的值，只可读，不能修改
     */
    const std::vector<std::pair<int, int>>& getNeighbors(int nodeNumber);

    /**
     * @brief 添加一条有向边
     * 
     * @param start 该有向边的起点
     * @param end 该有向边的终点
     * @param weightOfEdge 该有向边的权重
     * 
     * @return true代表添加成功 false代表添加失败
     */
    bool addEdge(int start, int end, int weightOfEdge);

    /**
     * @brief 返回两点之间的边的权重
     * 
     * @param start 边的起点
     * @param end 边的终点
     * 
     * @return 该边的权重，如果为-1，则代表该边不存在
     */
    int getEdgeWeight(int start, int end);

    /**
     * @brief 判断两点是否连通
     * 
     * @param start 边的起点
     * @param end 边的终点
     * 
     * @return true连通 false不连通
     */
    bool isConnected(int start, int end);
};