/*Given an unsorted array arr[] of n positive integers. Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles. 

Example 1:

Input: 
n = 3
arr[] = {3, 5, 4}
Output: 
1
Explanation: 
A triangle is possible 
with all the elements 5, 3 and 4.
Example 2:

Input: 
n = 5
arr[] = {6, 4, 9, 7, 8}
Output: 
10
Explanation: 
There are 10 triangles
possible  with the given elements like
(6,4,9), (6,7,8),...
 

Your Task: 
This is a function problem. You only need to complete the function findNumberOfTriangles() that takes arr[] and n as input parameters and returns the count of total possible triangles.

Expected Time Complexity: O(n2).
Expected Space Complexity: O(1).

Constraints:
3 <= n <= 103
1 <= arr[i] <= 103

*/

class Solution
{
    public:
    // Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr, arr + n);
        int ans = 0;
        for(int i = n - 1; i > 1; i--)
        {
            int l = 0, r = i - 1;
            while(l < r)
            {
                if(arr[l] + arr[r] > arr[i])
                {
                    ans += (r - l);

                    r--;
                }
                else 
                {
                    l++;
                }
            }
        }
        return ans;
    }
};

// 3
// 3 5 4

// 5
// 6 4 9 7 8

// 4
// 4 4 23 26



// tc o(n * n)
// sc o(1)
