#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int i, int x) {
  cout << "? " << i << " " << x << endl;
  int result = 0;
  cin >> result;
  return result;
}

void answer(int x) {
  cout << "! " << x << endl;
}

void solve() {
  int n = 0;
  cin >> n;
  int msb = 31 - __builtin_clz(n);
  vector<int> indices;
  for (int i = 1; i < n; ++i) {
    indices.push_back(i);
  }

  vector<int> p(n+1);

  int mask = 0;
  int ans = 0;
  for (int b = 0; b <= msb; ++b) {
    for (int idx : indices) {
      int result = query(idx, 1<<b);
      if (result) {
        p[idx] |= (1<<b);
      }
    }

    int one = 0;
    for (int i = 1; i <= n; ++i) {
      if (i & (1<<b)) {
        if ((i & mask) == ans) {
          one++;
        }
      }
    }

    mask |= (1<<b);

    // count the number which starts with ans
    int found_one = 0;
    for (int idx : indices) {
      if (p[idx] & (1<<b)) {
        found_one++;
      }
    }

    if (found_one < one) {
      ans |= (1<<b);
    }

    // cout << "found=" << found_one << " one=" << one << " ans=" << ans << endl;

    vector<int> new_indices;
    int size = indices.size();
    for (int i = 0; i < size; ++i) {
      if ((p[indices[i]] & mask) == ans) {
        new_indices.push_back(indices[i]);
      }
    }
    indices = std::move(new_indices);
    // cout << "indices_count=" << indices.size() << endl;
  }

  answer(ans);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
