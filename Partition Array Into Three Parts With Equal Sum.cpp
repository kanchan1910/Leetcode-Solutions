class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) 
    {
        int n = arr.size();
        int sum = 0;
        for(auto x: arr)
        {
            sum += x;
        }
        if(sum % 3 != 0)
        {
            return false;
        }
        int each_partition_sum = sum / 3; 
        int cur_sum = 0;
        int partition = 0;
        for(int i = 0; i < n; i++)
        {
            cur_sum += arr[i];
            if(cur_sum == each_partition_sum)
            {
                partition++;
                cur_sum = 0;
                if(partition == 3)
                {
                    break;
                }
            }
        }
        /*
        [0,0,0,0]
        [1,-1,1,-1]
        */
        if(partition == 3)
        {
            return true;
        }
        return false;
    }
};



// tc o(n)
// sc o(1)
