/*
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。

给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。

示例 1:

输入: 2
输出: [0,1,3,2]
解释:
00 - 0
01 - 1
11 - 3
10 - 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gray-code
--------------------------------------
Wiki解释的官方解释方法: 以二進制為0值的格雷碼為第零項，第一項改變最右邊的位元，第二項改變右起第一個為1的位元的左邊位元，第三、四項方法同第一、二項，如此反覆，即可排列出n個位元的格雷碼。
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int end = pow(2, n) - 1;
        backtrace(1, end, 0, res);
        return res;
    }

    void backtrace(int cur, int end, int num, vector<int>& res) {
        res.push_back(num);
        if (cur > end) {
            return;
        }

        // cur为奇数时，改变最右边的bit位
        if (cur & 1) {
            if (num & 1) {
                --num;
            } else {
                ++num;
            }
        } else {
            // cur为偶数时，改变从右起第一个为1的bit位左边的bit位
            int flag = 1;
            while ((num&flag) == 0) {
                flag <<=1;
            }
            // 找到为1的bit的左边bit
            flag <<=1;
            if ((num&flag)) {
                num -= flag;
            } else {
                num += flag;
            }
        }
        backtrace(cur + 1, end, num, res);
    }
};
