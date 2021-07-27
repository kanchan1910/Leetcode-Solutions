class Solution 
{
    public:
    static bool com(Job j1, Job j2)
    {
        return j1.profit > j2.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
      sort(arr, arr + n, com); 
      vector<bool>slot(n, false);
      vector<int>ans(n);
      for(int i = 0; i < n; i++)
      {
          for(int j = min(n, arr[i].dead) - 1; j >= 0; j--)
          {
              if(slot[j] == false)
              {
                  slot[j] = true;
                  ans[j] = i;
                  break;
              }
          }
      }
      int selected = 0, total_profit = 0;
      for(int i = 0; i < n; i++)
      {
          if(slot[i] == true)
          {
              selected++;
              total_profit += arr[ans[i]].profit;
          }
      }
      return {selected, total_profit};
    } 
};
