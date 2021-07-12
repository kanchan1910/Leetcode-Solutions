class Solution {
public:
    int maxScore(string s)
    {
        int n = s.length();
        int to = 0, tz = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                to++;
            }
            else
            {
                tz++;
            }
        }
        int l = 0;
        int lz = 0, lo = 0;
        int ans = 0;
        while(l < n - 1)
        {
            if(s[l] == '0')
            {
                lz++;
            }
            else
            {
                lo++;
            }
            ans = max(ans, lz + (to - lo));
            l++;
        }
        return ans;
    }
};
// tc o(n)
// sc o(1)
