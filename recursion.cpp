#include <chrono>
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

// Linear Recursion
void linearRecursion(int n) {
  if (n > 0) {
    cout << n << endl;
    linearRecursion(n - 1);
    cout << n << endl;
  }
};

// Tree Recursion
void treeRecursion(int n) {
  if (n > 0) {
    treeRecursion(n - 1);

    treeRecursion(n - 1);
    cout << n << endl;
  }
}

// Indirect Recursion
//
void indirectB(int n);

void indirectA(int n) {
  if (n > 0) {
    cout << n << endl;
    indirectB(n - 1);
  }
};

void indirectB(int n) {
  if (n > 1) {
    cout << n << endl;
    indirectA(n / 2);
  }
};

// Nested Recursion
int nestedRecursion(int n) {
  cout << n << endl;
  if (n > 100) {
    return n - 10;
  } else {
    return nestedRecursion(nestedRecursion(n + 11));
  }
}

// Sum of natural numbers using recursion
int sum(int n) {
  if (n == 0) {
    return 0;
  } else {
    return sum(n - 1) + n;
  }
}

// Factorial of a number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return factorial(n - 1) * n;
  }
}

// Exponent using recursion
long int exponent(long int base, int power) {
  if (power == 0)
    return 1;
  else
    return base * exponent(base, power - 1);
}

// Optimized exponent function
long int exponentOptimized(long int base, int power) {
  if (power == 0)
    return 1;
  if (power % 2 == 0) {
    return exponent(base * base, power / 2);
  } else {
    return base * exponent(base * base, power / 2);
  }
}

int main() {
  int x = 3;

  // Ascending phase
  cout << "Ascending phase" << endl << endl;
  fun1(x);

  // Descending phase
  cout << "Descending phase" << endl << endl;
  fun2(x);

  // Staidc variables in recursion
  cout << "Static" << endl;
  cout << fun(x) << endl << endl;

  // Tail Recursion
  cout << "Tail Recursion" << endl;
  tailRecursion(x);

  // Head Recursion
  cout << "Head Recursion" << endl;
  headRecursion(x);

  cout << "Tree RRecursion" << endl;
  treeRecursion(x);

  cout << "Indirect Recursion" << endl;
  indirectA(x);

  cout << "Nested Recursion" << endl;
  nestedRecursion(91);

  cout << "Sum of natural numbers" << endl;
  cout << sum(10) << endl << endl;

  cout << "Factorial" << endl;
  cout << factorial(10) << endl << endl;
  ;
  auto start1 = chrono::high_resolution_clock::now();
  cout << "Exponent" << endl;
  cout << exponent(1000, 1000) << endl;
  auto end1 = chrono::high_resolution_clock::now();

  auto start2 = chrono::high_resolution_clock::now();
  cout << "Optimized Exponent" << endl;
  cout << exponentOptimized(1000, 1000) << endl;
  auto end2 = chrono::high_resolution_clock::now();

  auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
  auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

  cout << "Duration 1 : " << duration1.count() << endl;
  cout << "Duration 2 : " << duration2.count() << endl;
  return 0;
}
