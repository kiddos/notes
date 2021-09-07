#include <bits/stdc++.h>

using namespace std;

// The Number of Weak Characters in the Game
//
// this one is quite difficult for me to find a O(n log n) solution
// the naive solution is O(n^2).
// However, the constraints require a O(n) or O(n log n) solution
//
// the idea is to sort the characters using 1 of its properties
// so the last character should have the largest of this property
// starting from the last character,
// every character before this character should have less than or equal amount of this property
// so for every character starting from the right
// if current character has both property less than the max of property
// then current character can be consider weak

class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end(), [&](auto& p1, auto& p2) {
      if (p1[0] == p2[0]) {
        return p1[1] > p2[1];
      }
      return p1[0] < p2[0];
    });

    int n = properties.size();
    int ans = 0;
    int max_attack = 0, max_defense = 0;
    for (int i = n - 1; i >= 0; --i) {
      int attack = properties[i][0], defense = properties[i][1];
      if (attack < max_attack && defense < max_defense) {
        ans++;
      }
      max_attack = max(max_attack, attack);
      max_defense = max(max_defense, defense);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> properties = {{5, 5}, {6, 3}, {3, 6}};
  int ans = Solution().numberOfWeakCharacters(properties);
  assert(ans == 0);

  properties = {{2, 2}, {3, 3}};
  ans = Solution().numberOfWeakCharacters(properties);
  assert(ans == 1);

  properties = {{1, 5}, {10, 4}, {4, 3}};
  ans = Solution().numberOfWeakCharacters(properties);
  assert(ans == 1);
  return 0;
}
