//
// Created by Yingdong Pu on 2021/1/28.
//
#include <iostream>
#include <vector>

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] == total - sum) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
