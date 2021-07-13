class Solution {
public:
    int maxDepth(string s) 
    {
        int ans = 0;
        int len = s.length();
        stack<char>ss;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
            {
                ss.push(s[i]);
            }
            else if(s[i] == ')')
            {
                if(ss.top() == '(')
                {
                    ss.pop();
                }
            }
            if(ans < ss.size())
            {
                ans = ss.size();
            }
        }
        return ans;
    }
};



class Solution {
public:
    int maxDepth(string s) 
    {
        int ans = 0;
        int len = s.length();
        int count = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
            {
                count++;
            }
            else if(s[i] == ')')
            {
               count--;
            }
            if(ans < count)
            {
                ans = count;
            }
        }
        return ans;
    }
};
