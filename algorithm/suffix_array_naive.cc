#include <bits/stdc++.h>

using namespace std;

struct Suffix {
  int index;
  const char* suffix;
};

vector<int> build_suffix_array(const string& s) {
  vector<Suffix> suffix;
  const char* p = s.c_str();
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    suffix.push_back(Suffix{i, p+i});
  }

  sort(suffix.begin(), suffix.end(), [&](auto& s1, auto& s2) {
    return strcmp(s1.suffix, s2.suffix) < 0;
  });

  vector<int> suffix_array;
  for (int i = 0; i < n; ++i) {
    suffix_array.push_back(suffix[i].index);
  }
  return suffix_array;
}

int search(vector<int>& suffix_array, const string& s, const string& t) {
  int n = s.length(), m = t.length();
  int l = 0, r = n-1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    int compare = strncmp(t.c_str(), s.c_str() + suffix_array[mid], m);
    if (compare == 0) {
      return suffix_array[mid];
    } else if (compare < 0) {
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s = "banana";
  vector<int> suffix_array = build_suffix_array(s);
  cout << "suffix array: " << endl;
  for (int s : suffix_array) cout << s << " ";
  cout << endl;

  vector<string> words = {"nan", "an", "ban", "bob", "bana"};

  for (string word : words) {
    int ans = search(suffix_array, s, word);
    if (ans >= 0)  {
      cout << "found: " << word << " at " << ans << endl;
    } else {
      cout << word <<  " not found" << endl;
    }
  }
  return 0;
}
