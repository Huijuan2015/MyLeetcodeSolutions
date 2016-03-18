class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        //s[j]-s[i]
        int maxLength = 0;
        int sum = 0;
        
        unordered_map <int, int> map;
        
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            //if(sum == k) maxLength = i+1;//加这句
            if(map.find(sum-k) != map.end()){
                maxLength = max(maxLength, i-map[sum-k]+1);
                //哪里有问题？
            }
            if(map.find(sum) == map.end()) 
                map[sum] = i;
            
        }
        return maxLength;
    }
};