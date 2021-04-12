class Solution {
public:
    unordered_map<int, int>m;
    void inorder(TreeNode* root, int& maxi)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root->left, maxi);
        m[root->val]++;
        maxi = max(maxi, m[root->val]);
        inorder(root->right, maxi);
    }
    vector<int> findMode(TreeNode* root)
    {
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        int maxi = INT_MIN;
        inorder(root, maxi);
        for(auto x: m)
        {
            if(x.second == maxi)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(n)
