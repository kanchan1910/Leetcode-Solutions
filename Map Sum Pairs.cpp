class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int>m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int ans = 0;
        for(auto x: m)
        {
            string str = x.first;
            for(int i = 1; i <= str.length(); i++)
            {
                if(str.substr(0, i) == prefix)
                {
                    ans += x.second;
                }
            }
        }
        return ans;
    }
};

