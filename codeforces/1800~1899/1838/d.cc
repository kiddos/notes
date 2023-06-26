#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<int> queries(q);
  for (int i = 0; i < q; ++i) {
    cin >> queries[i];
  }

  if (n % 2 == 1) {
    for (int i = 0; i < q; ++i) {
      cout << "NO" << endl;
    }
    return;
  }


  set<int> L, R;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) {
      if (s[i] == '(') {
        L.insert(i);
      } else {
        R.insert(i);
      }
    }
  }

  auto check = [&]() -> bool {
    if (s[0] == ')' || s.back() == '(') {
      return false;
    } else if (L.empty() && R.empty()) {
      return true;
    } else if (L.empty() || R.empty()) {
      return false;
    } else {
      int l = *L.begin(), r = *R.begin();
      if (l > r) return false;
      l = *L.rbegin(), r = *R.rbegin();
      if (l > r) return false;
      return true;
    }
  };

  for (int k = 0; k < q; ++k) {
    int i = queries[k] - 1;
    if (i > 0 && s[i] == s[i-1]) {
      if (s[i] == '(') {
        L.erase(i);
      } else {
        R.erase(i);
      }
    }

    if (i+1 < n && s[i] == s[i+1]) {
      if (s[i] == '(') {
        L.erase(i+1);
      } else {
        R.erase(i+1);
      }
    }

    s[i] = (s[i] == '(') ? ')' : '(';

    if (i > 0 && s[i] == s[i-1]) {
      if (s[i] == '(') {
        L.insert(i);
      } else {
        R.insert(i);
      }
    }

    if (i+1 < n && s[i] == s[i+1]) {
      if (s[i] == '(') {
        L.insert(i+1);
      } else {
        R.insert(i+1);
      }
    }

    if (check()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
