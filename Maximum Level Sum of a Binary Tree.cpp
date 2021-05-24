
class Solution {
public:
    int maxLevelSum(TreeNode* root) 
    {
        int maxi_sum = INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        int ans_level = 0;
        while(!q.empty())
        {
            level++;
            int sum = 0;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                sum += q.front()->val;
                
                if(q.front()->left != NULL)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right != NULL)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(maxi_sum < sum)
            {
                maxi_sum = sum;
                ans_level = level;
            }
            else if(maxi_sum == sum && level < ans_level)
            {
                ans_level = level;
            }
        }
        return ans_level;
    }
};
