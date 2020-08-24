#ifndef LG_FUNCTIONS_H_
#define LG_FUNCTIONS_H_

#include "iostream"
#include "vector"
#include "map"
#include "string"
#include "stdlib.h"
#include "algorithm"

using namespace std;

    // functions
    int linear_search (map <int, Names>::iterator it_begin, map <int, Names>::iterator it_end, string s) {
    // needit s1;

    for (int i = 0; it_begin != it_end; it_begin++, i++ ) {
        if ( it_begin->second.check_name(s) == 1 ) {
            return i;
        }
    }
    return -1;
}

    void check_max( double x) {
    if ( x >= 24 )
        throw string{"Entered value is equal to or exceeds maximum value allowed."};
    if ( x<=0 )
        throw string("Entered value is too less to be added.");
}

    void change_loop (map <int, Names> &tasks, double multi, double div) {
    double change;

    for (auto it = tasks.begin(); it != tasks.end(); it++ ) {
        change = double( it->second.get_hrs()*multi )/div;
        it->second.change_hrs(change);
    }
}

    int add ( map <int, Names> &tasks, string s,  double x ) {

    try {
        check_max(x);
    }
    catch (string y) {
        cout<<"Error message : "<<y;
        return 0;
    }

    int pos = linear_search(tasks.begin(), tasks.end(), s);
    int string_num = stoi_r(s);
    int flag = 0;

    double TEMP{24-x}, temp2;

    if (pos != -1) {
        temp2 = 24 - tasks.find(pos)->second.get_hrs();

        cout<<"\nUpdating existing task: "<<s<<" ( "<<24-temp2<<" hrs ) to : "<<x<<" hrs\n";

        change_loop (tasks, TEMP, temp2);
        tasks.find(pos)->second.write(x);
        return 1;
    }
    else if (string_num != -1) {
        pos = string_num;
        temp2 = 24 - tasks.find(pos)->second.get_hrs();

        cout<<"\nUpdating existing task: "<<tasks.find(pos)->second.get_name()<<" ( "<<24-temp2<<" hrs ) to : "<<x<<" hrs\n";

        change_loop (tasks, TEMP, temp2);
        tasks.find(pos)->second.write(x);
        return 1;
    }
    else {
        pos = tasks.size();
        temp2 = 24;
        cout<<"\nAdding new task: "<<s<<" ( "<<x<<" hrs )";

        if (pos == 1) {
            tasks.insert( make_pair( pos, Names(s, 24 - tasks.begin()->second.get_hrs() ) ) );
        }
        else {

            change_loop (tasks, TEMP, temp2);
            tasks.insert(make_pair(pos, Names(s, x)));
        }
        return 1;
    }
}

    
#endif