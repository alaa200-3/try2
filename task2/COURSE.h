#ifndef COURSE_H
#define COURSE_H



#include<string.h>
#include<iostream>
#include "FCIvector.h"
using namespace std;
class COURSE {
private:
    string Course_name,Course_code;
    char Course_grade;
    float Course_point;
    int course_year,course_semester;
public:
    COURSE();
    friend istream & operator >> (istream &in,  COURSE &c);
    friend ostream & operator << (ostream &out,  COURSE &c);
    void course_info();
};

COURSE ::COURSE() {
}
istream & operator >> (istream &in, COURSE &c)
{
    cout << "course name: ";
    in >> c.Course_name;
    cout << "course code:";
    in >> c.Course_code;
    cout<<"course grade:";
    in>>c.Course_grade;
    cout<<"course point:";
    in>>c.Course_point;
    cout<<"course year:";
    in>> c.course_year;
    cout<<"course semester";
    in>> c.course_semester;
    return in;
}
ostream & operator <<(ostream &out, COURSE &c)
{
    out << "course name: ";
    out<< c.Course_name;
    out<<endl;
    out << "course code:";
    out<< c.Course_code;
    out<<endl;
    cout<<"course grade:";
    out<<c.Course_grade;
    out<<endl;
    out<<"course point:";
    out<<c.Course_point;
    out<<endl;
    out<<"course year:";
    out<< c.course_year;
    out<<endl;
    out<<"course semester";
    out<<c.course_semester;
    return out;
}

#endif // COURSE_H
