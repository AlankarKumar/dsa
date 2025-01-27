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
double factorial(int n) {
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
long double exponentOptimized(long int base, int power) {
  if (power == 0)
    return 1;
  if (power % 2 == 0) {
    return exponent(base * base, power / 2);
  } else {
    return base * exponent(base * base, power / 2);
  }
}
// taylor series
long double taylorSeries(int base, long int n) {
  if (n == 0) {
    return 1;
  } else {
    return taylorSeries(base, n - 1) +
           exponentOptimized(base, n) / factorial(n);
  }
}

// taylor series with static varibles
long double staticTaylorRecursive(int base, int n) {
  static double numerator = 1, denominator = 1;
  double r;
  if (n == 0) {
    return 1;
  } else {
    r = staticTaylorRecursive(base, n - 1);
    numerator *= base;
    denominator *= n;
    return r + (numerator / denominator);
  }
}

// taylor series with Horner's rule
long double hornerTalyorIterative(int base, int n) {
  double s = 1;
  for (; n > 0; n--) {
    s = 1 + base / (n * s);
  }
  return s;
}

// recursive taylor series with Horner
long double hornerTaylorRecursive(int base, int n) {
  static double s = 1;
  if (n == 0) {
    return s;
  }
  s = 1 + base / (n * s);
  return hornerTaylorRecursive(base, n - 1);
}

// Fibonacci Recursive
long int fib(int n) {
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

// Fibonacci iterative
long int fibIterative(int n) {
  int t0 = 0, t1 = 1;
  int tn = 0;
  if (n == 0 || n == 1)
    return n;
  for (int i = 2; i <= n; i++) {
    tn = t0 + t1;
    t0 = t1;
    t1 = tn;
  }
  return tn;
}

// Fibonnaci Recurisve memoized
int F[10];
long int fibRecursiveMemoized(int n) {
  if (n <= 1) {
    F[n] = n;
    return n;
  } else {
    if (F[n - 2] == -1) {
      F[n - 2] = fibRecursiveMemoized(n - 2);
    }
    if (F[n - 1] == -1) {
      F[n - 1] = fibRecursiveMemoized(n - 1);
    }
    return F[n - 2] + F[n - 1];
  }
};

// nCr ReRecursive
int combination(int n, int r) {
  if (r == 0 || n == r) {
    return 1;
  } else {
    return combination(n - 1, r - 1) + combination(n - 1, r);
  }
}

int main() {
  int x = 3;

  for (int i = 0; i < 10; i++) {
    F[i] = -1;
  }

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
  cout << exponent(2, 10) << endl;
  auto end1 = chrono::high_resolution_clock::now();

  auto start2 = chrono::high_resolution_clock::now();
  cout << "Optimized Exponent" << endl;
  cout << exponentOptimized(2, 50) << endl;
  auto end2 = chrono::high_resolution_clock::now();

  auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
  auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

  cout << "Duration 1 : " << duration1.count() << endl;
  cout << "Duration 2 : " << duration2.count() << endl;

  auto taylorStart1 = chrono::high_resolution_clock::now();
  cout << "Taylor Series" << endl;
  cout << taylorSeries(1, 10) << endl;
  auto taylorEnd1 = chrono::high_resolution_clock::now();

  auto taylorStart2 = chrono::high_resolution_clock::now();
  cout << "Static Taylor series" << endl;
  cout << staticTaylorRecursive(1, 10) << endl;
  auto taylorEnd2 = chrono::high_resolution_clock::now();

  auto taylorDuration1 =
      chrono::duration_cast<chrono::microseconds>(taylorEnd1 - taylorStart1);
  auto taylorDuration2 =
      chrono::duration_cast<chrono::microseconds>(taylorEnd2 - taylorStart2);

  cout << "Taylor Duration 1" << taylorDuration1.count() << endl;
  cout << "Taylor Duration 2" << taylorDuration2.count() << endl;

  cout << "Fibonacci" << endl;
  cout << fib(10) << endl;

  cout << "Fibonacci Iterative" << endl;
  cout << fibIterative(10) << endl;

  cout << "Fibonacci Memoized" << endl;
  cout << fibRecursiveMemoized(10) << endl;
  return 0;
}
