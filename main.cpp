#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;
struct szoveg { //szerintem a structban inkább egy-egy aritmetikai utasításnak kéne csak lenine, nem az egész kódnak
 string fnev;
 stack<string> lkod;
 string gkod;
 vector<pair<bool, double> > registers; //van-e az adott regiszterben valami
 int line_num; //sorok száma
};

struct sor{
 string valtozonev;
 stack<string> lkod;
	string atirt;
 int regiszter; //0, ha memóriában van tárolva
 int memo; //0, ha regiszterben van tárolva
};

void lengyel (szoveg &pelda)
{
// Peti, kapok .txt fájlt, aminél a példa legyen:  proba.txt VALAMI=a^b+(c+d)*a-e
// ezt leforditom lengyel formává:  példa.lkod={VALAMI;-e+*a+dc^ba}

}

void sortatir (sor &pelda){
	stack<string> curr = pelda.lkod;
	string res;
    while(!curr.empty()){
        if(isdigit(curr.top()[0])){

        }
        else if(isalpha(curr.top()[0])){

        }
        else{

        }
    }
}

void regiszteres (szoveg &pelda)
{
//Áron kapja a lengyel formát: lengyel.txt ab^cd+a*+e-
//leforditja regiszteresre:
    stack<string> current = pelda.lkod;
    if(!current.empty()){
        string resultname = current.top();
        current.pop();
    }
    while(!current.empty()){
        string temp;
        string operand_1;
        string operand_2;
        if(strtod(current.top().c_str(), NULL)==0.0){
            temp+="reg[1]"+current.top()+"reg[2];";
            current.pop();
        }
        else {
            for(int i = 0; i < pelda.registers.size()-1; i++){
                if(pelda.registers[i].first != true){
                    pelda.registers[i].first = true;
                    pelda.registers[i].second = strtod(current.top().c_str(), NULL);
                    temp+="reg["+to_string(i+1)+"]="+current.top();
                    current.pop();
                }
            }
        }
        pelda.gkod+=temp;
    }
}



void gepikod (szoveg &pelda)

{
//Laci a kapott gépi kódot, kiszámolja:
//eredmény , adott példákkal:  a=1; b=2; c=3; d=4; e=5;   erre lesz VALAMI=4, gepivel meg simával is
}


int main()
{
    szoveg pelda;
   // pelda.fnev=''proba.txt'';
    lengyel(pelda);
    regiszteres(pelda);
    gepikod(pelda);
    return 0;
}
