#include<iostream>
#include<string>
#include <windows.h>
#include <cstdlib>
using namespace std;
void exit();
void play();
int play2();
void play3();
void menu();
void mapgenerator(char *pointer);
void mapgenerator2(char* pointer, char* pointer2);
void marker(int move, char* marker);
bool check(char *checker);
bool check3(char* checker);
void mapgenerator3(char* pointer);
void playexit();
bool remiss(char* pointer);
bool remish(char* pointer,int size, int x, int y);

string choice = "0";

int main() {
	menu();
	system("pause");
	return 0;
}

bool remiss(char* pointer) {
	if (*pointer != ' ' && *(pointer + 1) != ' ' && *(pointer + 2) != ' ' && *(pointer + 3) && *(pointer + 4) != ' ' && *(pointer + 5) != ' ' && *(pointer + 6)!=' ' && *(pointer + 7) != ' ' && *(pointer + 8) != ' ')return true;
	else return false;
}

bool remish(char* pointer,int size, int x, int y) {
	int c=0;
	for (int j = 0; j < x; j++) {
		for (int i = 0; i < y; i++) {
			if (*(pointer + i +(j*100)) == 'O'|| *(pointer + i + (j * 100)) == 'X') c++;
		}
	}
	if (c == size) return true;
	else return false;
}

void playexit() {
	string jeden = "1";
	string dwa = "2";
	string trzy = "3";
	string choicepe = "0";
	while (choicepe != jeden && choicepe != dwa && choicepe != trzy) {
		choicepe.clear();
		cout << endl << endl << endl <<
			"What do you want to do?\n\n  1. Play again the same mode \n  2. Go back to menu\n  3. Exit the game\n";
		getline(cin, choicepe);
		system("cls");
		if (choicepe == jeden);
		else if (choicepe == dwa) { choice.clear(); choice = "0"; }
		else if (choicepe == trzy) exit();
	}
}

bool check3(char* checker, int x, int y) {
	char c='X';

	for (int k = 0; k < 2; k++) {
		if (k > 0) c = 'O';
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 95; j++) {
				if (*(checker + i + (j * 100)) == c && *(checker + 1 + i + (j * 100)) == c && *(checker + 2 + i + (j * 100))
					== c && *(checker + 3 + i + (j * 100)) == c && *(checker + 4 + i + (j * 100)) == c || //poziom

					*(checker + j + (i * 100)) == c && *(checker + j + ((i + 1) * 100)) == c && *(checker + j + ((i + 2) * 100))
					== c && *(checker + j + ((i + 3) * 100)) == c && *(checker + j + ((i + 4) * 100)) == c //pion
					) return true;
			}
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 95; j++) {
				if (*(checker + i + (j * 100)) == c && *(checker + 1 + i + (j * 100)) == c && *(checker + 2 + i + (j * 100))
					== c && *(checker + 3 + i + (j * 100)) == c && *(checker + 4 + i + (j * 100)) != c || //poziom

					*(checker + j + (i * 100)) == c && *(checker + j + ((i + 1) * 100)) == c && *(checker + j + ((i + 2) * 100))
					== c && *(checker + j + ((i + 3) * 100)) == c && *(checker + j + ((i + 4) * 100)) == c //pion
					) return true;
			}
		}

		// nie wiem, czy to przypadkiem nie jest iteracja pod kwadrat i czy nie trzeba powyrzszej pętli rozłożyć na dwa

		for (int i = 0; i < 95; i++) {
			for (int j = 0; j < 95; j++) {
				if (*(checker + i + (j * 100)) == c && *(checker + 1 + i + ((j + 1) * 100)) == c && *(checker + 2 + i + ((j + 2) * 100))
					== c && *(checker + 3 + i + ((j + 3) * 100)) == c && *(checker + 4 + i + ((j + 4) * 100)) == c /* ukos w \ */ ||

					*(checker + (j + 4) + (i * 100)) == c && *(checker + 1 + (j + 4) + ((i + 1) * 100)) == c && *(checker + 2 + (j + 4) + ((i + 2) * 100))
					== c && *(checker + 3 + (j + 4) + ((i + 3) * 100)) == c && *(checker + 4 + (j + 4) + ((i + 4) * 100)) == c /* ukos w / */) return true;
			}
		}
	}
	return false;
}

