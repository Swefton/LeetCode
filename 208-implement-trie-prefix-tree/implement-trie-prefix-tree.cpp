class Trie {
private:
    Trie* wordSearch(string word) {
        Trie* currentNode = this;

        for (auto character : word) {
            int index = character - 'a';
            if (currentNode->children && currentNode->children[index]) {
                currentNode = currentNode->children[index];
            } else {
                return nullptr;
            }
        }

        return currentNode;
    }
public:
    static const int ALPHABET_SIZE = 'z'-'a'+1;

    Trie* children[ALPHABET_SIZE];
    bool isLeaf;

    Trie() {
        isLeaf = false;
        for (int i = 0; i < ALPHABET_SIZE; ++i)  {
            children[i] = nullptr;
       }
    }
    
    void insert(string word) {
        Trie* currentNode = this;
        for (auto letter : word) {
            int index = letter - 'a';
            
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new Trie();
            }
            currentNode = currentNode->children[index];
        }

        currentNode->isLeaf = true;
    }
    
    bool search(string word) {
        auto leaf = wordSearch(word);
        return (leaf && leaf->isLeaf) ? true : false;
    }
    
    bool startsWith(string prefix) {
        auto leaf = wordSearch(prefix);
        return !(leaf == nullptr);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */