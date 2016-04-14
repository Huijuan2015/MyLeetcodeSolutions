class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int start = 0;
    	int end = 0;
    	int n = nums.size();

    	int sum = 0;
    	int minLen = INT_MAX;

    	while(start < n && end < n){
    		
    		while(sum < s && end < n){
    			sum += nums[end ++];
    		}
    		while(sum >= s && start <= end){
    			minLen = min(minLen,end-start);
    			sum -= nums[start++];
    		}
    	}
    	return minLen == INT_MAX ? 0 : minLen;
    }
    };