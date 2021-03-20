class FrontMiddleBackQueue {
public:
      vector<int>v;
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        
        v.insert(v.begin(),val);
    }
    
    void pushMiddle(int val) {
       
             int i=v.size()/2;
        
            v.insert(v.begin()+i,val); 
    }
    
    void pushBack(int val) {
        
        v.push_back(val);
    }
    
    int popFront() {
        
        if(v.size()==0){
            
            return -1;
        }
        else{
            
            int val=v[0];
            
            v.erase(v.begin());
            
            return val;
            
        }
    }
    
    int popMiddle() {
        if(v.size()==0){
            
            return -1;
        }
        else{
             
        int val;
            if(v.size()%2==0){
                
                int i=v.size()/2;
                
                val=v[i-1];
                
               v.erase(v.begin()+i-1);
            }
            else{
                 int i=v.size()/2;
                
                val=v[i];
                
                v.erase(v.begin()+i);
            }
       
            return val;
        }
       
    }
    
    int popBack() {
        
         if(v.size()==0){
             
            return -1;
        }
        else{
            
            int val=v[v.size()-1];
            
            v.pop_back();
            
            return val;
        }
    }
};
