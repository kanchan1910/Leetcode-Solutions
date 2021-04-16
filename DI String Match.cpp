class Solution {
public:
    vector<int> diStringMatch(string s) 
    {
        vector<int>ans;
        int n = s.length();
        int l = 0, r = n;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'D')
            {
                ans.push_back(r);
                r--;
            }
            else
            {
                ans.push_back(l);
                l++;
            }
        }
        ans.push_back(l);
        return ans;
    }
};
// tc o(n)
// sc o(1)
