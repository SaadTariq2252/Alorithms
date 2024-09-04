#include<iostream>
#include <fstream>
#include <vector>
using namespace std;

//Sorting Functions
void swap(int &x ,int &y);
vector<int> readFile(int n);
vector<int> bubbleSort(vector<int> A );  // with flag to reduce comparisions
vector<int> SimpleBubbleSort(vector<int> A ); // No flag; Does full comparisions
vector<int> insertionSort(vector<int> A);
vector<int> selectionSort(vector<int> A);

//Helper Functions
void PrintVector(vector<int> &A);
void PrintStats(string AlgoName, int Count1, int Count2,int n);
bool isFileEmpty(const string& filename);
void SaveCsv(string AlgoName,int n, int SwapCnt, int ComparisionCnt);

//Global counters
int comparisonCount=0;
int swapCount=0;

int main()
{
    system("clear");
    vector<int> randomNums;
    vector<int> sorted;
    int n=5;
    vector<int> Inputs={100,250,500,1000,10000};
    int N = Inputs.size();
    for (int i = 0; i < N; i++)
    {
        n=Inputs[i];
        randomNums=readFile(n);

        comparisonCount=0;
        swapCount=0;
        sorted=SimpleBubbleSort(randomNums);
        PrintStats("SimpleBubbleSort", comparisonCount, swapCount,n);
        SaveCsv("SimpleBubbleSort",n, comparisonCount, swapCount);
   
        comparisonCount=0;
        swapCount=0;
        sorted=bubbleSort(randomNums);
        PrintStats("BubbleSort", comparisonCount, swapCount,n);
        SaveCsv("BubbleSort",n, comparisonCount, swapCount);
    
        comparisonCount=0;
        swapCount=0;
        sorted=insertionSort(randomNums);
        PrintStats("Insertion Sort", comparisonCount, swapCount,n);
        SaveCsv("InsertionSort",n, comparisonCount, swapCount);

        comparisonCount=0;
        swapCount=0;
        sorted=selectionSort(randomNums);
        PrintStats("selectionSort", comparisonCount, swapCount,n);
        SaveCsv("selectionSort",n, comparisonCount, swapCount);
    

    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < N; j++)
        {
            n=Inputs[j];
            randomNums=readFile(n);
            comparisonCount=0;
            swapCount=0;
            sorted=SimpleBubbleSort(randomNums);
            PrintStats("SimpleBubbleSort", comparisonCount, swapCount,n);
            SaveCsv("SimpleBubbleSort",n, comparisonCount, swapCount);
        }
        
        
        for (int j = 0; j < N; j++)
        {
            n=Inputs[j];
            randomNums=readFile(n);
        comparisonCount=0;
        swapCount=0;
        sorted=bubbleSort(randomNums);
        PrintStats("BubbleSort", comparisonCount, swapCount,n);
        SaveCsv("BubbleSort",n, comparisonCount, swapCount);
        }

        for (int j = 0; j < N; j++)
        {
            n=Inputs[j];
            randomNums=readFile(n);
        comparisonCount=0;
        swapCount=0;
        sorted=insertionSort(randomNums);
        PrintStats("Insertion Sort", comparisonCount, swapCount,n);
        SaveCsv("InsertionSort",n, comparisonCount, swapCount);
        }
        for (int j = 0; j < N; j++)
        {
            n=Inputs[j];
            randomNums=readFile(n);

        comparisonCount=0;
        swapCount=0;
        sorted=selectionSort(randomNums);
        PrintStats("selectionSort", comparisonCount, swapCount,n);
        SaveCsv("selectionSort",n, comparisonCount, swapCount);
        }

    }


 return 0;
}


//Helper Functions

bool isFileEmpty(const string& filename) 
{
    ifstream file(filename, ios::binary | ios::ate);
    if (!file) 
    {
        cerr << "Could not open the file!" << endl;
        return false;
    }
    return file.tellg() == 0;
}

void SaveCsv(string AlgoName,int n, int SwapCnt, int ComparisionCnt)
{
    string filename="Algorithm_Data.csv";
    ofstream fout(filename, ios::app);
    if(isFileEmpty(filename))
    {
        fout<<"Name,Total elements,Total Swaps, Total Comparisions\n";
    }
    fout<<AlgoName<<","<<n<<","<< ComparisionCnt <<","<<SwapCnt <<endl;
}

void PrintStats(string AlgoName, int Count1, int Count2,int n)
{
    cout<<endl;
    cout<<"sorted with "<<AlgoName<<"\n";
    cout<<"total Number of comparisions for "<< n<<" inputs: "<<Count1<<endl;
    cout<<"total Number of swaps for "<< n<<" inputs: "<<Count2<<endl;
}

void PrintVector(vector<int> &A)
{
    for (auto i : A)
    {
        cout<<i<<" ";
    }
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

// Sorting Functions

vector<int> bubbleSort(vector<int> A) 
{
    int n = A.size(); 
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) 
        {
            comparisonCount++;
            if (A[j] > A[j + 1]) 
            {
                swap(A[j], A[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
    return A;
}
vector<int> SimpleBubbleSort(vector<int> A )
{
    int n = A.size(); 
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            comparisonCount++;
            if (A[j] < A[j-1]) 
            {
                swap(A[j-1] , A[j]);
            }
        } 
    } 
    return A;
}

void swap(int &x ,int &y)
{
    swapCount++;
    int temp=x;
    x=y;
    y=temp;
}
vector<int> insertionSort(vector<int> A)
{
    int temp=0;
    int n=A.size();
    for (int i =1; i < n; i++)
    {
        temp = A[i];
        for (int j = i-1; j>=0 && A[j] > temp; j--)
        {
            comparisonCount++;
            A[j+1] = A[j];
            A[j] = temp;
        }
    }
    comparisonCount++;
    return A;
}

vector<int> selectionSort(vector<int> A)
{
    int n=A.size();
    for (int i =0; i < n; i++)
    {
        int min = i;
        for (int j = i+1; j < n ;j++)
        {
            comparisonCount++;
            if ( A[j] < A[min])
            {
                min = j;
            } 
        }
        swap(A[i], A[min]);
    }
    return A;
}