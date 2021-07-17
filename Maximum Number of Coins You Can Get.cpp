class Solution {
public:
    int maxCoins(vector<int>& piles)
    {
        int n = piles.size();
        int ans = 0;
        int r = n - 2;
        int thrid_friend = n / 3;
        sort(piles.begin(), piles.end());
        while(r >= thrid_friend)
        {
            ans += piles[r];
            r -= 2;
        }
        return ans;
    }
};

// tc o(nlogn)
// sc o(1)
// [GREEDY]
