#include<iostream>
using namespace std;

template <class T>
class Arithmetic
{
    public:
        T No1;
        T No2;

        Arithmetic(T A, T B);
        T Addition();
        T Substraction();
};

template <class T>
Arithmetic<T> :: Arithmetic(T A, T B)
{
    No1 = A;
    No2 = B;
}

template <class T>
T Arithmetic<T> :: Addition()
{
    T Ans;
    Ans = No1 + No2;
    return Ans;
}

template <class T>
T Arithmetic<T> :: Substraction()
{
    T Ans;
    Ans = No1 - No2;
    return Ans;
}

int main()
{
    //  Arithmetic <int> iobj (11,10);    

    Arithmetic<int> *iobj = new Arithmetic<int>(11,10);

    cout<<"Addition is: "<<iobj->Addition()<<"\n";
    cout<<"Substraction is: "<<iobj->Substraction()<<"\n";

    Arithmetic <double> *dobj = new Arithmetic<double>(90.23345,67.345666);    

    cout<<"Addition is: "<<dobj->Addition()<<"\n";
    cout<<"Substraction is: "<<dobj->Substraction()<<"\n";

    delete iobj;
    delete dobj;

    return 0;
}