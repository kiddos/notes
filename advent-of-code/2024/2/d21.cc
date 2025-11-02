#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool increasing(vector<int>& x) {
  int size = x.size();
  for (int i = 1; i < size; ++i) {
    int diff = x[i] - x[i-1];
    if (diff != 1 && diff != 2 && diff != 3) {
      return false;
    } 
  }
  return true;
}

bool decreasing(vector<int>& x) {
  int size = x.size();
  for (int i = 1; i < size; ++i) {
    int diff = x[i-1] - x[i];
    if (diff != 1 && diff != 2 && diff != 3) {
      return false;
    }
  }
  return true;
}

void solve() {
  string line;
  int ans = 0;
  while (getline(cin, line)) {
    stringstream ss;
    ss << line;
    int x = 0;
    vector<int> report;
    while (ss >> x) {
      report.push_back(x);
    }

    if ((increasing(report) || decreasing(report))) {
      ans++;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
