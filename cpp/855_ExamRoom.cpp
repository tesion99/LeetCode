/*
在考场里，一排有 N 个座位，分别编号为 0, 1, 2, ..., N-1 。

当学生进入考场后，他必须坐在能够使他与离他最近的人之间的距离达到最大化的座位上。

如果有多个这样的座位，他会坐在编号最小的座位上。(另外，如果考场里没有人，那么学生就坐在 0 号座位上。)

返回 ExamRoom(int N) 类，它有两个公开的函数：其中，函数 ExamRoom.seat() 会返回一个 int （整型数据），代表学生坐的位置；

函数 ExamRoom.leave(int p) 代表坐在座位 p 上的学生现在离开了考场。每次调用 ExamRoom.leave(p) 时都保证有学生坐在座位 p 上。
 

示例：

输入：["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
输出：[null,0,9,4,2,null,5]
解释：
ExamRoom(10) -> null
seat() -> 0，没有人在考场里，那么学生坐在 0 号座位上。
seat() -> 9，学生最后坐在 9 号座位上。
seat() -> 4，学生最后坐在 4 号座位上。
seat() -> 2，学生最后坐在 2 号座位上。
leave(4) -> null
seat() -> 5，学生最后坐在 5 号座位上。
 

提示：

1 <= N <= 10^9
在所有的测试样例中 ExamRoom.seat() 和 ExamRoom.leave() 最多被调用 10^4 次。
保证在调用 ExamRoom.leave(p) 时有学生正坐在座位 p 上。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/exam-room
*/
// 注意检测0与N-1是否在作为区间中
class ExamRoom {
public:
    ExamRoom(int N) {
        cap_ = N;
    }
    
    int seat() {
        int val = 0;
        if (m_.size() == 1) {
            int tmp = m_.begin()->first;
            if (tmp - 0 > cap_ - 1 - tmp) {
                val = 0;
            } else {
                val = cap_ - 1;
            }
        } else if (m_.size() > 1) {
            map<int,int>::iterator it1, it2;
            it1 = m_.begin();
            it2 = ++m_.begin();
            // 初始化，防止第一个数作为不是0
            int start= 0 - it1->first, diff = it1->first - start;
            val = start + diff / 2;
            while (it2 != m_.end()) {
                if (it2->first - it1->first > diff) {
                    diff = it2->first - it1->first;
                    int tmp = diff / 2;
                    if (tmp > val - start) {
                        start = it1->first;
                        val = start + tmp;
                    }
                }
                it1 = it2;
                ++it2;
            }
            // 判断最后一个座位，没有被占据，加入检测
            if (it1->first != cap_ - 1) {
                int tmp = (cap_ - it1->first) / 2;
                if (tmp > val - start) {
                    start = it1->first;
                    val = start + tmp;
                }
            }
        }

        m_[val] = 1;
        return val;
    }
    
    void leave(int p) {
        m_.erase(p);
    }
private:
    map<int, int> m_;
    int cap_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
