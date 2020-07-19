/*
给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。

返回使 A 中的每个值都是唯一的最少操作次数。

示例 1:

输入：[1,2,2]
输出：1
解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
示例 2:

输入：[3,2,1,2,1,7]
输出：6
解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
提示：

0 <= A.length <= 40000
0 <= A[i] < 40000
*/
// 根据A[i]的取值范围，判定最大值不超过80000
// 由题意知，需要将重复的数转变为个数为0的数
// 对A中的数做引用计数，然后查找最近个数为0的数
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size() <= 1) {
            return 0;
        } 
        
        int arr[80000] = {0};
        for (auto n : A) {
            ++arr[n];
        }
        int off = 0, move = 0;
        for (int i = 0; i < 80000; ++i) {
            while (arr[i] > 1 && off < 80000) {
                if (off <= i) {
                    off = i + 1;
                }
                while (off < 80000 && arr[off] != 0) {
                    ++off;
                }
                if (off < 80000) {
                    arr[off] = 1;
                    move += off - i;
                    --arr[i];
                }
            }
        }

        return move;
    }
};
