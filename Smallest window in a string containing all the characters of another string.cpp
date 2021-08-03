    string smallestWindow (string s, string p)
    {
        int n1 = s.length();
        int n2 = p.length();
        if(n1 < n2)
        {
            return "-1";
        }
        vector<int>m1(256, 0);
        vector<int>m2(256, 0);
        for(int i = 0; i < n2; i++)
        {
            m2[p[i]]++;
        }
        int count = 0;
        int start = 0, start_index = -1;
        int ans = INT_MAX;
        for(int i = 0; i < n1; i++)
        {
            m1[s[i]]++;
            if(m2[s[i]] != 0 && m1[s[i]] <= m2[s[i]])
            {
                count++;
            }
            if(count == n2)
            {
                while(m2[s[start]] == 0 || m2[s[start]] < m1[s[start]])
                {
                    if(m2[s[start]] < m1[s[start]])
                    {
                        m1[s[start]]--;
                    }
                    start++;
                }
                int len = i - start + 1;
                if(ans > len)
                {
                    ans = len;
                    start_index = start;
                }
            }
        }
        if(start_index == -1)
        {
            return "-1";
        }
        return s.substr(start_index, ans);
    }
