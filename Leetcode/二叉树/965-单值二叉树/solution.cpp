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
    /**
     * 判断给定二叉树是否是单值二叉树
     * @param root 二叉树的根节点
     * @return 如果是单值二叉树则返回 true，否则返回 false
     */
    bool isUnivalTree(TreeNode *root)
    {
        // 如果根节点为空，视为空的二叉树，返回 true
        if (root == nullptr)
            return true;

        // 如果左子树存在且值不等于根节点的值，返回 false
        if (root->left)
        {
            if (root->val != root->left->val)
                return false;
        }

        // 如果右子树存在且值不等于根节点的值，返回 false
        if (root->right)
        {
            if (root->val != root->right->val)
                return false;
        }

        // 递归检查左右子树是否也是单值二叉树
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
