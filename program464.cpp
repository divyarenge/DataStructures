#include<iostream>
using namespace std;

class Arithmetic
{
    public:
        int No1;
        int No2;

        Arithmetic(int A, int B)
        {
            No1 = A;
            No2 = B;
        }

        int Addition()
        {
            int Ans;
            Ans = No1 + No2;
            return Ans;
        }
};

int main()
{
    Arithmetic *obj = new Arithmetic(11,10);    

    cout<<"Addition is: "<<obj->Addition()<<"\n";

    delete obj;

    return 0;
}