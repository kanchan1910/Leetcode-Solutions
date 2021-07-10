
class Solution {
public:
    void fun(TreeNode* root, vector<int>& l)
    {
        if(root == NULL)
        {
            return;
        }
        fun(root->left, l);
        if(root->left == NULL && root->right == NULL)
        {
            l.push_back(root->val);
        }
        fun(root->right, l);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int>l1, l2;
        fun(root1, l1);
        fun(root2, l2);
        return l1 == l2;
    }
};

// tc o(n) 
// sc o(n)
