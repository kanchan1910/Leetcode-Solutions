    string mostFrequentWord(string arr[], int n) 
    {
        unordered_map<string, int>m;
        unordered_set<string>s;
        int max_fre = 0;
        for(int i = 0; i < n; i++)
        {
            m[arr[i]]++;
            max_fre = max(max_fre, m[arr[i]]);
        }
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            if(m[arr[i]] == max_fre && s.find(arr[i]) == s.end())
            {
                ans = arr[i];
                s.insert(arr[i]);
            }
        }
        return ans;
    }
