#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      map<pair<int, int>, int> slopes;
      int duplicate = 1;
      for (int j = i+1; j < n; ++j) {
        auto& p1 = points[i];
        auto& p2 = points[j];
        if (p1[0] == p2[0] && p1[1] == p2[1]) {
          duplicate++;
        } else {
          int dx = p1[0] - p2[0], dy = p1[1] - p2[1];
          int g = gcd(dx, dy);
          dx /= g;
          dy /= g;
          slopes[{dx, dy}]++;
        }
      }
      ans = max(ans, duplicate);
      for (auto p : slopes) ans = max(ans, p.second+duplicate);
    }
    return ans;
  }

  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<vector<int>> points(n);
    for (int i = 0; i < n; ++i) {
      int x = 0, y = 0;
      cin >> x >> y;
      points[i] = {x, y};
    }

    int ans = Solution().maxPoints(points);
    cout << ans << endl;
  }
  return 0;
}
