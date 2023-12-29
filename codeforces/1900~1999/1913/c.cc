#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> bits(31);
  auto possible_sum = [&](int w) -> bool {
    vector<int> current = bits;
    for (int b = 0; b < 30; ++b) {
      if (w & (1<<b)) {
        if (current[b] == 0) {
          return false;
        }

        int can_take = max(current[b]-1, 0);
        current[b+1] += can_take / 2;
        current[b] = 1;
      } else {
        current[b+1] += current[b] / 2;
        current[b] %= 2;
      }
    }
    return true;
  };

  for (int i = 0; i < n; ++i) {
    int t = 0;
    cin >> t;
    if (t == 1) {
      int v = 0;
      cin >> v;
      bits[v]++;
    } else if (t == 2) {
      int w = 0;
      cin >> w;

      if (possible_sum(w)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
