void reverseWords(string& s){
	string ss;
	int i = s.length()-1;
	while(i >= 0){
		while(i >= 0 && s[i] == ' '){//解决多个字符的情况  单词与单词之间有多个空格字
			i--;
		}
		if(i < 0) break;//解决首部多个字符剔除完毕后，i<0 ，即后续没有字符，需跳出循环。   							//i"   out:"i".
		if(ss.length() != 0){//加空格
			ss.push_back(' ');
		}
		string temp;
		for(; i >=0 && s[i] != ' '; --i){//push单词
			temp.push_back(s[i]);
		}

		reverse(temp.begin(), temp.end());//反转单词再push进结果
		ss.append(temp);//apend string, push_back char
	}
	s = ss;
	
}


void reverseWords(string& s){
	
	istringstream is(s);
	string tmp;
	is >> s;
	while(is >> tmp){
		ss = tmp + ' ' + ss;
	}
	if(s[0] == ' ') s = "";

	return ss;
}
