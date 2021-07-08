class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        int n = timeSeries.size();
        int ans = duration;
        int cur_time = (timeSeries[0] + duration - 1);
        for(int i = 1; i < n; i++)
        {
            if(timeSeries[i] > cur_time)
            {
                 ans += duration;
            }
            else
            {
                ans += ((timeSeries[i] + duration - 1) - cur_time);
            }
            cur_time = (timeSeries[i] + duration - 1);
        }
        return ans;
    }
};

// tc o(n)
// sc o(1)
