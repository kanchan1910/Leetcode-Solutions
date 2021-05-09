 string removeKdigits(string num, int k)
    {
          int n = num.length();
        if(k == 0)
        {
            return num;
        }
        if(k == n)
        {
            return "0";
        }
        stack<char>s;
        if(num[0] != '0')
        {
            /*
            for this case
            Input:
                    041921
                    3
                    
                    Its Correct output is:
                    11
                    
                    And Your Code's output is:
                    011
            */
          s.push(num[0]);   
        }
        for(int i = 1; i < n; i++)
        {
            while(!s.empty() && k > 0 && s.top() > num[i])
            {
                s.pop();
                k--;
            }
            if(num[i] != '0' || !s.empty())
            {
                s.push(num[i]);
            }
        }
        if(k > 0)
        {
            while(!s.empty() && k > 0)
            {
                s.pop();
                k--;
            }
        }
        if(s.empty())
        {
            return "0";
        }
        string ans = "";
        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
}
};
 
// tc o(n)
// sc o(n)
