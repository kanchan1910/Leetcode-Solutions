    int findSubArraySum(int Arr[], int N, int k)
    {
        unordered_map<int, int>m;
        int cur_sum = 0, ans = 0;
        for(int i = 0; i < N; i++)
        {
            cur_sum += Arr[i];
            if(cur_sum == k)
            {
                ans++;
            }
            if(m.find(cur_sum - k)!= m.end())
            {
                ans += m[cur_sum - k];
            }
            m[cur_sum]++;
        }
        return ans;
    }
    // tc o(n)
    // sc o(n)
