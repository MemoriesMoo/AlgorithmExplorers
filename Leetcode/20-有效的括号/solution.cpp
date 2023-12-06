#include <iostream>
#include <stack>
#include <string>

class Solution
{
public:
    // 判断给定的字符串中的括号是否匹配
    bool isValid(std::string s)
    {
        // 使用栈来辅助括号匹配的检查
        std::stack<char> st;

        // 遍历字符串中的每个字符
        for (int index = 0; index < s.size(); ++index)
        {
            if (s[index] == '(' || s[index] == '{' || s[index] == '[')
            {
                // 如果是左括号，则将其推入栈中
                st.push(s[index]);
            }
            else
            {
                // 如果是右括号，则进行匹配
                // 首先检查栈是否为空
                if (st.empty())
                    return false;

                // 取出栈顶元素
                char cmp = st.top();

                // 检查当前右括号与栈顶元素是否匹配
                if ((s[index] == ')' && cmp != '(') || (s[index] == ']' && cmp != '[') || (s[index] == '}' && cmp != '{'))
                {
                    // 不匹配则返回false
                    return false;
                }
                else
                {
                    // 匹配则出栈，继续循环
                    st.pop();
                }
            }
        }

        // 判断此时栈是否为空，确保所有左括号都有右括号匹配
        return st.empty();
    }
};
