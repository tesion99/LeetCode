/*
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle
*/
// 循环或者递归解题
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0) {
            return res;
        }

        for (int i = 1; i <= numRows; ++i) {
            vector<int> tmp;
            tmp.reserve(i);
            if (i == 1) {
                tmp.push_back(1);
            } else {
                vector<int>& pre = res.back();
                for (int j = 0; j < i; ++j) {
                    if (j == 0 || j == i - 1) {
                        tmp.push_back(1);
                    } else {
                        tmp.push_back(pre[j-1] + pre[j]);
                    }
                }
            }
            res.push_back(move(tmp));
        }
        return res;
    }
};
