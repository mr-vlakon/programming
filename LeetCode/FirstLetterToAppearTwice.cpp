class Solution {
public:
    char repeatedCharacter(string s) {
        vector<char> v;
        for (const auto &e: s) {
            if (find(v.cbegin(), v.cend(), e) != v.cend()) {
                return e;
            } else
                v.push_back(e);
        }
        char c = 'c';
        return c;
    }
};

int main() {

  
  return 0;
}
