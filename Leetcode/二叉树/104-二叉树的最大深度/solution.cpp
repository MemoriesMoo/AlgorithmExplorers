#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;         // 节点值
    TreeNode *left;  // 左子树指针
    TreeNode *right; // 右子树指针

    // 默认构造函数，节点值初始化为0，左右子树指针为空
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // 值初始化构造函数，节点值为x，左右子树指针为空
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // 完整构造函数，节点值为x，左子树指针为l，右子树指针为r
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        // 如果根节点为空，表示空树，深度为0
        if (root == nullptr)
            return 0;

        // 计算左子树的深度
        int leftHeight = maxDepth(root->left);
        // 计算右子树的深度
        int rightHeight = maxDepth(root->right);

        // 取左右子树深度的较大值，加上当前节点的深度1
        int maxLenght = leftHeight > rightHeight ? leftHeight : rightHeight;

        return maxLenght + 1;
    }
};