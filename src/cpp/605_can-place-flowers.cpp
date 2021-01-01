#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int size = flowerbed.size();
        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0)) {
                --n;
                flowerbed[i] = 1;
            }

            if (n <= 0) {
                return true;
            }
        }

        return n <= 0;
    }
};