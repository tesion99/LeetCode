/*
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
*/
// 选定1~n中的某个点x作为根节点，递归统计 1~x-1与x+1~n两个区域的BST个数
class Solution {
public:
    map<pair<int,int>, int> m;
    int numTrees(int n) {
        return numsTrees(1, n);
    }
    int numsTrees(int start, int end) {
        if (start <= 0 || start > end || end <= 0) {
            return 0;
        }
        auto it = m.find(make_pair(start, end));
        if (it != m.end()) {
            return it->second;
        }

        int cnt = 0;
        for (int i = start; i <= end; ++i) {
            // 以i作为根节点，递归统计左右子树为BST的个数
            int left = numsTrees(start, i - 1);
            int right = numsTrees(i + 1, end);
            m[make_pair(start, i - 1)] = left;
            m[make_pair(i + 1, end)] = right;
            if (left == 0 && right == 0) {
                cnt += 1;
            } else if (left == 0) {
                cnt += right;
            } else if (right == 0) {
                cnt += left;
            } else {
                cnt += left * right;
            }
        }
        m[make_pair(start, end)] = cnt;
        return cnt;
    }
};
