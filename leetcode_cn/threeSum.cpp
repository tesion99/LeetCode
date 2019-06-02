/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

Ps: 
    先排序，然后固定一个值，从前后查找两数之后等于target
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        if (nums.size() < 3)
        {
            return res;
        }

        sort(nums.begin(), nums.end());

        size_t sz = nums.size();
        int target = 0;
        for (int i = 0; i < sz - 2; ++i)
        {
            if (i >= 1)
            {
                if (nums[i] == nums[i - 1]) continue;
            }

            target = 0 - nums[i];
            int start = i + 1;
            int end = sz - 1;
            while (start < end)
            {
                int sum = nums[start] + nums[end];
                if (sum > target)
                {
                    --end;
                }
                else if (sum < target)
                {
                    ++start;
                }
                else
                {
                    vector<int> tmp = {nums[i], nums[start], nums[end]};
                    if (res.empty())
                    {
                        res.push_back(tmp);
                    }
                    else
                    {
                        // 检查上一组结果与当前结果是否相等
                        auto & last = res.back();
                        for (int i = 0; i < 3; ++i)
                        {
                            if (last[i] != tmp[i])
                            {
                                res.push_back(tmp);
                                break;
                            }
                        }
                    }
                    ++start;
                    --end;
                }
            } // end while
        } // end for

        return res;
    }
};
