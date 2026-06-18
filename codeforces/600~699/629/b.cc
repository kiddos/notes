#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  constexpr int max_days = 367;
  vector<int> male(max_days+1), female(max_days+1);
  for (int i = 0; i < n; ++i) {
    char c = '\0';
    cin >> c;
    int a = 0, b = 0;
    cin >> a >> b;
    if (c == 'M') {
      male[a]++;
      male[b+1]--;
    } else if (c == 'F') {
      female[a]++;
      female[b+1]--;
    }
  }

  int ans = 0;
  for (int d = 0, m = 0, f = 0; d <= max_days; ++d) {
    m += male[d];
    f += female[d];
    int pair = min(m, f);
    ans = max(ans, pair * 2);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
