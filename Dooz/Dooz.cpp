#include <iostream>
#include <conio.h>
using namespace std;
#define M 3
#define N 3
// Start the board with 0 value for each room
void startbord(int bord[M][N])
{
	for (int i = 0; i<M; i++)
		for (int j = 0; j<N; j++)
			bord[i][j] = 0;
}
// Printing the board after each change
void printbord(int bord[M][N])
{
	system("cls");
	for (int i = 0; i<M; i++)
	{
		for (int j = 0; j<N; j++)
		{
			if (bord[i][j] == 0)
				cout << "* ";
			if (bord[i][j] == 1)
				cout << "A ";
			if (bord[i][j] == 2)
				cout << "B ";
		}
		cout << "\n";
	}

}
// Changing the board based on the input
void changebord(int bord[M][N], int x1, int y1, int x2, int y2)
{
	if (x1 != 0 && y1 != 0)
		bord[x1 - 1][y1 - 1] = 1;
	if (x2 != 0 && y2 != 0)
		bord[x2 - 1][y2 - 1] = 2;
}
int result(int bord[M][N])
{
	// Result for player 1
	for (int i = 0; i < M; i++){
		if (bord[i][0] == 1 && bord[i][1] == 1 && bord[i][2] == 1)
			return 1;
		if (bord[0][i] == 1 && bord[1][i] == 1 && bord[2][i] == 1)
			return 1;
		if (bord[0][0] == 1 && bord[1][1] == 1 && bord[2][2] == 1)
			return 1;
		if (bord[0][2] == 1 && bord[1][1] == 1 && bord[2][0] == 1)
			return 1;
	}
	// Result for player 2
	for (int i = 0; i < N; i++){
		if (bord[i][0] == 2 && bord[i][1] == 2 && bord[i][2] == 2)
			return 2;
		if (bord[0][i] == 2 && bord[1][i] == 2 && bord[2][i] == 2)
			return 2;
		if (bord[0][0] == 2 && bord[1][1] == 2 && bord[2][2] == 2)
			return 2;
		if (bord[0][2] == 2 && bord[1][1] == 2 && bord[2][0] == 2)
			return 2;
	}
	return 0;
}
int main()
{
	system("cls");
	int k = 0, r = 0;
	int bord[M][N];
	int x1, x2, y1, y2;
	startbord(bord);
	while (r<9)
	{
		printbord(bord);
		cout << "player 1 enter the row number :";
		cin >> x1;
		cout << "player 1 enter the column number :";
		cin >> y1;
		r++;
		changebord(bord, x1, y1, 0, 0);
		printbord(bord);
		if (r == 9)
			break;
		k = result(bord);
		if (k != 0)
			break;
		cout << "player 2 enter the row number :";
		cin >> x2;
		cout << "player 2 enter the column number :";
		cin >> y2;
		r++;
		changebord(bord, 0, 0, x2, y2);
		printbord(bord);
		k = result(bord);
		if (k != 0)
			break;
	}
	if (k == 0)
		cout << "No winner!";
	if (k == 1)
		cout << "Player 1 is the winner!";
	if (k == 2)
		cout << "Player 2 is the winner!";
	cin.get();
	cin.get();
	return 0;
}