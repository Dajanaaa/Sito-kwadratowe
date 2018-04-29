#include <iostream>
#include<stdlib.h>
#include <vector>
#include <stdlib.h>
#include <math.h>


#include <unistd.h>
using namespace std;
 
typedef long long typ;


 
typ szybkie_pot(typ a, typ b, typ mod)
{
    
	typ x=a;
	typ n = b;
    vector <int> binarnie;
  
    while (n > 0)
    {
        binarnie.push_back(n % 2);
        n = n / 2;
    }
 
    
	typ wynik = 1;
   
    for (int i = 0; i<binarnie.size(); i++)
    {
        if (binarnie[i] == 1) 
        {
            wynik = wynik * x;
            wynik = wynik % mod;
        }
        x = x*x;
        x = x%mod;
    }
    return wynik;
   
}

 
 vector <typ> liczby_pierwsze(int B)
{
	vector <typ> pierwsza;
	
	int i,j;
	for(i = 2; i < B ; ++i)
	{
		bool liczba_pierwsza = true;
		for(int j = 2; j < i; ++j)
		{
			if(i%j == 0)
			{
				liczba_pierwsza  = false;
				break;
			}
		}
		if(liczba_pierwsza)
		{
			pierwsza.push_back(i);
		}
	}
	return pierwsza;
}

 
 
vector <typ> Baza(typ N ,vector <typ> Pierwsze)
{
	typ a,b;
	vector <typ>  baza_rozkladu;
    for (int i = 0; i < Pierwsze.size();i++)
    {
    b=(Pierwsze[i]-1)/2	;
    a=szybkie_pot(N,b,Pierwsze[i]);
        if(a==1)
        {
        	baza_rozkladu.push_back(Pierwsze[i]);
		}
    }
 

 return baza_rozkladu;
}

 
vector <typ> Sito(typ N,vector <typ> Pierwsze,vector <typ>baza_rozkladu)
{
	vector <int> dzielniki;
	vector<typ> gladkie;
	int k=3;
    typ a = sqrt(N) + 1 ;
    typ b = a * k;
   
 
    bool flaga = false;
    int licznik;
 
    
    for (int i = 0;i < baza_rozkladu.size();i++)
    {
        cout << "\t" << baza_rozkladu[i];
    }
    cout << endl<<endl;
 
    for (int i = a;i <= b;i++)
    {
        typ x = pow(i, 2) - N;
        typ tmp = x;
        flaga = false;
        licznik = 0;
        
        dzielniki.clear();
      	for (int i = 0;i < baza_rozkladu.size();i++)
    	{
        dzielniki.push_back(0);
   		 }
       
        while (flaga == false && licznik < baza_rozkladu.size())
        {
            if (x%baza_rozkladu[licznik] == 0)
            {
                x = x / baza_rozkladu[licznik];
                dzielniki[licznik]++;
            }
            else
            {
                licznik++;
            }
 
 
            if (abs(x) == 1) {
                cout << i;
                flaga = true;
 
                for (int i = 0;i < baza_rozkladu.size();i++)
                {
                    cout << "\t" << dzielniki[i];
                }
 
                gladkie.push_back(tmp);
                cout << endl;
            }
 
        }
    }
    
    return gladkie;
}
 
 
int main()
{
	
	vector <typ> baza_rozkladu;
	vector <typ> Pierwsze;
	vector <typ> gladkie;
	typ N, p;
	
    cout<<"Podaj liczbe N:"<<endl;
    cin>>N;
    typ B;
    
    B = pow(M_E,(sqrt(log(N) * log(log(N)) / 2 )));
    
	Pierwsze=liczby_pierwsze(B);
    baza_rozkladu=Baza( N ,Pierwsze);
    gladkie= Sito( N, Pierwsze,baza_rozkladu);
    
 
    system("PAUSE");
    return 0;
}
