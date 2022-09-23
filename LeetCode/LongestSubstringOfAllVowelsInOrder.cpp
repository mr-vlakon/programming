class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int max = 0;
        auto it = find(word.cbegin(), word.cend(), 'a');
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, size_t> vow;
        int index = 0;
        while (index != vowels.size()) {
            vow[vowels[index]] = index;
            ++index;
        }
        while (it != word.cend()) {
            int cnt = 1;
            auto beg = it;
            while (it != word.cend() && 
                   (*it == *(it + 1) || (vow[*(it + 1)] - vow[*it] == 1))) {
                ++cnt;
                ++it;
            } 
            ++it;
            unordered_set<char> st(beg, it);
            it = find(it, word.cend(), 'a');
            if (st.size() != 5) continue;
            if (cnt > max)
                max = cnt;
        }
        return max;
    }   
};

int main() {
  
  
  return 0;  
}
