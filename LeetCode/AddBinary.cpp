class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result(max(a.size(), b.size()) + 1, '0');
        int tmp = 0;
        int perenos = 0;
        for (int i = 0; i != min(a.size(), b.size()); ++i) {
            tmp = (a[i] - '0') + (b[i] - '0');
            if (tmp == 2 && perenos == 0) {
                result[i] = '0';
                perenos = 1;
            } else if (tmp == 2 && perenos == 1) {
                result[i] = '1';
                perenos = 1;
            } else if (tmp == 1 && perenos == 0) {
                result[i] = '1';
            } else if (tmp == 1 && perenos == 1) {
                result[i] = '0';
            } else if (tmp == 0 && perenos == 1) {
                result[i] = '1';
                perenos = 0;
            } 
        }
        if (perenos == 1) {
            result[min(static_cast<int>(a.size()), static_cast<int>(b.size()))] = '1';
            perenos = 0;
        }
        int i = min(static_cast<int>(a.size()), static_cast<int>(b.size()));
        if (a.size() > b.size()) {
            int i = b.size();
            int tmp = 0;
            while (i < a.size()) {
                tmp = (a[i] - '0') + (result[i] - '0');
                if (tmp == 2 && perenos == 0) {
                    result[i] = '0';
                    perenos = 1;
                } else if (tmp == 2 && perenos == 1) {
                    result[i] = '1';
                    perenos = 1;
                } else if (tmp == 1 && perenos == 0) {
                    result[i] = '1';
                } else if (tmp == 1 && perenos == 1) {
                    result[i] = '0';
                } else if (tmp == 0 && perenos == 1) {
                    result[i] = '1';
                    perenos = 0;
                } 
                ++i;
            }
            if (perenos == 1) {
                result[a.size()] = '1';
            }
            perenos = 0;
        } else if (a.size() < b.size()) {
            int i = a.size();
            int tmp = 0;
            while (i < b.size()) {
                tmp = (b[i] - '0') + (result[i] - '0');
                if (tmp == 2 && perenos == 0) {
                    result[i] = '0';
                    perenos = 1;
                } else if (tmp == 2 && perenos == 1) {
                    result[i] = '1';
                    perenos = 1;
                } else if (tmp == 1 && perenos == 0) {
                    result[i] = '1';
                } else if (tmp == 1 && perenos == 1) {
                    result[i] = '0';
                } else if (tmp == 0 && perenos == 1) {
                    result[i] = '1';
                    perenos = 0;
                } 
                ++i;
            }
            if (perenos == 1) {
                result[b.size()] = '1';
            }
       }
        reverse(result.begin(), result.end());
        auto it = find(result.begin(), result.end(), '1');
        if (it == result.end()) {
            return "0";
        }
        return {it, result.end()};
    }
};

int main() {
  
  
  return 0;  
}
