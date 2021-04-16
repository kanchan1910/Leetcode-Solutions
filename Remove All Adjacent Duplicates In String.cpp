class Solution {
public:
    string removeDuplicates(string S)
    {
        int n = S.length();
        stack<char>s;
        for(int i = 0; i < n; i++)
        {
            if(s.empty())
            {
                s.push(S[i]);
            }
            else
            {
                if(s.top() != S[i])
                {
                    s.push(S[i]);
                }
                else
                {
                    s.pop();
                }
            }
        }
        S = "";
        while(!s.empty())
        {
            S += s.top();
            s.pop();
        }
        reverse(S.begin(), S.end());
        return S;
    }
};
// tc o(n)
// sc o(n)
