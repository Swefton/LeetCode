struct trieNode {
    trieNode* children[26] = {};
    int score = 0;
};

class MapSum {
    private:
        std::unordered_map<std::string, int> nodeSum;
        trieNode* root;
    public:
        MapSum() {
            root = new trieNode;
        }

        void insert(string key, int val) {
            int delta = val - nodeSum[key];
            nodeSum[key] = val;
            auto curr = root;

            for (auto i : key) {
                int idx = i - 'a';
                if (!curr->children[idx]) curr->children[idx] = new trieNode();
                curr = curr->children[idx];
                curr->score += delta;
            }
        }

        int sum(string prefix) {
            auto curr = root;
            for (auto i : prefix) {
                int idx = i - 'a';
                if (!curr->children[idx]) return 0;
                curr = curr->children[idx];
            }

            return curr->score;
        }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */