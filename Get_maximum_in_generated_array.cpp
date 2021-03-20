class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0){   //critical cases
            return 0;
        }
        if(n==1){   //critical cases
            return 1;
        }
        vector<int>arr(n+1);
        arr[0]=0;
        arr[1]=1;
        for(int i=1;i<=n/2;i++){
            if(2*i<=n){
               arr[2*i]=arr[i];   
            }
            if(2*i+1<=n){
              arr[2*i+1]=arr[i]+arr[i+1];   
            }
        }
    return *max_element(arr.begin(),arr.end());
    }
};
