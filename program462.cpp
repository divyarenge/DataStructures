#include<iostream>
using namespace std;

template <class T>
T Addition(T No1,T No2)
{
    T Ans ;
    Ans = No1 + No2;
    return Ans;
};

int main()
{
    cout<<"Addition of Characters: "<<Addition('a','b')<<"\n";
    cout<<"Addition of Integers: "<<Addition(10,11)<<"\n";
    cout<<"Addition of float: "<<Addition(10.5f,11.3f)<<"\n";
    cout<<"Addition of double: "<<Addition(90.3445667,30.455)<<"\n";

    return 0;
}