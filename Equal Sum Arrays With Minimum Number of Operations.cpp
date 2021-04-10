class Solution {
public:
int minOperations(vector<int>& a, vector<int>& b) {
       
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int suma = 0;
        int sumb = 0;
        for(int i = 0; i < a.size(); i++)
        {
            suma += a[i];
        }
        for(int i = 0; i < b.size(); i++)
        {
            sumb += b[i];
        }
        if(sumb > suma) 
        {
            swap(suma, sumb);
            swap(a, b);
        }
        
        int diff = suma - sumb, operations = 0;
        if(diff == 0) 
        {
            return 0;
        }
       
        int ia = a.size()-1, ib = 0;
        
        while((ib < b.size() || ia >= 0) && diff != 0) 
        {
            // choose the one with max impact
            int inc = ib < b.size() ? 6 - b[ib]: -1;
            int dec = ia >= 0 ? a[ia] - 1 : -1;
            if(inc > dec)
            {
                int mn = min(diff, inc);
                diff -= mn;
                b[ib] += mn;
                ib++;
            }
            else 
            {
                int mn = min(diff, dec);
                diff -= mn;
                a[ia] -= mn;
                ia--;
            }
            operations++;
        }
        
        return (diff == 0) ? operations : -1;
    }
};
// two pointer approach
// tc o(nlogn)
// sc o(1)
