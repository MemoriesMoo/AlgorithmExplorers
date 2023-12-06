#include <iostream>
#include <vector>

using namespace std;

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
    // 前序遍历的递归函数
    void preorder(TreeNode *root, vector<int> &res)
    {
        // 如果当前结点为空，则直接返回
        if (root == nullptr)
        {
            return;
        }

        // 将当前结点的值加入结果集
        res.push_back(root->val);

        // 递归遍历左子树
        preorder(root->left, res);

        // 递归遍历右子树
        preorder(root->right, res);
    }

    // 前序遍历的入口函数
    vector<int> preorderTraversal(TreeNode *root)
    {
        // 用于存储遍历结果的向量
        vector<int> res;

        // 调用递归函数进行前序遍历
        preorder(root, res);

        // 返回最终结果
        return res;
    }
};