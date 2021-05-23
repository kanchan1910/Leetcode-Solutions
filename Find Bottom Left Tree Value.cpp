
class Solution {
public:
    int findBottomLeftValue(TreeNode* root)
    {
        // leaf node
        if(root->left == NULL && root->right == NULL)
        {
            return root->val;
        }
        queue<TreeNode*>q;
        q.push(root);
        int last_left;
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                if(i == 0)
                {
                  last_left = front->val;  
                }
                if(front->left != NULL)
                {
                    q.push(front->left);
                }
                if(front->right != NULL)
                {
                    q.push(front->right);
                }
            }
        }
        return last_left;
    }
};
