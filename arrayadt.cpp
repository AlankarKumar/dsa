#include <iostream>

using namespace std;

struct Array {
  int *A;
  int size;
  int length;
};

void displayArray(struct Array arr) {
  for (int i = 0; i < arr.length; i++) {
    cout << (arr.A[i]) << " ";
  }
  cout << endl;
}

int main() {
  cout << "ARRAY ADT" << endl;
  struct Array arr;
  cout << "Enter the size of the array " << endl;
  cin >> arr.size;
  arr.A = new int[arr.size];
  cout << "Enter the number of number numbers you want to enter : " << endl;
  cin >> arr.length;

  for (int i = 0; i < arr.length; i++) {
    cin >> arr.A[i];
  };

  displayArray(arr);
  return 0;
}
