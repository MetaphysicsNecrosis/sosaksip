#include <bits/stdc++.h>



#include <cstdlib> // For rand(), c rand() functions.
#include <ctime>
#include <clocale>

// Here, we're including our systems,
#include "WorkingClass.h"
#include "Functions.h"
#include "ORDER_FUNCTIONS.h"
using namespace std;



int main()
{

    // GLOBAL FUNCTION, DONT TUCH IT!!
    setlocale(LC_CTYPE, "rus"); // Function calling for definite local
    srand(static_cast<unsigned int>(time(0)));
    HASH_TABLE_FORMER();



    string s;
        {  // Document redrawing
        std::ifstream in("input.txt");
        std::ofstream out("output.txt");

        Rewrite(s, in, out);

        in.close();
        out.close();
        }

    ifstream in("output.txt");
    ForeignWords fwr[112];

    int i = 0;
    while(getline(in, s)){
        fwr[i] = s;
        i++;
        }


    in.close();


    queue<int> order;
    string answer, word;
    while(true){
        order_forming_BYTHEFOREIGN(fwr, order, 110);
        while(order.empty() != true){
            int index = order.front();
            order.pop();

            cout << fwr[index].translate << endl;
            getline(cin , answer);
            NumbersReg_delete(answer);

            if ( StringCheck(fwr[index].word, answer) == true )
                {

                fwr[index].relevant -=0.05;
                cout << "ПРАВИЛЬНО!" << endl;


                } else
                    {

                    fwr[index].relevant += 0.1;
                    cout << "Верно будет -> " << fwr[index].word  << endl;

                    }
            cout << endl;
            answer.clear();
            }

    }
    /*
      getline(cin, answer);
        NumbersReg_delete(answer);
     if (!StringCheck(answer, fwr[t].word)){
            cout << "Верно будет ->" << fwr[t].word;
            fwr[t].relevant += 0.05;
            }else{
                fwr[t].relevant -=0.1;
                cout <<"Правильно!";
                    }
        answer.clear();
        cout << endl;
        */









    return 0;
}
