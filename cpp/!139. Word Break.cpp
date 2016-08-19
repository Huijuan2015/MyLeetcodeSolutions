1. solution 1: DP
->dp[i] = true, if there exists j < i such that dp[j] = true and s.substr(j, i - j) is in wordDict

->dp[i] = false, otherwise.


class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        //substr(start, length)
        int n = s.length();
        vector<bool> dp(n+1, false);//注意长度
        dp[0] = true;
        for(auto word:wordDict){
            minlen = min(minlen, (int)word.length());//强制转换比较
            maxlen = max(maxlen, (int)word.length());
        }
        
        for(int i = 1; i <= n; ++i){
            for(int j = i-minlen; j >= max(0, j-maxlen); --j){//注意范围
            //如果前J在词典中，后面也在词典中
                if(dp[j] && wordDict.find(s.substr(j,i-j)) != wordDict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
    
    private:
    int minlen, maxlen;
};


2. solution 2 DFS

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        for(auto word : wordDict){
            maxlen = max(maxlen, (int)word.length());
            minlen = min(minlen, (int)word.length());
        }
        unordered_map<string, bool> records;
        return wordBreakDFS(s, 0, wordDict, records);
    }
    
private:
    int maxlen, minlen;
    bool wordBreakDFS(string& s, int idx, unordered_set<string>& wordDict, unordered_map<string, bool>& records){
        int n = s.length();
        if(idx == n) return true;
        string tail = s.substr(idx, n-idx);
        if(records.find(tail) != records.end()){
            return records[tail];
        }
        for(int i = idx + minlen; i <= min(idx+maxlen, n); ++i){
            string part = s.substr(idx, i-idx);
            if(wordDict.find(part) != wordDict.end() && wordBreakDFS(s,i,wordDict,records)){
                return records[part] = true;
            }
        }
        return records[tail] = false;
    }
};