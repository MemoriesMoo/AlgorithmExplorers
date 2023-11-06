#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode
{
    int val;                // 节点的值
    struct TreeNode *left;  // 左子节点
    struct TreeNode *right; // 右子节点
};

// 创建新的二叉树节点
struct TreeNode *createNode(int value)
{
    // 为节点分配内存并初始化值和子节点
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 使用递归方式实现先序遍历
void preorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->val);       // 先访问当前节点的值
    preorderTraversal(root->left);  // 然后递归左子树
    preorderTraversal(root->right); // 最后递归右子树
}

// 使用递归方式实现中序遍历
void inorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);  // 先递归左子树
    printf("%d ", root->val);      // 然后访问当前节点的值
    inorderTraversal(root->right); // 最后递归右子树
}

// 使用递归方式实现后序遍历
void postorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);  // 先递归左子树
    postorderTraversal(root->right); // 然后递归右子树
    printf("%d ", root->val);        // 最后访问当前节点的值
}

// 释放二叉树节点及其子树的内存
void freeTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);  // 递归释放左子树
    freeTree(root->right); // 递归释放右子树
    free(root);            // 释放当前节点
}

// 计算二叉树的节点数量
int treeSize(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return treeSize(root->left) + treeSize(root->right) + 1;
}

// 计算二叉树的叶子节点数量
int treeLeafSize(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return treeLeafSize(root->left) + treeLeafSize(root->right);
}

// 计算二叉树的高度
int treeHeight(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 计算二叉树第K层节点个数
int treeKLevel(struct TreeNode *root, int K)
{
    if (root == NULL)
    {
        return 0;
    }

    // 走到这里就代表此处的根节点不为空且位于的层数就是要求的层数
    if (K == 1)
    {
        return 1;
    }

    return treeKLevel(root->left, K - 1) + treeKLevel(root->right, K - 1);
}

struct TreeNode *TreeFind(struct TreeNode *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->val == val)
            return root;
    }

    struct TreeNode *leftRes = TreeFind(root->left, val);
    if (leftRes)
        return leftRes;

    struct TreeNode *rightRes = TreeFind(root->right, val);
    if (rightRes)
        return rightRes;

    return NULL;
}

int main()
{
    // 创建一个示例二叉树
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    int size = treeSize(root);
    printf("Size of the tree: %d\n", size);

    int leafSize = treeLeafSize(root);
    printf("Number of leaf nodes: %d\n", leafSize);

    int height = treeHeight(root);
    printf("Height of the tree: %d\n", height);

    // 递归释放二叉树节点的内存
    freeTree(root);

    return 0;
}
