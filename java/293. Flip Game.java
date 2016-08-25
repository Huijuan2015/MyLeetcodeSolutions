public class Solution {
    public List<String> generatePossibleNextMoves(String s) {
        List<String> result = new ArrayList<String>();
        for(int i = 1; i < s.length(); ++i){
            if(s.charAt(i-1) == '+' && s.charAt(i) == '+'){
                result.add(s.substring(0,i-1) + "--" + s.substring(i+1));
            }
        }
        return result;
    }
}

//只要能找出连续的“++”，加上前面的和后面的，就得到了一个结果。