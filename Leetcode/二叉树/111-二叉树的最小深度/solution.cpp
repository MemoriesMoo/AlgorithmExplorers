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
    int minDepth(TreeNode *root)
    {
        // 如果根节点为空，表示空树，深度为0
        if (root == nullptr)
            return 0;

        // 如果当前节点是叶子节点，深度为1
        if (root->left == nullptr && root->right == nullptr)
            return 1;

        // 计算左子树的深度
        int leftHeight = minDepth(root->left);
        // 计算右子树的深度
        int rightHeight = minDepth(root->right);

        // 处理其中一个子树为空的情况
        if (leftHeight == 0)
            return rightHeight + 1;
        else if (rightHeight == 0)
            return leftHeight + 1;
        else
            // 返回左右子树深度的较小值加1
            return min(leftHeight, rightHeight) + 1;
    }
};
