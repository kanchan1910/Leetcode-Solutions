class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) 
    {
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        long long cost = 0;
        for(int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        while(pq.size() >= 2)
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            long long new_len = first + second;
            cost += (new_len);
            pq.push(new_len);
        }
        return cost;
    }
};

