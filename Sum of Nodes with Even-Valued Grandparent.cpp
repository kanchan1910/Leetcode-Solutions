
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) 
    {
        int sum = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            if(front->val % 2 == 0)
            {
                if(front->left != NULL)
                {
                    if(front->left->left != NULL)
                    {
                        sum += front->left->left->val;
                    }
                    if(front->left->right != NULL)
                    {
                        sum += front->left->right->val;
                    }
                }
                if(front->right != NULL)
                {
                    if(front->right->left != NULL)
                    {
                        sum += front->right->left->val;
                    }
                    if(front->right->right != NULL)
                    {
                        sum += front->right->right->val;
                    }
                }
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
        return sum;
    }
};

// tc o(n)
// sc o(n)
