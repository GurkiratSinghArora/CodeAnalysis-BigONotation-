#include "a3.h"
#include <iostream>
#include<cmath>
using namespace std;

void cartesianProductTest()
{
       cout << "Cartesian Product Test" << endl;
       int arr[] = { 1,2,3,4,5 };
       int n = 5;
       int cost = 0;
       cartesianProduct(arr, n, cost);
       cout << endl << "cost = " << cost;
       cout << endl << "t(CartesianProduct): 4n^2+5n+2 = " << 4*n*n + 5*n + 2;  //O(n^2)
       cout << endl << "--------------" << endl << endl;
}

void triangleTest()
{
    cout<< "Triangle Test" <<endl;
    int n= 15;
    int cost=0;
    triangle(n, cost);
    cout << endl << "cost = "<<cost;
    cout << endl << "t(triangle): 3n^2 + 13n + 3 =  "<<3*n*n + 13*n + 3;  //O(n^2)
    cout << endl << "----------------"<< endl << endl;
}
void matrixSelfMultiplyTest()
{
    cout<< "Matrix Self Multiply Test"<<endl;
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n=3;
    int cost=0;
    int* pt=  matrixSelfMultiply(arr,n,cost);
    cout << endl << "cost = " << cost;
    cout << endl << "t(MatrixSelfMultiply): 5n^3+6n^2+4n+4 = " << 5*n*n*n + 6*n*n + 4*n + 4;  //O(n^3)
    cout << endl << "--------------" << endl << endl;
}
void patternTest()
{
    cout<<" Pattern Test "<<endl;
    int cost =0;
    int n=16;
    pattern(n,0,cost);
    cout<< endl << "cost = "<< cost;
    cout<< endl << "t(pattern) : 3nlogn + 23n - 9= "<< 3*n*log2(n) + 23*n - 9 ; //O(nlogn)
    cout<< endl << "----------------" << endl << endl;
}
void ssortTest()
{
    cout<<" Sorting Test "<<endl;
    int arr[]= {9,8,7,6,5,4,3,2,1};
    int n=9;
    int i=0;
    int cost=0;
    ssort(arr,n,i, cost);
    cout << endl << "cost = " << cost;
    cout << endl << "t(ssort): 2n^2 + 5n - 6  = "<<2*n*n + 5*n - 6;  //O(n^2)
    cout << endl << "--------------" << endl << endl;
}
void lsearchtest()
{
    cout<<" Linear Search Test "<<endl;
    int arr[]= {9,8,7,6,4};
    int n=5;
    int target=4;
    int cost=0;
    lsearch(arr,n,target,cost);
    cout << endl << "cost = " << cost;
    cout << endl << "t(lsearch): 3n + 1 = "<<3*n+1<<endl; //cost if the element is not there in there in the array
    
    cout<<2*(pow(2,n-1))+4*(pow(2,n-1)-1); //cost if the element is the last element
    cout << endl << "--------------" << endl << endl;   //O(2^n)
}
void testpow()
{
    cout<<" Power Test "<<endl;
    int cost=0;
    int base=2;
    int exp=14;
    unsigned int power= pow(base, exp, cost);
    cout<<"The power value is "<<power<<endl;
    cout << endl << "cost = " << cost;
    cout << endl << "t(pow): 5*floor(logn) + 7  = "<<5*log2(exp)+7;   //O(logn)
    cout << endl << "--------------" << endl << endl;
}
int main()
{
    testpow();
    lsearchtest();
    ssortTest();
    patternTest();
    matrixSelfMultiplyTest();
    triangleTest();
    cartesianProductTest();
    return 0;
}

