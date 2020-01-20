/*
一个网站域名，如"discuss.leetcode.com"，包含了多个子域名。作为顶级域名，常用的有"com"，下一级则有"leetcode.com"，最低的一级为"discuss.leetcode.com"。当我们访问域名"discuss.leetcode.com"时，也同时访问了其父域名"leetcode.com"以及顶级域名 "com"。

给定一个带访问次数和域名的组合，要求分别计算每个域名被访问的次数。其格式为访问次数+空格+地址，例如："9001 discuss.leetcode.com"。

接下来会给出一组访问次数和域名组合的列表cpdomains 。要求解析出所有域名的访问次数，输出格式和输入格式相同，不限定先后顺序。

示例 1:
输入: 
["9001 discuss.leetcode.com"]
输出: 
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
说明: 
例子中仅包含一个网站域名："discuss.leetcode.com"。按照前文假设，子域名"leetcode.com"和"com"都会被访问，所以它们都被访问了9001次。

注意事项：

 cpdomains 的长度小于 100。
每个域名的长度小于100。
每个域名地址包含一个或两个"."符号。
输入中任意一个域名的访问次数都小于10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subdomain-visit-count
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// hash计数
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        map<string, int> m;
        istringstream iss;
        int times = 0;
        string domain;
        for (auto& s : cpdomains) {
            if (s.empty()) continue;
            iss.clear();
            domain.clear();
            iss.str(s);
            times = 0;
            iss >> times >> domain;
            if (times <= 0 || domain.empty()) {
                continue;
            }
            m[domain] += times;
            size_t start = 0, end = 0, sz = domain.size();
            string tmp;
            while (start < sz && (end = domain.find('.', start)) != string::npos) {
                //tmp = domain.substr(end + 1, sz -  end);
                m[domain.substr(end + 1, sz - end)] += times;
                start = end + 1;
            }
        }

        ostringstream oss;
        for (auto& p : m) {
            oss.str("");
            oss << p.second << " " << p.first;
            res.push_back(oss.str());
        }
        return res;
    }
};
