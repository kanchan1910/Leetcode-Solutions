class Solution {
public:
    string modifyString(string s)
    {
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '?')
            {
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    if(i < len - 1 && s[i + 1] == ch)
                    {
                        continue;
                    }
                    if(i > 0 && s[i - 1] == ch)
                    {
                        continue;
                    }
                    s[i] = ch;
                    break;
                }
            }
        }
        return s;
    }
};
