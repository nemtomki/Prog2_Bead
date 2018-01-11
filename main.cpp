#include <iostream>
#include <vector>
#include <struct>
#include <string>
using namespace std;
struct szoveg {
string fnev;
 stack<string> lkod;
 string gkod;
} ;
void lengyel (szoveg &pelda)
{
// Peti, kapok .txt fájlt, aminél a példa legyen:  proba.txt VALAMI=a^b+(c+d)*a-e
// ezt leforditom lengyel formává:  példa.lkod={VALAMI;-e+*a+dc^ba}
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include  <stdio.h>
#include  <ctype.h>

using namespace std;

struct darab
{
    string nev;
    stack<string> lkod;
};
struct szoveg
{
    string fnev;
    stack<darab> komplett;
};
void lengyel (szoveg &pelda)
{
    fstream f,g,h;
    f.open("proba.txt");
    g.open("proba.txt");
    h.open("proba.txt");
    string aktu;
    char aktu2;
    bool alnum;
    string eredet;
    string szam;
    darab elso;
    string vissza;
    vissza="";
    stack<string> verem;
    alnum=1;
    while (f.good())
    {
        elso.lkod=stack<string>();
        getline(g,eredet,';');
        cout << eredet << endl;
        getline(f,aktu,'=');
        elso.nev=aktu;
        cout << aktu<< endl;
        getline(h,aktu,'=');
        szam=".";
        while (szam!=";" )
        {
            f >> aktu2;
            szam=aktu2;
            if (szam=="*" || szam=="/" )
            {
                while (!verem.empty() && verem.top()!="(" && verem.top()!="+" && verem.top()!="-")
                {
                    cout << verem.top();
                    elso.lkod.push(verem.top());
                    verem.pop();
                }
                verem.push(szam);
                 alnum=0;
            }
            else
            {
                if (szam=="+" || szam=="-" )
                {
                    while (!verem.empty() && verem.top()!="(" )
                    {
                        cout << verem.top();
                        elso.lkod.push(verem.top());
                        verem.pop();
                    }
                    verem.push(szam);
                     alnum=0;
                }
                else
                {

                    if (szam==")")
                    {
                        while (verem.top()!="(")
                        {
                            cout << verem.top();
                            elso.lkod.push(verem.top());
                            verem.pop();
                        }
                        verem.pop();
                         alnum=0;
                    }
                    else
                    {
                        if (szam=="(")
                        {
                            verem.push("(");
                             alnum=0;
                        }
                        else
                        {
                            if (szam==";")
                            {
                                 alnum=1;
                            }
                            else
                            {
                                if (!alnum || szam==";")
                                {
                                   cout << vissza;
                                   elso.lkod.push(vissza);
                                   vissza="";
                                   alnum=1;
                                }
                                else
                                {
                                    if (alnum)
                                    {
                                        vissza+=szam;
                                    }
                                }


                            }
                        }
                    }
                }
            }
        }
        while (!verem.empty())
        {
            cout << verem.top();
            elso.lkod.push(verem.top());
            verem.pop();
        }
        cout << endl;
        pelda.komplett.push(elso);
        f >> ws;
    }

}

int main()
{
    szoveg pelda;
    pelda.fnev="proba.txt";
    lengyel(pelda);
    cout << pelda.fnev ;
    return 0;

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
