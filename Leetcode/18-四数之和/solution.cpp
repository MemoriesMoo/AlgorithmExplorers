#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // 存储结果的二维向量
        vector<vector<int>> ret;

        // 对输入数组进行排序
        sort(nums.begin(), nums.end());

        // 获取数组大小
        int n = nums.size();

        // 外层循环，固定第一个数
        for (int i = 0; i < n;)
        {
            // 内层循环，固定第二个数
            for (int j = i + 1; j < n;)
            {
                // 初始化左右指针
                int left = j + 1;
                int right = n - 1;

                // 计算目标值，注意使用长整型防止溢出
                long long aim = (long long)target - nums[i] - nums[j];

                // 双指针法，查找满足条件的两个数
                while (left < right)
                {
                    int sum = nums[left] + nums[right];

                    // 如果和小于目标值，左指针右移
                    if (sum < aim)
                        left++;
                    // 如果和大于目标值，右指针左移
                    else if (sum > aim)
                        right--;
                    // 如果找到一组解
                    else
                    {
                        // 将四个数加入结果集
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // 更新左右指针
                        left++;
                        right--;

                        // 避免重复结果，跳过相同的数
                        while (left < right && nums[left] == nums[left - 1])
                            left++;

                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }

                // 更新第二个数的索引
                j++;

                // 避免重复结果，跳过相同的数
                while (j < n && nums[j] == nums[j - 1])
                    j++;
            }

            // 更新第一个数的索引
            i++;

            // 避免重复结果，跳过相同的数
            while (i < n && nums[i] == nums[i - 1])
                i++;
        }
        return ret;
    }
};
