
/*
 data una matrice 
     quadrata 
     di dimensione dispari
 
 esempio: 
  5x5 con i seguenti valori:
  
  25  10  11  12  13                                                             
  24   9   2   3  14                                                             
  23   8   1   4  15                                                             
  22   7   6   5  16                                                             
  21  20  19  18  17                 
 
stampa gli elementi a spirale partendo da quello centrale  seguendo nord , est , sud ,ovest 

1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  
*/


#include <iostream>
#include<iomanip>

using namespace std;
#define N  5

int mat[N][N] = {
  {25, 10, 11, 12, 13},
  {24, 9, 2, 3, 14},
  {23, 8, 1, 4, 15},
  {22, 7, 6, 5, 16},
  {21, 20, 19, 18, 17}
};

int
main ()
{
  cout << "Hello World";
  cout << endl;
  for (int r = 0; r < N; r++)
    {
      for (int c = 0; c < N; c++)
	cout <<setw(3)<< mat[r][c] << " ";
      cout << endl;
    }
  cout << endl;


  int r = N/2;
  int c = N/2;			// n/2+1 
  cout << mat[r][c] << "  ";

  int ite = 2;

  while (ite < N)
    {
      r--;

//dx
      for (int i = 0; i < ite; i++)
	{
	  cout << mat[r][c] << "  ";
	  c++;
	}
      c--;

//giu 
      r++;
      for (int i = 0; i < ite; i++)
	{
	  cout << mat[r][c] << "  ";
	  r++;
	}
      r--;

//sx 
      c--;
      for (int i = 0; i < ite; i++)
	{
	  cout << mat[r][c] << "  ";
	  c--;
	}
      c++;

// su
      r--;

      for (int i = 0; i < ite; i++)
	{
	  cout << mat[r][c] << "  ";
	  r--;
	}
      r++;


      ite += 2;
    }


  return 0;
}
