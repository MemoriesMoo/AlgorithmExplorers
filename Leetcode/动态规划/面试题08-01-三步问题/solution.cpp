#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int waysToStep(int n)
    {
        // 处理基本情况
        if (n == 0)
            return 1;
        if (n == 1 || n==2)
            return n;

        const int MOD = 1e9 + 7;

        // 初始化前三个值，表示爬到第1、2、3阶楼梯的方法数
        long long first = 1, second = 1, third = 2, current = 0;

        // 从第4阶楼梯开始，计算爬到每一阶楼梯的方法数
        for (int i = 3; i <= n; i++)
        {
            // 计算当前值，是前三个值的和，对结果取模以防溢出
            current = (first + second + third) % MOD;

            // 更新前三个值，向前移动一位
            first = second % MOD;
            second = third % MOD;
            third = current % MOD;
        }

        // 返回爬到第n阶楼梯的方法数，对结果再次取模
        return current % MOD;
    }
};
