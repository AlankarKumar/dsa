#include <cmath>
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

void deleteElement(struct Array *arr, int index) {
  if (index < arr->length) {
    int deletedElement = arr->A[index];
    for (int i = index; i < arr->length - 1; i++) {
      arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
    cout << "Deleted Element " << deletedElement << endl;
  } else {
    cout << "Index out of range" << endl;
  }
};

// Linear Search
void linearSeach(int key, struct Array arr) {
  for (int i = 0; i < arr.length; i++) {
    if (key == arr.A[i]) {
      cout << "Element found at index " << i << endl;
      return;
    }
  }
  cout << "Element not found in array " << endl;
  return;
}

// Binary Search
void binarySearch(int key, struct Array arr) {
  int low = 0;
  int high = arr.length - 1;
  while (low <= high) {
    int mid = floor((low + high) / 2);
    if (arr.A[mid] == key) {
      cout << "Element Found at " << mid << endl;
      break;
    } else if (key < arr.A[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
}

int max(struct Array arr) {
  int max = arr.A[0];
  for (int i = 0; i < arr.length; i++) {
    if (arr.A[i] > max)
      max = arr.A[i];
  }
  return max;
}

int min(struct Array arr) {
  int min = arr.A[0];
  for (int i = 0; i < arr.length; i++) {
    if (arr.A[i] < min)
      min = arr.A[i];
  }
  return min;
}

int sum(struct Array arr) {
  int sum = 0;
  for (int i = 0; i < arr.length; i++) {
    sum += arr.A[i];
  }
  return sum;
}

int average(struct Array arr) { return sum(arr) / arr.length; }

int recursiveBinarySearch(int key, int low, int high, struct Array arr) {
  int mid = floor((low + high) / 2);
  if (low > high) {
    return -1;
  }
  if (arr.A[mid] == key)
    return mid;
  if (key < arr.A[mid]) {
    high = mid - 1;
  } else {
    low = mid + 1;
  }
  return recursiveBinarySearch(key, low, high, arr);
}

void reverseArrayWithAuxilliaryMemory(struct Array *arr) {
  int *p = new int[arr->length];
  for (int i = arr->length - 1, j = 0; i >= 0 && j < arr->length; i--, j++) {
    p[j] = arr->A[i];
  }

  for (int i = 0; i < arr->length; i++) {
    arr->A[i] = p[i];
  }
}

void reverseArrayInPlace(struct Array *arr) {
  for (int i = 0, j = arr->length - 1; i < j; i++, j--) {
    int temp = arr->A[i];
    arr->A[i] = arr->A[j];
    arr->A[j] = temp;
  }
}

// Left Shift

// Right Shift

// Rotation

// Left Rotation

// Right Rotation

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
  struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};
  append(&arr, 10);
  displayArray(arr);
  deleteElement(&arr, 3);
  // insert(&arr, 20, 6);
  displayArray(arr);
  linearSeach(1, arr);
  binarySearch(1, arr);
  cout << "Recursive Search "
       << recursiveBinarySearch(1, 0, arr.length - 1, arr) << endl;
  displayArray(arr);
  reverseArrayInPlace(&arr);
  displayArray(arr);
  return 0;
}
