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
    // 后序遍历的递归函数
    void Postorder(TreeNode *root, vector<int> &res)
    {
        // 如果当前结点为空，则直接返回
        if (root == nullptr)
        {
            return;
        }

        // 递归遍历左子树
        Postorder(root->left, res);

        // 递归遍历右子树
        Postorder(root->right, res);

        // 将当前结点的值加入结果集
        res.push_back(root->val);
    }

    // 后序遍历接口函数
    vector<int> postorderTraversal(TreeNode *root)
    {
        // 用于存储遍历结果的向量
        vector<int> res;

        // 调用递归函数进行后序遍历
        Postorder(root, res);

        // 返回最终结果
        return res;
    }
};