Partition Array

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int start = 0;
        int end = nums.size()-1;
        
        while(start <= end){
            while(start <= end && nums[start] < k) start ++;
            while(start <= end && nums[end] >= k) end --;
            if(start <= end){//else
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start ++;
                end --;
            }
        }
        return start;
    }
};
---------------
Sort Letters by Case
class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int start = 0;
        int end = letters.length()-1;
        
        while(start<=end){
            while(start <= end && letters[start] >= 'a'&& letters[start] <= 'z') start++;
            while(start <= end && letters[end] >='A' && letters[end] <='Z' )end--;
            if(start<=end){
                char tmp = letters[start];
                letters[start] = letters[end];
                letters[end] = tmp;
                start++;
                end--;
            }
        }
    }
};

sort kcolors

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int len = colors.size();
        int right = len-1;
        for(int i = 0; i < k-1;++i){//排k-1次
            right = partition(colors, 0, right, k-i-1);//颜色k-1~0
        }
    }
    int partition(vector<int> &nums, int left, int right, int pivot){
        int l = left;
        int r = right;
        //为什么是=
        //当前排pivot=k的情况
        while(l<=r){
            while(l<=r && nums[l]<=pivot)l++;
            while(l<=r && nums[r]>pivot)r--;
            if(l<=r){
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        return r;
    }
};




