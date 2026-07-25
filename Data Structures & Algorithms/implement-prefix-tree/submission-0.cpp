struct TreeNode {
    unordered_map<char, unique_ptr<TreeNode>> children = {};
    bool endOfWord = false;
};

class PrefixTree {
private:
    TreeNode root;
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        TreeNode* curr = &this->root;
        for (auto& c: word) {
            auto it = curr->children.find(c);
            if (it == curr->children.end()) {
                curr->children[c] = make_unique<TreeNode>();
            }
            curr = curr->children[c].get();
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TreeNode* curr = &this->root;
        for (auto& c: word) {
            auto it = curr->children.find(c);
            if (it == curr->children.end()) return false;
            curr = curr->children[c].get();
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TreeNode* curr = &this->root;
        for (auto& c: prefix) {
            if (auto it = curr->children.find(c); it == curr->children.end()) return false;
            curr = curr->children[c].get();
        }

        return true;
    }
};
