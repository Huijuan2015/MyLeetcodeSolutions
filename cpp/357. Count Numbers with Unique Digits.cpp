class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        int val = 9;
        int ans = 10;
        for(int i = 2; i <= n; ++i){
            val *= (9-i+2);
            ans += val;
        }
        return ans;
    }
};


public class Solution {
    public int countNumbersWithUniqueDigits(int n) {
		if(n==0)
			return 1;
		if(n==1)
			return 10;
		int num=9;
        for(int i=0;i<n-1;i++){
        	num*=(9-i);
        }
		return num+=countNumbersWithUniqueDigits(n-1);
    }
}