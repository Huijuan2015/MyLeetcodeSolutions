#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for(int a_i = 0;a_i < n;a_i++){
           cin >> a[a_i];
        }
    }
    return 0;
}

sting
hashmap
unordered_map<char, int> mp;
for(int i = 0; i < s.length(); ++i){
    mp[i] ++;
    if(map[i] == 2) return s[i];
}
return -1;


    vector<int> testNums(3,-1);
    istringstream is(s);
    string tmp;
    is >> s;
    int i = 0;
    while(is >> tmp){
        testNums[i] = atoi(tmp);//stoi(str) include <string>  atoi(tmp.c_str());
        i++;
        if(i == 3) break;
    }
    //sort
    for(int i = 1; i < 3; ++i){
        if(testNums[i] < testNums[i-1]){
         swap()
        }
    }
    triangleHelper(testNums);
}

string triangleHelper(vector<int> & nums){
    string isxxx
    string isxxx
    string Notxxx
    //是否组成三角形
    if(nums[0] + nums[2] <= nums[3]) return 3
    //等腰三角形
    else if(nums[0] == nums[1]) {
        if(nums[0] == nums[2]) return 2
        } else return 1
    //等边三角形
    else return 3














}
