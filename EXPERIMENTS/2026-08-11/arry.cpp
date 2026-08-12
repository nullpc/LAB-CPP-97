#include<iostream>
using namespace std;
int main()
{
    int *arr;
    int size;
    cout<<"Enter the Size of Array : ";
    cin>>size;
    cout<<"Creating Array....\n";
    arr=new int[size];
    cout<<"Enter the Vaules of Array: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    delete arr;
    cout<<"Displayed Array are : ";
    for(int i=0;i<size;i++)
    {
        cout<<" "<<arr[i];
    }
    return 0;
}