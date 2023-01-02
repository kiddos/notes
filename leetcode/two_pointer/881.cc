#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int n = people.size();
    int l = 0, r = n-1;
    int ans = 0;
    while (l <= r) {
      if (people[l] + people[r] <= limit) {
        l++;
        r--;
      } else {
        r--;
      }
      ans++;
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> people = {1, 2};
  int limit = 3;
  int ans = Solution().numRescueBoats(people, limit);
  assert(ans == 1);

  // code here...
  return 0;
}
