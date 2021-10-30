/*
ID: varunra2
LANG: C++
TASK: anagrams
*/

#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "lib/debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define debug_arr(...) \
  cerr << "[" << #__VA_ARGS__ << "]:", debug_arr(__VA_ARGS__)
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC diagnostic ignored "-Wunused-parameter"
//#pragma GCC diagnostic ignored "-Wunused-variable"
#else
#define debug(...) 42
#endif

#define EPS 1e-9
#define IN(A, B, C) assert(B <= A && A <= C)
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define x first
#define y second

const double PI = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef map<int, int> MPII;
typedef multiset<int> MSETI;
typedef set<int> SETI;
typedef set<string> SETS;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
#pragma GCC diagnostic ignored "-Wsign-compare"
// util functions

void setIO(string name = "") { // name is nonempty for USACO file I/O
	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int main() {
  string s;
  for(int i = 0; i < 6; i++) cin >> s;
  vector<char> chars(s.begin(), s.end());

  setIO("usa");

  int n;
  cin >> n;

  map<string, bool> there;

  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    there[s] = true;
  }

  vector<pair<int, string>> words;

  sort(all(chars));

  do {
    string cur = "";
    for(int i = 0; i < 6; i++) {
      cur.append(1, chars[i]);
      if(there[cur]) words.PB(MP(i + 1, cur));
    }
  } while(next_permutation(all(chars)));

  sort(all(words));
  words.resize(unique(all(words)) - words.begin());

  reverse(all(words));

  for(auto& x: words) cout << x.y << '\n';

  return 0;
}
