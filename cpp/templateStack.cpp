#include<iostream>
using namespace std;
int flag = 0;
class complex
{
 int real;
 int img;
public:
 complex()
 {
  real = img = 0;
 }
 friend istream& operator>>(istream& cin, complex &c);
 friend ostream& operator<<(ostream& cout, complex &c);
 ~complex()
 {
 }
};
istream& operator>>(istream& cin, complex &c)
{
 cout << "enter the real part: ";
 cin >> c.real;
 cout << "enter the imaginary part:";
 cin >> c.img;
 return cin;
}
ostream& operator<<(ostream& cout, complex &c)
{
 cout << "the real part is:" << c.real << endl;
 cout << "the imaginary part is:" << c.img << endl;
 return cout;
}
template<class T>//template class
class stack
{
 T  *arr;//array depending on type of template used
 int size;
 int top = -1;
public:
 void getsize(int n)//function to initialise the stack
 {
  arr = new T[n];
  size = n;
 }
 void push(T n)//function to push element into stack
 {
  if (!isfull())
  {
   arr[++top] = n;
   cout << "pushed element: " << n << endl;
  }
  else
  {
   cout << "stack is full" << endl;
  }
 }
 T pop()//function to delete or pop element from the stack
 {
  T b;
  if (!isempty())
  {
   return arr[top--];
  }
  else
  {
   cout << "stack is empty" << endl;
   flag = 1;
   return b;
  }
 }
 T peek()//function to just view top of stack
 {
  T b;
  if (!isempty())
  {
   return arr[top];
  }
  else
  {
   cout << "stack is empty" << endl;
   flag = 1;
   return b;
  }
 }
 bool isfull()//conditional function returning wether stack is full or not
 {
  return(top == size-1);
 }
 bool isempty()//conditional function returning wether stack is empty or not
 {
  return(top == -1);
 }
};
# define type complex //define either int,float,char,double,complex
int main()
{
 int size = 0,choice=0;
 stack <type>intstack;//template class definition
 type ele;
 cout << "enter size of stack: ";
 cin >> size;
 if (sizeof(size) != 4)//input validation for checking wether correct size is mentioned
 {
  cout << "invalid size" << endl;
  return 0;
 }
 intstack.getsize(size);//initialise the stack with size provided
 while (1)
 {
  cout << "enter choice: " << endl << "1.push" << endl << "2.pop" << endl << "3.peek" << endl << "4.exit" << endl;
  cin >> choice;
  if (choice == 1 && sizeof(choice) == 4)//push element
  {
   cout << "enter the element to push :";
   cin >> ele;
   intstack.push(ele);
  }
  else if (choice == 2 && sizeof(choice) == 4)//pop element
  {
   ele = intstack.pop();
   if (!flag)
   {
    cout << "popped :" << ele << endl;
   }
   flag = 0;
  }
  else if (choice == 3 && sizeof(choice) == 4)//peek top element
  {
   ele = intstack.peek();
   if (!flag)
   {
    cout << "top element is :" << ele << endl;
   }
   flag = 0;
  }
  else if (choice == 4 && sizeof(choice) == 4)//exit
  {
   return 0;
  }
  else //exit if correct choice is not given
  {
   cout << "invalid input" << endl;
   cout << "enter correct choice" << endl;
   return 0;
  }
 }
}