class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v;
        for (const auto &e: operations) {
            if (e != "C" && e != "D" && e != "+") {
                v.push_back(stoi(e));
            } else if (e == "C") {
                v.erase(--v.cend());
            } else if (e == "D") {
                int tmp = v.back() * 2;
                v.push_back(tmp);
            } else if (e == "+") {
                int tmp = v.back() + v[v.size() - 2];
                v.push_back(tmp);
            }
        }
        return accumulate(v.cbegin(), v.cend(), 0);
    }
};

int main() {
  
  
  return 0;  
}
