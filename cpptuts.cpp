//This is a c++ file
#include <iostream>

using namespace std;

//Template class


template <class T>
class Arithmetic{
  private:
    T a;
    T b;

  public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T>
 Arithmetic<T>::Arithmetic(T a, T b){
  this -> a = a;
  this -> b = b;
}

template <class T>
 T Arithmetic<T>::add(){
   return a+b;
 }

template <class T>
T Arithmetic<T>::sub(){
  return a-b;
}




/*class Rectangle{*/
/*  private: */
/*    int length;*/
/*    int breadth;*/
/**/
/*  public: */
/*    Rectangle(int l, int b);*/
/*    int getPerimeter();*/
/*    int getArea();*/
/*};*/
/**/
/*Rectangle::Rectangle(int l , int b){*/
/* length = l;*/
/* breadth = b;*/
/*};*/
/**/
/*int Rectangle::getPerimeter(){*/
/*  return 2*(length + breadth);*/
/*};*/
/**/
/*int Rectangle::getArea(){*/
/*  return length * breadth;*/
/*};*/
/**/



//Structures
/*struct Rectangle {*/
/* int length;*/
/* int breadth;*/
/* int edges[4];*/
/*};*/
/**/
/**/
/*int add(int a, int b){*/
/*  int c = a + b;*/
/*  return c;*/
/*}*/
/**/
/*void swap(int *x, int *y){*/
/*  int z = *x;*/
/*  *x = *y;*/
/*  *y = z;*/
/**/
/*}*/
/**/
/*void func(int *A, int n){*/
/**/
/*  for(int i=0; i< n; i++){*/
/*    A[i] = A[i] * 2;*/
/*  }*/
/**/
/*  for(int i =0 ; i < n ; i++){*/
/*    cout << A[i] << endl;*/
/*  }*/
/*}*/
/**/
/**/
/*int * returnArray(int size){*/
/* int *p;*/
/* p = new int[size];*/
/**/
/* for(int i = 0 ; i < size; i++){*/
/*  p[i] = i + 1; */
/* }*/
/**/
/* return p;*/
/*}*/
/**/
/**/
/*void changeLength(struct Rectangle *p){*/
/* for(int i = 0 ; i < 4 ; i++){*/
/*   p -> edges[i] = i+2;*/
/* } */
/**/
/*}*/

int main(){
  
/*int A[] = {1,2,3,4,5};*/
//Standard For Loop
/*for(int i =0 ; i< 5; i++){*/
/*  cout << A[i] << endl;*/
/*};*/

//Foreach loop
/*for(int x:A){*/
/*  cout << x << endl;*/
/*}*/


//Variable Sized Array
/*int n;*/
/*cout << "Enter size  :  ";*/
/*cin >> n;*/
/*cout << endl;*/
/*int A[n];*/
/*cout << "now printing " << endl;*/
/*for(int x:A){*/
/*  cout << x << " " ;*/
/*}*/

//Structures
/*struct Rectangle r;*/
/*r.length = 10;*/
/*r.breadth = 10;*/
/*cout << "Area " << r.length * r.breadth  << endl;*/
/*cout << "Sizeof structure : " << sizeof(r) << endl;*/

//Pointers
/*int a = 10;*/
/*int *p = &a;*/
/**/
/*cout << "The value " << *p << "and the address " << p;*/

///Pointer to an Array
/*int A[5] = {1,2,3,4,5};*/
/*int *p;*/
/*p=A;*/
/**/
/*for(int i =0 ; i < 5; i++){*/
/*  cout << p[i] << endl;*/
/*}*/


//New OPerator & Heap memory
/*int *p;*/
/*p = new int[5];*/

//Reference
/*int a = 10;*/
/*int &r = a;*/
/**/
/*int b = 25;*/
/*r = b;*/
/*cout << r <<  a << endl;*/

//Pointer to strcures
/*struct Rectangle r = {10,5};*/
/*struct Rectangle *p = &r;*/
/**/
/*cout << p -> length << endl;*/
/*cout << p -> breadth << endl;*/


//Allocating heap memory to strcures
/*struct Rectangle r = {10,5};*/
/*struct Rectangle *p; */
/*p = new Rectangle;*/
/*p = &r;*/
/*cout << p ->length << p -> breadth << endl;*/

//function call 
/*int x,y,z;*/
/*x = 10;*/
/*y =10;*/
/*z = add(x,y);*/
/*cout << z << endl;*/


//Call by address
/*int a = 10, b = 20;*/
/*cout << a << " " << b << endl;*/
/**/
/*swap(&a, &b);*/
/**/
/*cout << a << " " << b << endl;*/

//Pass Array
/*int A[] = {1,2,3,4,5};*/
/*int n=5;*/
/*func(A,n);*/
/**/
/*for(int x:A){*/
/*  cout << x << " ";*/
/*}*/


//Return array 
/*int *arr = returnArray(10);*/
/**/
/*for( int i = 0 ; i < 10; i ++ ){*/
/*  cout << arr[i] << endl;*/
/*}*/

//Rectangle as a Struct member variable passed as a pointer
/*struct Rectangle r ; */
/*r.length = 10;*/
/*r.breadth = 5;*/
/*for(int i=0 ; i < 4; i++){*/
/*  r.edges[i] = i+1;*/
/*}*/
/*changeLength(&r);*/
/**/
/*for(int i=0 ; i < 4; i++){*/
/*  cout << r.edges[i] << endl;*/
/*}*/

/*Rectangle r(10,5);*/
/**/
/**/
/*cout << r.getArea() << endl;*/
/*cout << r.getPerimeter() << endl;*/
/*Arithmetic<int> ar(2,4);  */
/*cout << ar.add() << endl;*/
return 0;
}

