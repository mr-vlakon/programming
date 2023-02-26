class Solution {
public:
    void generate(const vector<string> &arr, int i, string &s, unordered_set<char> &us) {
        if (i == arr.size()) {
            answer = max(answer, static_cast<int>(s.size()));
            return;
        }
        if (i > arr.size()) {
            return;
        }
        bool status = true;
        unordered_set<char> us1 = us;
        for (const auto &e: arr[i]) {
            if (us.find(e) != us.end()) {
                status = false;
                break;
            }
            us.insert(e);
        }
        if (status) {
            s += arr[i]; 
            generate(arr, i + 1, s, us);
            s.erase(s.begin() + s.size() - arr[i].size(), s.end());
            generate(arr, i + 1, s, us1);
        } else {
            generate(arr, i + 1, s, us1);
        }
    }
    int maxLength(vector<string>& arr) {
        string str;
        unordered_set<char> us;
        generate(arr, 0, str, us);
        return answer;
    }
private:
    int answer = 0;
};

int main() {

  
  
  return 0;  
}
