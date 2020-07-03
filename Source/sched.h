#ifndef SCHED_H_
#define SCHED_H_

#include "iostream"
#include "vector"
#include "map"
#include "string"
#include "stdlib.h"
#include "algorithm"

using namespace std;

    // functions
    int stoi_r (string s) {
    if ( (s[0] >=97 && s[0] <=122) || (s[0]>=65 && s[0]<=90) )
        return -1;
    else
        return stoi(s);
    }

    class Names {
        string name;
        double hrs;
    public:
        Names () {
        }

        Names (string new_name, double new_hrs):
        name(new_name), hrs(new_hrs) {
        }

        friend ostream &operator<<(ostream  &out, Names const &other) {
          out<<other.name<<" : "<<other.hrs;
          return out;
        }

        double get_hrs () {
            return hrs;
        }

        string get_name () {
            return name;
        }

        void change_hrs ( double change) {
            this->hrs = change;
        }

        bool check_name ( string s ) {
            return (s == this->name);
        }

        void write (double d) {
            this->hrs = d;
        }
    };
#endif
