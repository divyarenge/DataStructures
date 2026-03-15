#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;

    ArrayX(int no);
    ~ArrayX();

    void Accept();
    void Display();

    bool CheckSorted();

    void BubbleSort();
};

ArrayX :: ArrayX(int no)
{
    cout<<"Inside constructor \n";
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

ArrayX :: ~ArrayX()
{
    cout<<"Inside destructor \n";
    delete [] Arr;
}

void ArrayX :: Accept()
{
    int iCnt = 0;

    cout<<"Enter the elements : \n";
    cin>>Arr[iCnt];

    for(iCnt = 1; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];

        if(Arr[iCnt-1] > Arr[iCnt])
        {
            Sorted = false;
        }
    }

    //  Sorted = CheckSorted();

}

void ArrayX :: Display()
{
    int iCnt = 0;

    cout<<"Elements of the array are :\n";

    for(iCnt = 0; iCnt <iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    
    cout<<"\n";
}

//  0     1     2     3      4      5       6       7       8       9
//  12   14     17    24     42     36      48      52      52      65
bool ArrayX :: CheckSorted()
{
    int i = 0;
    bool bFlag  = true;

    for(i = 0; i < iSize-1; i++)
    {
        if(Arr[i] > Arr[i + 1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;

}

void ArrayX :: BubbleSort()
{
    int i = 0, j = 0;
    int temp = 0;

    for(i = 0; i < iSize-1; i++)                //Outer Loop
    {
        for(j = 0; j < (iSize-1)-i ; j++)       //Inner loop
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }

    Sorted = true;
}

int main()
{
    int iValue = 0;

    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    ArrayX aobj(iValue);
    
    aobj.Accept();

    cout<<"Data Before Sorting :\n";
    aobj.Display();

    aobj.BubbleSort();

    cout<<"Data After Sorting :\n";
    aobj.Display();
    
    return 0;
}