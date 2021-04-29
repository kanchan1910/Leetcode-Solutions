class Solution {
public:
// Fill all the even positions of the result string first, with the highest frequency character. If there are still some even positions remaining, fill them first. Once even positions are done, then fill the odd positions. This way, we can ensure that no two adjacent characters are the same. 


    string reorganizeString(string S)
    {
        int n = S.length();
        if(n == 1)
        {
            return S;
        }
        vector<int>freq(26, 0);
        for(int i = 0; i < n; i++)
        {
            freq[S[i] - 'a']++;
        }
        char ch;
        int max_ch = 0;
        for(int i = 0; i < 26; i++)
        {
            if(max_ch < freq[i])
            {
                max_ch = freq[i];
                ch = i + 'a';
            }
        }
        if(max_ch > (n + 1) / 2)
        {
            return "";
        }
        int index = 0;
        string ans(n, ' ');
        while(max_ch > 0)
        {
            ans[index] = ch;
            index += 2;
            max_ch--;
        }
        freq[ch - 'a'] = 0;
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] > 0)
            {
                while(freq[i] > 0)
                {
                    index = (index >= n) ? 1 : index;
                    ans[index] = i + 'a';
                    index += 2;
                    freq[i]--;
                }
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(n + 26)