void mapgenerator3(char* pointer, int x, int y) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	char r = 0xCD;
	char s = 0xCE;
	char c = 0xBA;
	char g = 0xCB;
	char d = 0xCA;
	char b = 0xB9; 
	char bg = 0xBB;
	char bd = 0xBC;
	for (int k = 0; k < y; k++) cout << r << r << r << g;
	cout << r << r << r << bg << "\nR/C" << c;
	for (int i = 0; i < y; i++) {
		SetConsoleTextAttribute(hConsole, 1);
		if (i + 1 < 10)cout << ' ' << i + 1 << '.';
		else if (i + 1 > 9)cout << i + 1 << '.';
		else cout << i + 1;
		SetConsoleTextAttribute(hConsole, 7);
		cout << c;
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 7);
	for (int k = 0; k < y; k++) cout << r << r << r << s;
	cout << r << r << r << b << endl;
	
	for (int i = 0; i < x; i++) {
		SetConsoleTextAttribute(hConsole, 4);
		if (i + 1 < 10)cout << ' ' << i + 1 << '.';
		else if (i + 1 > 9)cout << i + 1 << '.';
		else cout << i + 1;
		SetConsoleTextAttribute(hConsole, 7);
		if (i < x) cout << c;
		for (int j = 0; j < y; j++)
			cout << ' ' << *(pointer + (i * 100) + j) << ' ' << c;
;
		cout << endl;
		if (i + 1 < x) {
			for (int k = 0; k < (y); k++) cout << r << r << r << s;
			cout << r << r << r << b << endl;
		}
		//(2*x)+(x-1)
	}
	for (int k = 0; k < y; k++) cout << r << r << r << d;
	cout << r << r << r << bd << endl;
}

void play3(){ //100 na 100 to przesada
	//gracze
	char players[2] = { 'X','O' };
	int player = 1;
	//mapa i wybieranie
	char map[100][100];
	int size;
	int x=0, y=0;
	string xs, ys;

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	
	while (x < 5 || x > 101) {
		system("cls");
		cout << "How many rows?: ";
		getline(cin, xs);
		x = atoi(xs.c_str());
	}
	while (y < 5 || y > 101) {
		system("cls");
		cout << "How many rows?: " << x << endl;
		cout << "How many columns?: ";
		getline(cin, ys);
		y = atoi(ys.c_str());
	}
	size = x * y;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			map[i][j] = ' ';
		}
	}

	char* mapgenpointer3 = map[0];
	int row = 0, col = 0;
	string rows, cols;
	while (check3(mapgenpointer3, x, y) == false && remish(mapgenpointer3,size,x,y)==false) {
		while (row > x || row < 1 || col>y || col < 1 || map[row - 1][col - 1] != ' ') {
			system("cls");
			if (player % 2 == 1) cout << "   Player 1 (O)\n";
			if (player % 2 == 0) cout << "   Player 2 (X)\n";
			mapgenerator3(mapgenpointer3, x, y);
			cout << endl;
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Row: ";
			getline(cin, rows);
			row = atoi(rows.c_str());
			SetConsoleTextAttribute(hConsole, 1);
			cout << "Column: ";
			getline(cin, cols);
			col = atoi(cols.c_str());
			SetConsoleTextAttribute(hConsole, 7);
		}
		row--;
		col--;
		map[row][col] = players[player % 2];
		row = 0; col = 0;
		player++;
	}
	system("cls");
	mapgenerator3(mapgenpointer3, x, y);
	if (check3(mapgenpointer3, x, y) == true) {
		if (player % 2 == 1) cout << "Player 1 has won the match" << endl;
		else if (player % 2 == 0) cout << "Player 2 has won the match" << endl;
	}
	else cout << "Oh... that was unexpected" << endl;
	playexit();
}

void mapgenerator2(char* pointer, char* pointer2) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout <<' '<< *(pointer+(i*3)+j)<< *(pointer2 + (i * 3) + j);
			if (j < 2) cout << '#';
		}
		cout << endl;
		if (i < 2) cout << "###########" << endl;
	}
}

void mapgenerator(char* pointer) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ' ' << *(pointer + (i * 3) + j) << ' ';
			if (j < 2) cout << '#';
		}
		cout << endl;
		if (i < 2) cout << "###########" << endl;
	}
}

