
1.


int specialM(int N){
//corner case 
	if(N <= 0) return -1;
//normal case

    int M = 0;
	int curNDigit = N;//= N%10
	bool carry = false;//进位
	int MLength = 0;
	while(N>10){//leave the hight digit to parse later
		curNDigit = N % 10;//当前位
		N /= 10;
		Mlength ++;

		for(int i = 0; i < 10; ++i){
			int preMDigit = findMPreDigit(N, curNDigit, i, carry);//return preMDigit
			M = pow(10, MLength)*preMDigit + M;
		}

	}

	if( M*N*10 < INT_MAX && ){
		findMPreDigit(N,)
	}








	int M = 0;
	bool carry = false;//进位
	int curNDigit = N;//= N%10
	while(N>10){//leave the hight digit to parse later
		curNDigit = N % 10;//当前位
		N /= 10;
		preNDigit = N % 10;//当前位的前一位
		for(int i = 0; i < 10; ++i){
		
			findMPreDigit(N, curNDigit, i, M);
		}
	}

	if( M*N*10 < INT_MAX){
		findMPreDigit(N,)
	}









		//
//for 1-9,进位
//加了进位之后和11的差/当前位
//第一位不能是0




				int curNProduct= curNDigit * i;
			if(curNProduct >= 10 && (curNProduct % 10 == 1){
				int curMDigit = i;
				M = M*10+i;
				int formerDigit = 11 - 
				carry = true;
			}else if(curNProduct >= 10 && curNProduct % 10 == 0){
				int curMDigit = i;
				M = M*10+i;
				int formerDigit = 11 - 
				carry = true;
			}

		}
	}
}
