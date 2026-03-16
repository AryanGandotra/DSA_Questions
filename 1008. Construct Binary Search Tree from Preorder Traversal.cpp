
class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        return buildTree(preorder, inorder);
    }

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

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }

    TreeNode *build(vector<int> &preorder, int &i, int bound)
    {
        if (i >= preorder.size() || preorder[i] > bound)
            return NULL;
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
};