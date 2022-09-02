class Solution {
public:
    string maxValue(string n, int x) {
        bool status = false;
        if (n[0] == '-') {
            status = true;
        }
        char s = x + '0';
        auto it = n.cbegin();
        if (!status) {
            it = find_if(n.cbegin(), n.cend(), [=](const char &c) {
               return s > c; 
            });
        } else {
            it = find_if(n.cbegin(), n.cend(), [=](const char &c) {
               return s < c; 
            });

        }
        n.insert(it, s);
        return n;
    }
};

int main() {

  return 0;  
}
