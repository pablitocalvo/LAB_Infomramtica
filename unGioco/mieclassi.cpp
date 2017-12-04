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
  
  bool is_uguale_a ( Carta* c )
  { 
	  return ( valore == c->get_valore() ) ;
  }
  
  
} ;





class Partita
{
	int carte_sul_tavolo=10 ; 
	
	// TODO : generare una didtribuzione casuale ...
	Carta  mazzo_carte[ 10 ] = { Carta('A') , Carta('B') , Carta('C'),
								 Carta('D') , Carta('E') , Carta('A'),
								 Carta('B') , Carta('C') , Carta('D'),
								 Carta('E') };
	
public:

Partita ()
	{	
		stampa_le_carte();
	};
	
~Partita ()
	{
	 cout<<"alla prossima partita \n";
	}


	void stampa_le_carte()
	{	
		// su windows usare system("cls");
		// su LINUX  usare system("clear");
		
		system("cls");
	
		cout << endl ;
		
		for (int i = 0 ; i < carte_sul_tavolo; ++i)
		{
			cout<< i << "   " ;
		};
		
		cout << endl;
		
		for (int i = 0 ; i < carte_sul_tavolo ; ++i)
		{
			if ( mazzo_carte[i].is_fuori() ) 
			    {    cout << "    " ; continue;}
		    
		    if ( mazzo_carte[i].is_coperta() )
				{	 cout<< "X   " ; continue; }
		    
		    cout << mazzo_carte[i].get_valore() << "   " ;
			
		}	;
		cout << endl;
	}	
		
	Carta * una_carta_scelta_dallo_utente()
	{  
		int i;
	 
	   do 
	   {
		  cout<<"scegli una carta";
		  cin>>i ;
	   } while ( ! mazzo_carte[i].is_coperta() );
	   
	   mazzo_carte[i].viene_scoperta();
	   
	   stampa_le_carte();
	   
	   return & mazzo_carte[i];
	   
	}	
				
	void gioca()
	{ 	
		bool partita_finita = false;
		Carta *carta1 ;
		Carta *carta2 ; 
		do
		{ 	
			
			carta1=una_carta_scelta_dallo_utente();
			
			carta2=una_carta_scelta_dallo_utente();
					
			if ( (*carta1).is_uguale_a(carta2) )
			{   
				(*carta1).viene_tolta_dal_tavolo() ;
				(*carta2).viene_tolta_dal_tavolo() ;
				
				carte_sul_tavolo = carte_sul_tavolo - 2 ;
				
				if (carte_sul_tavolo == 0 ) 
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

