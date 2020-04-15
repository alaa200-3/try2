#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <string>
#include "COURSE.h"
#include "FCIvector.h"
using namespace std;
class STUDENT {
private:
    string sName,sDepartment;
    int  sID;
    int num_ofcourses=0;
   FCIvector< COURSE>  course;
public:
    STUDENT();
    friend istream & operator >> (istream &in,  STUDENT &s);
    friend ostream & operator << (ostream &out,  STUDENT &s);
};
STUDENT::STUDENT()

{}
istream & operator >> (istream &in,  STUDENT &s)
{   int n;
    COURSE co;
    cout << "name: ";
    in >> s.sName;
    cout << "department";
    in >> s.sDepartment;
    cout<<"ID";
    in>>s.sID;
    cout<<"enter number of course you want to add\n";
    in>>n;
    for(int i=0;i<n;i++){
        s.num_ofcourses++;
        in>>co;
        s.course.push_back(co);
    }
    return in;
}
ostream & operator << (ostream &out,  STUDENT &s)
{
    out << "name: ";
    out << s.sName;
    out<<endl;
    out << "department:";
    out<< s.sDepartment;
    out<<endl;
    out<<"ID:";
    out<<s.sID;
    out<<endl;
    for(int i=0;i<s.num_ofcourses;i++){
        cout<<s.course[i];
    }
    return out;
}





#endif // STUDENT_H
