/*
给定一组字符，使用原地算法将其压缩。

压缩后的长度必须始终小于或等于原数组长度。

数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。

在完成原地修改输入数组后，返回数组的新长度。

进阶：
你能否仅使用O(1) 空间解决问题？


示例 1：

输入：
["a","a","b","b","c","c","c"]

输出：
返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]

说明：
"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。
示例 2：

输入：
["a"]

输出：
返回1，输入数组的前1个字符应该是：["a"]

说明：
没有任何字符串被替代。
示例 3：

输入：
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

输出：
返回4，输入数组的前4个字符应该是：["a","b","1","2"]。

说明：
由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
注意每个数字在数组中都有它自己的位置。
注意：

所有字符都有一个ASCII值在[35, 126]区间内。
1 <= len(chars) <= 1000。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-compression
*/
// 使用栈来做个数的反向插入
class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) {
            return 0;
        }
        char pre = chars[0];
        int cnt = 1, len = 0, sz = chars.size();
        stack<int> st;
        for (int i = 1; i <= sz; ++i) {
            if (i < sz && pre == chars[i]) {
                ++cnt;
            } 
            if (i == sz || pre != chars[i]) {
                chars[len] = pre;
                ++len;
                if (cnt > 1) {
                    while (cnt) {
                        st.push(cnt % 10);
                        cnt /= 10;
                    }
                    while (!st.empty()) {
                        chars[len] = '0' + st.top();
                        ++len;
                        st.pop();
                    }
                }
                if (i == sz) {
                    break;
                }
                pre = chars[i];
                cnt = 1;
            }
        }
        return len;
    }
};
