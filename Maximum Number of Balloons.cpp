class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        int len = text.length();
        vector<int>freq(26, 0);
        for(int i = 0; i < len; i++)
        {
            freq[text[i] - 'a']++;
        }
        int ans = INT_MAX;
        ans = min({ min({ans, freq[0], freq[1], freq[13]}), min(freq[11] / 2, freq[14] / 2)});
        return ans;
    }
};
