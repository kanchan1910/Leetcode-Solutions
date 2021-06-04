class Solution{
public:
	
	int findMaximum(int arr[], int n) 
	{
	    for(int i = 0; i < n - 1; i++)
	    {
	        if(arr[i + 1] < arr[i])
	        {
	            return arr[i];
	        }
	    }
	    return arr[n - 1];
	}
};
// tc o(n)
// sc o(1)
