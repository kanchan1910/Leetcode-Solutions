class Solution {
public:
    string generateTheString(int n) 
    {
        string ans(n - 1, 'a');
        if(n % 2 != 0)
        {
             ans.push_back('a');
        }
        else
        {
            ans.push_back('b');
        }
        return ans;
    }
};
