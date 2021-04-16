class Solution {
public:
    int minAddToMakeValid(string S) 
    {
        stack<char>s;
        int n = S.length();
        for(int i = 0; i < n; i++)
        {
            if(S[i] == '(')
            {
                s.push(S[i]);
            }
            else
            {
                if(s.empty())
                {
                    s.push(S[i]);
                }
                else
                {
                    if(s.top() == '(')
                    {
                        s.pop();
                    }
                    else
                    {
                        s.push(S[i]);
                    }
                }
            }
        }
        return s.size();
    }
};
// tc o(n)
// sc o(n)
