#pragma once

#include <vector>

class HeapBase
{

public:
    
    HeapBase() = default;
    virtual ~HeapBase() = default;

    /**
     * @brief 向堆里面添加一条边
     */
    virtual void add(std::pair<int, int> edge) = 0;

    /**
     * 获取最小值
     */
    virtual std::pair<int, int> getMin() = 0;

    /**
     * 删除最小值，注意与getMin的区别
     */
    virtual void deleteMin() = 0;

    /**
     * // TODO: 讨论是否要用decreaseKey，或者说把它变成非虚函数？
     *          主要是：我想让heap的接口统一，使得运行dijkstra算法的时候方便一点。
     *                 斐波那契堆是支持decreaseKey操作的，而且斐波那契堆理论上是dijkstra算法的最优选择。
     *                 但是很多其他的堆都不支持高效的decreaseKey操作，它们在实际应用中使用的好像是惰性删除策略（插入重复节点）
     *                 是否可以这样：在其他堆的decreaseKey实现中，偷偷用惰性删除策略？
     */
    virtual void decreaseKey(std::pair<int, int> edge) = 0;

    /**
     * 获取堆的大小
     */
    virtual int size() = 0;

    /**
     * 判断堆是否为空
     */
    virtual bool isEmpty() = 0;

}