class Solution {
public:
    bool isValid(string s) {
        if(s.length() < 2) return false;
        
        stack<char> stk;
        int n = s.length();
       
        for(int i = 0; i < n; ++i){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                stk.push(s[i]);
            }else if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
                if(stk.empty()) return false;
                if(matches(stk.top(), s[i])){
                    stk.pop();
                }else return false;
                
            }
        }
        return stk.empty();
    }
    
    bool matches(char i, char j){
        if(i == '{' && j == '}') return true;
        if(i == '(' && j == ')') return true;
        if(i == '[' && j == ']') return true;
        else return false;
    }
};