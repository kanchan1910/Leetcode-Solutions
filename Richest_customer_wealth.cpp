class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int ans=0,count=0;
        
        for(int i=0;i<accounts.size();i++){
            
            count = 0;
            
            for(int j=0;j<accounts[0].size();j++){
                
                count+=accounts[i][j];
                
            }
            
            ans=max(ans,count);
        }
        
        return ans; 
    }
};
