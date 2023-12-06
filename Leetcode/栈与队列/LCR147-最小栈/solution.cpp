#include <iostream>
#include <stack>

class MinStack
{
public:
    MinStack()
    {
        // 构造函数，初始化MinStack对象。
    }

    void push(int val)
    {
        _elem.push(val); // 将元素值压入元素栈。

        // 如果最小栈为空或者val小于等于最小栈的栈顶元素，则将val也压入最小栈。
        if (_min.empty() || val <= _min.top())
        {
            _min.push(val);
        }
    }

    void pop()
    {
        // 如果元素栈的栈顶元素等于最小栈的栈顶元素，表示要弹出的元素是最小值，需要同时从最小栈和元素栈中弹出。
        if (_elem.top() == _min.top())
        {
            _min.pop();
        }
        _elem.pop(); // 从元素栈中弹出元素。
    }

    int top()
    {
        return _elem.top(); // 返回元素栈的栈顶元素。
    }

    int getMin()
    {
        return _min.top(); // 返回最小栈的栈顶元素，即最小值。
    }

private:
    std::stack<int> _elem; // 用于存储元素的栈。
    std::stack<int> _min;  // 用于存储最小值的栈。
};