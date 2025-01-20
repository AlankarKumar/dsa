#include <iostream>

using namespace std;

// Descending phase
void fun2(int n) {
  if (n > 0) {
    cout << n << endl;
    fun2(n - 1);
  }
}

// Ascending phase
void fun1(int n) {
  if (n > 0) {
    fun1(n - 1);
    cout << n << endl;
  }
}

// Static varibles in recursion
int fun(int n) {

  static int x = 0;

  if (n > 0) {

    x++;
    return fun(n - 1) + x;
  }
  return 0;
}

// Tail Recursion
//
void tailRecursion(int n) {
  if (n > 0) {
    cout << n << endl;
    tailRecursion(n - 1);
  }
};

// Head Recursion
void headRecursion(int n) {
  if (n > 0) {
    headRecursion(n - 1);
    cout << n << endl;
  }
};

int main() {
  int x = 5;

  // Ascending phase
  cout << "Ascending phase" << endl << endl;
  fun1(x);

  // Descending phase
  cout << "Descending phase" << endl << endl;
  fun2(x);

  // Staidc variables in recursion
  cout << "Static" << endl;
  cout << fun(x) << endl;

  // Tail Recursion
  cout << "Tail Recursion" << endl;
  tailRecursion(x);

  // Head Recursion
  cout << "Head Recursion" << endl;
  headRecursion(x);

  return 0;
}
