#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <fstream>
#include <vector>

using namespace std;

void RNG(int n, int max)
{ 
    srand(time(0));
    string filename = to_string(n)+"_RandNum.txt";
    ofstream fout(filename);
    if(!fout.is_open())
    cout<<"Error opening file\n";
    cout << "Generated " << n << " random numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        int randomNumber = rand()%(max+1);  
        fout << randomNumber << endl;  
    }
    fout.close();
}
vector<int> readFile(int n)
{
    vector<int> Randnums={};
    string filename = to_string(n)+"_RandNum.txt";
    ifstream fin(filename);
    if(!fin.is_open())
    {
        cout<<"Error opening file\n";
        return Randnums;
    }
    for (int i = 0; i < n; ++i) {
        int randomNumber=0; 
        fin >> randomNumber;  
        Randnums.push_back(randomNumber);
    }
    cout << "Read " << n << " random numbers:" << endl;
    fin.close();
    return Randnums;
}
int main() {
    system("clear");
    int n;
    cout << "Enter the number of random numbers to generate: ";
    cin >> n;
    int max;
    cout << "Enter the max number: ";
    cin >> max;
    RNG(n,max);
    // vector<int> rnds=readFile(n);
    // for (auto i : rnds)
    // {
    //     cout<<i<<" ";
    // }
    
    
    return 0;
}
