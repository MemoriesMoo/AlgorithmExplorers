#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        int cur = 0;      // 当前遍历的位置
        int dest = -1;    // 最后一个复写的位置
        int num = arr.size();  // 数组的长度

        // 第一次遍历，找到最后一个复写的位置
        while (cur < num) {
            // 如果当前元素是非零，直接将 dest 和 cur 都加1
            if (arr[cur] != 0) {
                dest++;
            } else {
                // 如果当前元素是零，因为我们要复写两次零，所以 dest 加2
                dest += 2;
            }

            // 如果 dest 超过数组长度减1，跳出循环
            if (dest >= num - 1) {
                break;
            }

            // 继续遍历下一个位置
            cur++;
        }

        // 处理特殊情况：最后一个复写的位置在数组末尾
        if (dest == num) {
            // 在数组末尾设置零，并调整 dest 和 cur
            arr[num - 1] = 0;
            dest -= 2;
            cur--;
        }

        // 第二次遍历，从数组末尾开始移动元素
        while (cur >= 0) {
            // 如果当前元素是非零，直接将其复写到 dest 的位置，然后将 dest 和 cur 分别减1
            if (arr[cur] != 0) {
                arr[dest--] = arr[cur--];
            } else {
                // 如果当前元素是零，需要复写两次零，所以将 dest 的位置和 dest-1 的位置都设置为零，并将 cur 减2
                arr[dest--] = 0;
                arr[dest--] = 0;
                cur--;
            }
        }
    }
};