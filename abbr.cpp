aaacbbcc->3a1c2b2c

string abbr(string& s){
	string res;
	for(int i = 1; i < s.length(); ++i){
		int count = 1;
		while(s[i] == s[i-1]){
			count++;
			i++;
		}
		res += to_string(count) + s[i-1];
	}
	return res;
}