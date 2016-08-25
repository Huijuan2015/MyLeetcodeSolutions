public class Solution {
    public boolean isPowerOfThree(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        else if(n%3 == 0) return isPowerOfThree(n/3);
        else return false;
    }
}



public class Solution {
    public boolean isPowerOfThree(int n) {
        if(n <= 0)return false;
        while(n != 1){
        	if(n%3 != 0) break;
        	n/=3;
        }
        return n == 1;
    }
}



return n>0 && Math.pow(3, (int)(Math.log(0x7fffffff)/Math.log(3)))%n==0;