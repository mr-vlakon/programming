class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        lst.insert(lst.cend(), homepage);
        iter = lst.begin();
    }
    
    void visit(string url) {
        auto it = iter;
        ++it;
        lst.erase(it, lst.cend());
        lst.insert(lst.cend(), url);
        iter = --lst.end();
    }
    
    string back(int steps) {
        while (steps && iter != lst.cbegin()) {
            --steps;
            --iter;
        }
        return *iter;
    }
    
    string forward(int steps) {
        while (steps && iter != lst.cend()) {
            --steps;
            ++iter;
        }
        if (iter == lst.cend()) {
            --iter;
            return *iter;
        }
        return *iter;       
    }
private:
    list<string>::iterator iter;
    list<string> lst;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {
  
  

  return 0;
}
