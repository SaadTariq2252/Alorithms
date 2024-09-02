#include <iostream>


using namespace std;

int* findCommonElements(int* list1,int sz1 , int* list2, int sz2, int&count)
{
    count=0;
    int i = 0, j = 0;
    int sz3=sz1<sz2?sz1:sz2;
    int* result=new int[sz3];
    while (i < sz1 && j < sz2)
    {
        if (list1[i] == list2[j]) 
        {
            result[count]=list1[i];
            count++;
            i++;
            j++;
        } else if (list1[i] < list2[j]) 
        {
            i++;
        } else 
        {
            j++;
        }
    }

    return result;
}

int main() {
    int list1[] = {2, 5, 5, 5};
    int list2[] = {2, 2, 3, 5, 5, 7};
    int sz1 = sizeof(list1)/sizeof(list1[0]);
    int sz2 = sizeof(list2)/sizeof(list2[0]);
    int resSz=0;
    int* res = findCommonElements(list1,sz1, list2,sz2,resSz);
   
    cout << "\nCommon elements are: ";
    for (int i=0 ;i<resSz;i++ ) 
    {
        cout << res[i] << " ";
    }

    return 0;
}
