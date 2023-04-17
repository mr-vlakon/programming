/*
class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        us.insert(word);
    }
    
    bool search(string word) {
        return (us.find(word) != us.cend());
    }
    
    bool startsWith(string prefix) {
        for (const auto &prev: us) {
            if (prefix > prev)
                continue;
            auto result = std::mismatch(prefix.begin(), prefix.end(), prev.begin());
            if (result.first == prefix.end()) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_set<string> us;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
*/
class Trie {
public:
    Trie() {
        
    }
    void construct(string &word) {
        if (word.size() == 0) return;
        if (us.find(word) != us.cend()) return;
        else us.insert(word);
        word.pop_back();
        construct(word);
    }

    void insert(string word) {
        searchable.insert(word);
        if (us.find(word) != us.cend()) return;
        construct(word);
    }
    
    bool search(string word) {
        return searchable.find(word) != searchable.cend();
    }
    
    bool startsWith(string prefix) {
        return us.find(prefix) != us.cend();
    }
private:
    unordered_set<string> searchable;
    unordered_set<string> us;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main() {
  
    
  return 0;   
}
