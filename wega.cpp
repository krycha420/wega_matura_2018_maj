#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream plik;
    plik.open("sygnaly.txt");
    string tab [26];
    cout <<"4.1 ";
    string ntab [1001];
    for(int i =0; i<1001; i++)
    {
        ntab[i] = "";
    }
    for(int i =1; i<1001; i++)
    {
        plik>>ntab[i];
    }
    for(int k =1; k<1001; k++)
    {
        if(k%40==0)
        {


            tab[k/40] = ntab[k][9];
        }
    }
    for(int j=1; j<26; j++)
    {
        cout << tab[j];
    }

    ifstream plik2;
    plik2.open("sygnaly.txt");
    string slowo, jakie;
    int freq[26];
    int ile =0, ilemax=0;
    for(int i =0; i<1000; i++)
    {

        plik2>>slowo;
        ile =0;
        for (int x = 0; x < 26; x++)
        {
            freq[x] = 0;
        }

        for(int j =0; j< slowo.length(); j++)
        {

            freq[slowo[j] - 'A']++;
        }

        for (int y=0; y<26; y++)
        {
            if(freq[y]>0)
            {
                ile++;
            }
        }
        if(ile >ilemax)
        {
            ilemax =ile;
            jakie = slowo;

        }

    }
    cout <<" "<<    endl;
    cout<<"4.2 "<< ilemax << " " << jakie<< endl;
    cout <<"4.3 "<< endl;
    ifstream plik3;
    ofstream wynik;
    wynik.open("wyniki.txt");
    string noweslowo;
    int licznik =0;
    plik3.open("sygnaly.txt");
    for(int z =0; z<1000; z++)
    {
        plik3>>noweslowo;

        licznik =0;
        for(int h =0; h<noweslowo.length(); h++)
        {
            for(int k =0; k<noweslowo.length(); k++)
            {
                if(noweslowo[h]-noweslowo[k]>10)
                    licznik++;
            }
        }
        if(licznik==0)
        {
            wynik << noweslowo << endl;
            cout << noweslowo << endl;
        }
    }
}
