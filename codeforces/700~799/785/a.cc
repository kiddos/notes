#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == "Tetrahedron") {
      ans += 4;
    } else if (s[i] == "Cube") {
      ans += 6;
    } else if (s[i] == "Octahedron") {
      ans += 8;
    } else if (s[i] == "Dodecahedron") {
      ans += 12;
    } else if (s[i] == "Icosahedron") {
      ans += 20;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
