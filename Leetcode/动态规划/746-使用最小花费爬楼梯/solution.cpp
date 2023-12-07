#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 返回dp[n]
    int minCostClimbingStairs(vector<int> &cost)
    {
        // cost[i]表示从楼梯第i个台阶向上爬需要支付的费用（跨越1/2个台阶）
        // dp[i]表示到达i位置时的最小花费
        // i 只能由 i-1 | i-2 跨越阶梯到达

        // 两种情况的最小值
        // 先到达i-1位置 dp[i] = dp[i-1] + cost[i-1] 走一步
        // 先到达i-2位置 dp[i] = dp[i-2] + cost[i-2] 走两步
        // dp[i] = min( dp[i-1] + cost[i-0], dp[i-2] + cost[i-2] )

        // dp[0] = dp[1] = 0 可以从第0/1个台阶直接向上爬
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i < dp.size(); ++i)
            dp[i] = min(dp[i - 1] + cost[i - 0], dp[i - 2] + cost[i - 2]);

        return dp[dp.size() - 1];
    }
};