#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 存储结果
        vector<vector<int>> ret;

        // 先对数据进行排序
        sort(nums.begin(), nums.end());

        // 利用双指针算法
        int n = nums.size();

        // 固定一个元素
        for (int i = 0; i < n;)
        {
            // 如果固定元素为正数，后续元素不可能使得三数之和为零，直接退出循环
            if (nums[i] > 0)
                break;

            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                // 计算当前三个元素的和
                int sum = nums[left] + nums[right];
                int target = -nums[i];
                if (sum < target)
                    left++; // 如果和小于目标值，移动左指针增大和
                else if (sum > target)
                    right--; // 如果和大于目标值，移动右指针减小和
                else
                {
                    // 找到一种组合之后加入结果集
                    ret.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // 对结果进行去重
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }

            i++;

            // 对i进行去重
            while (i < n && nums[i] == nums[i - 1])
                i++;
        }
        return ret;
    }
};
