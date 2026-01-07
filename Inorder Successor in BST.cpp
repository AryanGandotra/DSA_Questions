class Solution
{
public:
    int inOrderSuccessor(Node *root, Node *x)
    {
        int suc = -1;

        while (root)
        {
            if (root->data > x->data)
            {
                suc = root->data;
                root = root->left;
            }

            else
                root = root->right;
        }

        return suc;
    }
};