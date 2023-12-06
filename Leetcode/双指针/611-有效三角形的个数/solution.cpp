#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        // 1. 优化：对输入数组进行排序
        sort(nums.begin(), nums.end());

        // 2. 利用双指针解决问题
        int count = 0; // 记录符合条件的三元组个数
        int n = nums.size();

        // 3. 从数组末尾开始，固定最大的数
        for (int i = n - 1; i >= 2; i--)
        {
            // 4. 使用双指针从数组开头和当前最大数的前一个位置开始向中间移动
            int left = 0, right = i - 1;

            // 5. 在双指针移动的过程中，判断是否满足三角形的条件
            while (left < right)
            {
                // 如果两较小边之和大于当前最大边，则说明符合条件
                if (nums[left] + nums[right] > nums[i])
                {
                    // 6. 在此情况下，右指针左移，统计符合条件的个数
                    count += right - left;
                    right--;
                }
                else
                {
                    // 7. 如果不满足条件，左指针右移
                    left++;
                }
            }
        }
        // 8. 返回符合条件的三元组个数
        return count;
    }
};
