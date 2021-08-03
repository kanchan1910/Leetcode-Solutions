class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
    
    // longest prefix-suffix logic
        int n = s.length();
	    vector<int>lps(n, 0);
	    for(int i = 1; i < n; i++)
	    {
	        int j = lps[i - 1];
	        while(j > 0 && s[i] != s[j])
	        {
	            j = lps[j - 1];
	        }
	        if(s[i] == s[j])
	        {
	            j++;
	        }
	        lps[i] = j;
	    }
	    int len = lps[n - 1];
	    return len > 0 && n % (n - len) == 0;
    }
};
// tc o(n)
// sc o(n)
