#include <iostream>
using namespace std;
class Solution {
public:
    int fib(int n)
    {
        if (n < 2)
            return n;
        int p = 0;
        int q = 0;
        int r = 1;
        for (int i = 2; i <= n; ++i) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};

int main()
{
    Solution test;
    cout << test.fib(20) << endl;
    return 0;
}