#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t)
    {
        vector<int> symbol(26, 0);
        for (char ch : s) {
            ++symbol[ch - 'a'];
        }

        for (char ch : t) {
            --symbol[ch - 'a'];
            if (symbol[ch - 'a'] < 0) {
                return ch;
            }
        }
        return ' ';
    }
};

int main()
{
    string str1 = "abcde";
    string str2 = "abcfde";
    Solution test;
    cout << test.findTheDifference(str1, str2) << endl;
    return 0;
}