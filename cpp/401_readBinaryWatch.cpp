/*
二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。

每个 LED 代表一个 0 或 1，最低位在右侧。
例如，上面的二进制手表读取 “3:25”。

给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

案例:

输入: n = 1
返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 

注意事项:

输出的顺序没有要求。
小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-watch
*/
// 小时的亮灯个数 + 分钟的亮灯个数 = num
// 分别记录小时灯个数、分钟灯个数
// 先统计分钟灯个数的组合，当灯个数为0时，再计算小时灯个数的组合
// 当两个灯剩余都为0时，组合完毕，记录结果
static int hours[4] = {1, 2, 4, 8};
static int minutes[6] = {1, 2, 4, 8, 16, 32};

class Solution {
public:
        vector<string> readBinaryWatch(int num) {
        if (num <= 0) {
            return vector<string>(1, "0:00");
        }

        vector<string> res;
        int hour = 0, minute = 0;

        for (int i = 0; i <= num; ++i) {
            backtrace(i, 0, hour, num - i, 0, minute, res);
        }
        return res;
    }
     void backtrace(int h_num, int h_start, int hour, int m_num, int m_start, int minute, vector<string>& res) {
        if (h_num < 0 || h_num > 4 || m_num < 0 || m_num > 6) {
            return;
        }
        if (hour > 11 || minute > 59) {
            return;
        }
        if (h_num == 0 && m_num == 0) {
            char buf[8] = {0};
            sprintf(buf, "%d:%02d", hour, minute);
            res.push_back(string(buf));
        }

        if (m_num != 0) {
            for (int i = m_start; i < 6; ++i) {
                backtrace(h_num, h_start, hour, m_num - 1, i + 1, minute + minutes[i], res);
            }
        } else {
            for (int i = h_start; i < 4; ++i) {
                backtrace(h_num - 1, i + 1, hour + hours[i], m_num, m_start, minute, res);
            }
        }

    }
};
