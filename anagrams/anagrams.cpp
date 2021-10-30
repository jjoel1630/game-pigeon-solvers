#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define pb push_back
#define rsz resize
#define mp make_pair
#define f x
#define s y

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define grid(name, x, y) name(x, vector<int>(y));
#define boolgrid(name, x, y) vector<vector<bool>> name(x, vector<bool> (y, false));
#define coutvect(name, n) for(int i = 0; i < n; i++){cout << name[i] << "\t";}

using LL = long long;
using VI = vector<int>;
using PII = pair<int,int>;
using PII = pair<int,int>;
using PIS = pair<int, string>;
using VI = vector<int>;
using VS = vector<string>;
using VC = vector<char>;
using VB = vector<bool>;
using VII = vector<vector<int>>;
using MII = map<int, int>;
using MSI = map<string, int>;
using MSB = map<string, bool>;
using MCI = map<char, int>;

//Global Variables:
void setIO(string name = "") { // name is nonempty for USACO file I/O
	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}

// MSI substrs;
MSB dictwords;
vector<PIS> avaliablewords;

// void inputs(string& s) {
// 	dictwords[s] = true;
// 	for(int j = 0; j < s.length(); j++) substrs[s.substr(0, j + 1)]++;
// }

int main(){
	VC anagrams(6);
	
	for(int i = 0; i < 6; i++) cin >> anagrams[i];


	setIO("usa");
	
	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		dictwords[s] = true;
	}

	sort(all(anagrams));

	do {
		string s = "";
		for(int i = 0; i < 6; i++) {
			s += anagrams[i];
			if(dictwords[s]) avaliablewords.pb({s.length(), s});
		}
	} while(next_permutation(anagrams.begin(), anagrams.end()));

	sort(all(avaliablewords));
	avaliablewords.resize(unique(all(avaliablewords)) - avaliablewords.begin());

	reverse(all(avaliablewords));	

	for(auto& x: avaliablewords) cout << x.second << '\n';
}