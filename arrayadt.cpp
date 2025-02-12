#include <iostream>

using namespace std;

struct Array {
  int A[20];
  int size;
  int length;
};

void displayArray(struct Array arr) {
  for (int i = 0; i < arr.length; i++) {
    cout << (arr.A[i]) << " ";
  }
  cout << endl;
}

void append(struct Array *arr, int x) {
  if (arr->length < arr->size) {
    arr->A[arr->length++] = x;
  } else {
    cout << "Array is already full, cannot add a new element" << endl;
  }
}

void insert(struct Array *arr, int element, int index) {
  if (arr->length < arr->size) {
    if (index <= arr->length) {
      for (int i = arr->length; i > index; i--) {
        arr->A[i] = arr->A[i - 1];
      }
      arr->A[index] = element;
      arr->length++;
    } else {
      cout << "Cannot insert an element in an non-contiguous location" << endl;
    }
  } else {
    cout << "Array is already full, cannot insert a new element" << endl;
  }
}

int main() {
  cout << "ARRAY ADT" << endl;
  // Array parsing from terminal into pointers
  //  struct Array arr;
  //  cout << "Enter the size of the array " << endl;
  //  cin >> arr.size;
  //  arr.A = new int[arr.size];
  //  cout << "Enter the number of number numbers you want to enter : " << endl;
  //  cin >> arr.length;
  //
  //  for (int i = 0; i < arr.length; i++) {
  //    cin >> arr.A[i];
  //  };
  //
  //  displayArray(arr);
  //
  //
  struct Array arr = {{1, 2, 3, 4, 5}, 6, 3};
  append(&arr, 10);
  insert(&arr, 20, 6);
  displayArray(arr);

  return 0;
}
