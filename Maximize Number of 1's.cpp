    int findZeroes(int nums[], int n, int m)
    {
       int start = 0;
       int ans = 0;
       int count_of_0 = 0;
       for(int i = 0; i < n; i++)
       {
           if(nums[i] == 0)
           {
               count_of_0++;
               if(count_of_0 <= m)
               {
                   ans = max(ans, i - start + 1);
               }
               else
               {
                   while(count_of_0 > m)
                   {
                       if(nums[start] == 0)
                       {
                          count_of_0--;   
                       }
                        start++;
                   }
                   ans = max(ans, i - start + 1);
               }
           }
           else
           {
               ans = max(ans, i - start + 1);
           }
       }
       return ans;
    }
    // tc o(n)
    // sc o(1)
