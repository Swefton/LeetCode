struct LRUNode {
    int key;
    int value;
};

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, std::list<LRUNode>::iterator> cache;
    std::list<LRUNode> order;

public:
    LRUCache(int capacity) : capacity(capacity) {
        cache.reserve(capacity);
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;

        order.splice(order.begin(), order, it->second);

        return it->second->value;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        if (it != cache.end()) {
            it->second->value = value;

            order.splice(order.begin(), order, it->second);
            return;
        }

        if (order.size() == capacity) {
            auto last = order.back();
            cache.erase(last.key);
            order.pop_back();
        }

        order.push_front({key, value});
        cache[key] = order.begin();
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */