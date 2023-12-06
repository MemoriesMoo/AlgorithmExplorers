#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // 如果两个节点都为空，视为相同的二叉树
        if (p == nullptr && q == nullptr)
            return true;

        // 如果其中一个节点为空而另一个不为空，视为不相同的二叉树
        if (p == nullptr || q == nullptr)
            return false;

        // 如果两个节点的值不相等，视为不相同的二叉树
        if (p->val != q->val)
            return false;

        // 递归检查左右子树是否相同
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    // 给你一个二叉树的根节点root，检查它是否轴对称
    bool isSymmetric(TreeNode *root)
    {
        if(root == nullptr)
            return true;

        return isSameTree(root->left, root->right);
    }
};