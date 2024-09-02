#include<iostream>
using namespace std;

void toggleLockers(bool* doors, int n);

int main()
{
    system("clear");
    int n =16;
    bool * doors = new bool[n+1];

    for(int i=1;i<=n;i++)
    {
        doors[i]=0;
    }
    toggleLockers(doors, n);

    delete[] doors;
 return 0;
}

void toggleLockers(bool* doors, int n)
{
    for(int i=1;i<=n;++i)
    {
        for (int j = i; j <= n; j+=i)
        {
            doors[j]=!doors[j];
        }
        
       
    }
    string door="";
    int openDoors=0;
    for (int i = 1; i <= n; i++)
    {
        if(doors[i]) openDoors++;
    }
    cout<<"\nTotal doors: "<<n;
    cout<<"\nOpened doors are "<<openDoors<<"\n";
    
}
