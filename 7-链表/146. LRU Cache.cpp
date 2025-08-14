// https://leetcode.com/problems/lru-cache/

class LRUCache
{
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> map; // 哈希表，用于快速查找
    list<int> lst;                                          // 双向链表（存储key），用于记录LRU，越前面的结点越常访问
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        int value;
        if (map.find(key) == map.end())
        {
            return -1;
        }
        else
        {
            auto it = map[key].second;
            // 将访问的结点移动至链表最首端
            lst.erase(it);                 // 先删除
            lst.push_front(key);           // 再放到首端
            map[key].second = lst.begin(); // 更新map中key对应的迭代器
            return map[key].first;
        }
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            // 有记录，需要先删除
            lst.erase(map[key].second);
            // 新修改的放在队列首端
            lst.push_front(key);
            // 修改哈希表
            map[key] = pair<int, list<int>::iterator>{value, lst.begin()};
        }
        else
        {
            if (lst.size() < capacity)
            {
                // 新修改的放在队列首端
                lst.push_front(key);
                // 修改哈希表
                map[key] = pair<int, list<int>::iterator>{value, lst.begin()};
            }
            else
            {
                // 删除最远最少使用的结点
                int LRU_key = lst.back();
                map.erase(LRU_key);
                lst.pop_back();
                // 新修改的放在队列首端
                lst.push_front(key);
                // 修改哈希表
                map[key] = pair<int, list<int>::iterator>{value, lst.begin()};
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */