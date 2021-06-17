class Solution {
  public:
    int findMaxLen(string s) 
    {
        stack<int>ss;
        int ans = 0;
        ss.push(-1);
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                ss.push(i);
            }
            else
            {
                if(!ss.empty())
                {
                    ss.pop();
                }
                if(!ss.empty())
                {
                    ans = max(ans, i - ss.top());
                }
                else
                {
                    ss.push(i);
                }
            }
        }
        return ans;
    }
};
