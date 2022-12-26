class Allocator {
public:
    Allocator(int n) {
        v.resize(n, -1);
    }
    
    int allocate(int size, int mID) {
        auto it = find(v.cbegin(), v.cend(), -1);
        int start = it - v.cbegin();
        int end = 0;
        bool status = false;
        for (int i = start; i != v.size(); ++i) {
            if (v[i] != -1) {
                if ((i - start) >= size) {
                    status = true;
                    end = i + 1;
                    break;
                } else {
                    start = i + 1;
                }
            } else if (v[i] == -1) {
                if ((i - start + 1) >= size) {
                    status = true;
                    end = i + 1;
                    break;
                }
            }
        }
        if (!status)
            return -1;
        int answer = start;
        while (start < end) {
            v[start] = mID;
            um[mID].push_back(start);
            ++start;
        }
        return answer;
    }
    
    int free(int mID) {
        auto count = um[mID].size();
        for (const auto &e: um[mID]) {
            v[e] = -1;
        }
        um.erase(mID);
        return count;
    }
private:
    unordered_map<int, vector<int>> um;
    vector<int> v;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

int main() {
  
  
  
  return 0;  
}
