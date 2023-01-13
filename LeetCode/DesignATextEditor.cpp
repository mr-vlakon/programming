class TextEditor {
public:
    TextEditor() : iter(lst.end()){
    }    
    void addText(string text) {
        for (int i = 0; i != text.size(); ++i) {
            iter = lst.insert(iter, text[i]);
            ++iter;
        }  
    }  
    int deleteText(int k) {
        if (iter == lst.begin()) return 0;
        int i = 0;
        auto it = iter;
        --it;
        while (i != k) {
            if (it != lst.begin()) {
                ++i;
                it = lst.erase(it);
                --it;
            } else {
                lst.erase(lst.begin());
                ++i;
                break;
            }
        }
        return i;
    }
    
    string cursorLeft(int k) {
        if (lst.size() == 0) return "";
        if (iter == lst.begin()) return "";
        int i = 0;
        while ((i != k) && (iter != lst.begin())) {
            --iter;
            ++i;
        }
        if (iter == lst.begin()) {
            return "";
        }
        string tmp;
        auto it = iter;
        --it;
        i = 0;
        while ((i < 10) && (it != lst.begin())) {
            tmp.push_back(*it);
            --it;
            ++i;
        }
        if (i != 10) {
            tmp.push_back(*it);
        }
        return {tmp.rbegin(), tmp.rend()};
    }
    
    string cursorRight(int k) {
        int i = 0;
        if (lst.size() == 0) return "";
        while ((i != k) && (iter != lst.end())) {
            ++iter;
            ++i;
        }
        if (iter == lst.begin()) return "";
        string tmp;
        auto it = iter;
        --it;
        i = 0;
        while ((i < 10) && (it != lst.begin())) {
            tmp.push_back(*it);
            --it;
            ++i;
        }
        if (i != 10) {
            tmp.push_back(*it);
        }
        return {tmp.rbegin(), tmp.rend()};
    }
private:
    list<char>::iterator iter;
    list<char> lst;
};

int main() {
  
  
  
  return 0;  
}
