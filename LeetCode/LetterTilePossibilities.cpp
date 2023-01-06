class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> us;
        int answer = 0;
        sort(tiles.begin(), tiles.end());
        do {
            string tmp;
            for (int i = 0; i != tiles.size(); ++i) {
                tmp.push_back(tiles[i]);
                us.insert(tmp);
            }
        } while(next_permutation(tiles.begin(), tiles.end()));
        return us.size();
    }
};

int main() {
  
  
  
  
  return 0;  
}
