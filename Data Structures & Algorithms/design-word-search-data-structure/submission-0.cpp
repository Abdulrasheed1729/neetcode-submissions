struct DictNode {
    unordered_map<char, unique_ptr<DictNode>> children = {};
    bool endOfWord = false;
};

class WordDictionary {
private:
    DictNode root;
public:
    WordDictionary() {
        root = DictNode();
    }
    
    void addWord(string word) {
        DictNode* curr = &this->root;
        for (auto& c: word) {
            auto it = curr->children.find(c);
            if (it == curr->children.end()) {
                curr->children[c] = make_unique<DictNode>();
            }
            curr = curr->children[c].get();
        }
        curr->endOfWord = true;
    }

    bool searchFrom(DictNode* node, const string& word, size_t i) {
        if (i == word.size()) return node->endOfWord;
        
        char c = word[i];

        if (c == '.') {
            for (auto& [ch, child_node]: node->children) {
                if (searchFrom(child_node.get(), word, i + 1)) return true;
            }

            return false;
        }
        if (node->children.find(c) == node->children.end()) {
            return false;
        }
        return searchFrom(node->children[c].get(), word, i + 1);
    }
    
    bool search(string word) {
        return searchFrom(&this->root, word, 0);
    }
};
