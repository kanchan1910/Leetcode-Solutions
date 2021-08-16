
class Solution {
  public:
    vector<long long> distributeCandies(int N, int K) 
    {
        vector<long long>ans(K, 0);
        int candy = 1;
        int i = 0;
        while(N > 0)
        {
            if(candy <= N)
            {
                ans[i] += candy;  
                N -= candy;
            }
            else
            {
                ans[i] += N;
                break;
            }
            i++;
            candy++;
            //  start from the begining
            if(i == K)
            {
                i = 0;
            }
        }
        return ans;
    }
};
// tc o(candies)
// sc o(1)
