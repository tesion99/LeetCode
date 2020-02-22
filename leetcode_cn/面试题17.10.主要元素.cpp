/*
如果数组中多一半的数都是同一个，则称之为主要元素。给定一个整数数组，找到它的主要元素。若没有，返回-1。

示例 1：

输入：[1,2,5,9,5,9,5,5,5]
输出：5
 

示例 2：

输入：[3,2]
输出：-1
 

示例 3：

输入：[2,2,1,1,1,2,2]
输出：2
 

说明：
你有办法在时间复杂度为 O(N)，空间复杂度为 O(1) 内完成吗？



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-majority-element-lcci
*/
// 不同数字相互抵消，剩余的则为主要元素
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, pre = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                pre = nums[i];
                count = 1;
                continue;
            }

            count += pre == nums[i] ? 1 : -1;
        }

        if (count == 0) {
            return -1;
        }

        // 再次验证，防止出现[1,2,3]这类情况
        count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == pre) ++count;
        }
        return count >= (nums.size() / 2 + 1) ? pre : -1;
        
        return count == 0 ? -1 : pre;
    }
};
