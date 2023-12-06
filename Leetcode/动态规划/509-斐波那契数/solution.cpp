#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        // 处理基本情况
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        // 初始化动态规划数组，存储中间结果
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        // 通过迭代填充数组，计算斐波那契数列的第 n 项
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // 返回结果
        return dp[n];
    }
};