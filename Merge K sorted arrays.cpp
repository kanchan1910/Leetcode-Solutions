    vector<int>mergeTwoSortedArrays(vector<int>arr1, vector<int>arr2)
    {
        int i = 0, j = 0;
        int k1 = arr1.size(), k2 = arr2.size();
        vector<int>ans;
        while(i < k1 && j < k2)
        {
            if(arr1[i] < arr2[j])
            {
                ans.push_back(arr1[i]);
                i++;
            }
            else
            {
                ans.push_back(arr2[j]);
                j++;
            }
        }
        while(i < k1)
        {
            ans.push_back(arr1[i]);
            i++;
        }
        while(j < k2)
        {
            ans.push_back(arr2[j]);
            j++;
        }
        return ans;
    }
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>ans;
        for(int i = 0; i < K; i++)
        {
            ans.push_back(arr[0][i]);
        }
        for(int i = 1; i < K; i++)
        {
        // one more doubt, can't we just take, arr[i] instead of tmp, then , tc will be reduced to o(k * k)
            vector<int>tmp;
            for(int j = 0; j < K; j++)
            {
                tmp.push_back(arr[i][j]);
            }
            ans = mergeTwoSortedArrays(ans, tmp);
        }
        return ans;
    }
    // tc o(k * k * k)
    // sc o(1)



 vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>ans(K * K);
        vector<int>index(K, 0);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i = 0; i < K; i++)
        {
            pq.push({arr[i][0], i});
        }
        int idx = 0;
        while(!pq.empty())
        {
            pair<int, int>p = pq.top();
            pq.pop();
            ans[idx] = (p.first);
            idx++;
            if(index[p.second] + 1 < K)
            {
                index[p.second] += 1;
                pq.push({arr[p.second][index[p.second]], p.second});
            }
        }
        return ans;
    }
    
    // according to me tc should be o(k * log(k))
    // tc o(k * k * log(k))
    // sc o(k)
