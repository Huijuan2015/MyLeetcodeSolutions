//Solution 1.
//quick sort
//O(n)->ave
//o(n^2)->worst
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        while(true){
            int pos = partition(nums, left, right);
            if(pos == k-1) return nums[pos];
            if(pos > k-1) right = pos-1;
            if(pos < k-1) left = pos+1;
        }
    }
    
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int l = left+1;
        int r = right;
        while(l <= r){
            if(nums[l] < pivot && nums[r] > pivot){
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

Solution 2：时间 O(NlogK) 空间 O(K)
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i = 0; i < k-1; ++i){
            pq.pop();//最大堆把前k-1个都pop出来
        }
        return pq.top();
    }

很多follow ups:
https://leilater.gitbooks.io/codingpractice/content/binary_search/kth_largest_element.html
