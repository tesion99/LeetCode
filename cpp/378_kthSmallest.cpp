/*
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。

示例:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
说明: 
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix
*/
// 堆，优先队列
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for (auto& r : matrix) {
            for (auto n : r) {
                if (pq.size() < k) {
                    pq.push(n);
                } else {
                    if (pq.top() > n) {
                        pq.pop();
                        pq.push(n);
                    }
                }
            }
        }
        return pq.top();
    }
};
