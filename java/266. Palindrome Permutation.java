public class Solution {
    public boolean canPermutePalindrome(String s) {
        Map<Character, Integer> map = new HashMap<Character, Integer> ();
        int len = s.length();
        for(int i = 0; i < len; ++i){
            char c = s.charAt(i);
            Integer count = map.get(c);
            if(count == null){
                count = new Integer(0);
            }
            map.put(c,++count);
        }
        
        boolean hasOdd = false;
        for(Character c : map.keySet()){
            if(map.get(c) % 2 == 1){
                if(!hasOdd){
                    hasOdd = true;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
}