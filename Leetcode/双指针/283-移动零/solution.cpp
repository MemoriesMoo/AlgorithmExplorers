#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int nonZeroIndex = 0;

        // 遍历数组，将非零元素移到前面
        for (int cur = 0; cur < nums.size(); ++cur)
        {
            if (nums[cur] != 0)
            {
                swap(nums[nonZeroIndex++], nums[cur]);
            }
        }

        // 填充剩余位置为零
        while (nonZeroIndex < nums.size())
        {
            nums[nonZeroIndex++] = 0;
        }
    }
};
