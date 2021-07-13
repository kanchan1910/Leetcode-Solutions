class Solution {
public:
    bool isValid(string s, int i, int j)
    {
        vector<int>v1(26, 0);
        vector<int>v2(26, 0);
        for(int k = i; k <= j; k++)
        {
            if(s[k] >= 'a' && s[k] <= 'z')
            {
                v1[s[k] - 'a']++;
            }
            else if(s[k] >= 'A' && s[k] <= 'Z')
            {
                v2[s[k] - 'A']++;
            }
        }
        for(int i = 0; i < 26; i++)
        {
            if((!v1[i] && v2[i]) || (v1[i] && !v2[i]))
            {
                return false;
            }
        }
        return true;
    }
    string longestNiceSubstring(string s)
    {
        int n = s.length();
        int ans = 0;
        string str;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(isValid(s, i, j) == true)
                {
                    if(ans < (j - i + 1))
                    {
                        ans = j - i + 1;
                        str = s.substr(i, ans);
                    }
                }
            }
        }
        return str;
    }
};
// TIP:
// before thinking of complex solution, first check its constraints as they are only n = 100 , so brute force will work, as sometimes may be its not possible to have optimised soltuion of that particular problem
