
#include <iostream>

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
	cout << mat[r][c] << " ";
      cout << endl;
    }
  cout << endl;


  int r = 2;
  int c = 2;			// n/2+1 
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
