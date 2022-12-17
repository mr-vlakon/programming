class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> lst;
        int i = 1;
        while (i <= n) {
            lst.insert(lst.cend(), i);
            ++i;
        }
        int j = 1;
        int prev = 1;
        auto it = lst.begin();
        while (lst.size() != 1) {
            while (j != (prev + k - 1)) {
                ++it;
                if (it == lst.end()) 
                    it = lst.begin();
                ++j;
            }
            auto pr = it;
            ++pr;
            if (pr == lst.end())
                pr = lst.begin();
            lst.erase(it);
            it = pr;
            prev = j;
        }
        return *(lst.cbegin());
    }   
};

int main() {
  
  
  
  
  return 0;  
}
