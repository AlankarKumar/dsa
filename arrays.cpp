#include <iostream>

using namespace std;

void printArray(int *p, int n) {
  cout << "Printing array " << endl;
  for (int i = 0; i < n; i++) {
    cout << *(p + i) << endl;
  }
  cout << "Printing array end" << endl;
}

int main() {
  cout << "ARRAYS" << endl;

  // Dynamic array size allocation
  int *p;
  int n;
  cout << "Enter the size of the array : " << endl;
  cin >> n;
  p = new int[n];

  for (int i = 0; i < n; i++) {
    *(p + i) = i;
  }

  printArray(p, n);
  //
  // // Increasing the size of an array
  int *q, newSize;
  cout << "Enter new arary size : " << endl;
  cin >> newSize;
  q = new int[newSize];
  for (int i = 0; i < newSize; i++) {
    q[i] = p[i];
  }
  delete[] p;
  p = q;
  q = nullptr;

  printArray(p, newSize);

  // 2D array
  // Inside stack
  int A[3][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};

  // Inside Stack &  Heap
  int *B[3];
  B[0] = new int[4];
  B[1] = new int[4];
  B[2] = new int[4];

  // Inside heap
  int **C;
  C = new int *[3];
  C[0] = new int[4];
  C[1] = new int[4];
  C[2] = new int[4];

  // Traversing the 2D Array
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }

  // Initializing the stack and heap 2D arrays
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      B[i][j] = i + j;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cout << B[i][j] << " ";
    }
    cout << endl;
  }

  // Row Major 2D array

  return 0;
}
