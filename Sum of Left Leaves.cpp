class Solution
{
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        long sum = 0;
        while(!q.empty())
        {
                TreeNode* front = q.front();
                q.pop();
                if(front->left != NULL)
                {
                    if(front->left->left == NULL && front->left->right == NULL)
                    {
                      sum += front->left->val;   
                    }
                    q.push(front->left);
                }
                if(front->right != NULL)
                {
                    q.push(front->right);
                }
        }
        return sum;  
    }
};
// tc o(N)
// sc o(N)
