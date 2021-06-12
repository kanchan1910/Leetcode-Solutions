class Solution
{
    public:
    int pre(char ch)
    {
        if(ch == '^')
        {
            return 3;
        }
        if(ch == '*' || ch == '/')
        {
            return 2;
        }
        if(ch == '+' || ch == '-')
        {
            return 1;
        }
        return -1;
    }
    //Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        string ans = "";
        stack<char>st;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            char ch = s[i];
            if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
            {
               ans += ch;
            }
            else if(ch == '(')
            {
                st.push(ch);
            }
            else if(ch == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else 
            {
                while(!st.empty() && pre(s[i]) <= pre(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
        // Your code here
    }
};
// tc o(n)
// sc o(n)
