/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    void expand(const vector<NestedInteger> &ns) {
        for (const auto &e: ns) {
            if (e.isInteger()) {
                v.push_back(e.getInteger());
            } else {
                expand(e.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        expand(nestedList);
    }
    
    int next() {
        ++pos;
        return v[pos - 1];     
    }
    
    bool hasNext() {
        return pos < v.size();
    }
private:
    vector<int> v;
    int pos = 0;
};

/*
class NestedIterator {
public:
    void expand(const vector<NestedInteger> &ns) {
        for (const auto &e: ns) {
            if (e.isInteger()) {
                v.push_back(e.getInteger());
            } else {
                for (const auto &p: e.getList()) {
                    if (p.isInteger()) {
                        v.push_back(p.getInteger());
                    } else {
                        expand(p.getList());
                    }
                }
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        expand(nestedList);
    }
    
    int next() {
        ++pos;
        return v[pos - 1];     
    }
    
    bool hasNext() {
        return pos < v.size();
    }
private:
    vector<int> v;
    int pos = 0;
};
*/
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
  
  
  
  
  return 0;  
}
        
