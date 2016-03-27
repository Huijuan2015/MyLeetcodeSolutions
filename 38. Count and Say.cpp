class Solution {
public:
    string countAndSay(int n) {
        string num = "1";
        for(int i = 1; i < n; ++i){
            num = say(num);
        }
        return num;
    }
    
    private:
    string say(string& num){
        string s;
        int n = num.length(), i = 0, j, k;
        for(int i = 0; i < n; i = j, k=0){
            k = 1, j = i+1;
            while(j < n && num[j] == num[i]) j++, k++;
            s += char(k+'0');
            s += num[i];
        }
        return s;
    }
};