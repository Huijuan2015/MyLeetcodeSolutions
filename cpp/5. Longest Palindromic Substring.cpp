//动态规划算法
Define P[ i, j ] ← true iff the substring Si … Sj is a palindrome, otherwise false.
P[ i, j ] ← ( P[ i+1, j-1 ] and Si = Sj ) 
其中的base case是
P[ i, i ] ← true
P[ i, i+1 ] ← ( Si = Si+1 

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int max = 1;
        int s_start = 0;
        int s_end = 0;
        bool flag[len][len];
        //
        //f[i][i]长度为1的回文串
        for(int i = 0; i < len; ++i){
            for(int j = 0; j < len; ++j){
                if(i >= j){
                    flag[i][j] = true;
                }else flag[i][j] = false;
            }
        }
      
        for(int j = 1; j < len; ++j){
            for(int i = 0; i < j; ++i){
                if(s[i] == s[j]){
                    flag[i][j] = flag[i+1][j-1];
                    if(flag[i][j] == true && j-i+1 > max){
                        max = j-i+1;
                        s_start = i;
                        s_end = j;
                    }
                }else flag[i][j] = false;
            }
        }
        return s.substr(s_start, max);
    }
};

从某位扩展，更优化？

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len < 2){
            return s;
        }
        
        for(int i = 0; i < len-1; ++i){
            extendPalindrome(s, i, i);
            extendPalindrome(s, i, i+1);
        }
        
        return s.substr(start, maxLen);
    }
    
private:
    int start, maxLen;
    void extendPalindrome(string s, int j, int k){
        while(j >= 0 && k < s.length() && s[j] == s[k]){
            j--;
            k++;
        }
        if(maxLen < k-j-1){
            start = j+1;
            maxLen = k-j-1;
        }
    }
};

Manacher算法？
http://www.cnblogs.com/bitzhuwei/p/Longest-Palindromic-Substring-Part-II.html
