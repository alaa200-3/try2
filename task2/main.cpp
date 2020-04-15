
/*****************************************************
 Name:: Alaa Adel Mohamed Soliman
 ID:: 20180050
 G:: 1
 Assignment :: #3
 **************************************************** */

#include <iostream>
#include "FCIvector.h"
#include "COURSE.h"
#include "STUDENT.h"
#include <string>
using namespace std;

template <class T>
void operations_of_fcivector(T val) {
    FCIvector<T> s; //take object from class fci using data type which coming from  T val
    int n, option, another_option;
    do {
        cout << "What kind of operation would you like to perform?\n"
                "    1. Add element.\n" //push_back();
                "    2. Remove last element.\n" //pop_back();
                "    3. Insert element at certain position.\n" //insert();
                "    4. Erase element from a certain position.\n"// erase();
                "    5. Clear.\n" //clear();
                "    6. Display first element.\n" // front();
                "    7. Display last element.\n" // back();
                "    8. Display element at certain position.\n"//operator[]();
                "    9. Display vector size.\n"      //size();
                "    10. Display vector capacity.\n" //capacity();
                "    11. Is empty?" << endl;
        cin >> option;
        if (option == 1) {

            cout << "enter number of element you want to add:";
            cin >> n;
            cout << "enter your elements" << endl;
            for (int i = 0; i < n; i++) {
                T val2;
                cin >> val2; //take val from user;
                s.push_back(val2);//push val to the arry elements
            }
        }
                if (option == 2) {
                    if(s.size()==0) cout<<"the array is empty\n";
                      else {
                        int n;
                        cout << "enter number of element you want to delete from last array: ";
                        cin >> n;
                        for (int i = 0; i < n; i++) {
                            s.pop_back();
                        }
                    }
        }

        if (option == 3) {
            if(s.size()==0) cout<<"the array is empty\n";
                else {
                int i;
                T val3;
                cout << "enter the position :";cin>>i;
                while(i>=s.size()||i<0){
                      cout<<"the index is out of the range\nenter again";
                      cin>>i;
                      }
               cout<<"enter value:";
                cin >> val3;
                s.insert(s.begin() + i, val3);
                }
        }

        if (option == 4) {
            if (s.size() == 0) cout << "the array is empty\n";
            else {
                int i;
                cout << "enter index";
                cin >> i;
            while(i>=s.size()||i<0){
                      cout<<"the index is out of the range\nenter again";
                      cin>>i;
                      }
                s.erase(s.begin() + i);

            }
        }
        if (option == 5) {
            s.clear();
            cout << "the array is cleared successfully\n";
        }

        if (option == 6) {
            if(s.size()==0) cout<<"the array is empty\n";
            else cout << s.front();
        }
        if (option == 7)
        {
            if(s.size()==0) cout<<"the array is empty\n";
            else  cout << s.back();
        }
        if (option == 8) {
            if (s.size() == 0)cout << "the array is empty\n";
            else {
                int n;
                cout << " enter index of element you want to get from 0 to num of elements-1\n";
                cin >> n;
                cout << s.operator[](n);
            }
        }
            if (option == 9)  cout<<"size of vector is:"<<  s.size();
            if (option == 10) cout<<"capacity of vector is:"<< s.capac();
            if (option == 11) cout << s.empty();
            cout << "\n do you want to choose another option enter 1 for yes or 0 for no :";
            cin >> another_option;
        }

    while (another_option == 1);

}
//------------------------------------------------------------------------------------------------//
int main() {
    int type, another_type, y; //y :for return a data type of int to the fcivector
    char c;        //for return a data type of char to the fcivector
    string s;      //for return a data type of string to the fcivector
    float f;       //for return a data type of float to the fcivector
    STUDENT c1;  //for return a data type of studnet to the fcivector

    cout << "Insert type of vector you would like to create:\n"
            "1. list of integer\n"
            "2. list of character\n"
            "3. list of string\n"
            "4. list of float\n"
            "5. list of students\n"
            "6. Exit" << endl;
    cin >> type;
    if (type == 1) {
        cout<<"List Of Integers Was created\n";
        operations_of_fcivector(y);
    }
    if (type == 2) {
        cout<<"List Of Characters Was created\n";
        operations_of_fcivector(c);
    }
    if (type == 3){
       cout<< "List Of Strings Was created\n";
        operations_of_fcivector(s);
    }
    if (type == 4) {
       cout<< "List Of Floats Was created\n";
        operations_of_fcivector(f);
    }
    if (type == 5) {
        cout<<"\"List Of Students Was created\n";
        operations_of_fcivector(c1);
    }
 //   if (type == 6) exit(0);


    return 0;
}

