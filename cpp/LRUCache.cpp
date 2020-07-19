/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 2 // 缓存容量  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
*/

class LRUCache {
public:
    struct data {
        int key;
        int value;

        data(int k, int v) : key(k), value(v) {}
    };

    typedef shared_ptr<data> data_ptr;
    typedef list<data_ptr> data_list;
    typedef data_list::iterator iter_type;
    typedef map<int, iter_type> key_type;

public:
    LRUCache(int capacity) {
        size_ = 0;
        cap_ = capacity;
    }

    int get(int key) {
        auto it = keys_.find(key);
        int value = -1;
        if (it != keys_.end()) {
            auto ptr = *it->second;
            datas_.erase(it->second);
            datas_.push_front(ptr);
            keys_[key] = datas_.begin();
            value = ptr->value;
        }

        return value;
    }

    void put(int key, int value) {
        auto it = keys_.find(key);
        data_ptr ptr;
        if (size_ < cap_) {
            if (it == keys_.end()) {
                ptr = data_ptr(new data(key, value));
                ++size_;
            } else {
                auto lit = it->second;
                ptr = *lit;
                ptr->value = value;
                datas_.erase(lit);
            }

            datas_.push_front(ptr);
            keys_[key] = datas_.begin();

        } else {
            if (it == keys_.end()) {
                ptr = data_ptr(new data(key, value));
                auto last = datas_.back();
                keys_.erase(last->key); // 没有key, 直接删除
                datas_.pop_back();
            } else {
                auto lit = it->second;
                ptr = *lit;
                ptr->value = value;
                datas_.erase(lit);
            }

            datas_.push_front(ptr);
            keys_[key] = datas_.begin();
        }
    }
private:
    data_list datas_;
    key_type keys_;
    size_t size_;
    size_t cap_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
