#include <iostream>
#include <queue>
using namespace std;

class Pos { //좌표 클래스
private:
	int x, y;
public:
	void set(int x, int y) {
		this->x = x; this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
};

bool get_distance(Pos rock, int x, int y) {
	if (abs(rock.getX() - x) + abs(rock.getY() - y) <= 1000) return true;
	else return false;
}

bool BFS(Pos home, Pos con[], Pos rock, bool visited[], int n) {
	queue <pair<int, int>> Q;
	Q.push(make_pair(home.getX(), home.getY()));
	bool chk = false;

	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	while (!Q.empty()) {
		int x = Q.front().first, y = Q.front().second;
		Q.pop();

		if (get_distance(rock, x, y)) {
			chk = true;
			break;
		}

		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				if (get_distance(con[i], x, y)) {
					Q.push(make_pair(con[i].getX(), con[i].getY()));
					visited[i] = true;
				}
			}
		}
	}

	return chk;
}

int main() {

	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n = 0; //편의점 수
		cin >> n;

		int x, y;

		Pos home;
		cin >> x >> y; //집 좌표
		home.set(x, y);

		Pos* con = new Pos[n];
		bool* visited = new bool[n];

		for (int j = 0; j < n; j++) {
			cin >> x >> y;
			con[j].set(x, y);
		}

		Pos rock;
		cin >> x >> y; //락 공연장 좌표
		rock.set(x, y);

		if (BFS(home, con, rock, visited, n)) cout << "happy\n";
		else cout << "sad\n";

		delete[] con;
	}

	return 0;
}
