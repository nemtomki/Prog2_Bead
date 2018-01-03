#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <queue>
#include <algorithm>

using namespace std;
struct szoveg { //szerintem a structban inkább egy-egy aritmetikai utasításnak kéne csak lenine, nem az egész kódnak
    string fnev;
    stack<string> lkod;
    string gkod;
    vector<pair<bool, string> > registers; //van-e az adott regiszterben valami + a tartalma - az utóbbi azért string, mert inputon kapott változó is lehet benne
    int line_num; //sorok száma
};

struct sor{ //lehet így csinálom majd, még nem biztos
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

/*void sortatir (sor &pelda){
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
}*/



void regiszteres (szoveg &pelda)
{
//Áron kapja a lengyel formát: lengyel.txt ab^cd+a*+e-
//leforditja regiszteresre:
    stack<string> current = pelda.lkod;
    queue<string> operands;
    while(!current.empty()){
        string temp;
        if(! (isdigit(current.top()[0]) || isalpha(current.top()[0])) && ! current.top().empty()){
            string op1 = operands.front();
            operands.pop();
            string op2 = operands.front();
            operands.pop();
            int op1_reg = distance(pelda.registers.begin(), find_if(pelda.registers.begin(), pelda.registers.end(),
                [op1](const pair<bool,string>& elem) {return op1.compare(elem.second)==0;}))+1;
            int op2_reg = distance(pelda.registers.begin(), find_if(pelda.registers.begin(), pelda.registers.end(),
                [op2](const pair<bool,string>& elem) {return op2.compare(elem.second)==0;}))+1;
            string utasitas = "reg[" + to_string(op1_reg)+"] " + current.top() + " reg["+to_string(op2_reg) + "]";
            for(int i = 0; i < pelda.registers.size(); i++){
                if(pelda.registers[i].first == 0){
                    pelda.registers[i].first = true;
                    pelda.registers[i].second = utasitas;
                    temp += "reg[" + to_string(i+1) + "]";
                    operands.push(utasitas);
                    break;
                }
            }
            temp += " = " + utasitas + "\n";
            current.pop();
        }
        else if(!current.top().empty()){
            for(int i = 0; i < pelda.registers.size(); i++){
                if(pelda.registers[i].first == 0){
                    pelda.registers[i].first = true;
                    pelda.registers[i].second = current.top();
                    temp+="reg["+to_string(i+1)+"] = "+current.top()+"\n";
                    operands.push(current.top());
                    break;
                }
            }
            current.pop();
        }
        pelda.gkod += temp;
    }
    cout << pelda.gkod;
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
    pelda.registers = { {0, ""}, {0, ""}, {0, ""}, {0, ""}, {0, ""}, {0, ""}};
    pelda.lkod.push("*");
    pelda.lkod.push("2");
    pelda.lkod.push("+");
    pelda.lkod.push("1");
    pelda.lkod.push("3");
    //lengyel(pelda);
    regiszteres(pelda);
    //gepikod(pelda);
    return 0;
}
