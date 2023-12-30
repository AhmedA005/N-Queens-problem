#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define FAST ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
int solCount=0;

bool isSafe(char**&Board,int& i,int& j, int&N) {
    // left
    for (int col = j - 1; col >= 0; --col) {
        if (Board[i][col] == 'Q') return false;
    }
    // diag up (up left)
    for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; --row, --col) {
        if (Board[row][col] == 'Q') return false;
    }
    // diag down (down left)
    for (int row = i + 1, col = j - 1; row < N && col >= 0; ++row, --col) {
        if (Board[row][col] == 'Q') return false;
    }
    return true;
}


void nQueens(char** &Board,int & N,int col=0) {
    if (col == N){
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << Board[i][j];
            }
            cout << endl;
        }
        cout<<endl;
        solCount++;
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (isSafe(Board, i, col,N)) {
            Board[i][col] = 'Q';
            nQueens(Board,N, col + 1);
            Board[i][col] = char(254);
        }
    }
}

int main() {
    FAST;
    int N;
    cin >> N;
    char **Board = new char *[N];
    for (int i = 0; i < N; ++i) {
        Board[i] = new char[N];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            Board[i][j] = char(254);
        }
    }

    nQueens(Board, N);
    cout<<solCount;

    for (int i = 0; i < N; ++i) {
        delete[] Board[i];
    }
    delete [] Board;
}