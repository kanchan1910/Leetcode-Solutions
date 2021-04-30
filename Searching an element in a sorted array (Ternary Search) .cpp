/*
Given a sorted array of size N and an integer K. Check if K is present in the array or not using ternary search.
Ternary Search - It is a divide and conquer algorithm that can be used to find an element in an array. It is similar to binary search where we divide the array into two parts but in this algorithm, we divide the given array into three parts and determine which has the key (searched element).
To know more please click this link.


Example 1:

Input:
N = 5, K = 6
arr[] = {1,2,3,4,6}
Output: 1
Exlpanation: Since, 6 is present in 
the array at index 4 (0-based indexing),
output is 1.
 

Example 2:

Input:
N = 5, K = 2
arr[] = {1,3,4,5,6}
Output: -1
Exlpanation: Since, 2 is not present 
in the array, output is -1.
 

Your Task:
You don't need to read input or print anything. Complete the function ternarySearch() which takes the sorted array arr[], its size N and the element K as input parameters and returns 1 if K is present in the array, else it returns -1. 


Expected Time Complexity: O(Log3N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 106
1 <= K <= 106
1 <= arr[i] <= 106


*/
 int ts(int arr[], int N, int K)
    {
        int l = 0, r = N - 1;
        while(l <= r)
        {
            int  mid1 = l + (r - l) / 3;
            int mid2 = mid1 + (r - l) / 3; // mid1 se leke bchi hui length ka 1/3 hissa
            if(arr[mid1] == K)
            {
                return mid1;
            }
            else if(arr[mid2] == K)
            {
                return mid2;
            }
            else if(K < arr[mid1])
            {
                r = mid1 - 1;
            }
            else if(K > arr[mid2])
            {
                l = mid2 + 1;
            }
            else
            {
                // lies in portion between mid1 and mid2
                l = mid1 + 1;
                r = mid2 - 1;
            }
        }
        return -1;
    }
    int ternarySearch(int arr[], int N, int K) 
    { 
        return ts(arr, N, K) == -1 ? -1 : 1;
    }
};

// tc o(log3N)
// sc o(1)


class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    
    int ternarySearch(int arr[], int N, int K) 
    { 
        if(binary_search(arr, arr + N, K) == true)
        {
            return 1;
        }
        return -1;
    }
};

// tc o(log2N)
// sc o(1)

 int bs(int arr[], int N, int K)
    {
        int l = 0, r = N - 1;
        while(l <= r)
        {
            int  mid = l + (r - l) / 2;
            if(arr[mid] == K)
            {
                return mid;
            }
            else if(K < arr[mid])
            {
                r = mid - 1;
            }
            else if(K > arr[mid])
            {
                l = mid + 1;
            }
        }
        return -1;
    }
    int ternarySearch(int arr[], int N, int K) 
    { 
        return bs(arr, N, K);
    }
};

// tc o(log2N)
// sc o(1)
