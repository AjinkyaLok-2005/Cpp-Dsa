#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";

        for(int i = s.length()-1; i >= 0; i--)
        {
            if(s[i] == ' ')
            {
                if(!temp.empty())
                {
                    reverse(temp.begin(), temp.end());
                    if(!ans.empty())
                        ans.push_back(' ');
                    ans = ans + temp;
                    temp = "";
                }
            }
            else
            {
                temp.push_back(s[i]);
            }
        }

        if(!temp.empty())
        {
            reverse(temp.begin(), temp.end());
            if(!ans.empty())
                ans.push_back(' ');
            ans += temp;
        }

        return ans;
    }
};

int main() {
    string s;
    getline(cin, s);   // read full line with spaces

    Solution obj;
    cout << obj.reverseWords(s);

    return 0;
}