struct LFUNode {
    int value;
    int freq;
    std::list<int>::iterator it;
};

class LFUCache {
private:
    int capacity;
    int minFrequency;
    std::unordered_map<int, LFUNode> keyMap;
    std::unordered_map<int, std::list<int>> freqMap;

    void counter(int key) {
        int oldFreq = keyMap[key].freq;
        int newFreq = oldFreq + 1;

        freqMap[oldFreq].erase(keyMap[key].it);
        keyMap[key].freq = newFreq;

        freqMap[newFreq].push_front(key);
        keyMap[key].it = freqMap[newFreq].begin();

        if (freqMap[oldFreq].empty() && oldFreq == minFrequency) {
            minFrequency++;
        }
    }


public:
    LFUCache(int capacity) : capacity(capacity), minFrequency(0) {
        keyMap.reserve(capacity);
    }
    
    int get(int key) {
        auto it = keyMap.find(key);
        if (it == keyMap.end()) {
            return -1;
        }

        counter(key);

        return it->second.value;
    }
    
    void put(int key, int value) {
        if (keyMap.count(key)) {
            keyMap[key].value = value;
            counter(key);
            return;
        }

        if (keyMap.size() >= capacity) {
            int keyToRemove = freqMap[minFrequency].back();
            freqMap[minFrequency].pop_back();
            keyMap.erase(keyToRemove);
        }

        minFrequency = 1;
        freqMap[1].push_front(key);
        keyMap[key] = {value, 1, freqMap[1].begin()};

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */