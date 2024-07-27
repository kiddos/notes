#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    for (char& c : version1) if (c == '.') c = ' ';
    for (char& c : version2) if (c == '.') c = ' ';
    istringstream s1(version1);
    istringstream s2(version2);
    int v1 = 0, v2 = 0;
    while (true){
      if (!(s1 >> v1)) v1 = 0;
      if (!(s2 >> v2)) v2 = 0;
      if (!s1 && !s2) return 0;
      if (v1 > v2) return 1;
      if (v2 > v1) return -1;
    }
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string version1, version2;
    cin >> version1 >> version2;
    int ans = Solution().compareVersion(version1, version2);
    cout << ans << endl;
  }

  return 0;
}
