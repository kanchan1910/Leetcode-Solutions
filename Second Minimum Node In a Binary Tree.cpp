
class Solution {
public:
    void fun(TreeNode* root, int& first, int& second)
    {
        if(root == NULL)
        {
            return;
        }
        fun(root->left, first, second);
        if(first < 0 || first > root->val)
        {
            second = first;
            first = root->val;
        }
        else if(second < 0  && root->val != first || second > root->val && root->val != first)
        {
            second = root->val;
        }
        fun(root->right, first, second);
    }
    int findSecondMinimumValue(TreeNode* root) 
    {
        int first = -1, second = -1;
        fun(root, first, second);
        return second;
    }
};

// tc o(n)
// sc o(1)

// can't take first = INT_MAX and second = INT_MAX
// because of the case [2,2,2147483647]



class Solution {
public:
    void fun(TreeNode* root, int& firstmaxi, int& secondmaxi)
    {
        if(root == NULL)
        {
            return;
        }
        fun(root->left, firstmaxi, secondmaxi);
        if(firstmaxi > root->val)
        {
            secondmaxi = firstmaxi;
            firstmaxi = root->val;
        }
        else if(secondmaxi > root->val && root->val != firstmaxi)
        {
            secondmaxi = root->val;
        }
        fun(root->right, firstmaxi, secondmaxi);
    }
    int findSecondMinimumValue(TreeNode* root) 
    {
        int firstmaxi = INT_MAX, secondmaxi = INT_MAX;
        fun(root, firstmaxi, secondmaxi);
        return secondmaxi == INT_MAX ? -1 : secondmaxi;
    }
};
// WRONG
