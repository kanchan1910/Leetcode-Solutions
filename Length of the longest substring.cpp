 int longestUniqueSubsttr(string S)
    {
        int ans = 0;
        int n = S.length();
        unordered_set<char>s;
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            if(s.find(S[i]) != s.end())
            {
                while(s.find(S[i]) != s.end())
                {
                    s.erase(S[start]);
                    start++;
                }
            }
            s.insert(S[i]);
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
    
    
    
    int longestUniqueSubsttr(string S)
    {
        int ans = 0;
        int n = S.length();
        unordered_map<int,int>m;
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            if(m.find(S[i]) != m.end())
            {
                // for case
                // "abba"
                start = max(start, m[S[i]] + 1);
            }
            m[S[i]] = i;
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
    
    // these both solutions gives tle on gfg but they pass on leetcode
    
    
     int longestUniqueSubsttr(string str)
    {
        int N = str.size();
        vector<int> lastOccur(256, -1);
        
        int res = 0;
        
        int i = 0;
        for(int j = 0; j < N; j++)
        {
            if(lastOccur[str[j]] != -1)
            {
              i = max(i, lastOccur[str[j]] + 1);   
            }
            res = max(res, j - i + 1);
            
            lastOccur[str[j]] = j;
        }
        
        return res;
    }
    
    // pass on gfg
