/*
 * mieclassi.cpp
 * 
 * Copyright 2017 pablitocalvo
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
 
#include <string>
#include <iostream>
using namespace std ;

class Carta
{
private:

	static const int COPERTA  =0;
	static const int SCOPERTA =1;
	static const int FUORI    =2;
	
	char valore ;  // valori A B C D E F G H I L 
	int  stato ;  // valori 0 coperta, 1 is_scoperta,  2 is_fuori 
	
	
public:
  
  Carta(char c )
  {	
	  valore = c;
	  stato  = COPERTA;
  } 
  
  char get_valore()
  { 
	  return valore ;
  }
  
  bool is_fuori()
  {
	  return ( stato == FUORI );
  }
   
  bool is_scoperta()
  {
	return ( stato == SCOPERTA );
  }
  
  void viene_tolta_dal_tavolo()
  {
	  stato= FUORI;	
  }
  
  void viene_scoperta()
  {
	  stato= SCOPERTA;	
  }
  void viene_coperta()
  {
	  stato= COPERTA;	
  }
  bool is_coperta()
  {
	  return ( stato == COPERTA );
  }
  
  bool is_uguale_a ( Carta * c )
  { 
	  return ( valore == c->get_valore() ) ;
  }
  
  
} ;





class Partita
{	const int numero_carte_del_gioco=10;
	int numero_carte_sul_tavolo=10 ; 
	
	// TODO : generare una didtribuzione casuale ...
	Carta  mazzo_carte[ 10 ] = { Carta('A') , Carta('B') , Carta('C'),
								 Carta('D') , Carta('E') , Carta('A'),
								 Carta('B') , Carta('C') , Carta('D'),
								 Carta('E') };
	
public:

Partita ()
	{	
		stampa_le_carte_sul_tavolo();
	};
	
~Partita ()
	{
	 cout<<"alla prossima partita \n";
	}


	void stampa_le_carte_sul_tavolo()
	{	
		// su windows usare system("cls");
		// su LINUX  usare system("clear");
		
		system("cls");
	
		cout << endl ;
		
		for (int i = 0 ; i < numero_carte_del_gioco; ++i)
		{
			if ( mazzo_carte[i].is_fuori() ) 
				cout<< "    " ;
			else cout << i<<"   ";
		};
		
		cout << endl;
		
		for (int i = 0 ; i < numero_carte_del_gioco ; ++i)
		{
			if ( mazzo_carte[i].is_fuori() ) 
			    {    cout << "    " ; continue;}
		    
		    if ( mazzo_carte[i].is_coperta() )
				{	 cout<< "X   " ; continue; }
		    
		    cout << mazzo_carte[i].get_valore() << "   " ;
			
		}	;
		cout << endl;
	}	
		
	Carta * una_carta_scelta_e_scoperta_dallo_utente()
	{  
		int i;
	 
	   do 
	   {
		  cout<<"scegli una carta";
		  cin>>i ;
	   } while ( ! mazzo_carte[i].is_coperta() );
	   
	   mazzo_carte[i].viene_scoperta();
	   
	   stampa_le_carte_sul_tavolo();
	   
	   return & mazzo_carte[i];
	   
	}	
				
	void gioca()
	{ 	
		bool partita_finita = false;
		Carta *carta1 ;
		Carta *carta2 ; 
		do
		{ 	
			
			carta1=una_carta_scelta_e_scoperta_dallo_utente();
			carta2=una_carta_scelta_e_scoperta_dallo_utente();
					
			if ( (*carta1).is_uguale_a(carta2) )
			{   
				(*carta1).viene_tolta_dal_tavolo() ;
				(*carta2).viene_tolta_dal_tavolo() ;
				
				numero_carte_sul_tavolo = numero_carte_sul_tavolo - 2 ;
				
				if (numero_carte_sul_tavolo == 0 ) 
					partita_finita = true;
			}
			else
			{ 
				(*carta1).viene_coperta();
				(*carta2).viene_coperta();
				
			}

		} while ( ! partita_finita );

	}
};

