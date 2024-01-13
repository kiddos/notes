#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  string s;
  cin >> s;
  set<int> index;
  for (int i = 0; i+2 < n; ++i) {
    if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
      index.insert(i);
    }
  }

  for (int j = 0; j < q; ++j) {
    int i = 0;
    char c = 0;
    cin >> i >> c;
    i--;

    if (s[i] == 'a') {
      index.erase(i);
    } else if (s[i] == 'b') {
      index.erase(i-1);
    } else if (s[i] == 'c') {
      index.erase(i-2);
    }

    s[i] = c;
    if (i+2 < n && s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
      index.insert(i);
    }
    if (i+1 < n && i-1 >= 0 && s[i-1] == 'a' && s[i] == 'b' && s[i+1] == 'c') {
      index.insert(i-1);
    }
    if (i-2 >= 0 && s[i-2] == 'a' && s[i-1] == 'b' && s[i] == 'c') {
      index.insert(i-2);
    }

    cout << index.size() << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
