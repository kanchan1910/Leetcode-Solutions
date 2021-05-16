    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        map<int, int>m;
        for(int i = 0; i < N; i++)
        {
            m[A1[i]]++;
        }
        vector<int>ans;
        for(int i = 0; i < M; i++)
        {
            if(m.find(A2[i]) != m.end())
            {
                int freq = m[A2[i]];
                for(int j = 0; j < freq; j++)
                {
                    ans.push_back(A2[i]);
                }
                m[A2[i]] = 0;
            }
        }
        for(auto x: m)
        {
            if(x.second > 0)
            {
                int freq = x.second;
                for(int j = 0; j < freq; j++)
                {
                    ans.push_back(x.first);
                }
            }
        }
        return ans;
    } 



// OR

    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        vector<int>fre(1000005, 0);
        for(int i = 0; i < N; i++)
        {
            fre[A1[i]]++;
        }
        vector<int>ans;
        for(int i = 0; i < M; i++)
        {
           if(fre[A2[i]] > 0)
           {
               while(fre[A2[i]] > 0)
               {
                   ans.push_back(A2[i]);
                   fre[A2[i]]--;
               }
           }
        }
        for(int i = 1; i <= 1000005; i++)
        {
            if(fre[i] > 0)
            {
            while(fre[i] > 0)
               {
                   ans.push_back(i);
                   fre[i]--;
               }
            }
        }
        return ans;
    } 
