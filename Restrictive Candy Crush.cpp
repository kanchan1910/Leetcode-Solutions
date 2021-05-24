Given a string s and an integer k, the task is to reduce the string by applying the following operation:
Choose a group of k consecutive identical characters and remove them.

The operation can be performed any number of times until it is no longer possible.

Example 1:

Input:
k = 2
s = "geeksforgeeks"
Output:
gksforgks
Explanation:
Modified String after each step: 
"geeksforgeeks" -> "gksforgks"
Example 2:

Input:
k = 2
s = "geegsforgeeeks" 
Output:
sforgeks
Explanation:
Modified String after each step:
"geegsforgeeeks" -> "ggsforgeks" -> "sforgeks"
Your Task:  
You don't need to read input or print anything. Complete the function Reduced_String() which takes integer k and string s as input parameters and returns the reduced string.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|k|)

Constraints:
1 ≤ |s| ≤ 105
1 ≤ k ≤ |s|

    string Reduced_String(int k,string s)
    {
        stack<pair<char, int>>st;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s.empty())
            {
                st.push({s[i], 1});
            }
            else
            {
                if(st.size() > 0 && st.top().second == k)
                {
                    char ch = st.top().first;
                    while(st.size() > 0 && st.top().first == ch)
                    {
                        st.pop();
                    }
                }
                if(st.size() > 0 && s[i] != st.top().first)
                {
                    st.push({s[i], 1});
                }
                else if(st.size() > 0 && s[i] == st.top().first)
                {
                    st.push({s[i], st.top().second + 1});
                }
                if(st.empty())
                {
                   st.push({s[i], 1});  
                }
            }
        }
        if(st.size() > 0 && st.top().second == k)
        {
            char ch = st.top().first;
            while(st.size() > 0 && st.top().first == ch)
            {
                st.pop();
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
