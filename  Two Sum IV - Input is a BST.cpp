
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    bool findTarget(TreeNode* root, int k)
    {
        vector<int>ans;
        inorder(root, ans);
        int l = 0, r = ans.size() - 1;
        while(l < r)
        {
            int sum = ans[l] + ans[r];
            if(sum == k)
            {
                return true;
            }
            else if(sum < k)
            {
                l++;
            }
            else if(sum > k)
            {
                r--;
            }
        }
        return false;
    }
};

// tc o(n)
// sc o(n)
