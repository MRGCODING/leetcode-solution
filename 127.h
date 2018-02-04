class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.count(endWord)) 
            dict.erase(endWord);
        else
            return 0;
        queue<string> Q;
        Q.push(beginWord);
        Q.push("");
        int res = 1;
        while(Q.empty() == false)
        {
            string str = Q.front();
            Q.pop();
            if(str != ""){
                int strLen = str.length();
                for(int i = 0; i < strLen; i++)
                {
                    char tmp = str[i];
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        if(c == tmp)
                            continue;
                        str[i] = c;
                        if(str == endWord)
                            return res+1;
                        if(dict.find(str) != dict.end())
                        {
                            Q.push(str);
                            dict.erase(str);
                        }
                    }
                    str[i] = tmp;
                }
            }
            else if(Q.empty() == false){
                res++;
                Q.push("");
            }
        }
        return 0;
    }
};
