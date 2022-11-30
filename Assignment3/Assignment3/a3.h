//Name - Gurkirat Singh Arora
//Date- 8th June, 2022

#include<iostream>
using namespace std;

// PARAM: arr is array to print the Cartesian product of, n is size of arr
void cartesianProduct(int arr[], int n, int& ops)
{
   int i = 0;
   ops= 1;   // intializes cost for the first statement
   while (i < n)
   {
          int j = 0;
          ops += 2;    //while comparison and the above statement
          while (j < n)
          {
             cout << "{" << arr[i] << "," << arr[j] << "}";
             j++;
             cout << " ";
             ops += 4;  //while comparison and above three statements
          }
          ops++;       //terminating while comparison
          cout << endl;
          i++;
          ops += 2;    //cost for the above two statement
    }
    ops += 1;  //terminating while comparison
    
}
void triangle(int x, int& ops)
{
   int i = 0;
   ops = 1;     //cost for the first statement
   while (i < x)
   {
       int j = 0;
      ops += 2;  //while comparison and above statement
      while (j <= i)
      {
         cout << j << " ";
         j++;
         ops += 3; //while comparison and above two statements
      }
      ops ++;   //terminating while comparison
      cout << endl;
      i++;
      ops +=2;  //cost for the above two statements
   }
    ops ++; //terminating while comparison
   while (i > 0)
   {
      i--;
      int j = 0;
      ops += 3;    //while comparison and above two statements
      while (j <= i)
      {
         cout << j << " ";
         j++;
         ops += 3; //while comparison and above two statements
      }
      ops ++;  //terminating while comparison
      cout << endl;
      ops ++; //the above statement
   }
   ops ++;  //terminating while comparison
}

// Returns the index of a 1d array representing a matrix
// given row (r) and column (c) values
int rcIndex(int r, int c, int columns)
{
       return r * columns + c;
}

// PRE: m represents a square matrix of size rows * rows
// PARAM: rows represents the number of both rows and columns
// POST: Returns a pointer to an array (matrix) of the same size as m
// NOTE: values are indexed r0c0,r0c1,…,r0cn-1,r1c0,…
int* matrixSelfMultiply(int* m, int rows, int& ops)
{
   // Create result array
   int columns = rows;
   int* result = new int[rows * columns];
   int r = 0;
   ops = 3; //cost for the first three statements
   while (r < rows)
   {
      int c = 0;
      ops += 2;   // while comparison and the above statement
      while (c < columns)
      {
         //columns = rows
         int next = 0;
         int iNext = 0;
         ops += 3;  //while comparison and the above two statement
         while (iNext < rows)
         {
             ops ++; //while comparison
             next += m[rcIndex(r, iNext, columns)] * m[rcIndex(iNext, c, columns)];
             ops += 3; //cost of the rcIndex function(operation in the return) and += operation
             iNext++;
             ops +=1;  //cost of the above two statement
         }
         ops ++;  //terminating while comparison
         result[rcIndex(r, c, columns)] = next;
         c++;
         ops += 2; //cost of above two statements
      }
       ops ++;  //terminating while comparison
       r++;
       ops ++;  //cost of above statement
   }
    ops ++; //terminating while loop
    return result;
}

// PARAM: arr is array to be sorted, n is size of array, i should initially = 0
void ssort(int arr[], int n, int i, int& ops)
{
   ops++ ; //cost of the if statement
   if (i < n-1)
   {
      // Find and swap smallest remaining
      int next = i + 1;
      int smallest = i;
      ops +=2; //cost of the above two statements
      while (next < n)  //b
      {
         ops ++;   //while comparison
         if (arr[next] < arr[smallest])
         {
            smallest = next;
         }
         next++;
         ops+=3; //cost of the above three statement
      }
      ops ++; //terminating while comparison
      // Swap i with smallest
      int temp = arr[i];
      arr[i] = arr[smallest];
      arr[smallest] = temp;
      ops += 3; //cost of above three statement
      ssort(arr, n, i + 1, ops);
   }
}
// PRE: n is a power of 2 greater than zero.
// PRE: Initial call should be to i = 0
// e.g. pattern(8, 0)
void pattern(int n, int i, int& ops)
{
   ops ++;  //cost of the below if statement
   if (n > 0)
   {
      pattern(n/2, i, ops);
      // Print i spaces
      cout << string(i, ' ');
      ops += 4; // << operation and string constructor has an operation of count of 3
      // A loop to print n asterisks, each one followed by a space
      int ast = 0;
      ops ++;      //cost of the above statement
      while (ast < n)
      {
         cout << "* ";
         ast++;
         ops += 3; //while comparison and above two statement
      }
      ops ++;  //terminating while comparison
      cout << endl;
      i += n;
      ops += 2; //cost of above two statements
      pattern(n / 2, i, ops);
   }
}
// Desc: Linear search.  Reports position if found, else -1
// Post:  Elements unchanged
int lsearch(int arr[], unsigned int len, int target, int& ops)
{
    if (len == 0)
    {
        ops ++;   //cost for the above if statement if it is true
        return -1;
    }
    ops ++;   //cost for the above if statement if it is not true
    if (arr[0] == target)
    {
        ops ++;   //cost for the above if statement if it is true
        return 0;
    }
    ops++; //cost for the above if statement if it is not true
    if (lsearch(arr+1, len-1, target, ops) == -1)
    {
        ops ++; //cost of the above if statement if it is true
        return -1;
    }
    else
    {
        ops ++; //cost of the above if statement if it is false
        ops ++; //cost of the + operation in the return statement
        return 1 + lsearch(arr+1, len-1, target, ops);
    }
} // lsearch

unsigned pow(unsigned int base, unsigned int exp, int& ops)
{
    unsigned int ubtret = 1;
    ops++; //cost of the above statement
    while (exp > 0)
    {
        ops ++; //cost of the while comparison
        if (exp & 1)
        {
            ubtret *= base;
        }
        ops +=2; //cost of the if statement and operation within if
        exp >>= 1;
        base = base * base;
        ops +=2;  //cost of the above two operations
    }
    ops ++;  //cost for the terminating while comparison
    return ubtret;
} // pow

