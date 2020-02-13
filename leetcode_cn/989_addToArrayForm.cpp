/*
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。

给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。

 

示例 1：

输入：A = [1,2,0,0], K = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234
示例 2：

输入：A = [2,7,4], K = 181
输出：[4,5,5]
解释：274 + 181 = 455
示例 3：

输入：A = [2,1,5], K = 806
输出：[1,0,2,1]
解释：215 + 806 = 1021

提示：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
如果 A.length > 1，那么 A[0] != 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-to-array-form-of-integer
*/
// 反向遍历数组X, 使用K的每一位 + X的当前位 + carry进位
// 遍历X完毕后，检测K或carry是否都为0，否则插入后续数值到X头部
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int carry = 0;
        for (int i = A.size() - 1; i >= 0; --i) {
            int tmp = A[i] + (K % 10) + carry;
            A[i] = tmp % 10;
            carry = tmp / 10;
            K /= 10;

            if (carry == 0 && K == 0) {
                break;
            }
        }

        while (K != 0 || carry != 0) {
            int tmp = (K % 10) + carry;
            A.insert(A.begin(), tmp % 10);
            carry = tmp / 10;
            K /= 10;
        }

        return A;
    }
};
