#include <bits/stdc++.h>



#include <cstdlib> // For rand(), c rand() functions.
#include <ctime>
#include <clocale>

// Here, we're including our systems,
#include "WorkingClass.h"
#include "Functions.h"

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

    while(true){
        string answer;
        int t = rand()&110;
        cout << "�������� �������: " << fwr[t].translate << endl;
        getline(cin, answer);
        NumbersReg_delete(answer);
        if (!StringCheck(answer, fwr[t].word)){
            cout << "����� ����� ->" << fwr[t].word;
            }else cout <<"���������!";
        answer.clear();
        cout << endl;

    }









    return 0;
}
