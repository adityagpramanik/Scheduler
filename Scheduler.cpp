#include "sched.h"

// functions declaration

// linear_search() searches for  string passed to it in tasks list(map)
int linear_search (map <int, Names>::iterator it_begin, map <int, Names>::iterator it_end, string s);

// check_max() is an exception handler which throws error if value provided value is negative or greater/equal to 24
void check_max( double );

// change_loop() changes the value of tasks elements
void change_loop (map <int, Names> &tasks, double, double);

// add() simply adds a task in tasks by name or position of the string
int add ( map <int, Names> &tasks, string, double );

// main function
int main () {
    map <int, Names> tasks;
    int flag = 0;
    double temp;
    string s;

    cout<<"+++++++++++++++                                               ++++++++++++++++++\n";
    cout<<"+++++++++++++++ Scheduler.cpp : Come and analyse your schedule++++++++++++++++++\n";
    cout<<"+++++++++++++++                                               ++++++++++++++++++\n\n";

    cout<<"\nEnter task name and hours:";

    while (cin>>s>>temp) {
        flag = add(tasks, s, temp);
        double sum{0.0};

        if(flag == 0 || s == "n" || s == "exit") {
            cout<<"\nquitting.";
            return 0;
        }
        else {
            cin.peek();
            system("clear");
            for (auto it = tasks.begin(); it != tasks.end(); it++ ) {
                cout<<it->second<<endl;
            }
        }
        cout<<"\nEnter task name and hours: ";
    }
    cout<<"\nquitting.";
    return 0;
}

// function defination
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
