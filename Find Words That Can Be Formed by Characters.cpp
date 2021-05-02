class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        unordered_map<char, int>m;
        for(int i = 0; i < chars.length(); i++)
        {
            m[chars[i]]++;
        }
        int n = words.size();
        int ans = 0;
        bool f;
        for(int i = 0; i < n; i++)
        {
            f = 0;
            unordered_map<char, int>mm;
            string str = words[i];
            for(int j = 0; j < str.length(); j++)
            {
                mm[str[j]]++;
            }
            for(int j = 0; j < str.length(); j++)
            {
                if(mm[str[j]] > m[str[j]])
                {
                    f = 1;
                    break;
                }
            }
            if(f == 0)
            {
                ans += str.length();
            }
        }
        return ans;
    }
};
