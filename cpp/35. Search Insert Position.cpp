// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int start = 0;
//         int end = nums.size();//if need to insert in the end
        
//         while(start < end){
//             int mid = start + (end-start)/2;
//             if(nums[mid] < target) start = mid +1;
//             else end = mid;
//         }
//         return end;
//     }
// };
// 
// 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int start = 0;
        int end = nums.size()-1;
        while(start+1 < end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) start = mid;
            else end = mid;
        }
        if(nums[start] >= target) return start;
        else if(nums[end] >= target) return end;
        else return end+1;//1 element
    }
};