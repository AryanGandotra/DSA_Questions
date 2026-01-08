class BSTIterator
{
public:
    vector<int> inorder;
    int i = 0;

    void initialiseInorderVector(TreeNode *root, vector<int> &inorder)
    {
        if (root == nullptr)
            return;
        initialiseInorderVector(root->left, inorder);
        inorder.push_back(root->val);
        initialiseInorderVector(root->right, inorder);
    }

    BSTIterator(TreeNode *root)
    {
        initialiseInorderVector(root, inorder);
    }

    int next()
    {
        return inorder[i++];
    }

    bool hasNext()
    {
        if (i < inorder.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */