#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            // 计算当前两个指针指向的元素之和
            int sum = nums[left] + nums[right];

            if (sum > target)
            {
                // 如果和大于目标值，减小和的值，移动右指针
                right--;
            }
            else if (sum < target)
            {
                // 如果和小于目标值，增大和的值，移动左指针
                left++;
            }
            else
            {
                // 如果和等于目标值，找到结果，返回
                return {nums[left], nums[right]};
            }
        }

        // 循环结束仍未找到符合条件的两个数
        return {-1, -1};
    }
};