#ifndef ORDER_FUNCTIONS_H_INCLUDED
#define ORDER_FUNCTIONS_H_INCLUDED
#include <bits/stdc++.h>


#include "Functions.h"
#include "WorkingClass.h"


#include <cstdlib> // For rand(), c rand() functions.
#include <ctime>
#include <clocale>

using namespace std;

void order_forming_BYTHEFOREIGN(ForeignWords *A, queue<int> &B, int words_count)
{

// SYSTEM (every step they will appear -> )
                    // 5[ here  1 ... 3 here ] 4[ 1 ... 4 ] 3,2[ 1 .. 5 ] 1[ means - step by step, single appear ]

        // 5 ARRAY forming by relevant more than(and equal) 2 <- high
        // 4 ARRAY forming by relevant more than 1, less than 2 <- medium
        // 3 ARRAY forming by relevant more than 0, less than 1 <- low





    srand(static_cast<unsigned int>(time(0)));
    vector<int>HIGHPRIORITY_ORDER, MEDIUMPRIORITY_ORDER, LOWPRIORITY_ORDER;
    bool USED[words_count+1] = {false};

    for (int i = 0;i < words_count;i++)
        {

        if( A[i].relevant >= 2 ) HIGHPRIORITY_ORDER.push_back(i);
        if( A[i].relevant >= 1 && A[i].relevant < 2 ) MEDIUMPRIORITY_ORDER.push_back(i);
        if( A[i].relevant > 0 ) LOWPRIORITY_ORDER.push_back(i);

        }


    // Lets form out order >
    int index = 0, High_step = 0, Medium_step = 0, Low_step;

    for(int step = 1;step <= words_count;step++)
        {

        if( High_step >= HIGHPRIORITY_ORDER.size() ) High_step = 0;
        if( Medium_step >= MEDIUMPRIORITY_ORDER.size() ) Medium_step = 0;
        if( Low_step >= LOWPRIORITY_ORDER.size() ) Low_step = 0;


        while(USED[index] == true)
            {index = rand()%110;}
        USED[index] = true;
        B.push( index );

        if( ( step%3 == 0 ) && ( HIGHPRIORITY_ORDER.empty() != true ) )
            {

                B.push( HIGHPRIORITY_ORDER[High_step] );
                ++High_step;

            }
        if( ( step%4 == 0 ) && ( MEDIUMPRIORITY_ORDER.empty() != true ) )
             {

                B.push( MEDIUMPRIORITY_ORDER[Medium_step] );
                ++Medium_step;

            }
        if( ( step%5 == 0 )&&( LOWPRIORITY_ORDER.empty() != true ) )
            {

                B.push( LOWPRIORITY_ORDER[Low_step] );
                ++Low_step;

            }

        }

}

void sortingByRelevant(ForeignWords *A, int final_value)
{
    int pos_max = 0, index_max = 0, past_max = 0;
    while ( pos_max < final_value ){
        for( int i = pos_max;i < final_value;i++ ){
            if (past_max < A[i].relevant){
                past_max = A[i].relevant;
                index_max = i;
                }
            }
        // replace
        ForeignWords t;
        t = A[index_max];
        A[index_max] = A[pos_max];
        A[pos_max] = t;

    }
}


int find_most_irrelevant(ForeignWords *a, int final_value)
{
    int answer = 0;

    for( int i = 0;i < final_value;i++ )
        {
        if( a[answer].relevant < a[i].relevant )answer = i;
        }

    return answer;
}

#endif // ORDER_FUNCTIONS_H_INCLUDED
