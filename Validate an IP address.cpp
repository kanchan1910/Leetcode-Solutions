 int isValid(string s) 
        {
        // number of dots
           int dots = 0;
           int n = s.length();
         // temporary string
           string str = "";
         // vector for stroring all strings
           vector<string>ans;
           for(int i = 0; i < n; i++)
           {
           
               if(s[i] == '.')
               {
                   dots++;
                   // these all cases are invalid
                   if(str.size() == 0 || str.size() > 3 || stoi(str) > 255 || str[0] == '0' && str.size() > 1)
                   {
                       return false;
                   }
                   ans.push_back(str);
                   str = "";
               }
               else if(s[i] >= '0' && s[i] <= '9')
               {
                   str += s[i];
               }
                // it is not mentioned but test cases are designed like this, can also have character instead of integer
               else
               {
                   return false;
               }
           }
           // for the last temporary string
           if(str.size() == 0 || str.size() > 3 || stoi(str) > 255 || str[0] == '0' && str.size() > 1)
           {
               return false;
           }
           else
           {
               ans.push_back(str);
           }
           // if not satisfying the properties of valid IP address
           if(ans.size() != 4 || dots != 3)
           {
               return false;
           }
           return true;
        }
        
        // tc o(n), where n is the length of the string
        // sc o(1)
