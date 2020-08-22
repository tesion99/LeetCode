/*
爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 块糖的大小，B[j] 是鲍勃拥有的第 j 块糖的大小。

因为他们是朋友，所以他们想交换一个糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）

返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。

如果有多个答案，你可以返回其中任何一个。保证答案存在。

 

示例 1：

输入：A = [1,1], B = [2,2]
输出：[1,2]
示例 2：

输入：A = [1,2], B = [2,3]
输出：[1,2]
示例 3：

输入：A = [2], B = [1,3]
输出：[2,3]
示例 4：

输入：A = [1,2,5], B = [2,4]
输出：[5,4]
 

提示：

1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
保证爱丽丝与鲍勃的糖果总量不同。
答案肯定存在。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fair-candy-swap
*/
// 分别计算总量，早出需要交换的两个数之间的差距值，满足差距值即可
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_set<int> sa, sb;
        int asum = 0, bsum = 0;
        for (auto n : A) {
            asum += n;
            sa.insert(n);
        }
        for (auto n : B) {
            bsum += n;
            sb.insert(n);
        }

        int a = 0, b = 0;
        if (asum < bsum) {
            int diff = (bsum - asum) / 2;
            for (auto& n : sa) {
                if (sb.count(n + diff)) {
                    a = n;
                    b = n + diff;
                    break;
                }
            }
        } else {
            int diff = (asum -  bsum) / 2;
            for (auto& n : sb) {
                if (sa.count(n + diff)) {
                    a = n + diff;
                    b = n;
                    break;
                }
            }
        }

        return {a, b};
    }
};