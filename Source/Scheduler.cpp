#include "sched.h"
#include "lg_functions.h"

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