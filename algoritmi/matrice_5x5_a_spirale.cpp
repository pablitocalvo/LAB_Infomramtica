/*
 data una matrice 
     quadrata 
     di dimensione 5X5
 
 esempio: 
  con i seguenti valori:
  
  25  10  11  12  13                                                             
  24   9   2   3  14                                                             
  23   8   1   4  15                                                             
  22   7   6   5  16                                                             
  21  20  19  18  17                 
 
stampa gli elementi a spirale partendo da quello centrale  seguendo nord , est , sud ,ovest 

1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  
*/


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
	
	cout<< mat[2][2] << " ";

	cout<< mat[1][2] << " ";
	cout<< mat[1][3] << " ";

	cout<< mat[2][3] << " ";
	cout<< mat[3][3] << " ";

	cout<< mat[3][2] << " ";
    cout<< mat[3][1] << " ";

	cout<< mat[2][1] << " ";
    cout<< mat[1][1] << " ";
    
    
    cout<< mat[0][1] << " ";
    cout<< mat[0][2] << " ";
	cout<< mat[0][3] << " ";
    cout<< mat[0][4] << " ";
    
    cout<< mat[1][4] << " ";
    cout<< mat[2][4] << " ";
	cout<< mat[3][4] << " ";
    cout<< mat[4][4] << " ";
    
    cout<< mat[4][3] << " ";
    cout<< mat[4][2] << " ";
	cout<< mat[4][1] << " ";
    cout<< mat[4][0] << " ";
    
    cout<< mat[4][0] << " ";
    cout<< mat[3][0] << " ";
	cout<< mat[2][0] << " ";
    cout<< mat[1][0] << " ";
    
    
    

    
}
