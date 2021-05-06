// https://www.hackerrank.com/challenges/jesse-and-cookies/problem
int cookies(int k, vector<int> A)
{
    priority_queue<int, vector<int>, greater<int>>pq;
    int n = A.size();
    for(int i = 0; i < n; i++)
    {
        pq.push(A[i]);
    }
    if(pq.top() >= k)
    {
        return 0;
    }
    int ans = 0;
    while(pq.size() >= 2 && pq.top() < k)
    {
        ans++;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int item = first + 2 * second;
        pq.push(item);
    }
    if(pq.top() < k)
    {
        return -1;
    }
    return ans;
}
