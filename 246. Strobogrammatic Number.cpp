class Solution {
public:
    bool isStrobogrammatic(string num) {
        //0,1,6,8,9
        unordered_map <char, char> map = {{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
        
        int start = 0; 
        int end = num.length()-1;
        
        while(start <= end){
            if(map.find(num[start]) != map.end() && map[num[start]] == num[end]){
                start ++;
                end --;
            }else return false;
        }
        return true;
    }
};