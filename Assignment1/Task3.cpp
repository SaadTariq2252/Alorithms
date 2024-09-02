#include<iostream>
using namespace std;

int EuclidGcd(int num1, int num2);


int main()
{
    system("clear");
    // int a=14142;
    // int b=31415; 
    int a=252;
    int b=105;
    int euclidGCD=EuclidGcd(a,b);
    cout<<"\neuclidGCD of "<< a <<" and "<< b <<" is "<<euclidGCD;

 return 0;
}

int EuclidGcd(int num1, int num2)
{
    int a = num1>num2?num1:num2;
    int b = num1>num2?num2:num1;
    int r=-1;

    while(r!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}