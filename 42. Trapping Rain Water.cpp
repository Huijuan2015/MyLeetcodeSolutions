class Solution {
public:
    int trap(vector<int>& height) {
    //只需判断当前位置是否对蓄的水有贡献。
    //当前位置宽度为1最终的贡献值，为左边高度的最大值和右边高度的最大值，取其中最小的，然后和当前高度相减，如果大于0，则这个值就是贡献值
    
        int n = height.size();
        int l = 0;
        int r = n-1;
        int water = 0;
        int minHeight = 0;
        
        while(l<r){
            while(l<r && height[l] <= minHeight){
                water += minHeight - height[l++];
            }
            //遇到更小的minHeight就停下来， 有个新的height[lr]值
            while(l<r && height[r] <= minHeight){
                water += minHeight - height[r--];
            }
            minHeight = min(height[l], height[r]);
        }
        
        return water;
    }
};