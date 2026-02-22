class WordDictionary {
private:
    struct Node;
    Node* root;

    struct Node {
        Node* children[26];
        bool isEndOfWord;

        Node() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    bool dfs(const string& word, int index, Node* curr) {
            if (index == word.length()) {
                return curr->isEndOfWord;
            }
    
            char c = word[index];
    
            if (c == '.') {
                for (int i = 0; i < 26; i++) {
                    if (curr->children[i] != nullptr) {
                        if (dfs(word, index + 1, curr->children[i])) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                int idx = c - 'a';
                if (curr->children[idx] == nullptr) {
                    return false;
                }
                return dfs(word, index + 1, curr->children[idx]);
            }
        }
    
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        auto currentNode = this->root;
        for (auto character : word) {
            int i = character - 'a';
            if (!currentNode->children[i]) {
                currentNode->children[i] = new Node();
            }
            currentNode = currentNode->children[i];
        }
        currentNode->isEndOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, this->root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */