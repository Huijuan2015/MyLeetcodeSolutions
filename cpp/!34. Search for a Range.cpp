class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res={-1, -1};
        //Given [5, 7, 7, 8, 8, 10，15] and target value 8,
        //return [3, 4].
        //二分法找左右边界，两次
        // left->res[0] right->res[1]
        if(nums.empty()) return res;
        int low = binarySearchLow(nums, target, 0, nums.size()-1);
        int up = binarySearchUp(nums, target, 0, nums.size()-1);
        if(up >= low){
            res[0] = low;
            res[1] = up;
        }
        return res;
    }
private:   
    int binarySearchLow(vector<int>& nums, int target, int start, int end){
        if(start > end) return start;
        int mid = start + (end-start)/2;
        if(nums[mid] < target) return binarySearchLow(nums, target, mid+1, end);
        else return binarySearchLow(nums, target, start, mid-1);
    }
    int binarySearchUp(vector<int>& nums, int target, int start, int end){
        if(start > end) return end;
        int mid = start + (end-start)/2;
        if(nums[mid] > target) return binarySearchUp(nums, target, start, mid-1);
        else return binarySearchUp(nums, target, mid+1, end);
    }
};