class Solution {
public:
    int trailingZeroes(int n) {
        //1.  2的个数永远多于5个个数.
        //2.  计算5的个数时, 最简单的方法是 SUM(N/5^1,  N/5^2, N/5^3...)
        int numZero = 0;
        if(n < 1) return 0;
        while(n/5 != 0){
            n /=  5;
            numZero += n;
        }
        return numZero;
    }
};