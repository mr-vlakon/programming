class CombinationIterator {
public:
    void generate(const string &str, int i, string &s) {
        if (i == str.size()) {
            if (s.size() == length)
                result.push_back(s);
            return;
        }
        if (i > str.size()) {
            return;
        }
        s.push_back(str[i]);
        generate(str, i + 1, s);
        s.pop_back();
        generate(str, i + 1, s);

    }
    CombinationIterator(string characters, int combinationLength) : s(characters), 
        length(combinationLength) 
    {
        string empty;
        generate(s, 0, empty);
    }
    
    string next() {
        ++i;
        return result[i - 1]; 
    }
    
    bool hasNext() {
        if (i < result.size()) {
            return true;
        }
        return false;
    }
private:
    int i = 0;
    vector<string> result;
    int length = 0;
    string s;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
  
  
  return 0;  
}
