#include <bits/stdc++.h>

using namespace std;

// Compare Version Numbers
//
// interesting way to use stringstream

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    for (char& c : version1)
      if (c == '.') c = ' ';
    for (char& c : version2)
      if (c == '.') c = ' ';
    stringstream s1(version1);
    stringstream s2(version2);
    int v1 = 0, v2 = 0;
    while (true) {
      if (!(s1 >> v1)) v1 = 0;
      if (!(s2 >> v2)) v2 = 0;
      if (!s1 && !s2) return 0;
      if (v1 > v2) return 1;
      if (v2 > v1) return -1;
    }
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string version1 = "1.01";
  string version2 = "1.001";
  int ans = Solution().compareVersion(version1, version2);
  assert(ans == 0);
  return 0;
}
