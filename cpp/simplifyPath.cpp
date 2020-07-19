/*
以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；
两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。
最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

 

示例 1：

输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/simplify-path
*/
class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty() || path.size() == 0) return path;

        stack<string> st;
        int pre = 0;
        for (int i = 1, sz = path.size(); i < sz; ++i) {
            while (i < sz && path[i] != '/') ++i;

            // 出现"//情况"
            if (i - pre == 1) {
                pre = i;
                continue;
            }

            string str(path.c_str() + pre + 1, i - pre - 1);
            pre = i;
            if (str == "..") {
                if (!st.empty()) {
                    st.pop();
                }
                continue;
            }

            if (str == ".") continue;

            st.push(move(str));

        }

        string res;
        res.reserve(path.size());
        while (!st.empty()) {
            string & str = st.top();
            res.insert(0, str);
            res.insert(0, "/");
            st.pop();
        }

        if (res.empty()) res = "/";

        return res;
    }
};
