#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        std::stack<int> st;

        for (const auto &str : tokens)
        {
            // 如果当前字符串是运算符
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                // 弹出堆栈中的右操作数
                int rightNum = st.top();
                st.pop();

                // 弹出堆栈中的左操作数
                int leftNum = st.top();
                st.pop();

                // 调用 evaluateExpression 函数执行运算并获取中间结果
                int resultNum = evaluateExpression(str[0], leftNum, rightNum);

                // 将中间结果压入堆栈
                st.push(resultNum);
            }
            else
            {
                // 如果当前字符串是操作数，将其转换为整数并压入堆栈
                st.push(stoi(str));
            }
        }

        // 最终堆栈中仅剩一个元素，即计算结果
        return st.top();
    }

private:
    int evaluateExpression(char op, int left, int right)
    {
        // 根据运算符执行相应的运算
        switch (op)
        {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        }
        // 此处需要一个返回值（但是题目用例无误，任意返回值即可）
        return 0;
    }
};