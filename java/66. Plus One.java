public class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        int pos = len-1;
        
        while(pos>=0 && digits[pos] == 9){
            digits[pos] = 0;
            pos--;
        }
        if(pos == -1){
            int[] res = new int[len+1];
            res[0] = 1;
            return res;
        }else{
            digits[pos] ++;
        }
        return digits;
    }
}