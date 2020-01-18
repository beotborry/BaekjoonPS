#include <iostream>
#include <vector>
using namespace std;

int w, h;
int map[50][50];


int dr[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc[8] = {1, 0, -1, 1, 0, -1, 1, -1};

bool safe(int r, int c) {
	return ((0 <= r && r < h) && (0 <= c && c < w)) ? true : false;
}

int DFS(int start_r, int start_c) {
	int& curr = map[start_r][start_c];
	if(curr == 2)
		return 0;
	curr = 2;
	for (int i = 0; i < 8; i++) {
		int next_r = start_r + dr[i];
		int next_c = start_c + dc[i];
		
		if(safe(next_r, next_c) && map[next_r][next_c] == 1)
			DFS(next_r, next_c);
	}
	return 1;
}

int main() {

	while(cin >> w >> h) {
		vector< pair<int, int> > marker;
		int res = 0;
		if(w == 0 && h == 0)
			break;
		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				cin >> map[r][c];
				if(map[r][c] == 1)
					marker.push_back(make_pair(r, c));
			}
		}
		for (int i = 0; i < marker.size(); i++) {
			res += DFS(marker[i].first, marker[i].second);
		}
		cout << res << "\n";
	}
}