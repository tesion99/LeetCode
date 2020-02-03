/*
我们给出两个单词数组 A 和 B。每个单词都是一串小写字母。

现在，如果 b 中的每个字母都出现在 a 中，包括重复出现的字母，那么称单词 b 是单词 a 的子集。 例如，“wrr” 是 “warrior” 的子集，但不是 “world” 的子集。

如果对 B 中的每一个单词 b，b 都是 a 的子集，那么我们称 A 中的单词 a 是通用的。

你可以按任意顺序以列表形式返回 A 中所有的通用单词。

 

示例 1：

输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
输出：["facebook","google","leetcode"]
示例 2：

输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
输出：["apple","google","leetcode"]
示例 3：

输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
输出：["facebook","google"]

示例 4：

输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
输出：["google","leetcode"]
示例 5：

输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
输出：["facebook","leetcode"]
 

提示：

1 <= A.length, B.length <= 10000
1 <= A[i].length, B[i].length <= 10
A[i] 和 B[i] 只由小写字母组成。
A[i] 中所有的单词都是独一无二的，也就是说不存在 i != j 使得 A[i] == A[j]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// 本题类似统计字符串B中的所有字符都出现在字符串数组A中的一个字符串元素中
// 利用字符计数，做hash比对，需要注意B中元素之间交叉的情况，字符计数取最大值
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        if (B.empty() || A.empty()) {
            return A;
        }

        int b[26] = {0};
        int tmp[26] = {0};
        for (auto& w : B) {
            memset(tmp, 0, sizeof(tmp));
            for (auto ch : w) {
                ++tmp[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                b[i] = max(b[i], tmp[i]);
            }
        }

        vector<string> res;
        int a[26] = {0};
        for (auto& w : A) {
            memset(a, 0, sizeof(a));
            for (auto ch : w) {
                ++a[ch - 'a'];
            }

            bool flag = true;
            for (int i = 0; i < 26; ++i) {
                if (a[i] < b[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(w);
            }
        }
        return res;
    }
};
