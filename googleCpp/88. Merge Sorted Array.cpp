class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   
        int cur1 = m-1;
        int cur2 = n-1;
        int cur = m+n-1;
        
        while(cur1 >= 0 && cur2 >= 0){
            if(nums1[cur1] <= nums2[cur2]){
                nums1[cur] = nums2[cur2];
                cur2--;
                cur--;
            }else{
                nums1[cur] = nums1[cur1];
                cur1--;
                cur--; 
            }
        }
        while(cur2 >= 0){
            nums1[cur] = nums2[cur2];
            cur--;
            cur2--;
        }
    }
};