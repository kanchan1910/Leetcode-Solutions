class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>m;
        int n=s.length();
        if(n==1){
            return 0;
        }
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        vector<int>freq;
        for(auto x:m){
            freq.push_back(x.second);
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int val=freq[0];
        int ans=0;
        for(int i=1;i<freq.size();i++){
            if(val==0){
                ans+=freq[i];
                freq[i]=0;
            }
            else if(freq[i]>=val){
                ans+=(freq[i]-val+1);
                freq[i]=val-1;
            }
            val=freq[i];
        }
        return ans;
    }
};
