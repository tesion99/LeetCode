/*
给定一个由 4 位数字组成的数组，返回可以设置的符合 24 小时制的最大时间。

最小的 24 小时制时间是 00:00，而最大的是 23:59。从 00:00 （午夜）开始算起，过得越久，时间越大。

以长度为 5 的字符串返回答案。如果不能确定有效时间，则返回空字符串。

 

示例 1：

输入：[1,2,3,4]
输出："23:41"
示例 2：

输入：[5,5,5,5]
输出：""
 

提示：

A.length == 4
0 <= A[i] <= 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-time-for-given-digits
*/
// 首先需要一个存储各个位的数组
// 其次，从最高位0~3，其取值范围不同
// 第0位： 0~2
// 第1位： 当第0位为2时，取值范围0~3；否则为0~9
// 第2位： 0~5
// 第3位： 0~9
// 然后对数组A排序，从最大遍历，到第一个满足当前范围的值，即是可放到当前位的最大值
// 注意：如果当前位放置的最大值导致后续无法进行，可能该值选取有误，需减小，然后回溯，进行下一个值的选取
// 特殊测试用例: A=[2,0,6,6]
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        if (A.empty()) {
            return "";
        }
        sort(A.begin(), A.end());
        if (A[0] > 2 || A[3] > 9 || A[0] < 0) {
            return "";
        }

        int arr[4] = {0};
        bool res = false;
        backtrace(A, arr, 0, res);
        if (res == false) {
            return "";
        }

        ostringstream oss;
        for (int i = 0; i < 4; ++i) {
            oss << arr[i];
            if (i == 1) {
                oss << ":";
            }
        }
        return oss.str();
    }
    void backtrace(vector<int>& A, int arr[], int cur, bool& res) {
        if (cur >= 4) {
            res = true;
            return;
        }

        int max = 0;
        switch (cur) {
        case 0:
            max = 2;
            break;
        case 1:
            max = (arr[0] == 2) ? 3 : 9;
            break;
        case 2:
            max = 5;
            break;
        default:
            max = 9;
        }

        for (int i = 3; i >= 0; --i) {
            if (max < 0) break;

            if (A[i] >= 0 && A[i] <= max) {
                arr[cur] = A[i];
                A[i] = -1; 
                backtrace(A, arr, cur + 1, res);
                A[i] = arr[cur];
                if (res == true) {
                    break;
                }
                --max;
            }
        }
    }
};
