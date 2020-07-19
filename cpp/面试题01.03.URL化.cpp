/*
URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）

示例1:

 输入："Mr John Smith    ", 13
 输出："Mr%20John%20Smith"
示例2:

 输入："               ", 5
 输出："%20%20%20%20%20"
提示：

字符串长度在[0, 500000]范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-to-url-lcci
*/
// 先统计空格个数
// 根据空格个数，从尾部确定每个字符的新索引位置，然后进行移动
class Solution {
public:
    string replaceSpaces(string S, int length) {
        int space = 0;
        for (int i = 0; i < length; ++i) {
            if (S[i] == ' ') ++space;
        }

        if (space == 0) return S;

        int new_len = length + space * 2;
        int offset = new_len - 1;
        for (int i = length - 1; i >= 0 && space > 0; --i) {
            if (S[i] != ' ') {
                S[offset] = S[i];
                --offset;
            } else {
                S[offset] = '0';
                S[offset - 1] = '2';
                S[offset - 2] = '%';
                offset -= 3;
                --space;
            }
        }
        return S.substr(0, new_len);
    }
};
