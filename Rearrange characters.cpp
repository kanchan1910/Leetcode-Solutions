 string rearrangeString(string str)
    {
        int n = str.length();
        if(n == 1)
        {
            return str;
        }
        vector<int>fre(26, 0);
        for(int i = 0; i < n; i++)
        {
            fre[str[i] - 'a']++;
        }
        int max_char = 0;
        char ch;
        for(int i = 0; i < 26; i++)
        {
            if(max_char < fre[i])
            {
                max_char = fre[i];
                ch = i + 'a';
            }
        }
        if(max_char > (n + 1) / 2)
        {
            return "-1";
        }
        string ans(n, ' ');
        int index = 0;
        while(max_char > 0)
        {
            ans[index] = ch;
            index += 2;
            max_char--;
        }
        fre[ch - 'a'] = 0;
        for(int i = 0; i < 26; i++)
        {
            while(fre[i] > 0)
            {
                index = index >= n ? 1 : index;
                ans[index] = i + 'a';
                index += 2;
                fre[i]--;
            }
        }
        return ans;
    }

// tc o(n)
// sc o(1)
