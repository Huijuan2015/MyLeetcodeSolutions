class TwoSum {
public:
    
    // Add the number to an internal data structure.
    void add(int number) {
       
       vec.push_back(number);
       //if(map.find(number) == map.end()){
           map[number] = vec.size()-1;
       //}
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        if(vec.size() == 1) return false;
        for(int i = 0; i < vec.size(); ++i){
            int target = value-vec[i];
            if(map.find(target) != map.end() && map[target] != i){
                return true;
                break;
            }
        }
        return false;
    }
    
private:
    vector<int> vec;
    unordered_map<int, int> map;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);