/*
Given an array of size n such that each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police. 
Keep in mind the following conditions :

Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than K units away from him.
Example 1:

Input:
N = 5, K = 1
arr[] = {P, T, T, P, T}
Output: 2
Explanation: Maximum 2 thieves can be 
caught. First policeman catches first thief 
and second police man can catch either second 
or third thief.
Example 2:

Input:
N = 6, K = 2
arr[] = {T, T, P, P, T, P}
Output: 3
Explanation: Maximum 3 thieves can be caught.
Your Task:  
You dont need to read input or print anything. Complete the function catchThieves() that takes n, k and arr[ ] as input parameters and returns the maximum number of thieves that can be caught by the police. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ n ≤ 105
1 ≤ k ≤ 100
arr[i] = 'P' or 'T'
*/

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        vector<int>police, theif;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 'P')
            {
              police.push_back(i); 
            }
            else
            {
                theif.push_back(i);
            }
        }
        int ans = 0;
        int police_index = 0, theif_index = 0;
        while(police_index < police.size() && theif_index < theif.size())
        {
            if(abs(police[police_index] - theif[theif_index]) <= k)
            {
                ans++;
                police_index++;
                theif_index++;
            }
            else if(police[police_index] < theif[theif_index])
            {
                police_index++;
            }
            else if(theif[theif_index] < police[police_index])
            {
                theif_index++;
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(n)
