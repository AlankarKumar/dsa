#include <cmath>
#include <iostream>

using namespace std;

int lengthOfString(char str[]) {
  int i;
  for (i = 0; str[i] != '\0'; i++)
    ;
  return i;
}

char *toggleCase(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 65 && str[i] <= 90) {
      str[i] += 32;
    } else if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= 32;
    }
  }
  return str;
}

bool valid(char *name) { return true; }

int findDuplicate(char *str) {
  // HashTable approach
  int count = 0;

  return count;
}

int main() {
  cout << "Strings" << endl;

  char temp = 'A';
  cout << temp << endl;
  cout << (int)temp << endl;

  char X[10] = {'A', 'B', 'C', 'D', 'E', '\0'};
  // To mark the end of a string we use string delimiter. which is '\0'

  // A diffierent way to do this
  // When we declare using the below method the string delimiter is added
  // automatically
  //
  char name[] = "John";

  // Finding the length of the string
  // The index at which string delimiter is found that index is the length of
  // the string.
  cout << lengthOfString(name) << endl;

  // Changing the case of a string;
  // Upper case and lower case characters differ by 32 in ASCII.
  // To convert to lower case add 32
  // To conver to upper case subtract 32
  cout << toggleCase(name) << endl;

  // Count vowels  & consonants in a string
  // WAP

  // Count words in a string
  // WAP count spaces + 1 is the number of words.
  // Couninous set of spaces is called white space
  // if the next character is a space and the previous is also a space then we
  // should not be counting that space .

  // Validate a string
  // Scan the entire and check if any character is invalid
  // it should be between range small letters , capital letter and numbers
  // Other approach is to use Regular expression
  //
  //
  //

  // Reverse a string

  // Checking duplicates in a string
  //
  // 1 . Compare with other letters
  // 2. Use a HashTable
  // 3. Using bits
  //
  //

  // Check if String a Anagram
  // First check if they are equal in size
  // Then implement a hash table
  // Pass through first string increment everything in hashmap
  // Pass through second string if any value is becoming -1 then that means the
  // string is not anagram .
  // IF there are no duplicates then we can also use bitset 


  //Permutations of a given string
  //Technique is backtracking 
  //State space tree
  //Brute Force
  //Backtracking is implemented using Recursion.

  return 0;
}
