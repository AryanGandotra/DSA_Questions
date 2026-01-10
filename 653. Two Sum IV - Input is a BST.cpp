class Solution
{
public:
    void fillInorder(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;
        fillInorder(root->left, inorder);
        inorder.push_back(root->val);
        fillInorder(root->right, inorder);
    }
    bool findTarget(TreeNode *root, int k)
    {
        if (!root || (!root->left && !root->right))
            return false;

        vector<int> inorder;
        fillInorder(root, inorder);
        int i = 0, j = inorder.size() - 1;
        while (i < j)
        {
            if (inorder[i] + inorder[j] == k)
                return true;
            else if (inorder[i] + inorder[j] < k)
                i++;
            else
                j--;
        }
        return false;
    }
};