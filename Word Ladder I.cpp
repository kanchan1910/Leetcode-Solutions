 int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string>s;
        bool is_present = false;
        int n = wordList.size();
        for(int i = 0; i < n; i++)
        {
            s.insert(wordList[i]);
        }
        if(s.find(targetWord) != s.end())
        {
            is_present = true;
        }
        if(is_present == false)
        {
            return 0;
        }
        if(startWord == targetWord)
        {
            return 0;
        }
        int level = 0;
        queue<string>q;
        q.push(startWord);
        while(!q.empty())
        {
            level++;
            int m = q.size();
            for(int i = 0; i < m; i++)
            {
                string tmp = q.front();
                q.pop();
                for(int i = 0; i < tmp.length(); i++)
                {
                    string save = tmp;
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        save[i] = ch;
                        if(save == targetWord)
                        {
                            return level + 1;
                        }
                        if(save == tmp)
                        {
                            continue;
                        }
                        if(s.find(save) != s.end())
                        {
                            q.push(save);
                            s.erase(save);
                        }
                    }
                }
            }
        }
            return 0;
    }
