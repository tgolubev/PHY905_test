#include <iostream>
using namespace std;
//  Declare functions before main
void func(int, int*);

int main(int argc, char *argv[])
{
  int a;
  int *b;  //define that b is a pointer of type int. value of b will be an address in mememory.
  a = 10;
  b = new int[10];  //define an array with 10 elements
  for(int i = 0; i < 10; i++) {
    b[i] = i;                             //define the values of the elements
    cout <<  b[i] << endl;                //show values of elements
  }
  cout<<"a before being sent to func:" << a <<endl;

  // Call func. The variable a is transferred by 'call by value'. This means
  //  that the function func cannot change a in the calling function. func only uses the value of a.
  //An alternative to keep a unchanged, can define 'a' as a constant: defining as constant, could make code more readable.

  func( a,b);  //a and b are passed to the function.

  cout<<"a after being sent to func:" << a <<endl;

  delete [] b ;
  return 0;
} // End: function main()

void func( int x, int *y)  //function recieves variable x and pointer y.
{
  // a becomes locally x  and x can be changed locally, but 'a' will not be changed.
  x+=7;  //x = x+7;

  //  func gets the address of the first element of y (b)
   // it changes y[0] to 10 and when returning control to main
  // it changes also b[0]. Call by reference
  *y += 10;  //  *y = *y+10;  //changes the value of the variable y points to that value+10
  //  explicit element
  y[6] += 10;
  //   in this function y[0]  and y[6] have been changed and when returning
  // control to main  this means that b[0] and b[6] are changed.
  return;
} // End: function func()
