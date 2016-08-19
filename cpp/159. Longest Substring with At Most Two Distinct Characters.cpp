class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
       /*sliding window,i指向sliding window的起始位置，j指向另个一个字符在sliding window的最后一个，
       用于定位i的下一个跳转位置。
1）如果当前字符跟前一个字符是一样的，直接继续。
2）如果不一样，则需要判断当前字符跟j是不是一样的
a）一样的话sliding window左边不变，右边继续增加，但是j的位置需要调整到k-1。
b）不一样的话，sliding window的左侧变为j的下一个字符（也就是去掉包含j指向的字符的区间），j的位置也需要调整到k-1。

在对i进行调整的时候（1.a），需要更新maxLen。

[注意事项]
1）在最后返回的时候，注意考虑s.length()-i这种情况，也就是字符串读取到最后而没有触发（1.a）
2）讲解清楚sliding window的更新
3）该题目有个follow-up，就是如果是k个distinct characters怎么办。
这样的话就只能对所有可能的字符用一个数组去做counting，而且只能假设ASIC字符集256。Unicode太大了。*/
        int firstStart = 0;
        int secLastpos = -1;
        int maxLen = 0;
        
        for(int i = 1; i < s.length(); ++i){
            if(s[i] == s[i-1]) continue;//如果相等
            if(secLastpos >= 0 && s[i] != s[secLastpos]){//如果不相等，比较第二个，如果和第二个不相等,
                                                            //更新长度，更新start
                maxLen = max(int(maxLen), (int)(i- firstStart));
                firstStart = secLastpos+1;
            }
            //如果相等，比较第二个，和第二个相等，last second postion = i-1
            //无论是否相等，sec都要调整
            
            secLastpos = i-1;//把原来第一个元素定义为最后出现的第二个元素
            
        }
        return max((int)(s.length()-firstStart), (int)maxLen);
    }
};