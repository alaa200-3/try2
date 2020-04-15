#ifndef FCIVECTOR_H
#define FCIVECTOR_H


template <class T>
class FCIvector {
private:
    T * elements;  // pointer for array's memory
    int numofelements=0;// size of array (elemets)
    int capacity=10;  // actual size of allocated memory  // ERROR: there is a problem  that the capcity still 10 even if we add 13 elements
public:

    FCIvector();// Constructor for IntArray class. Sets the size of the array and allocates memory for it.  (it is done )
    int size(); // num of elements  that user will added it in the array
    int capac(); // size of array we initiate with it(it is done )
    bool empty(); // if size = 0 or not
    T& operator[](int index);
    T* begin(); // display element from begin to the end
    T& front(); //display the last element
    T& back();  //display the first element
    void insert(T* position , T val);// insert element in certain position and shift the following element of this position
    void push_back(T val);
    void pop_back(); // delete element from last index
    void clear();    //delete the array
    void erase(T* position); // delete a detected element in the array
    ~FCIvector();

};

/*------------------------------------------------------------------//
   constructor to allocate arry
//-------------------------------------------------------------------*/
template <class T>
FCIvector<T>::FCIvector() {
    //capacity=capac;
    elements = new T[capacity];
    //for (int i = 0; i < capacity ; i++)
       // elements[i]=0; // there is a problem to assign a null array for a string
}

//----------------------------------------------------------------------------//
template <class T>
void FCIvector<T>:: push_back(T val) {
    numofelements++;

    if(numofelements>capacity){
        capacity = capacity*2;
        T* temp = new T[capacity];
        for (int i = 0; i < numofelements; i++) {
            temp[i] = elements[i];
        }
        delete[] elements;
        elements = temp;
        *(elements + (numofelements-1)) = val;  // put the value in the last element in the new array temp
        //numofelements++;
    }
    else {

        *(elements+(numofelements-1))=val;
    }
}
//--------------------------------------------------------------------------------------------------//
template <class T>
T* FCIvector <T>::begin(){
    T * temp =elements;  //the same of return elements;
     return temp;
    return elements;
}
//------------------------------------------------------------------------------------------//

template <class T>
void FCIvector<T>:: pop_back(){

     numofelements --;
}
//-----------------------------------------------------------------------------------------------------//

template <class T>

void FCIvector<T>::erase(T *position) {
    int new_index;
        for (int i = 0; i < numofelements; i++) {
            if (begin() + i == position) {
                new_index = i;  // take index of the detected position
                numofelements--; // mince num to min size
                for (int i = new_index;
                     i < numofelements; i++) { //begin the for loop from the index of the detected element
                    elements[i] = elements[i + 1]; // shift the elements to the left
                }
            }
        }
        for(int i=0;i<numofelements;i++) std::cout<<elements[i]<<" ";
}

//--------------------------------------------------------------------------------------------------//
template <class T>
void  FCIvector<T>::insert(T *position, T val) {
int new_num_ele;
 for (int i = 0; i < numofelements; i++) {
        if (begin() + i == position) {
            new_num_ele = i;
            numofelements++;
            for (int i =numofelements; i > new_num_ele; i--) {
                elements[i] = elements[i-1];
            }
            elements[new_num_ele] = val;
        }
    }

    for(int i=0;i<numofelements;i++) std::cout<<elements[i]<<" ";
}


//--------------------------------------------------------------------------------------------------//
template <class T>
void FCIvector<T>:: clear(){
    numofelements=0;
    delete []elements;
}

//--------------------------------------------------------------------------------------------------//

template <class T>
T& FCIvector<T>::front()
{
      std::cout<< "the first element is:";
    return elements[0];
}

//--------------------------------------------------------------------------------------------------//

template <class T>
T& FCIvector<T>:: back()
{
     std::cout<< "the last element is:";
    return elements[numofelements-1];
}

//--------------------------------------------------------------------------------------------------//

template <class T>// does't appear any thing`
T&  FCIvector<T> ::operator[](int   index){
    while (index>numofelements-1 || index<0) {
        std::cout<<"index is out of the range\n enter again\n";
        std::cin>>index;
    }
    std::cout<<"element["<<index<<"] is:";
    return elements[index];
}
//--------------------------------------------------------------------------------------------------//

template <class T>
int FCIvector<T>::size(){

return numofelements;
}

//-------------------------------------------------------------------------------------------------//

template <class T>
int FCIvector <T>:: capac(){
     return capacity;
}

//---------------------------------------------------------------------------------------------------//

template <class T>
bool FCIvector<T> :: empty(){

    if (numofelements==0) {
        std::cout<<"the vector is empty" ;
        return true;
    }
    else {
        std::cout<<"the vector is not empty" ;
        return false;
    }
}

//-----------------------------------------------------------------------------------------------------//

template <class T>
FCIvector<T>::~FCIvector()
{
   // if (capacity> 0)
        delete elements;
}

//---------------------------------------------------------------------------------------------------------//

#endif // FCIVECTOR_H
