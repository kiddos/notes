#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// when t <= k[i]
// i contribute to answer 1
// when t > k[i]
// i contribute to answer k[i] / t

struct Fraction {
  i64 a, b;

  Fraction(i64 a, i64 b) : a(a), b(b) {}

  bool operator>(const Fraction& f2) {
    return a * f2.b > f2.a * b;
  }
};

void solve() {
  int n = 0;
  cin >> n;
  vector<int> m(n), k(n);
  for (int i = 0; i < n; ++i) {
    cin >> m[i] >> k[i];
  }

  int max_m = *max_element(m.begin(), m.end());
  int max_k = *max_element(k.begin(), k.end());
  Fraction best(0, 1);
  vector<int> ans;
  for (int t = 1; t <= max_k; ++t) {
    if (t > max_m) break;

    vector<int> score(max_m+1);
    for (int i = 0; i < n; ++i) {
      score[m[i]] += min(t, k[i]);
    }
    vector<pair<int,int>> p;
    for (int i = 0; i <= max_m; ++i) {
      p.emplace_back(score[i], i);
    }
    sort(p.rbegin(), p.rend());

    vector<int> list;
    int top = 0;
    for (int i = 0; i < t; ++i) {
      top += p[i].first;
      list.push_back(p[i].second);
    }
    Fraction f(top, t);
    if (f > best) {
      best = f;
      ans = list;
    }
  }

  cout << ans.size() << endl;
  for (int i : ans) cout << i << " ";
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
