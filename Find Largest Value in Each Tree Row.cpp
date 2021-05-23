
class Solution {
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            int maxi = INT_MIN;
            for(int i = 0; i < n; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                maxi = max(maxi, front->val);
                if(front->left != NULL)
                {
                    q.push(front->left);
                }
                if(front->right != NULL)
                {
                    q.push(front->right);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
