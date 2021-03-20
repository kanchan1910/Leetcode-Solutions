class Solution {
public:
    
       vector<int>index;
    void fun(string str, string sub_str) {
        
   for (int i = 0; i < str.length(); ) {
       
      if (str.substr(i, sub_str.length()) == sub_str) {
          
        index.push_back(i);
          
        i+=sub_str.length();
      }
       else{
           
           i++;
       }
   }
}
    int maxRepeating(string sequence, string word) {
        
        int ans=0;
        
        int n1=sequence.length();
        
        int n2=word.length();
        
        if(n1==n2){
            
            if(sequence==word){
               ans=1;
            }
            else{
                ans = 0;
            }
        }
        else if(n1<n2){
            ans = 0;
        }
        else if(n2<n1){
            
            fun(sequence,word);
  
         if(index.size()==0){
             
             ans = 0;
         }
         else if(index.size()==1){
             
             ans=1;
         }
         else{
             
             int count=1;
             
             for(int i=1;i<index.size();i++){
                 
                 if((index[i]-index[i-1])==word.length()){
                     
                     count++;
                 }
                 else{
                      ans=max(ans,count);
                     
                     count=1;
                 }
                 
             }
             ans=max(ans,count);
         }
        }
        return ans;
    }
};








class Solution {
public:
    
    int maxRepeating(string sequence, string word) {
        
        int ans=0;
        
        int n1=sequence.length();
        
        int n2=word.length();
        
        if(n1==n2){
            
            if(sequence==word){
               ans=1;
            }
            else{
                ans = 0;
            }
        }
        else if(n1<n2){
            ans = 0;
        }
        else if(n2<n1){
       
            int k=n1/n2;
            
            string tmp=word;
            
            for(int i=1;i<=k;i++){
             
                if(sequence.find(tmp)==string::npos){
                    
                    break;
                }
                
                ans++;
                
                tmp+=word;
            }
        }
        return ans;
    }
};
