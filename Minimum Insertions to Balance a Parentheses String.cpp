class Solution {
public:
    int minInsertions(string s)
    {
        stack<char>st;
        s += "#";
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] == '(')
            {
                st.push('(');
            }
            else if(s[i] == ')')
            {
                if(s[i] == ')' && s[i + 1] == ')')
                {
                    if(st.empty())
                    {
                        ans++;
                    }
                    else
                    {
                        st.pop();
                    }
                    i++;
                }
                else if(s[i] == ')') 
                {
                    if(st.empty())
                    {
                        ans += 2;
                    }
                    else
                    {
                        st.pop();
                        ans++;
                    }
                }
            }
        }
        if(st.size() > 0)
        {
            ans += 2 * st.size();
        }
        return ans;
    }
};
