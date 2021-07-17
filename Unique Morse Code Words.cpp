class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        unordered_set<string>s;
        vector<string> mapping = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int n = words.size();
        for(int i = 0; i < n; i++)
        {
            string str = words[i];
            string newstr = "";
            for(int j = 0; j < str.length(); j++)
            {
                newstr += mapping[str[j] - 'a'];
            }
            s.insert(newstr);
        }
        return s.size();
    }
};


