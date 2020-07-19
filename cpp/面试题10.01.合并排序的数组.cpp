/*
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

示例:

输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sorted-merge-lcci
*/
// 从合并数组后长度的尾部开始，比较A的当前元素与B的当前元素，插入到尾部即可
// 再调整A,B当前的有效结尾元素索引
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if (B.empty()) {
            return;
        }
        if (A.empty()) {
            A.swap(B);
            return;
        }
        int end = m + n - 1;
        --m;
        --n;
        while (n >= 0) {
            int value = 0;
            if (m < 0) {
                value = B[n];
                --n;
            } else {
                if (A[m] > B[n]) {
                    value = A[m];
                    --m;
                } else {
                    value = B[n];
                    --n;
                }
            }
            A[end] = value;
            --end;
        }
    }
};
