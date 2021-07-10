class Solution {
public:
    bool buddyStrings(string s, string goal)
    {
        if(s.length() != goal.length())
        {
            return false;
        }
        int diff = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != goal[i])
            {
                diff++;
            }
        }
        if(diff > 2)
        {
            return false;
        }
        if(diff == 0)
        {
            sort(s.begin(), s.end());
            int same = 0;
            for(int i = 1; i < s.length(); i++)
            {
                if(s[i] == s[i - 1])
                {
                    same++;
                }
            }
            if(same == 0)
            {
                return false;
            }
        }
        // diff == 1 or diff == 2 will be handled here
        sort(s.begin(), s.end());
        sort(goal.begin(), goal.end());
        return s == goal;
    }
};

// tc o(nlogn)
// sc o(1)
