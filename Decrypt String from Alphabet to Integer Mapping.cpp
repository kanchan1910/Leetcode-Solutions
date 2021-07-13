class Solution {
public:
    string freqAlphabets(string s) 
    {
        string str = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(i + 2 < s.size() && s[i + 2] == '#')
            {
                int a = (s[i] - '0') * 10 + (s[i + 1] - '0');
                a--;
                str += ('a' + a);
                i += 2;
            }
            else
            {
                int b = s[i] - '0';
                b--;
                str += ('a' + b);
            }
        }
        return str;
    }
};
