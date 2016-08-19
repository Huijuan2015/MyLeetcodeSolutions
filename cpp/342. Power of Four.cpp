class Solution {
public:
    bool isPowerOfFour(int num) {//16
        while(num > 1){//4
            if(num%4 == 0) num /= 4;//4  1
            else return false;
        }
        return num == 1;
    }
};

https://leetcode.com/discuss/97973/four-c-solutions
