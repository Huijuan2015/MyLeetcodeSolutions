/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int low = 1;
        int high = n;
        
        while(low+1 < high){
            int mid = low + (high - low)/2;
            if(!SVNRepo::isBadVersion(mid)) low = mid;
            else high = mid;
        }
        if(SVNRepo::isBadVersion(low)) return low;
        if(SVNRepo::isBadVersion(high))return high;
    }
};
