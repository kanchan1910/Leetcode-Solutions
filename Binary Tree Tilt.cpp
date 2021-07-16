
class Solution {
public:
    int ans = 0;
    int fun(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = fun(root->left);
        int right = fun(root->right);
        int tilt = abs(left - right);
        ans += tilt;
        return root->val + left + right;
    }
    int findTilt(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }
        fun(root);
        return ans;
    }
};

