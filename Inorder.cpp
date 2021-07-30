
class Solution {
public:

    void fun(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL)
        {
            return;
        }
        fun(root->left, ans);
        ans.push_back(root->val);
        fun(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        fun(root, ans);
        return ans;
    }
};
