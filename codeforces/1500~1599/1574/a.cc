#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 50;

vector<vector<string>> results(MAX_N+1);

void generate(int n) {
  if (n == 1) {
    results[1].push_back("()");
    return;
  }
  if (results[n].size() > 0) {
    return;
  }

  generate(n-1);
  vector<string>& last = results[n-1];
  vector<string>& list = results[n];
  for (string& s : last) {
    list.push_back(s + "()");
    if ((int)list.size() == n) break;
    list.push_back("(" + s + ")");
    if ((int)list.size() == n) break;
  }
}

void precompute() {
  generate(MAX_N);
}

void solve() {
  int n = 0;
  cin >> n;
  for (string& s : results[n]) {
    cout << s << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
