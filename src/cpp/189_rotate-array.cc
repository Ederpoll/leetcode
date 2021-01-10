#include <iostream>
#include <vector>
class Solution {
public:
    void reverse(vector<int>& num, int start, int end)
    {
        while (start < end) {
            int tmp = num[start];
            num[start] = num[end];
            num[end] = tmp;
            ++start;
            --end;
        }
    }

    void rotate(vector<int>& nums, int k)
    {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};