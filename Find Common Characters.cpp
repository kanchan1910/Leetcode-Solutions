class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        int n = words.size();
        vector<string>ans;
        vector<int>v1(26, 0), v2(26, 0);
        for(int i = 0; i < words[0].length(); i++)
        {
            v1[words[0][i] - 'a']++;
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < words[i].length(); j++)
            {
                v2[words[i][j] - 'a']++;
            }
            for(int i = 0; i < 26; i++)
            {
                v1[i] = min(v1[i], v2[i]);
                v2[i] = 0;
            }
        }
        for(int i = 0; i < 26; i++)
        {
            while(v1[i]--)
            {
                char tmp = (i + 'a');
                string str;
                str = tmp;
                ans.push_back(str);
            }
        }
        return ans;
    }
};
