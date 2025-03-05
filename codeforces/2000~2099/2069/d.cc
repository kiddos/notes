#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> char_count(const string& s) {
  vector<int> count(26);
  for (char ch : s) {
    count[ch-'a']++;
  }
  return count;
}

bool can_shuffle_half(vector<int>& count, vector<int>& half_count) {
  for (int i = 0; i < 26; ++i) {
    if (half_count[i] * 2 != count[i]) {
      return false;
    }
  }
  return true;
}

int min_shuffle(const string& t) {
  vector<int> right = char_count(t);
  vector<int> left(26);
  auto enough = [&]() -> bool {
    for (int c = 0; c < 26; ++c) {
      if (left[c] < right[c]) {
        return false;
      }
    }
    return true;
  };

  int size = t.length();
  for (int i = 0; i < size; ++i) {
    int c = t[i]-'a';
    left[c]++;
    right[c]--;
    if (enough()) {
      return i+1;
    }
  }
  return size;
}

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  string rev(s.rbegin(), s.rend());
  if (s == rev) {
    cout << "0" << endl;
    return;
  }

  vector<int> count = char_count(s);
  vector<int> half_count = char_count(s.substr(0, n/2));
  int ans = n;
  if (can_shuffle_half(count, half_count)) {
    int half_size = n / 2;
    string s1 = s.substr(0, half_size);
    string s2 = s.substr(half_size);
    reverse(s2.begin(), s2.end());
    int first = -1, second = -1;
    for (int i = 0; i < half_size; ++i) {
      if (s1[i] != s2[i]) {
        if (first < 0) first = i;
        second = i;
      }
    }
    int len = second-first+1;
    ans = min(ans, len);
  }

  int l = 0, r = n-1;
  while (l <= r) {
    if (s[l] != s[r]) {
      break;
    }
    l++;
    r--;
  }
  string t = s.substr(l, r-l+1);
  ans = min(ans, min_shuffle(t));
  reverse(t.begin(), t.end());
  ans = min(ans, min_shuffle(t));

  cout << ans << endl;
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
