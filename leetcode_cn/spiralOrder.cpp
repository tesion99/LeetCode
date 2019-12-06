/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

Ps:
    根据顺时针方向，旋转一周后，开始进入重复操作，寻找到规律
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int line = matrix.size();
        int column = 0;
        if (line != 0)
        {
            column = matrix[0].size();
        }
        
        int cs = 0, ce = column - 1;
        int ls = 0, le = line - 1;
        
        while (ls <= le && cs <= ce)
        {
            if (ls == le)
            {
                // 剩余最后一行
                while (cs <= ce)
                {
                    res.push_back(matrix[ls][cs]);
                    ++cs;
                }
                break;
            }
            
            if (cs == ce)
            {
                // 剩余最后一列
                while (ls <= le)
                {
                    res.push_back(matrix[ls][cs]);
                    ++ls;
                }
                break;
            }
            
            int c = cs;
            int l = ls;
            
            while (l < le)
            {
                while (c < ce)
                {
                    res.push_back(matrix[l][c]);
                    ++c;
                }
                
                res.push_back(matrix[l][c]);
                ++l;
            }
            
            while (c > cs)
            {
                res.push_back(matrix[l][c]);
                --c;
            }
            
            while (l > ls)
            {
                res.push_back(matrix[l][c]);
                --l;
            }
            
            ++ls;
            --le;
            ++cs;
            --ce;
        }
        
        return res;
    }
};
