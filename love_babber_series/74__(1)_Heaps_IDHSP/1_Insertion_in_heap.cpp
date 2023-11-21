#include<iostream>
using namespace std;

class heap
{
    public:
    int arr[100];
    int size;

    heap()
    {
        arr[0]=-1;
        size=0;
    }

    void insertion(int val)
    {
         size=size+1;
         int index=size;
         arr[index]=val;

         while(index > 1)
         {
            int parent=index/2;

            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else
            {
                return ;
            }
         }
    }


    void print()
    {
        for(int i=0;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

int main()
{
    heap h1;
    h1.insertion(60);
    h1.insertion(30);
    h1.insertion(50);
    h1.insertion(20);
    h1.insertion(70);
    h1.insertion(40);
    h1.insertion(55);

    h1.print();

    return 0;
}