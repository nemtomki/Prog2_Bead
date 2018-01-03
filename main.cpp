#include <iostream>
#include <vector>
#include <struct>
#include <string>
using namespace std;

struct darab
{
    string nev;
    stack<string> lkod;
 //ha vmi kell meg ide irjatok batran;
};
struct szoveg {
 string fnev;
 vector<darab>;
} ;

void lengyel (szoveg &pelda)
{
// pelda.txt-t csatoltam, mint minta
// 
{
    fstream f,g;
    f.open("proba.txt");
    g.open("proba.txt");
    string aktu;
    string eredet;
    char szam;
    darab elso;
    string vissza;
    stack<char> verem;
    while (f.good())
    {
        elso.lkod=stack<string>();
        getline(g,eredet,';');
        cout << eredet << endl;
        getline(f,aktu,'=');
        elso.nev=aktu;
        cout << aktu<< endl;
        szam='.';
        while (szam!=';' )
        {
            f >> szam;
            if (szam=='*' || szam=='/' )
            {
                while (!verem.empty() && verem.top()!='(' && verem.top()!='+' && verem.top()!='-')
                {
                    cout << verem.top();
                    vissza=verem.top();
                    elso.lkod.push(vissza);
                    verem.pop();
                }
                verem.push(szam);
            }
            else
            {
                if (szam=='+' || szam=='-' )
                {
                    while (!verem.empty() && verem.top()!='(' )
                    {
                        cout << verem.top();
                        vissza=verem.top();
                        elso.lkod.push(vissza);
                        verem.pop();
                    }
                    verem.push(szam);
                }
                else
                {

                    if (szam==')')
                    {
                        while (verem.top()!='(')
                        {
                            cout << verem.top();
                            vissza=verem.top();
                            elso.lkod.push(vissza);
                            verem.pop();
                        }
                        verem.pop();
                    }
                    else
                    {
                        if (szam=='(')
                        {
                            verem.push('(');
                        }
                        else
                        {
                            if (szam==';')
                            {
                                ;
                            }
                            else
                            {
                                cout << szam;
                                vissza=szam;
                                elso.lkod.push(vissza);
                            }
                        }
                    }
                }
            }
        }
        while (!verem.empty())
        {
            cout << verem.top();
            vissza=verem.top();
            elso.lkod.push(vissza);
            verem.pop();
        }
        cout << endl;
        pelda.komplett.push(elso);
        f >> ws;
    }

}

}

void regiszteres (szoveg &pelda)
{
//Áron kapja a lengyel formát: lengyel.txt ab^cd+a*+e-
//leforditja regiszteresre:
}


void gepikod (szoveg &pelda)

{
//Laci a kapott gépi kódot, kiszámolja:
//eredmény , adott példákkal:  a=1; b=2; c=3; d=4; e=5;   erre lesz VALAMI=4, gepivel meg simával is
}


int main()
{
    szoveg pelda;
    pelda.fnev=''proba.txt'';
    lengyel(pelda);
    regiszteres(pelda);
    gepikod(pelda);
    return 0;
}
