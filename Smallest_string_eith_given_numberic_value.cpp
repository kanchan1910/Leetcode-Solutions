class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        k-=n;
        int i=n-1;
        while(k!=0&&i>=0){
             if(k>=25){
                 ans[i]='z';
                 k-=25;
             }
            else{
                ans[i]+=k;
                break;
            }
            i--;
        }
        return ans;
    }
};
