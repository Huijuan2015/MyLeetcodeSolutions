1. 3 colors sort
O(n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //0-r
        //1-w
        //2-b
        if(nums.empty() || nums.size() <= 1) return;
        int red = 0;
        int blue = nums.size()-1;
        
        for(int i = 0; i <= blue; ++i){
            while(nums[i] == 2 && i < blue){
                swap(nums[blue], nums[i]);
                blue--;
            }
            while(nums[i] == 0 && i > red){
                swap(nums[i], nums[red]);
                red++;
             
            }
        }
        
    }
};
null
1,0,2
021210
121220
212120   
000000
111111
222222


2. 4 colors sort
Solution 1:
Count sort, 扫两遍即可，需要O(k)的空间 O(n)
extra space

class Solution {
    void sortColors2(vector<int>& colors, int k) {
        vector<int> count(k, 0);
        for (int color : colors) {
            count[color-1]++;
        }
        int index = 0;
        for (int i = 0; i < k; i++) {
            while (count[i]>0) {
                colors[index++] = i+1;
                count[i]--;
            }
        }
    }
};

Solution 2:

klgn
class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        auto r =  colors.size()-1;
        for(auto i=0;i<k-1;++i)
            r = partition(colors, 0, r, k-i-1);
    }
    
private:
    int partition(vector<int> &nums, int l, int r, int pivot)
    {
        int i=l, j=r;
        while(i<=j)
        {
            while(i<r && nums[i] <= pivot) ++i;
            while(j>0 && nums[j] > pivot) --j;
            if(i<=j) swap(nums[i++], nums[j--]);
        }
        
        return i-1;
    }
};


Method 1: Each time sort the array into three parts:
[all min] [all unsorted others] [all max], 
then update min and max and sort the [all unsorted others] 
with the same method.
复杂度是O(n^2): T(n) = T(n-2) + n
class Solution {
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    public void sortColors2(int[] colors, int k) {
        int pl = 0;
        int pr = colors.length - 1;
        int i = 0;
        int min = 1, max = k;
        while (min < max) {
            while (i <= pr) {
                if (colors[i] == min) {
                    swap(colors, pl, i);
                    i++;
                    pl++;
                } else if (colors[i] == max) {
                    swap(colors, pr, i);
                    pr--;
                } else {
                    i++;
                }
            }
            i = pl;
            min++;
            max--;
        }
    }
    
    private void swap(int[] colors, int i, int j) {
        int temp = colors[i];
        colors[i] = colors[j];
        colors[j] = temp;
    }
};

inplace，并且O(N)时间复杂度的算法。
// 1. 从左扫描到右边，遇到一个数字，先找到对应的bucket.比如
//    3 2 2 1 4
//    第一个3对应的bucket是index = 2 (bucket从0开始计算）
// 2. Bucket 如果有数字，则把这个数字移动到i的position(就是存放起来），然后把bucket记为-1(表示该位置是一个计数器，计1）。
// 3. Bucket 存的是负数，表示这个bucket已经是计数器，直接减1. 并把color[i] 设置为0 （表示此处已经计算过）
// 4. Bucket 存的是0，与3一样处理，将bucket设置为-1， 并把color[i] 设置为0 （表示此处已经计算过）
// 5. 回到position i，再判断此处是否为0（只要不是为0，就一直重复2-4的步骤）。
// 6.完成1-5的步骤后，从尾部到头部将数组置结果。（从尾至头是为了避免开头的计数器被覆盖）
// 例子(按以上步骤运算)：

//  3 2 2 1 4
//  2 2 -1 1 4
//  2 -1 -1 1 4
//  0 -2 -1 1 4
// -1 -2 -1 0 4
// -1 -2 -1 -1 0

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        
        for(int i = 0; i < colors.size(); i++){
            if (colors[i] > 0) {
                int pos = colors[i]-1;
                if (colors[pos] <= 0) {
                    colors[pos]--;
                    colors[i] = 0; 
                }
                else {
                    colors[i] = colors[pos];
                    colors[pos] = -1;
                    i--;
                }
            }
        }
        
        int i = colors.size()-1;
        int j = k-1;
        while(j >= 0) {
            while(colors[j] < 0) {
                colors[j] += 1;
                colors[i--] = j+1;
            }
            j--;
        } 
    }
};


sort priority

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        auto l =  0;
        for(auto i=0;i<k-1;++i)
            r = partition(colors, 0, colors.size()-1, i+1);
    }
    
private:
    int partition(vector<int> &nums, int l, int r, int pivot)
    {
        int i=l, j=r;
        while(i<=j)
        {
            while(i<r && nums[i] <= pivot) ++i;
            while(j>0 && nums[j] > pivot) --j;
            if(i<=j) swap(nums[i++], nums[j--]);
        }
        
        return i-1;
    }
};

