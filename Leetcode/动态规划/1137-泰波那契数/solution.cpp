#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        // 处理基本情况
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        // 初始化动态规划数组（n+1），存储中间结果
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        // 通过迭代填充数组，计算泰波那契序列的第n项
        for (int i = 3; i <= n; ++i)
        {
            // 状态转移方程
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        // 返回结果
        return dp[n];
    }
};

// 滚动数组优化
class Solution1
{
public:
    int tribonacci(int n)
    {
        // 处理基本情况
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        int first = 0, second = 1, third = 1, current = 0;
        for (int i = 3; i <= n; i++)
        {
            // 计算当前值，是前三个值的和
            current = first + second + third;

            // 更新前三个值，向前移动一位
            first = second;
            second = third;
            third = current;
        }

        return current;
    }
};
