class Solution {
public:
    /*
    Get the sum of Alice's candies & bob's candies.
Sa = sum of Alice
Sb = sum of Bob

Calculate the difference of the sums : say c = Sa - Sb

Now, In order to make the sums same , let's assume candy of hieght a is moved from Alice side & candy of height b is moved from bob side. After doing this resultant sum from both side should be equal right!. Now comes simple maths.

 		Resultant sum of Alice       =        Resultant sum of Bob
 				Sa - a + b           =            Sb - b + a
 				Sa - Sb              =              2*(a-b)
 					c                =              2*(a-b)
 									or
 							b    =   (2a - c)/2
So at last it means, if we are iterating on alice array(say a) we just need to find a number(say b) in bob array such that above relation satisfies.
*/
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes)
    {
        int diff = 0;
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < aliceSizes.size(); i++)
        {
            sum1 += aliceSizes[i];
        }
        for(int i = 0; i < bobSizes.size(); i++)
        {
            sum2 += bobSizes[i];
        }
        diff = (sum1 - sum2);
        unordered_map<int, int>m;
        for(auto x: bobSizes)
        {
            m[x]++;
        }
        for(auto x : aliceSizes)
        {
            if(m.find((2 * x - diff) / 2) != m.end())
            {
                return {x, ((2 * x - diff) / 2)};
            }
        }
        return {-1, -1};
    }
};
