class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //repeated reminder?
        if(!numerator) return "0";
        string res;
        //符号
        if(numerator < 0 ^ denominator < 0) res += '-';//负数
        long long numer = numerator < 0 ? (long long) numerator * (-1) : (long long) numerator;
        long long denom = denominator < 0 ? (long long) denominator * (-1) : (long long) denominator;
        
        long long integral = numer/denom;
        res += int2str(integral);
        long long rmd = numer - integral * denom;//remain
        if(!rmd) return res;//->整数
        res += '.';
        rmd *= 10;//处理小数部分
        
        unordered_map<long long, long long>map;//余数/位置
        while(rmd){
            long long quotient = rmd/denom;
            if(map.find(rmd) != map.end()){//有循环
                res.insert(map[rmd], 1,'(');//位置，长度，插入值
                res+= ')';
                break;
            }
            map[rmd] = res.size();
            res += int2str(quotient);
            rmd = (rmd - denom * quotient) * 10;
        }
        return res;
    }
    
private:
    string int2str(long long num){
        string str;
        while(num){
            int digit = num%10;
            str += digit + '0';
            num /= 10;
        }
        if(str.empty()) return "0";
        reverse(str.begin(), str.end());
        return str;
    }
};