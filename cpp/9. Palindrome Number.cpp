class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x && !x%10)) return false;、
        int s = 0;
        while(x>s){
            s = s*10 + x%10;
            x /= 10;
        }//除到一半，真聪明
        return x== s || x==s/10;
    }
};