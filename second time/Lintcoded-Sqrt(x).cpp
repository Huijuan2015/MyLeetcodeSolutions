class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if(x < 2) return x;
        long low = 1;
        long high = x/2;
        
        while(high > low+1){
            long mid = low + (high-low)/2;
            if(x /mid == mid) return mid;
            else if( x /mid < mid) high = mid;
            else low = mid;
            
        }
        if(x/low == low) return (int) low;
        if(x/high == high) return (int) high;
        
    }
};