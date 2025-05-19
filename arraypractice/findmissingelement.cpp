
#include <cmath>
#include <iostream>

using namespace std;

struct Array {
  int *A;
  int size;
  int length;
};
/***
 * Case when the sequence is a list of first n natural numbers and we know the
 * first and the last number In that case we can calculate the sum of the first
 * n natural numbers subtract the sum of the array and find the missing element
 * The sum of first n natural numbers is n*(n+1)/2 and the sum of array can be
 * found iteratively
 */
int findMissingElementInNaturalNumbers(int first, int last, struct Array arr) {
  int missingNumber = -1;

  return missingNumber;
}
// Test Case 6,7,8,9,11,12,15,16,17,18,19

/***
 *Case when the sequence is not any sequence of natural numbers
 * Calculate the difference between the numbers and theie indices
 * Wherever the difference mismatches you add the index to the difference that
 *is the missing number. This works also when we need to find multiple missing
 *elements. But we should also wno first element, last element, and number of
 *elements. Also the array should be sorted.
 */

/***
 * Case when multiple elements are missing in the sequence and multiple elements
 * missing between same two numbers. The indices method works here as well with
 * one change wherein whenever the difference mismatches we update the
 * difference to the just found mismatched difference for proceeding further in
 * the array
 */

/***
 *Case when elements are missing in unsorted array
 *Take an empty array with the size equal to the max of the unsorted array  and
 *initialize with zero.
 *Scan through the array the update the corresponding index in the empty array.
 *Now all the elements that are zero between the smallest value the largest
 *value indexes are the missing elements.
 *This is a hash table Remember the limitof 10^7
 */

int main() {
  cout << "Programs" << endl;
  return 0;
}
