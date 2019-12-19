/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
------------------------
Note: 注意最高位的进位问题
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            return vector<int>();
        }

        int sz = digits.size();
        if (digits[sz - 1] >= 0 && digits[sz - 1] <= 8) {
            digits[sz - 1] += 1;
            return digits;
        }

        int carray = 0, tmp = 0;
        for (int i = sz - 1; i >= 0; --i) {
            if (i == sz - 1) {
                digits[i] += 1;
            }
            tmp = digits[i] + carray;
            carray = tmp / 10;
            digits[i] = tmp % 10;
        }

        vector<int> res(digits);
        if (carray != 0) {
            res.insert(res.begin(), 1);
        }

        return res;
    }
};
