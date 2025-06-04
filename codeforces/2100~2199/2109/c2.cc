#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int command(const string& c) {
  int result = 0;
  cout << c << endl;
  cin >> result;
  return result;
}

int answer() {
  cout << "!" << endl;
  int result = 0;
  cin >> result;
  return result;
}

void solve() {
  int n = 0;
  cin >> n;
  command("mul 9");
  command("digit");
  command("digit");
  command("add " + to_string(n-9));
  answer();
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
