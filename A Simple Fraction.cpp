	string fractionToDecimal(int numerator, int denominator)
	{
	    int initial = numerator / denominator;
	    string ans;
	    ans += to_string(initial);
	    if(numerator % denominator == 0)
	    {
	        return ans;
	    }
	    ans += ".";
	    int rem = numerator % denominator;
	    bool repeating = false;
	    int index;
	    unordered_map<int, int>m;
	    while(rem > 0 && repeating == false)
	    {
	        if(m.find(rem) != m.end())
	        {
	            index = m[rem];
	            repeating = true;
	            break;
	        }
	        else
	        {
	            m[rem] = ans.length();
	        }
	        rem = rem * 10;
	        int temp = rem / denominator;
	        ans += to_string(temp);
	        rem = rem % denominator;
	    }
	    if(repeating == true)
	    {
	        ans += ")";
	        ans.insert(index, "(");
	    }
	    return ans;
	}