void play() {
	//gracze
	
	char players[2] = {'X','O'};
	int player=1;
	//mapa i wybieranie
	char map[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char* mapgenpointer = map[0];
	char* remischecker = map[0];
	int row=0, col=0;
	string rows, cols;
	while (check(mapgenpointer) == false && remiss(remischecker)==false) {
		while (row > 3 || row < 1 || col>3 || col < 1||map[row - 1][col - 1] != ' ') {
			system("cls");
			if (player % 2 == 1) cout << " Player 1 (O)\n";
			if (player % 2 == 0) cout << " Player 2 (X)\n";
			mapgenerator(mapgenpointer);
			cout << "Row: ";
			getline(cin, rows);
			row = atoi(rows.c_str());
			cout << "Column: ";
			getline(cin, cols);
			col = atoi(cols.c_str());
		}
		row--;
		col--;
		map[row][col] = players[player % 2];
		row = 0; col = 0;
		player++;
	}
	system("cls");
	mapgenerator(mapgenpointer);
	if (check(mapgenpointer) == true) {
		if (player % 2 == 1) cout << "Player 1 has won the match";
		else if (player % 2 == 0) cout << "Player 2 has won the match";
	}
	else cout << "Oh... that was unexpected" << endl; 
	playexit();
}

int play2() {
	//gracze
	char players[2] = { 'X','O' };
	int player = 1;
	//mapa i wybieranie
	char map[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
	char map2[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
	char* mapgenpointer2 = map2[0];
	char* mapgenpointer = map[0];
	int row = 0, col = 0, path = 0;
	string paths;
	map2[0][0] = '*';
	while (check(mapgenpointer) == false && remiss(mapgenpointer) == false) {
		while (map[row][col] != ' ' || path != 5) { //coś nie działa, ze zmianą playera, prawdopodobnie złe założenie
			system("cls");
			if (player % 2 == 1) cout << " Player 1 (O)\n";
			if (player % 2 == 0) cout << " Player 2 (X)\n";
			mapgenerator2(mapgenpointer, mapgenpointer2);
			if (path == 0) cout << "Use only: 2 , 4, 6, 8 to move and 5 to approve your possition and choose that place that's not taken already!" << endl;
			else
				cout << "Path: ";

			paths.clear();
			getline(cin, paths);
			path = atoi(paths.c_str());
			
			switch (path) {
			case 2:
				if (row + 1 <= 2) {
					map2[row][col] = ' ';
					row++;
					map2[row][col] = '*';
				}
				else {
					map2[row][col] = ' ';
					row = 0;
					map2[row][col] = '*';
				}
				break;
			case 4:
				if (col - 1 >= 0) {
					map2[row][col] = ' ';
					col--;
					map2[row][col] = '*';
				}
				else {
					map2[row][col] = ' ';
					col = 2;
					map2[row][col] = '*';
				}
				break;
			case 6:
				if (col + 1 <= 2) {
					map2[row][col] = ' ';
					row++;
					col++;
					map2[row][col] = '*';
				}
				else {
					map2[row][col] = ' ';
					col = 0;
					row++;
					map2[row][col] = '*';
				}
			case 8:
				if (row - 1 >= 0) {
					map2[row][col] = ' ';
					row--;
					map2[row][col] = '*';
				}
				else {
					map2[row][col] = ' ';
					row = 2;
					map2[row][col] = '*';
				}
				break;
			case 5:
				if (map[row][col] == ' ') {
					map2[row][col] = ' ';
					map[row][col] = players[player % 2];
				}
				else path = 0;
				break;
			default:
				path = 0;
				break;
			}
			if (path == 5) break;
		}
		check(mapgenpointer);
		row = 0; col = 0;
		if (path != 0)
			path = 1;
		map2[row][col] = '*';
		player++;
	}
	system("cls");
	mapgenerator2(mapgenpointer, mapgenpointer2);
	if (check(mapgenpointer) == true) {
		if (player % 2 == 1) cout << "Player 1 has won the match";
		else if (player % 2 == 0) cout << "Player 2 has won the match";
	}
	else cout << "Oh... that was unexpected" << endl;

	string jeden = "1";
	string dwa = "2";
	string trzy = "3";
	string choicepe = "0";
	while (choicepe != jeden && choicepe != dwa && choicepe != trzy) {
		choicepe.clear();
		cout << endl << endl << endl <<
			"What do you want to do?\n\n  1. Play again the same mode \n  2. Go back to menu\n  3. Exit the game\n";
		getline(cin, choicepe);
		system("cls");
		if (choicepe == jeden) { choice.clear(); return 2; }
		else if (choicepe == dwa) { choice.clear(); return 0; }
		else if (choicepe == trzy) { choice.clear(); return 4; }
	}
}

void marker(int move, char* wsk) {
	int k = 1;
	switch (move) {
	case 2:
		if (wsk)
		break;

	case 4:
		break;

	case 6:
		if (*(wsk + 1) != 0) {
			*wsk = ' ';
			*wsk += 1;
			*wsk = '*';
		}
		else *wsk = 0;
		break;
	case 8:
		if (*(wsk - 3) != 0) {
			*wsk = ' ';
			*wsk -= 3;
			*wsk = '*';
		}
		else *wsk = 0;
		break;
	case 5:
		if (*wsk != 'X' && *wsk != 'O')
			*wsk = 'X';
		else *wsk = 0;
		break;
	}
}

bool check(char *checker) {
	if (*(checker) == 'X' && *(checker + 1) == 'X' && *(checker + 2) == 'X' || *(checker + 3) == 'X' && *(checker + 4) == 'X' && *(checker + 5) == 'X' ||
		*(checker + 6) == 'X' && *(checker + 7) == 'X' && *(checker + 8) == 'X' ||
		*(checker) == 'X' && *(checker + 3) == 'X' && *(checker + 6) == 'X' || *(checker + 1) == 'X' && *(checker + 4) == 'X' && *(checker + 7) == 'X' ||
		*(checker + 2) == 'X' && *(checker + 5) == 'X' && *(checker + 8) == 'X' ||
		*(checker) == 'X' && *(checker + 4) == 'X' && *(checker + 8) == 'X' || *(checker + 2) == 'X' && *(checker + 4) == 'X' && *(checker + 6) == 'X'||
		*(checker) == 'O' && *(checker + 1) == 'O' && *(checker + 2) == 'O' || *(checker + 3) == 'O' && *(checker + 4) == 'O' && *(checker + 5) == 'O' ||
		*(checker + 6) == 'O' && *(checker + 7) == 'O' && *(checker + 8) == 'O' ||
		*(checker) == 'O' && *(checker + 3) == 'O' && *(checker + 6) == 'O' || *(checker + 1) == 'O' && *(checker + 4) == 'O' && *(checker + 7) == 'O' ||
		*(checker + 2) == 'O' && *(checker + 5) == 'O' && *(checker + 8) == 'O' ||
		*(checker) == 'O' && *(checker + 4) == 'O' && *(checker + 8) == 'O' || *(checker + 2) == 'O' && *(checker + 4) == 'O' && *(checker + 6) == 'O') return true;

	else return false;
//1. lewa-prawa 2.gora-dol 3.ukos przez srodek
}

void exit() {
	system("cls");
	string beornottobe;
	string n = "n", N = "N", y = "y", Y = "Y";
	cout << "Are you sure, you don't want to play another one? ;)" << endl
		<< "[Y] - Yes, I am to old for this" << endl
		<< "[N] - Night is young and so am I!" << endl;
	getline(cin, beornottobe);
	while ((beornottobe != Y) && (beornottobe != y) && (beornottobe != N) && (beornottobe != n)) {
		system("cls");
		cout << "Are you sure, you don't want to play another one? ;)" << endl
			<< "[Y] - Yes, I am to old for this" << endl
			<< "[N] - Night is young and so am I!" << endl << endl
			<< "Error: wrong sign typed in, please correct it: ";
		getline(cin, beornottobe);
	}
	if (beornottobe == Y || beornottobe == y);
	{
		choice.clear();
		choice = "4";
	}
	system("cls");
	if (beornottobe == N || beornottobe == n) {
		choice.clear();
		choice = "0";
	}
}

void menu() {
	string debil;
	string p1 = "1. Play the first version";
	string p2 = "2. Play the more advanced version with a pointer";
	string p3 = "3. Play the most advanced version with a huge map";
	string e = "4. Exit";
	
	string jeden = "1";
	string dwa = "2";
	string trzy = "3";
	string cztery = "4";
	while (choice != cztery) {
		while (choice != jeden && choice != dwa && choice != trzy && choice != cztery) {
			system("cls");
			cout << "TIC TAC TOU:" << endl << debil << endl << p1 << endl << p2 << endl << p3 << endl << endl << e << endl << "Type: ";
			choice.clear();
			getline(cin, choice);
			if (choice.size() > 1) debil = "\n Please, try not to break the game! >:((((( \n ~developer \n ";
			else debil.clear();
		}
		if (choice == jeden) play();
		else if (choice == dwa)
			choice = play2();
		else if (choice == trzy)
			play3();
		if (choice == cztery)
			exit();
	}
}
