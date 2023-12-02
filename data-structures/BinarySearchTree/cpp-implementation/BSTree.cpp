#include "BSTree.h"

// 节点构造函数
BSTNode::BSTNode(int val) : _val(val), _left(nullptr), _right(nullptr) {}

// 二叉搜索树构造函数
BSTree::BSTree() : _root(nullptr) {}

// 插入辅助函数，递归地插入新节点
BSTNode *BSTree::insertHelper(BSTNode *root, int val)
{
    // 基本情况：如果根节点为空，创建新节点并返回
    if (!root)
        return new BSTNode(val);

    // 根据值的大小关系递归插入节点
    if (val < root->_val)
        root->_left = insertHelper(root->_left, val);
    else
        root->_right = insertHelper(root->_right, val);

    return root;
}

// 查找辅助函数，递归寻求节点
BSTNode *BSTree::findHelper(BSTNode *root, int val)
{
    // 基本情况：如果根节点为空或找到了目标值，返回当前节点
    if (!root || root->_val == val)
        return root;

    // 根据值的大小关系递归查找节点
    if (val < root->_val)
        return findHelper(root->_left, val);
    else
        return findHelper(root->_right, val);
}

// 删除辅助函数，递归地删除树中的节点
BSTNode *BSTree::deleteHelper(BSTNode *root, int val)
{
    // 基本情况：如果根节点为空，返回空
    if (!root)
        return root;

    // 根据值的大小关系递归删除节点
    if (val < root->_val)
        root->_left = deleteHelper(root->_left, val);
    else if (val > root->_val)
        root->_right = deleteHelper(root->_right, val);
    else
    {
        // 找到要删除的节点

        // 情况1：节点没有子节点或只有一个子节点
        if (!root->_left)
        {
            BSTNode *temp = root->_right;
            delete root;
            return temp;
        }
        else if (!root->_right)
        {
            BSTNode *temp = root->_left;
            delete root;
            return temp;
        }

        // 情况3：节点有两个子节点
        BSTNode *temp = findMin(root->_right);
        root->_val = temp->_val;
        root->_right = deleteHelper(root->_right, temp->_val);
    }

    return root;
}

// 中序遍历辅助函数
void BSTree::inOrderTraversal(BSTNode *root)
{
    // 基本情况：如果当前节点为空，返回
    if (root)
    {
        // 递归遍历左子树
        inOrderTraversal(root->_left);

        // 输出当前节点的值
        std::cout << root->_val << " ";

        // 递归遍历右子树
        inOrderTraversal(root->_right);
    }
}

// 查找右子树的最小值节点
BSTNode *BSTree::findMin(BSTNode *node)
{
    // 遍历左子树找到最小值节点
    while (node->_left)
    {
        node = node->_left;
    }
    return node;
}

// 插入函数，调用插入辅助函数
void BSTree::insert(int val)
{
    _root = insertHelper(_root, val);
}

// 查找函数，调用查找辅助函数
BSTNode *BSTree::find(int val)
{
    return findHelper(_root, val);
}

// 删除函数，调用删除辅助函数
void BSTree::deleteNode(int val)
{
    _root = deleteHelper(_root, val);
}

// 中序遍历函数，调用中序遍历辅助函数
void BSTree::inOrderTraversal()
{
    // 调用中序遍历辅助函数，从根节点开始遍历
    inOrderTraversal(_root);
    std::cout << std::endl; // 输出一个换行，使结果更清晰
}
