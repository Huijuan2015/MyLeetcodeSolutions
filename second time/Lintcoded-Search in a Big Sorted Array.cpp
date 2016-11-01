/**
 * Definition of ArrayReader:
 * 
 * class ArrayReader {
 * public:
 *     int get(int index) {
 *          // return the number on given index, 
 *          // return -1 if index is less than zero.
 *     }
 * };
 */
class Solution {
public:
    /**
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader *reader, int target) {
        // write your code here
        int high = 1;
        //-1 越界
        while(reader->get(high-1) < target && reader->get(high- 1) != -1){
            high *= 2;
        }
       
        int low = 0;
        while(low+1 < high){//？？？？？？？？
            int mid = low + (high-low)/2;
            if(reader->get(mid) == target){
                high = mid;
            }else if(reader->get(mid) < target){
                low = mid;
            }else high = mid;
        }
        if (reader->get(low) == target) {
            return low;
        } else if (reader->get(high) == target) {
            return high;
        }
        return -1;
    }
};