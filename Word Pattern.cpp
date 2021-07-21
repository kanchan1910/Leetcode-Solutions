class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        vector<string>tmp;
        stringstream ss(s);
        string word;
        while(ss >> word)
        {
            tmp.push_back(word);
        }
        /*
        "aaa"
        "aa aa aa aa"
        "jquery"
        "jquery"        
        */
        if(tmp.size() != pattern.length())
        {
            return false;
        }
        unordered_map<char, string>m;
        /*
        "abba"
        "dog dog dog dog"
        */
        unordered_set<string>s1;
        unordered_set<char>s2;
        for(int i = 0; i < pattern.length(); i++)
        {
            s2.insert(pattern[i]);
        }
        for(int i = 0; i < pattern.length(); i++)
        {
            if(m.find(pattern[i]) == m.end() && s1.find(tmp[i]) == s1.end())
            {
                m[pattern[i]] = tmp[i];
                s1.insert(tmp[i]);
            }
            else
            {
                if(tmp[i] != m[pattern[i]])
                {
                    return false;
                }
            }
        }
        if(s1.size() != s2.size())
        {
            return false;
        }
        return true;
    }
};
