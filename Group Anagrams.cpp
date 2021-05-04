vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    unordered_map<string, vector<string>>m;
    vector<vector<string>>ans;
    int n = string_list.size();
    for(int i = 0; i < n; i++)
    {
        string str = string_list[i];
        sort(str.begin(), str.end());
        m[str].push_back(string_list[i]);
    }
    for(auto x: m)
    {
        ans.push_back(x.second);
    }
    return ans;
}

// tc o(n)
// sc o(n)
