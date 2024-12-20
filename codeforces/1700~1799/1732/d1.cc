#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int q = 0;
  cin >> q;
  set<i64> added;
  map<i64, i64> answer;
  for (int i = 0; i < q; ++i) {
    char op = '\0';
    cin >> op;
    if (op == '+') {
      i64 x = 0;
      cin >> x;
      added.insert(x);
    } else if (op == '?') {
      i64 k0 = 0;
      cin >> k0;
      i64 k = answer.count(k0) ? answer[k0] : k0;
      while (added.count(k)) {
        k += k0;
      }
      answer[k0] = k;
      cout << answer[k0] << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
