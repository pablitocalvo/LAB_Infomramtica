#include <iostream>
#include "mieclassi.cpp"

using namespace std;


int main(int argc, char **argv)
{
	char risposta ;
	
	do 
	{
		Partita p ;
		
		p.gioca();
		
		std::cout << "vuoi giocare ancora (Y/N) ? ";
		std::cin >> risposta ;
		
	} while ( risposta =='Y' );

	return 0;
}

