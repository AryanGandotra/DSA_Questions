class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }

    TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
    {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);
        int index = mp[root->val];
        int numbersLeft = index - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numbersLeft, inorder, inStart, index - 1, mp);
        root->right = buildTree(preorder, preStart + numbersLeft + 1, preEnd, inorder, index + 1, inEnd, mp);

        return root;
    }
};