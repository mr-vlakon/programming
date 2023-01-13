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
            ++i;
            if (it != lst.begin()) {
                it = lst.erase(it);
                --it;
            } else {
                lst.erase(lst.begin());
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
        auto it = iter;
        --it;
        i = 0;
        while ((i < 10) && (it != lst.begin())) {
            --it;
            ++i;
        }
        if (i == 10) {
            ++it;
        } 
        return {it, iter};
    }
    
    string cursorRight(int k) {
        if (lst.size() == 0) return "";
        int i = 0;
        while ((i != k) && (iter != lst.end())) {
            ++iter;
            ++i;
        }
        if (iter == lst.begin()) return "";
        auto it = iter;
        --it;
        i = 0;
        while ((i < 10) && (it != lst.begin())) {
            --it;
            ++i;
        }
        if (i == 10) {
            ++it;
        } 
        return {it, iter};
    }
private:
    list<char>::iterator iter;
    list<char> lst;
};

int main() {
  
  
  
  return 0;  
}
