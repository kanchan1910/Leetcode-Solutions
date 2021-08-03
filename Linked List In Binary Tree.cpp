
class Solution {
public:
    bool fun(ListNode* head, TreeNode* root)
    {
        if(head == NULL)
        {
            return true;
        }
        if(root == NULL)
        {
            return false;
        }
        return head->val == root->val && (fun(head->next, root->left) || fun(head->next, root->right));
    }
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if(head == NULL)
        {
            return true;
        }
        if(root == NULL)
        {
            return false;
        }
        return fun(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
