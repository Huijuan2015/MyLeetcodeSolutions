class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if(array.size() == 0) return -1;
        int len = array.size();
        int low = 0;
        int high = len - 1;
        
        while(low <= high){
            int mid = low + ((high-low)>>1);
            if(low < 0) return 0;
            if(array[mid] > target){
                high = mid-1;
            }else if(array[mid] < target){
                low = mid+1;
            }else {
                high = mid;
                if(high == 0) return high;
                if(high > 0 && array[high-1] != array[high]){
                    return high;
                }
                high --;
            }
        }
        
       return -1;
    }
};
