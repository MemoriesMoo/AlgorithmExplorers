#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 初始化左右指针和最大面积
        int left = 0, right = height.size() - 1, ret = 0;

        // 循环直到左右指针相遇
        while (left < right) {
            // 计算当前两个指针所指向的线段构成的容器的水量
            int v = min(height[left], height[right]) * (right - left);
            // 更新最大水量
            ret = max(ret, v);

            // 移动指针
            // 选择较短的线段移动，以期望找到更高的线段
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        // 返回最大水量
        return ret;
    }
};