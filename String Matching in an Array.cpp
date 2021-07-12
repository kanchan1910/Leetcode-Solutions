class Solution {
public:
    bool isSubstring(string str1, string str2)
    {
        for(int i = 0; i < str1.length(); i++)
        {
            if(str1.substr(i, str2.length()) == str2)
            {
                return true;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) 
    {
        int n = words.size();
        vector<string>ans;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j != i)
                {
                    if(isSubstring(words[j], words[i]) == true)
                    {
                        ans.push_back(words[i]);
                        // for these examples
                        // ["leetcoder","leetcode","od","hamlet","am"]
                        break;
                    }   
                }
            }
        }
        return ans;
    }
};
