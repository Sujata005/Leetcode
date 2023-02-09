# Preorder

144. Binary Tree Preorder Traversal [Easy]

void preorder(struct TreeNode* root, int * ans,int * returnSize){
    ans[(*returnSize)++]=root->val;
    if(root->left) preorder(root->left,ans,returnSize);
    if(root->right) preorder(root->right,ans,returnSize);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* p= malloc(100*sizeof(int));
    *returnSize=0;
    if(root) preorder(root,p,returnSize);
    p=realloc(p,(*returnSize)*sizeof(int));
    return p;
}



# Postorder

145. Binary Tree Postorder Traversal [Easy]

void postOrder(struct TreeNode* root, int* arr, int* returnSize){
    if(root!=NULL){
        postOrder(root->left, arr, returnSize);
        postOrder(root->right, arr, returnSize);
        arr[(*returnSize)++] = root->val;
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* arr = malloc(100*sizeof(int));
    *returnSize = 0;
    postOrder(root, arr, returnSize);
    arr = realloc(arr, (*returnSize)*sizeof(int));
    return arr;
}


# Inorder

94. Binary Tree Inorder Traversal [Easy]

void inorder(struct TreeNode* root, int * ans,int * returnSize){
        if(root->left) inorder(root->left,ans,returnSize);
        ans[(*returnSize)++]=root->val;
        if(root->right) inorder(root->right,ans,returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* ans=malloc(100*sizeof(int));
    *returnSize=0;
    if(root) inorder(root,ans,returnSize);
    ans=realloc(ans,(*returnSize)*sizeof(int));
    return ans;
}


# LevelOrder

102. Binary Tree Level Order Traversal [Medium]

void levelOrderTraversal(int *depth, int **res, int *resSize, struct TreeNode* root, int level){
    if (!root) return;
    *depth = (level + 1 > *depth)?level + 1:*depth;
    if (!resSize[level]) res[level] = malloc(sizeof(int)*2001);
    res[level][resSize[level]++] = root->val;
    levelOrderTraversal(depth, res, resSize, root->left, level + 1);
    levelOrderTraversal(depth, res, resSize, root->right, level + 1);
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **res = malloc(sizeof(int *)*2001);
    *returnColumnSizes = malloc(sizeof(int)*2001);
    *returnSize = 0;
    for (int i = 0; i < 2001; i++) {
        (*returnColumnSizes)[i] = 0;
    }
    levelOrderTraversal(returnSize, res, *returnColumnSizes, root, 0);
    return res;
}
