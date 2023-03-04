class Solution {
public:
    int splitNum(int num) {
        string tmp = to_string(num);
        string first;
        string second;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i != tmp.size(); ++i) {
            if ((i % 2) == 0) {
                first.push_back(tmp[i]);
            } else {
                second.push_back(tmp[i]);
            }
        }
        return stoi(first) + stoi(second);
    }
};

int main() {
  
 
  return 0;
}
