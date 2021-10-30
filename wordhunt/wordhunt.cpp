#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
using pis = pair<int,string>;
using pic = vector<char>;
#define f first
#define s second
#define mp make_pair
//Global Variables:
void setIO(string name = "") { // name is nonempty for USACO file I/O
	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vector<pic> grid(4, vector<char>(4));
map<string, int> substrs;
map<string, bool> dictwords;
vector<pis> avaliablewords;
// map<pair<int, int>, vector<pair<int, int>>> adjmat;

void dfs(int i, int j, vector<vector<bool>>& visited, string& s) {
	if(i < 0 || j < 0 || i >= 4 || j >= 4) return;
	if(visited[i][j]) return;
	visited[i][j] = true;
	// s.append(1, grid[i][j]);
	s += grid[i][j];

	if(dictwords[s]) avaliablewords.pb({s.length(), s});
	if(substrs[s] == 0) {
		visited[i][j] = false;
		s.pop_back();
		return;
	}

	for(int k = -1; k <= 1; k++) for(int l = -1; l <= 1; l++) dfs(i + k, l + j, visited, s);

	visited[i][j] = false;
	s.pop_back();
}

void inputs(string& s) {
	dictwords[s] = true;
	for(int j = 0; j < s.length(); j++) substrs[s.substr(0, j + 1)]++;
}

int main(){
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> grid[i][j];
		}
	}

	setIO("usa");

	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		inputs(s);
	}

	vector<vector<bool>> visited(4, vector<bool> (4, false));

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			string s = "";
			dfs(i, j, visited, s);
		}
	}


	sort(avaliablewords.begin(), avaliablewords.end());
	reverse(avaliablewords.begin(), avaliablewords.end());

	for(int i = 0; i < avaliablewords.size(); i++) cout << avaliablewords[i].second << "\n";

}