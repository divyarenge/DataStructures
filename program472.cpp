#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

        ArrayX(int no)
        {
            cout<<"Inside constructor \n";
            iSize = no;
            Arr = new int[iSize];
        }

        ~ArrayX()
        {
            cout<<"Inside destructor \n";
            delete [] Arr;
        }
};

int main()
{
    //ArrayX aobj(10);

    // Step 1 : Allocate the memory
    ArrayX *obj = new ArrayX(10);

    //Step 2: Use the memory
    // Logic

    //Step 3 : Deallocate the memory
    delete obj;
    
    return 0;
}