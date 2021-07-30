class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int>m;
    MapSum()
    {
        
    }
    bool isPrefix(string str1, string str2)
    {
        if(str2.substr(0, str1.length()) == str1)
        {
            return true;
        }
        return false;
    }
    void insert(string key, int val)
    {
        m[key] = val;
    }
    
    int sum(string prefix)
    {
        int ans = 0;
        for(auto x: m)
        {
            if(isPrefix(prefix, x.first) == true)
            {
                ans += x.second;
            }
        }
        return ans;
    }
};
