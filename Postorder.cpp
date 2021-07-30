
class Solution {
public:
    void fun(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL)
        {
            return;
        }
        fun(root->left, ans);
        fun(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) 
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
