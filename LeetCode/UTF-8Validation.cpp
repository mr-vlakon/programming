class Solution {
public:
    bool check(const int &x) {
        return ((1 << 7)&x) == 0 || ((1 << 6)&x) != 0;
    }
    bool validUtf8(vector<int>& data) {
        int start = 0;
        while (start != data.size()) {
            if (((1 << 7) & data[start]) == 0) {
                ++start;
            } else if ((((1 << 7)&data[start]) != 0) && ((1 << 6)&data[start]) != 0 && ((1 << 5) & data[start]) == 0) {
                ++start;
                if (start == data.size()) return false;
                if (check(data[start])) return false;
                ++start;
            } else if ((((1 << 7)&data[start]) != 0) && ((1 << 6)&data[start]) != 0 && ((1 << 5) & data[start]) != 0 && ((1 << 4) & data[start]) == 0) {
                ++start;
                if (start == data.size()) return false;
                if (check(data[start])) return false;
                ++start;
                if (start == data.size()) return false;
                if (check(data[start])) return false;
                ++start;
            } else if ((((1 << 7)&data[start]) != 0) && ((1 << 6)&data[start]) != 0 && ((1 << 5) & data[start]) != 0 && ((1 << 4) & data[start]) != 0 && ((1 << 3) & data[start]) == 0) {
                ++start;
                if (start == data.size()) return false;
                if (check(data[start])) return false;
                ++start;
                if (start == data.size()) return false;
                if (check(data[start])) return false;
                ++start;
                if (start == data.size()) return false;
                if (check(data[start])) return false;
                ++start;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {



  return 0;
}
