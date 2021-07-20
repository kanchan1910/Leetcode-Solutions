class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        if(s.length() < k)
        {
            return false;
        }
        unordered_map<char, int>m;
        for(int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
        }
        int count = 0;
        for(auto x: m)
        {
            if(x.second % 2 != 0)
            {
                count++;
            }
        }
        if(count > k)
        {
          return false;  
        }
        return true;
    }
};


