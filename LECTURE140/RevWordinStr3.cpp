#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";

        for(int i = 0; i <= s.length()-1; i++)
        {
            if(s[i] == ' ')
            {
                if(!temp.empty())
                {
                    reverse(temp.begin(), temp.end());
                    if(!ans.empty())
                    {
                        ans.push_back(' ');
                    }
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
            ans = ans + temp;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s;
    getline(cin, s);   // take full line input (including spaces)

    string result = sol.reverseWords(s);
    cout << result << endl;

    return 0;
}
