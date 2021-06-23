
class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        int count = 0;
        sort(arr.begin(), arr.end());
        int sum = 0;
        for(int i = 0; i < N; i++)
        {

            sum += arr[i];
            
            if(sum > K)
            {
                break;
            }
            count++;
        }
        return count;
    }
};
