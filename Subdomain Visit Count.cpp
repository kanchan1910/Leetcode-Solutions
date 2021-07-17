class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains)
    {
        vector<string>ans;
        int n = cpdomains.size();
        unordered_map<string, int>m;
        for(auto x: cpdomains)
        {
            int i = 0;
            int num = 0;
            while(i < x.size() && x[i] != ' ')
            {
                num = (10 * num) + (x[i] - '0');
                i++;
            }
            i++;
            while(i < x.size())
            {
                m[x.substr(i)] += num;
                while(i < x.size() && x[i] != '.')
                {
                    i++;
                }
                i++;
            }
        }
        for(auto x: m)
        {
            ans.push_back(to_string(x.second) + " " + x.first);
        }
        return ans;
    }
};

