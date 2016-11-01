class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2, -1);
        
        int start = 0;
        int end = numbers.size()-1;
        while(start < end){
            if(numbers[start]+numbers[end] == target){
                res[0] = start+1;
                res[1] = end+1;
                return res;
            }
            while(numbers[start]+numbers[end] < target) start++;
            while(numbers[start]+numbers[end] > target) end--;
        }
        return res;
    }
};