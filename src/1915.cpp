#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int grid[1000][1000];
int cache[1000][1000];

vector<pair<int, int> > marker;

int dr[3] = {-1, -1, 0};
int dc[3] = {0, -1, -1};

bool safe(int r, int c) {
	return ((0 <= r && r < n) && (0 <= c && c < m)) ? true : false;
}

int min(int a, int b, int c) {
	if(a < b)
		return (a < c) ? a : c;
	else if(a < c)
		return (a < b) ? a : b;
	else
		return (b < c) ? b : c;
}

int max_length = 0;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int r = 0; r < n; r++) {
		string row; cin >> row;
		for (int c = 0; c < m; c++) {
			grid[r][c] = row[c] - '0';
			if(grid[r][c] == 1) {
				cache[r][c] = 1;
				marker.push_back(make_pair(r, c));
				max_length = 1;
			}
		}
	}
	
	for (int i = 0; i < marker.size(); i++) {
		int curr_r = marker[i].first;
		int curr_c = marker[i].second;
		
		bool okay = true;
		
		for (int move = 0; move < 3; move ++) {
			int next_r = curr_r + dr[move];
			int next_c = curr_c + dc[move];
			
			if(!safe(next_r, next_c) || grid[next_r][next_c] == 0) {
				okay = false;
				break;
			}
		}
		
		if(okay == true) {
			cache[curr_r][curr_c] = min(cache[curr_r - 1][curr_c - 1],
									    cache[curr_r][curr_c - 1],
									    cache[curr_r - 1][curr_c]) + 1;
			max_length = (cache[curr_r][curr_c] > max_length) ? 
						cache[curr_r][curr_c] : max_length;
		}
	}
	cout << max_length * max_length << endl;
}