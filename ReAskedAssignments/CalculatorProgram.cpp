#include<iostream>
#include<string>
#include "mathematics.h"

using namespace std;

struct stack
{
	int top;
	char *sptr;
	int size;
};

class Stack {
	stack s;
public:
	Stack()//default constructor to initialise variables
	{
		s.top = -1;
		s.sptr = NULL;
		s.size = 0;
	}
	void push(char n);
	void ipush(int n);
	char pop();
	int ipop();
	char peek();
	bool isempty();
	bool isfull();
	void getsize(int n);
	int checkprec(char c);
	~Stack()//destructor to deallocate the assigned memory
	{
		delete(s.sptr);
	}
};

void Stack::push(char n)
{
	if (!isfull())//checking or overflow condition to avoid index going out of bounds
	{
		s.sptr[++s.top] = n;
	}
	else
	{
		cout << "stack is full" << endl;
	}
}
void Stack::ipush(int n)
{
	if (!isfull())//checking or overflow condition to avoid index going out of bounds
	{
		s.sptr[++s.top] = n;
	}
	else
	{
		cout << "stack is full" << endl;
	}
}
char Stack::pop()
{
	char x = '0';
	if (!isempty())//checking or underflow condition to avoid index going out of bounds
	{
		x = s.sptr[s.top--];
	}
	else
	{
		cout << "stack is empty" << endl;
	}
	return x;
}
int Stack::ipop()
{
	int x = -1;;
	if (!isempty())//checking or underflow condition to avoid index going out of bounds
	{
		x = s.sptr[s.top--];
	}
	else
	{
		cout << "stack is empty" << endl;
	}
	return x;
}
char Stack::peek()//function to get the top most element of stack without popping it
{
	char x = '0';
	if (!isempty())
	{
		x = s.sptr[s.top];
	}
	else
	{
		cout << "stack is empty" << endl;
	}
	return x;
}
bool Stack::isempty()
{
	return(s.top == -1);
}
bool Stack::isfull()
{
	return(s.top == s.size - 1);
}
void Stack::getsize(int n)//initialise stack with given size and allocating memory
{
	s.sptr = new char[n];
	s.size = n;
}
int Stack::checkprec(char c)//function to retrive precedence value of elements in the stack to check for any violation that can happen
{
	int x = 0;
	if (!isempty())
	{
		switch (peek())
		{
		case '+':
		case '-':x = 4;
			break;
		case '*':
		case '/':x = 5;
			break;
		}
		switch (c)
		{
		case '+':
		case '-':x = 4 - x;
			break;
		case '*':
		case '/':x = 5 - x;
			break;
		}
	}
	return x;
}
void InfixToPostfix(string str,char *ostr)
{
	Stack s1;
	char temp = 'a';
	int i = 0, j = 0, x = 0, count = 0;
	for (count = 0; str[count] != '\0'; count++);//cal the length of the given expression
	s1.getsize(count);
	for (i = 0; i < count; i++)
	{
		if (str[i]>'0')//append the character value to output string if the character in input string is a alphabet
		{
			ostr[j] = str[i];
			j++;
		}
		else
		{
			if (str[i] == '(' || str[i] == '[')//if an open paranthesis is encountered blindly push it 
			{
				s1.push(str[i]);
			}
			else if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')//when an operator is overcomed check for precedence and push and pop according to cases
			{
				if (s1.checkprec(str[i]) > 0)
				{
					s1.push(str[i]);
				}
				else
				{
					while (s1.checkprec(str[i]) <= 0 && (!s1.isempty()))
					{
						ostr[j] = s1.pop();
						j++;
					}
					s1.push(str[i]);
				}
			}
			else if (str[i] == ')')//when a close paranthesis is encountered pop elements until open bracket is encountered
			{
				while (temp != '(')
				{
					temp = s1.pop();
					ostr[j] = temp;
					j++;
				}
				j--;
			}
			else if (str[i] == ']')
			{
				while (temp != '[')
				{
					temp = s1.pop();
					ostr[j] = temp;
					j++;
				}
				j--;
			}
		}
	}
	while (!s1.isempty())//popping out elements at the last if any
	{
		ostr[j] = s1.pop();
		j++;
	}
	ostr[j] = '\0';//appending null character at the end 
	j++;
}


int PostfixEvaluation(char* str)
{
	Stack s1;
	Mathematics maths;//object of defined mathematics class
	int x = 0, count = 0, i = 0,val=0;
	int b = 0, a = 0;
	for (count = 0; str[count] != '\0'; count++);
	s1.getsize(count);
	for (i = 0; i < count; i++)
	{
		x = str[i] - '0';
		if (x >= 0 && x <= 9)//push the operands into stack 
		{
			s1.push(x);
		}
		else//when an operator is identified pop two elements from the stack and perform respective operation and push the result
		{
			switch (str[i])
			{
			case '*':
					a = s1.ipop();
					b = s1.ipop();
					s1.ipush(maths.mul(b, a));
					break;
			case '/':
					a = s1.ipop();
					b = s1.ipop();
					s1.ipush(maths.div(b, a));
					break;
			case '+':
				a = s1.ipop();
				b = s1.ipop();
				s1.ipush(maths.add(b, a));
				break;
			case '-':
					a = s1.ipop();
					b = s1.ipop();
					s1.ipush(maths.sub(b, a));
					break;
			}
		}
	}
	return s1.ipop();
}

int main()
{
	string str;
	int incrementer = 0,length=0;
	cout << "enter the expression to be evaluated " << endl<<endl;
	cout << "enter expression without spaces:";
	getline(cin, str);//get the expression to be evaluated
	cout << endl;
	for (incrementer = 0; str[incrementer] != '\0'; incrementer++)//find out wether any spaces are present in the given input
	{
		if (str[incrementer] == ' ')
		{
			cout << "entered expression is invalid please enter the expression again without spaces to proceed:";
			getline(cin, str);
			break;
		}
	}
	for (incrementer = 0; str[incrementer] != '\0'; incrementer++)//find out wether any spaces are present in the given input
	{
		if (str[incrementer] == ' ')
		{
			cout << "entered input is invalid terminating the process ...................." << endl;
			return 0;
		}
	}
	for (incrementer = 0; str[incrementer] != '\0'; incrementer++);
	length = incrementer;
	char *ostr = new char[length];//assign dynamic memory for the output string
	InfixToPostfix(str, ostr);//convert the given string into postfix expression
	int result;
	result=PostfixEvaluation(ostr);
	cout << "the result is" << result << endl;
	//delete(ostr);//delete allocated memory
	return 0;
}