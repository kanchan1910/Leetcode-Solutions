class Solution {
public:
    static bool com(string a, string b)
    {
        int pa = a.find(' ');
        int pb = b.find(' ');
        if(a.substr(pa + 1) == b.substr(pb + 1))
        {
            return a.substr(0 , pa) < b.substr(0 , pb);
        }
        else
        {
            return a.substr(pa + 1) < b.substr(pb + 1);
        }
    }
    vector<string> reorderLogFiles(vector<string>& logs)
    {
        int n = logs.size();
        vector<string>letter, digits;
        for(int i = 0 ; i < n ; i++)
        {
            int pos = logs[i].find(' ');
            if(logs[i][pos + 1] >=  '0' && logs[i][pos + 1]  <= '9')
            {
                digits.push_back(logs[i]);
            }
            else
            {
                letter.push_back(logs[i]);
            }
        }
        sort(letter.begin()  , letter.end() , com);
        for(auto x : digits)
        {
            letter.push_back(x);
        }
        return letter;
    }
};
