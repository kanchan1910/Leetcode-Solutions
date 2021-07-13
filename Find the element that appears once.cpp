	int search(int A[], int N)
	{
	    int xxor = 0;
	    for(int i = 0; i < N; i++)
	    {
	        xxor ^= A[i];
	    }
	    return xxor;
	}
// tc o(n)
// sc o(1)

// sorting method
// tc o(nlogn)
// sc o(1)

// map method
// tc o(n)
// sc o(n)

	int search(int A[], int N)
	{
//  If ‘mid’ is even, then compare arr[mid] and arr[mid + 1]. If both are the same, then the required element after ‘mid’ and else before mid.
//  If ‘mid’ is odd, then compare arr[mid] and arr[mid – 1]. If both are the same, then the required element after ‘mid’ and else before mid

	    int l = 0, r = N - 1;
	    while(l <= r)
	    {
	        int mid = (l + (r - l) / 2);
	        if(mid % 2 == 0 && A[mid] == A[mid + 1] || mid % 2 != 0 && A[mid] == A[mid - 1])
	        {
	            l = mid + 1;
	        }
	        else
	        {
	            r = mid - 1;
	        }
	    }
	    return A[l];
	}
	// binary seach method, as the given array is sorted.
	// tc o(logn)
	// sc o(1)
