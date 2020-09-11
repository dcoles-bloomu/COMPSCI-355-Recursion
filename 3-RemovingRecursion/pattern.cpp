/*
 * Function f generates a recursive sequence of numbers. It is transformed through a series
 * of intermediate functions to one that uses a stack in place of recursion. For the sake of
 * illustration, the stack is replaced with a queue in another version of the function, 
 * resulting in very different output.
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;

void f(int); // recursive implementation
void g(int); // tail recursion replaced by a loop
void h(int); // stack-based version with GOTO statements
void p(int); // stack-based version without GOTO statements

int main() {
    // for convenience, store pointers to functions in array
    typedef void (*ptf) (int);    // void (*) (int)    // int* // char
    ptf a[] = {f, g, h, p}; 

    // invoke each function through its pointer in the array
    for (int i = 0; i < 5; i++) {
        a[i](4);
        cout << endl;
    }
    return 0;
}

void f(int n) { // recursive implementation
    if (n == 0)
        return;
    f(n - 1);
    cout << n << " ";
    f(n - 1);
}

void g(int n) { // tail recursion replaced by a loop
    while (n > 0)  {
        g(n - 1);
        cout << n << " ";
        n--;
    }
}

void h(int n) { // stack-based version with GOTO statements
    A:
    if (n == 0)
        return;
    h(n - 1);
    cout << n << " ";
    n--;
    goto A;
}

void p(int n) { // stack-based version without GOTO statements
   stack<int> s;

   A:

   if (n == 0) {
     if (s.empty())
        return;
     n = s.top();
     s.pop();
     goto B;
   }

   s.push(n--);
   goto A;

   B:

   cout << n << " ";
   n--;
   goto A;
}