
class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int>ans(n, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(price[j] > price[i])
                {
                    break;
                }
                else
                {
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};

// tc o(n * n)
// sc o(1)
// TLE




class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int>ans(n);
        stack<pair<int, int>>s;
        for(int i = 0; i < n; i++)
        {
            if(s.empty())
            {
                ans[i] = i + 1;
            }
            else if(!s.empty() && s.top().first > price[i])
            {
                ans[i] = i - s.top().second;
            }
            else if(!s.empty() && s.top().first <= price[i])
            {
                while(!s.empty() && s.top().first <= price[i])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    ans[i] = i + 1;
                }
                else
                {
                    ans[i] = i - s.top().second;
                }
            }
            s.push({price[i], i});
        }
        return ans;
    }
};

// tc O(n)
// sc O(n)

