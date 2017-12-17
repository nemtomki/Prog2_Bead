#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
=======
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
