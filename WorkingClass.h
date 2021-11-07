#ifndef WORKINGCLASS_H_INCLUDED
#define WORKINGCLASS_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;


class ForeignWords{
    public:
        string  word = "", translate = "";


        double relevant = 0;

        ForeignWords() = default;



        ForeignWords& operator=(const ForeignWords& firstFW){// copy constructor
            this->word = firstFW.word;
            this->translate = firstFW.translate;
            this->relevant = firstFW.relevant;
        }
        ForeignWords& operator=(const string& s){// copy constructor


            int i = 0, lenght = s.size()-1;
                this->word.erase();
                this->translate.erase();


            while(s[i] != '-'){
                this->word += s[i];
                if(i > 100){
                    this->word = "error";
                    this->translate = "errorr";
                    break;
                    }
                i++;
                }

            i+= 2;
            while(i <= lenght){
                this->translate += s[i];
                i++;
                }

        }




        ForeignWords(const string &word ,const string &translate ){
        this->translate = translate;
        this->word = word;
            }
        ForeignWords(const string &s) //
            { //Initialization by the (doc)string/two words
            int i = 0, lenght = s.size()-1;
                this->word.erase();
                this->translate.erase();


            while(s[i] != '-'){
                this->word += s[i];
                if(i > 100){
                    this->word = "error";
                    this->translate = "errorr";
                    return;
                    }
                i++;
                }

            this->word.erase((this->word).size()-1);
            i+= 2;
            while(i <= lenght){
                this->translate += s[i];
                i++;
                }
            }


/// distructor needs tilda before its name
    private:
};


#endif // WORKINGCLASS_H_INCLUDED
