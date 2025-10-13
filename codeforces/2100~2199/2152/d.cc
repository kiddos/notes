#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  // 3, 5, 9, 17, 33
  // these kind of number will be prioritize by first player
  vector<int> divs(n+1);
  vector<int> first(n+1);
  vector<int> second(n+1);
  for (int i = 1; i <= n; ++i) {
    int x = a[i];
    int p = 0;
    while (x >= 2) {
      x /= 2;
      p++;
    }
    x = a[i];

    divs[i] = p;

    int remove1 = a[i]-1;
    if (a[i] > 2 && bitset<32>(remove1).count() == 1) {
      first[i]++;
    } else if (bitset<32>(a[i]).count() != 1) {
      second[i]++;
    }
    // cout << "a[i]=" << a[i] << " first=" << first[i] << ", second=" << second[i] << endl;
  }

  vector<array<int,3>> p(n+1);
  for (int i = 1; i <= n; ++i) {
    p[i][0] = p[i-1][0] + divs[i];
    p[i][1] = p[i-1][1] + first[i];
    p[i][2] = p[i-1][2] + second[i];
  }

  vector<int> l(q), r(q);
  for (int i = 0; i < q; ++i) {
    cin >> l[i] >> r[i];
  }

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int ops = p[r[i]][0] - p[l[i]-1][0];
    ops += (p[r[i]][1] - p[l[i]-1][1]) / 2;
    ops += (p[r[i]][2] - p[l[i]-1][2]);
    ans.push_back(ops);
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
  }
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
