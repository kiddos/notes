#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int MOD = 1e9 + 7;

i64 string_hash(const string& s) {
  i64 h = 0;
  for (char ch : s) {
    h = h * 3 + (ch - 'a');
    h %= MOD;
  }
  return h;
}

i64 add(i64 x, i64 y) {
  x += y;
  x %= MOD;
  return x;
}

i64 sub(i64 x, i64 y) {
  x -= y;
  x %= MOD;
  x += MOD;
  x %= MOD;
  return x;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  map<int, set<string>> memory;
  // set<string> memory;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    i64 h = string_hash(s);
    memory[h].insert(s);
    // memory.insert(s);
  }

  for (int i = 0; i < m; ++i) {
    string t;
    cin >> t;
    int len = t.length();
    bool found = false;
    i64 h = string_hash(t);
    i64 p = 1;
    for (int j = len-1; j >= 0 && !found; --j, p = (p * 3) % MOD) {
      char original = t[j];
      i64 h2 = sub(h, (original-'a') * p);
      for (char ch = 'a'; ch <= 'c'; ++ch) {
        if (ch == original) {
          continue;
        }
        t[j] = ch;

        i64 h3 = add(h2, (ch - 'a') * p);
        if (memory.count(h3) && memory[h3].count(t)) {
          found = true;
        }
        // if (memory.count(t)) {
        //   found = true;
        // }
      }
      t[j] = original;
    }
    if (found) {
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
