#include<iostream>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTreminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTreminal = false;
    }
};

int main()
{

    return 0;
}