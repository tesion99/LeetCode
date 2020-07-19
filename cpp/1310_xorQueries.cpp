/*
有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。

对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]）作为本次查询的结果。

并返回一个包含给定查询 queries 所有结果的数组。

 

示例 1：

输入：arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
输出：[2,7,14,8] 
解释：
数组中元素的二进制表示形式是：
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
查询的 XOR 值为：
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xor-queries-of-a-subarray
*/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        if (arr.empty()) {
            return vector<int>();
        }
        if (arr.size() == 1) {
            return vector<int>(queries.size(), arr[0]);
        }
        vector<int> xors(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            if (i == 0) {
                xors[0] = arr[0];
            } else {
                xors[i] = arr[i] ^ xors[i - 1];
            }
        }

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int start = queries[i][0];
            int end = queries[i][1];
            if (start == end) {
                res[i] = arr[start];
                continue;
            }
            if (start == 0) {
                res[i] = xors[end];
                continue;
            }
            res[i] = xors[end] ^ xors[start - 1];
        }
        return res;
    }
};
