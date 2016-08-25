public class Solution {
    public boolean isValid(String s) {
        if(s == null || s.length() == 0 ){
            return true;
        }
        int len = s.length();
        char[] stack = new char[len];
        int top = -1;
        
        for(int i = 0; i < len; ++i){
            char ch = s.charAt(i);
            if(ch == '(' || ch == '[' || ch == '{'){
                stack[++top] = ch;
            }else{
                if(top < 0)return false;
                char prev = stack[top];
                if(prev == '(' && ch !=')'|| prev == '[' && ch != ']'
              || prev == '{' && ch != '}'){
                  return false;
              }else --top;
            }
        }
        if(top == -1){
            return true;
        }
        return false;
    }
}