class Solution {
public:
    bool isHappy(int n) {
        if(n < 1) return false;
        if(n == 1) return true;
        unordered_set<int> circleNums;
        circleNums.insert(n);
        
        while(true){
            int sum = 0;
            while(n){//?
                sum += (n%10) * (n%10);
                n = n/10;
            }
            
            if(sum == 1) return true;
            else if(circleNums.find(sum) != circleNums.end()) return false;
            
            n = sum;
            circleNums.insert(sum);
        }
        
        
    }
};