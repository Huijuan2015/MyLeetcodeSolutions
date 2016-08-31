public class Solution {
    public String reverseVowels(String s) {
        //
        char[] res = s.toCharArray();
        int len = s.length();
        int start = 0;
        int end = len-1;
        while(start < end){
            while(start < end && !isVowel(res[start]))start++;
            while(start < end && !isVowel(res[end]))end--;
            char c = res[start];
            res[start] =  res[end];
            res[end] = c;
            start ++;
            end --;
        }

        return new String(res);
    }
    
    public boolean isVowel(char c){
        //if(c >= 'A' && c <= 'Z') c+= 'a'-'A';
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'; 
    }

}