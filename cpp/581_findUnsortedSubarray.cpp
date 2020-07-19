/*
给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

你找到的子数组应是最短的，请输出它的长度。

示例 1:

输入: [2, 6, 4, 8, 10, 9, 15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
说明 :

输入的数组长度范围在 [1, 10,000]。
输入的数组可能包含重复元素 ，所以升序的意思是<=。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray
*/
// 使用额外空间记录升序排序后的结果，从头比对对应元素是否已序，然后从尾部比对是否也已序
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        map<int, vector<int>> im;
        for (int i = 0; i < nums.size(); ++i) {
            im[nums[i]].push_back(i);
        }

        int start = 0;
        for (auto it = im.begin(); it != im.end(); ++it) {
            int i = 0;
            for (; i < it->second.size(); ++i) {
                if (it->second[i] == start) {
                    ++start;
                } else {
                    break;
                }
            }
            if (i != it->second.size()) {
                break;
            }
        }

        if (start == nums.size()) {
            return 0;
        }

        int end = nums.size();
        for (auto it = im.rbegin(); it != im.rend(); ++it) {
            int i = it->second.size() - 1;
            for (; i >= 0; --i) {
                if (it->second[i] == end - 1) {
                    --end;
                } else {
                    break;
                }
            }
            if (i >= 0) {
                break;
            }
        }
        return end - start;
    }
};
