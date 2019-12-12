/*
定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
-------------------------
Note: 类似三数和，先排序，然后分别内外双重指针
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }

        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int i = 0, j = nums.size() - 1;
        vector<int> tmp;
        tmp.resize(4);
        for (int i = 0; i < sz - 3; ++i) {
            if (!res.empty() && nums[i] == tmp[0]) {
                continue;
            }

            for (int j = sz - 1; j > i + 2; --j) {
                if (!res.empty() && nums[i] == tmp[0] && nums[j] == tmp[3]) {
                    continue;
                }
                int rest = target - nums[i] - nums[j];
                int start = i + 1, end = j - 1;
                while (start < end) {
                    int sum = nums[start] + nums[end];
                    if (sum > rest) {
                        --end;
                    } else if (sum < rest) {
                        ++start;
                    } else {
                        tmp[0] = nums[i];
                        tmp[1] = nums[start];
                        tmp[2] = nums[end];
                        tmp[3] = nums[j];

                        if (res.empty()) {
                            res.push_back(tmp);
                        } else {
                            vector<int> & pre = res.back();
                            if (tmp[0] != pre[0] || tmp[1] != pre[1] ||
                                tmp[2] != pre[2] || tmp[3] != pre[3]) {
                                    res.push_back(tmp);
                            } else {
                                ++start;
                                --end;
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};
