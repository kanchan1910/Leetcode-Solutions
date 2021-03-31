class Solution {
public:
    int secondHighest(string s)
    {
        int n = s.length();
        priority_queue<int>pq;
        for(int i = 0 ; i < n ; i++)
        {
            if(isdigit(s[i]))
            {
                pq.push(s[i] - '0');
            }
        }
        if(pq.empty())
        {
            return -1;
        }
        int largest = pq.top();
        pq.pop();
        while(!pq.empty() && pq.top() == largest)
        {
            pq.pop();
        }
        if(!pq.empty())
        {
            return pq.top();
        }
        return -1;
    }
};

// tc o(n)
// sc o(n)
