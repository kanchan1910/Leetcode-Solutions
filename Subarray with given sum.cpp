
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        vector<int>ans;
        int start = 0;
        int sum = arr[0];
        for(int i = 1; i <= n; i++)
        {
            while(sum > s && start < i - 1)
            {
                sum -= arr[start];
                start++;
            }
            if(sum == s)
            {
                ans.push_back(start + 1);
                ans.push_back(i);
                return ans;
            }
            sum += arr[i];
        }
        return {-1};
    }
};
// sliding window technique
// tc o(n)
// sc o(1)


// brute force 
// tc o(n * n)
// sc o(1)
