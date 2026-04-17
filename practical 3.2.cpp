#include<iostream>
using namespace std;

int iterativesum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int recursivesum(int arr[],int n)
{
    if(n==0)
        return 0;
    return arr[n-1]+recursivesum(arr,n-1);
}

int main()
{
    int n;
    cout<<"Enter size of arry: ";
    cin>>n;

    int arr[100];
     cout<<"Enter elements: ";
    for(int i=0;i<n;i++){

    cin>>arr[i];
    }

    int iterative=iterativesum(arr,n);
    int recursive=recursivesum(arr,n);

    cout<<"sum using iterative: "<<iterative<<endl;
    cout<<"sum using recursive: "<<recursive<<endl;
}
