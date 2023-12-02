
### 插入辅助函数 `insertHelper`

```cpp
BSTNode* insertHelper(BSTNode* root, int val) {
    // 如果根节点为空，创建新节点并返回
    if (!root) {
        return new BSTNode(val);
    }

    // 根据值的大小关系递归插入节点
    if (val < root->_val) {
        root->_left = insertHelper(root->_left, val);
    } else {
        root->_right = insertHelper(root->_right, val);
    }

    return root;
}
```

1. **基本情况：** 如果当前节点 (`root`) 为空，表示到达树的底部，创建一个新节点，并将其作为叶子节点插入。

   ```cpp
   if (!root) {
       return new BSTNode(val);
   }
   ```

2. **递归调用：** 根据值的大小关系，递归调用插入函数来在左子树或右子树中插入新节点。

   ```cpp
   if (val < root->_val) {
       root->_left = insertHelper(root->_left, val);
   } else {
       root->_right = insertHelper(root->_right, val);
   }
   ```

3. **返回根节点：** 返回当前子树的根节点。

   ```cpp
   return root;
   ```

### 查找辅助函数 `findHelper`

```cpp
BSTNode* findHelper(BSTNode* root, int val) {
    // 如果根节点为空或找到了目标值，返回当前节点
    if (!root || root->_val == val) {
        return root;
    }

    // 根据值的大小关系递归查找节点
    if (val < root->_val) {
        return findHelper(root->_left, val);
    } else {
        return findHelper(root->_right, val);
    }
}
```

1. **基本情况：** 如果当前节点 (`root`) 为空或找到了目标值，表示查找成功，返回当前节点。

   ```cpp
   if (!root || root->_val == val) {
       return root;
   }
   ```

2. **递归调用：** 根据值的大小关系，递归调用查找函数在左子树或右子树中查找目标值。

   ```cpp
   if (val < root->_val) {
       return findHelper(root->_left, val);
   } else {
       return findHelper(root->_right, val);
   }
   ```

### 删除辅助函数 `deleteHelper`

```cpp
BSTNode* deleteHelper(BSTNode* root, int val) {
    // 如果根节点为空，返回空
    if (!root) {
        return root;
    }

    // 根据值的大小关系递归删除节点
    if (val < root->_val) {
        root->_left = deleteHelper(root->_left, val);
    } else if (val > root->_val) {
        root->_right = deleteHelper(root->_right, val);
    } else {
        // 找到要删除的节点

        // 情况1：节点没有子节点或只有一个子节点
        if (!root->_left) {
            BSTNode* temp = root->_right;
            delete root;
            return temp;
        } else if (!root->_right) {
            BSTNode* temp = root->_left;
            delete root;
            return temp;
        }

        // 情况3：节点有两个子节点
        BSTNode* temp = findMin(root->_right);
        root->_val = temp->_val;
        root->_right = deleteHelper(root->_right, temp->_val);
    }

    return root;
}
```

1. **基本情况：** 如果当前节点 (`root`) 为空，表示到达树的底部，返回空。

   ```cpp
   if (!root) {
       return root;
   }
   ```

2. **递归调用：** 根据值的大小关系，递归调用删除函数在左子树或右子树中删除节点。

   ```cpp
   if (val < root->_val) {
       root->_left = deleteHelper(root->_left, val);
   } else if (val > root->_val) {
       root->_right = deleteHelper(root->_right, val);
   }
   ```

3. **节点删除：**
   - **情况1：** 如果要删除的节点没有左子节点或只有一个左子节点，用右子节点（如果存在）替换该节点，然后删除该节点。

   ```cpp
   if (!root->_left) {
       BSTNode* temp = root->_right;
       delete root;
       return temp;
   }
   ```

   - **情况2：** 如果要删除的节点没有右子节点或只有一个右子节点，用左子节点（如果存在）替换该节点，然后删除该节点。

   ```cpp
   else if (!root->_right) {
       BSTNode* temp = root->_left;
       delete root;
       return temp;
   }
   ```

   - **情况3：**

 如果要删除的节点有左右两个子节点，找到右子树中的最小值节点，用其值替换当前节点的值，然后递归地在右子树中删除这个最小值节点。

   ```cpp
   else {
       BSTNode* temp = findMin(root->_right);
       root->_val = temp->_val;
       root->_right = deleteHelper(root->_right, temp->_val);
   }
   ```

4. **返回根节点：** 返回当前子树的根节点。

   ```cpp
   return root;
   ```

### 查找右子树的最小值节点辅助函数 `findMin`

```cpp
BSTNode* findMin(BSTNode* node) {
    // 遍历左子树找到最小值节点
    while (node->_left) {
        node = node->_left;
    }
    return node;
}
```

### 中序遍历辅助函数 `inOrderTraversal`

```cpp
void BSTree::inOrderTraversal(BSTNode *root) {
    if (root) {
        // 递归遍历左子树
        inOrderTraversal(root->_left);

        // 输出当前节点的值
        std::cout << root->_val << " ";

        // 递归遍历右子树
        inOrderTraversal(root->_right);
    }
}
```

1. **基本情况：** 如果当前节点 (`root`) 为空，返回。

2. **递归调用：** 递归遍历左子树、输出当前节点的值、递归遍历右子树。

   ```cpp
   inOrderTraversal(root->_left);
   std::cout << root->_val << " ";
   inOrderTraversal(root->_right);
   ```

3. **中序遍历输出：** 在递归的过程中，每个节点的值都会按照从小到大的顺序输出。

### `BSTree` 类的中序遍历函数 `inOrderTraversal`

```cpp
void BSTree::inOrderTraversal() {
    // 调用中序遍历辅助函数，从根节点开始遍历
    inOrderTraversal(_root);
    std::cout << std::endl; // 换行
}
```
