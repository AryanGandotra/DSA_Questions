class Solution
{
public:
    void fillInorder(TreeNode *root, vector<TreeNode *> &inorder)
    {
        if (!root)
            return;
        fillInorder(root->left, inorder);
        inorder.push_back(root);
        fillInorder(root->right, inorder);
    }

    void recoverTree(TreeNode *root)
    {
        vector<TreeNode *> inorder;
        fillInorder(root, inorder);

        TreeNode *first = nullptr;
        TreeNode *second = nullptr;

        for (int i = 0; i < inorder.size() - 1; i++)
        {
            if (inorder[i]->val > inorder[i + 1]->val)
            {
                if (!first)
                {
                    first = inorder[i];
                    second = inorder[i + 1];
                }
                else
                {
                    second = inorder[i + 1];
                }
            }
        }

        if (first && second)
            swap(first->val, second->val);
    }
};