// can be done my first calculating the inorder traversal array., and then making these changes in the array and then converting that array into te binary search structure
// its tc o(n)
// sc o(n)


class Solution {
public:
    void setPointersByInorder(TreeNode* root, TreeNode* &first, TreeNode* &last, TreeNode* &prev)
    {
        if(root == NULL)
        {
            return;
        }
        setPointersByInorder(root->left, first, last, prev);
        if(prev != NULL && prev->val > root->val)
        {
            if(first == NULL)
            {
                first = prev;
            }
            last = root;
        }
        prev = root;
        setPointersByInorder(root->right, first, last, prev);
    }
    void recoverTree(TreeNode* root)
    {
        TreeNode* first = NULL;
        TreeNode* last = NULL;
        TreeNode* prev = NULL;
        setPointersByInorder(root, first, last, prev);
        swap(first->val, last->val);
    }
};
// tc o(n)
// sc o(1)
