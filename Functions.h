#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <bits/stdc++.h>
#include "WorkingClass.h"

using namespace std;



int const n = 2;
int hash_table[12];
void HASH_TABLE_FORMER(){
    hash_table[0] = 2;
    for(int i = 1;i < 12;i++)hash_table[i] = hash_table[i-1]*n;
}



void reReg_char(char& a){
    if (a >= 'A' && a <='Z')a += 32;
    if (a >= 'À' && a <= 'ß')a +=32;
}
void NumbersReg_delete(string& s){ // will delete every number(and point) in the document
    for(int i = 0;i < s.size();i++)
        {
        reReg_char(s[i]);
        if(s[i] >= '0' && s[i] <='9'){
            s.erase(i, 1);
            --i;
            }

        if(s[i] == '.'){
            s.erase(i, 1);
            --i;
            }
        }//22
}
// Rewrite overloading ->
void Rewrite(string& s, ifstream &in, ofstream &out)
{
    // It use to construct new file
    while(in){
        getline(in, s);
        NumbersReg_delete(s);
        for(auto iter = s.begin(); iter != s.end();++iter){out <<*iter;}
        out << endl;
    }
}

ForeignWords Rewrite(string &s, ifstream &in)
{
    // It use to rewrite out new file that was rewritten
    getline(in, s);
    ForeignWords w(s);
    cout << w.translate << " " <<w.word << endl;
    s.erase();
    return w;

}
// <- Rewrite overloading


bool StringCheck(string& s, string& t){
    // Simple function for strings


    int fword = 0, sword = 0;

    int i1 = 0;
    for(int i = 0;i < s.size();i++){
            (s[i]!= ' ')&&(fword += (hash_table[i1]*s[i])%INT_MAX);
            fword %= INT_MAX;
            if(i1 >= 11)i1 = 0;
            }
    i1 = 0;
    for(int i = 0;i < t.size();i++){
            (t[i]!= ' ')&&(sword += (hash_table[i1]*t[i])%INT_MAX);
            sword %= INT_MAX;
            if(i1 >= 11)i1 = 0;
            }

    if(fword == sword)return true;

    return false;
}



#endif // FUNCTIONS_H_INCLUDED
