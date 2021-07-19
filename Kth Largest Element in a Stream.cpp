// https://leetcode.com/problems/kth-largest-element-in-a-stream/
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int K;
    KthLargest(int k, vector<int>& nums)
    {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }
        K = k;
    }
    
    int add(int val) 
    {
        pq.push(val);
        while(pq.size() > K)
        {
            pq.pop();
        }
        return pq.top();
    }
};

// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1#
vector<int> kthLargest(int k, int arr[], int n)
    {
        vector<int>ans;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i = 0; i < n; i++)
        {
            if(pq.size() < k)
            {
                pq.push(arr[i]);
            }
            else
            {
                if(arr[i] > pq.top())
                {
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
            if(pq.size() < k)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(pq.top());
            }
        }
        return ans;
    }

// tc o(nlogk)
// sc o(k)
