/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses
*/
// IP地址由4个字段组成，每个字段最大为255
// 通过对每个字段分1~3个数字组成，进行回溯检测，跳过不合法的IP形式
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty() || s.size() > 12) {
            return vector<string>();
        }

        vector<int> ips;
        vector<string> res;
        backtrace(s, 0, s.size() - 1, 4, ips, res);
        return res;
    }

    void backtrace(string& s, int start, int end, int fields, vector<int>& ips, vector<string>& res) {
        if (start > end) {
            return;
        }
        string num;
        int value = 0;
        if (fields == 1) {
            num = string(s, start, end - start + 1);
            // 避免出现0xx的情况
            if (num.size() > 1 && num[0] == '0') {
                return;
            }
            value = stoi(num);
            if (value > 255) {
                return;
            }
            ostringstream oss;
            for (int i = 0, sz = ips.size(); i < sz; ++i) {
                oss << ips[i] << ".";
            }
            oss << value;
            res.push_back(move(oss.str()));
            return;
        }

        for (int i = 0; i < 3 && start + i <= end; ++i) {
            num = string(s, start, i+1);
            if (num.size() > 1 && num[0] == '0') {
                break;
            }
            int value = stoi(num);
            if (value >  255) {
                break;
            }
            ips.push_back(value);
            backtrace(s, start + i + 1, end, fields - 1, ips, res);
            ips.pop_back();
        }
    }
};
