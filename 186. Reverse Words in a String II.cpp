比1简单
可以直接reverse两次

void reverseWords(string& s){
	reverse(s, 0, s.length()-1);
	int left = 0;
	for(int i = 0; i <= s.length(); ++i){
		if(i == length() || s[i] ==' '){
			reverse(s, left, i-1);
			left = i+1;
		}
	}
}

void reverse(string&s, int start, int end){
	while(start < end){
		char tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		start ++;
		end --;
	}
}