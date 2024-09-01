#include<iostream>
using namespace std;

int sqRoot(int num);
int main()
{
    int num=0;
    cout<<"Enter a number to find sq root: ";
    cin>>num;
    cout<<"Sq root of "<<num<<" is : "<<sqRoot(num);

 return 0;
}

int sqRoot(int num)
{
    int low=0;
    int high=num;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (mid * mid == num)
            return mid;

        if (mid * mid > num)
            high = mid - 1;
        else
        {
            low = mid + 1;
            mid = low - 1;
        }
    }
    return mid;
}
