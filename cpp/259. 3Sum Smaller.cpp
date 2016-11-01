class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
       if(nums.empty() || nums.size() < 3)  return 0;
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            sum += twoSumSmaller(nums, i + 1, target - nums[i]);
        }
        return sum;
}

private:
    int twoSumSmaller(vector<int>& nums, int startIndex, int target) {
        int sum = 0;
        int left = startIndex;
        int right = nums.size()- 1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                sum += right - left;
                left++;
            } else {
                right--;
            }
        }
        return sum;
    }

};