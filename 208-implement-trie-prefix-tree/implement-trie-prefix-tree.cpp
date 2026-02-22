class Trie {
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
        Trie* currentNode = this;

        for (auto character : word) {
            int index = character - 'a';
            if (currentNode->children && currentNode->children[index]) {
                currentNode = currentNode->children[index];
            } else {
                return false;
            }
        }

        return currentNode->isLeaf ? true : false;
    }
    
    bool startsWith(string prefix) {

        Trie* currentNode = this;

        for (auto character : prefix) {
            int index = character - 'a';
            if (currentNode->children && currentNode->children[index]) {
                currentNode = currentNode->children[index];
            } else {
                return false;
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */