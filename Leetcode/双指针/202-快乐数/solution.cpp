#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int digitSquareSum(int num)
    {
        // 计算一个数的每个位置上的数字的平方和
        int result = 0;
        while (num > 0)
        {
            int digit = num % 10;
            result += digit * digit;
            num /= 10;
        }
        return result;
    }

    bool isHappy(int n)
    {
        // 初始化快慢指针
        int slow = n;
        int fast = n;

        do
        {
            slow = digitSquareSum(slow);                 // 慢指针移动一步
            fast = digitSquareSum(digitSquareSum(fast)); // 快指针移动两步

            if (slow == fast)
            {
                // 如果快慢指针相遇，说明存在循环
                break;
            }
        } while (fast != 1);

        // 判断相遇点是否为1
        return fast == 1;
    }
};