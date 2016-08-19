#include <iostream>
#include <stdexcept>
using namespace std;

//6.template <class T>
class IntStack {

private:
//3.change the size array to point in order to make it dynamically resizable
	int *ptr;
//1. define a top index and length for the stack
	int top;
	int length;

//1.change functions to public	
public:
	//1. add constructor
	IntStack(int size = 0);
	//1. add deconstructor
	~IntStack();

	//1. put implement of the functions outside
	void push(int);
	int pop();
};

//1.implement constructor
//6.template <class T>
//6.IntStack<T>::IntStack(int size)
IntStack::IntStack(int size){
	top = -1;
	length = size;
	while(length <= 0){
		cout << "IntStack is empty, please enter a size" << endl;
		cin >> length;
	}
	//3. dynamic size implemented
	ptr = new int[length];
}

//1.implement deconstructor
//6.template <class T>
//6.IntStack<T>::~IntStack()
IntStack::~IntStack(){
	delete []ptr;
}
	//1.push element, change to pass in value name
}

//1.implement push
//6.template <class T>
//6.void IntStack<T>::push(const T &elem)
void IntStack::push(int elem) {
	
	//if reach the max size
		if (top == (lenght-1)){
			//fprintf(stderr,"stack overflow");
			//1.define an push err here for test
			throw cannotpush_err("stack overflow");
			
		}
		else{
			top ++;
			ptr[top] = elem;
		}
	}

//1.implement pop
//6.template <class T>
//6.const T IntStack<T>::pop()
int IntStack::pop() {
		//if the stack is empty
		if (top == -1){
			//1.define an pop err here for test
			throw cannotpop_err("empty stack, cannot pop element");
		}
		int topValue = ptr[top];
		top --;
		length --;

		return topValue;
	}

};

// 4.test cases: 
// 1>reach the max size and cannot push
// 2>the stack is empty and cannot pop
// 3>normal case

int main(){
	int len;

	cin >> len;
	IntStack stk(len);
	try{
		stk.push(1);
		stk.push(2);
		stk.push(3);
		stk.push(4);
		stk.pop();
		stk.pop();
		stk.pop();
		stk.pop();
	}
	catch(cannotpush_err){
		cout << "catch cannotpush_err";
		return -1;
	}
	catch(cannotpop_err){
		cout << "catch cannotpop_err";
		return -1;
	}

}
/*

1. Please point out all the problems in the above code.
		make push and pop function public

2. Change the code to address the problems you found. You can change

   anything, including the coding style. How should the errors be handled?

3. Modify the code so that the stack is dynamically resizable at runtime (do not use STL vectors).

4. Describe the principles and approach you'd take to test your code.

   If you have time, write some of the tests.

5. Comment your code according to standard commenting practices.

6. How would you use C++ templates to make the stack accept any type of

   elements?
   */