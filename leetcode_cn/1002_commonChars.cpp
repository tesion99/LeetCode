/*
给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。

 

示例 1：

输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：

输入：["cool","lock","cook"]
输出：["c","o"]
 

提示：

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] 是小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-common-characters
*/
// 用首字母初始化结果集
// hash记录其他每个字符串的字符频率结果
// 对照结果集，取两者对应字符频率出现次数的最小值
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        if (A.empty()) {
            return vector<string>();
        }

        int res[26] = {0};
        // 先遍历第一个单词
        for (auto ch : A[0]) {
            ++res[ch - 'a'];
        }

        int tmp[26] = {0};
        for (int i = 0; i < A.size(); ++i) {
            if (A[i].empty()) {
                return vector<string>();
            }
            memset(tmp, 0, sizeof(tmp));
            for (auto ch : A[i]) {
                ++tmp[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                res[i] = min(res[i], tmp[i]);
            }
        }
        
        vector<string> ans;
        // 回写结果
        for (int i = 0; i < 26; ++i) {
            if (res[i] <= 0) continue;
            
            char ch = 'a' + i;
            ans.insert(ans.end(), res[i], string(1, ch));
        }
        return ans;
    }
};
