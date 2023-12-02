#pragma once
#include <iostream>

struct BSTNode
{
    BSTNode(int val) : _val(val), _left(nullptr), _right(nullptr) {} // 节点构造函数
    BSTNode *_left;                                                  // 左子节点指针
    BSTNode *_right;                                                 // 右子节点指针
    int _val;                                                        // 节点的值
};

class BSTree
{
private:
    BSTNode *_root; // 根节点指针

    // 插入辅助函数，递归地插入新节点
    BSTNode *insertHelper(BSTNode *root, int val);

    // 查找辅助函数，递归寻求节点
    BSTNode *findHelper(BSTNode *root, int val);

    // 删除辅助函数，递归地删除树中的节点
    BSTNode *deleteHelper(BSTNode *root, int val);

    // 查找右子树的最小值节点
    BSTNode *findMin(BSTNode *node);

    // 中序遍历辅助函数
    void inOrderTraversal(BSTNode *root);

public:
    // 二叉搜索树构造函数
    BSTree();

    // 插入函数，调用插入辅助函数
    void insert(int val);

    // 查找函数，调用查找辅助函数
    BSTNode *find(int val);

    // 删除函数，调用删除辅助函数
    void deleteNode(int val);

    // 中序遍历函数，调用中序遍历辅助函数
    void inOrderTraversal();
};