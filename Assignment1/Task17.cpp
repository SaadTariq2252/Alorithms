#include<iostream>
using namespace std;

bool IsAnagram(string word1, string word2);

int main()
{
    system("clear");
    string w1="eat";
    string w2="cat";
    bool anagram = IsAnagram(w1,w2);
    string res= anagram?"true":"false";
    cout<<w1<<" And "<<w2<<" are anagrams: "<<res<<endl<<endl;


 return 0;
}

bool IsAnagram(string word1, string word2)
{  
    if(word1.length()!=word2.length())
    {   
        return false;
    }
    int count=0;
    int len=word1.length();
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if(word1[i]==word2[j])
            {
                count++;
            }
        }
            
    }
    if(count!=len)
        return false;

    return true;

}