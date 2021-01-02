#include <deque>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int len = nums.size();
        deque<int> que;
        for (int i = 0; i < k; ++i) {
            while (!que.empty() && nums[i] >= nums[que.back()]) {
                que.pop_back();
            }
            que.push_back(i);
        }

        vector<int> res = { nums[que.front()] };
        for (int i = k; i < len; ++i) {
            while (!que.empty() && nums[i] >= nums[que.back()]) {
                que.pop_back();
            }
            que.push_back(i);
            while (que.front() <= i - k) {
                que.pop_front();
            }
            res.push_back(nums[que.front()]);
        }
        return res;
    }
};