/*
给出一个整数数组 A 和一个查询数组 queries。

对于第 i 次查询，有 val = queries[i][0], index = queries[i][1]，我们会把 val 加到 A[index] 上。然后，第 i 次查询的答案是 A 中偶数值的和。

（此处给定的 index = queries[i][1] 是从 0 开始的索引，每次查询都会永久修改数组 A。）

返回所有查询的答案。你的答案应当以数组 answer 给出，answer[i] 为第 i 次查询的答案。

 

示例：

输入：A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
输出：[8,6,2,4]
解释：
开始时，数组为 [1,2,3,4]。
将 1 加到 A[0] 上之后，数组为 [2,2,3,4]，偶数值之和为 2 + 2 + 4 = 8。
将 -3 加到 A[1] 上之后，数组为 [2,-1,3,4]，偶数值之和为 2 + 4 = 6。
将 -4 加到 A[0] 上之后，数组为 [-2,-1,3,4]，偶数值之和为 -2 + 4 = 2。
将 2 加到 A[3] 上之后，数组为 [-2,-1,3,6]，偶数值之和为 -2 + 6 = 4。
 

提示：

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
1 <= queries.length <= 10000
-10000 <= queries[i][0] <= 10000
0 <= queries[i][1] < A.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-even-numbers-after-queries
*/
// 首先扫描数组A，记录出偶数和even_sum
// 遍历queries，检测新加入的值是否为导致对应index处变为偶数
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int even_sum = 0;
        for (auto n : A) {
            if ((n & 1) == 0) {
                even_sum += n;
            }
        }

        int rows = queries.size();
        vector<int> res;
        for (int r = 0; r < rows; ++r) {
            int idx = queries[r][1];
            int val = queries[r][0];
            
            if ((A[idx] & 1)) {
                if (val & 1) {
                    even_sum += A[idx] + val;
                }
            } else {
                if (val & 1) {
                    even_sum -= A[idx];
                } else {
                    even_sum += val;
                }
            }
            res.push_back(even_sum);
            A[idx] += val;
        }
        return res;
    }
};
