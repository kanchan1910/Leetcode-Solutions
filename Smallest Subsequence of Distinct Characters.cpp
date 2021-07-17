class Solution {
public:
    string smallestSubsequence(string s) 
    {
        string ans = "";
        stack<char>ss;
        int n = s.length();
        vector<bool>vis(26, false);
        vector<int>lastindex(26);
        for(int i = 0; i < n; i++)
        {
            lastindex[s[i] - 'a'] = i;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(vis[s[i] - 'a'] == false)
            {
                if(ss.empty())
                {
                    ss.push(s[i]);
                    vis[s[i] - 'a'] = true;
                }
                else
                {
                    if(s[i] > ss.top())
                    {
                        ss.push(s[i]);
                        vis[s[i] - 'a'] = true;
                    }
                    else
                    {
                        while(ss.size() > 0 && ss.top() > s[i] && lastindex[ss.top() - 'a'] > i)
                        {
                            char ch = ss.top();
                            ss.pop();
                            vis[ch - 'a'] = false;
                        }
                        ss.push(s[i]);
                        vis[s[i] - 'a'] = true;
                    }
                }
            }
        }
        while(ss.size() > 0)
        {
            ans += ss.top();
            ss.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// tc o(N)
// sc o(N)
