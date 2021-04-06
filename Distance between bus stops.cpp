class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) 
    {
        
        int total = 0;
        for(int i = 0 ; i < distance.size(); i++)
        {
            total += distance[i];
        }
        if(start > destination)
        {
            swap(start, destination);
        }
         int val1 = 0;
        while(start < destination)
        {
            val1 += distance[start];
            start++;
        }
        return min(val1, total - val1);
    }
};
// tc o(N)
// sc o(1)
