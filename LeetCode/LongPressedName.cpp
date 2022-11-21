class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        string tmp;
        deque<char> d(typed.cbegin(), typed.cend());
        for(int i = 0; i != name.size(); ++i) {
            while (d.size() != 0 && d.front() != name[i] ) {
                if (d[0] != name[i] && (i - 1 >= 0) ? d[0] != name[i - 1]: true) return false;
                d.erase(d.cbegin());    
            }
            if (d.size() == 0) return false;
            tmp.push_back(d[0]);
            d.erase(d.cbegin());
        }
        auto it = find_if(d.cbegin(), d.cend(), [=] (const char &x) {
            return x != name.back();
        });
        if (d.size() != 0 && it != d.cend()) return false;
        return tmp == name;
    }
};

int main() {
  
  
  return 0;  
}
