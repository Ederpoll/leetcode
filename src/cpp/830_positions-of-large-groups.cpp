#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        int len = s.size();
        vector<vector<int>> res;
        for (int i = 0; i < len;) {
            int j = i + 1;
            while (j < len && s[i] == s[j]) {
                ++j;
            }
            if (j - i >= 3) {
                res.push_back({ i, j - 1 });
            }
            i = j;
        }
        return res;
    }
};