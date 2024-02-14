#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Header.h"
#include <sstream>
#include <ctime>
#include <iostream>
#include <windows.h>
#include <cmath>
#include <fstream>

using namespace sf;
using namespace std;

class Player {
public:
	float x, y, x1, y1, w, h, dx, dy, speed, r, p, uron;
	int dir, imhp;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Player(String F, float X, float Y, float X1, float Y1, float W, float H, float R, float P) { // онструктор с параметрами(формальными) дл€ класса Player. ѕри создании объекта класса мы будем задавать им€ файла, координату ’ и ”, ширину и высоту
		dx = 0; dy = 0; speed = 0; dir = 0; uron = 1;
		File = F;
		r = R; p = P;
		x1 = X1; y1 = Y1; w = W; h = H;
		image.loadFromFile("images/" + File);
		image.createMaskFromColor(Color::Black);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(x1, y1, w, h));
		sprite.setPosition(x, y);
		sprite.setScale(r, p);
		w *= r; h *= p;
	}
	void update(float time)
	{
		switch (dir)
		{
		case 0: dx = speed; dy = 0; break;
		case 1: dx = -speed; dy = 0; break;
		case 2: dx = 0; dy = speed; break;
		case 3: dx = 0; dy = -speed; break;
		}

		x += dx * time;
		y += dy * time;
		speed = 0;
		sprite.setPosition(x, y);
	}
	void updatez(float time)
	{
		switch (dir)
		{
		case 0: dx = speed; dy = -speed; break;
		case 1: dx = -speed; dy = -speed; break;
		}

		x += dx * time;
		y += dy * time;
		sprite.setPosition(x, y);
	}
	void updatex(float time)
	{
		x += dx * time;
		y += dy * time;
		sprite.setPosition(x, y);
	}
	void stenki()
	{
		for (int i = (y - 25) / 40; i < (y - 25 + h) / 40; i++)
		{
			for (int j = (x - 25) / 40; j < (x - 25 + w) / 40; j++)
			{
				if (TileMap[i][j] == '0')
				{
					if (dy > 0) { y = 25 + i * 40 - h; }
					if (dy < 0) { y = 25 + i * 40 + 40; }
					if (dx > 0) { x = 25 + j * 40 - w; }
					if (dx < 0) { x = 25 + j * 40 + 40; }
				}
			}
		}
	}
	int stenkiz()
	{
		if (x <= 65) { dx = -1 * dx; }
		if (x <= 60) { x += 8; }
		if ((x + w) >= 625) { dx = -1 * dx; }
		if ((x + w) >= 630) { x -= 8; }
		if ((y) <= 65) { dy = -dy; }
		if (y <= 60) { y += 8; }
		if ((y + h) >= 865) { return 1; }
		return 0;
	}
	int plat(int xp, int dxp, int hp, int wp) { 
		if (y + h - 2 >= 760 && y + h  <= 760 + hp) { if ((xp - 5 <= x + w) && (x <= (xp + wp + 10))) { dy = -1 * abs(dy); dx += (dxp * 0.3); } }
		return 0;
	}
	int interactionWithMap(int b, int i1, int j1){
	if (y <= 385) {
	int i = (y - 65) / 40;
			for (int j = (x - 65) / 80; j < (x - 65 + w) / 80; j++) {
				switch (TileMapBlok[i][j]) {
				case '1': blo[i][j] -= 1; dx = -dx; dy = -dy; if (blo[i][j] == 1) { TileMapBlok[i][j] = '5'; }; break;
				case '2': blo[i][j] -= 1; dx = -dx; dy = -dy; if (blo[i][j] == 2) { TileMapBlok[i][j] = '6'; }; break;
				case '3': blo[i][j] -= 1; dx = -dx; dy = -dy; if (blo[i][j] == 3) { TileMapBlok[i][j] = '7'; }; break;
				case '4': blo[i][j] -= 1; dx = -dx; dy = -dy; if (blo[i][j] == 4) { TileMapBlok[i][j] = '8'; }; break;
				case '5': blo[i][j] -= 1; dx = -dx; dy = -dy; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; b += 1; }; break;
				case '6': blo[i][j] -= 1; dx = -dx; dy = -dy; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; b += 1; }; break;
				case '7': blo[i][j] -= 1; dx = -dx; dy = -dy; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; b += 1; }; break;
				case '8': blo[i][j] -= 1; dx = -dx; dy = -dy; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; b += 1; }; break;
				}
			}
			return b;
	}
	return 0;
	}
	int interactionWithMapw() {
		int rty = 0;
		if (y <= 384) {
		int ic = 790;
		for (int t = x + 3; t <= x + w - 5; t++) {
			int i = (y - 65) / 40;
			int j = (t - 65) / 80;
			if (j > WIDTH_MAP_BLOK) { j = WIDTH_MAP_BLOK; }
			if (i > WIDTH_MAP_BLOK) { i = WIDTH_MAP_BLOK; }
			if (ic != j) {
				switch (TileMapBlok[i][j]) {
				case '1': blo[i][j] -= 1; dy = -dy; y = 105 + i * 40; rty += 1; if (blo[i][j] == 1) { TileMapBlok[i][j] = '5'; }; break;
				case '2': blo[i][j] -= 1; dy = -dy; y = 105 + i * 40; rty += 1; if (blo[i][j] == 2) { TileMapBlok[i][j] = '6'; }; break;
				case '3': blo[i][j] -= 1; dy = -dy; y = 105 + i * 40; rty += 1; if (blo[i][j] == 3) { TileMapBlok[i][j] = '7'; }; break;
				case '4': blo[i][j] -= 1; dy = -dy; y = 105 + i * 40; rty += 1; if (blo[i][j] == 4) { TileMapBlok[i][j] = '8'; }; break;
				case '5': blo[i][j] -= 1; dy = -dy; y = 105 + i * 40; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				case '6': blo[i][j] -= 1; dy = -dy; y = 105 + i * 40; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				case '7': blo[i][j] -= 1; dy = -dy; y = 105 + i * 40; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				case '8': blo[i][j] -= 1; dy = -dy; y = 105 + i * 40; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				}
			}
			ic = j;
		}
		}
		return rty;
	}
	int interactionWithMaps() {
		int rty = 0;
		if (y <= 384- h) {
		int ic = 790;
		for (int t = x + 5; t <= x + w - 3; t++) {
			int i = (y - 65 + h) / 40;
			int j = (t - 65) / 80;
			if (j > WIDTH_MAP_BLOK) { j = WIDTH_MAP_BLOK; }
			if (ic != j) {
				switch (TileMapBlok[i][j]) {
				case '1': blo[i][j] -= 1; dy = -dy; y = 65 + i * 40 - h; rty += 1; if (blo[i][j] == 1) {  TileMapBlok[i][j] = '5'; }; break;
				case '2': blo[i][j] -= 1; dy = -dy; y = 65 + i * 40 - h; rty += 1; if (blo[i][j] == 2) {  TileMapBlok[i][j] = '6'; }; break;
				case '3': blo[i][j] -= 1; dy = -dy; y = 65 + i * 40 - h; rty += 1; if (blo[i][j] == 3) { TileMapBlok[i][j] = '7'; }; break;
				case '4': blo[i][j] -= 1; dy = -dy; y = 65 + i * 40 - h; rty += 1; if (blo[i][j] == 4) {  TileMapBlok[i][j] = '8'; }; break;
				case '5': blo[i][j] -= 1; dy = -dy; y = 65 + i * 40 - h; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				case '6': blo[i][j] -= 1; dy = -dy; y = 65 + i * 40 - h; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				case '7': blo[i][j] -= 1; dy = -dy; y = 65 + i * 40 - h; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				case '8': blo[i][j] -= 1; dy = -dy; y = 65 + i * 40 - h; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				}
			}
			ic = j;
		}
		}
		return rty;
	}
	int interactionWithMapa() {
		int jc = 790;
		int rty = 0;
		if (y <= 384 - h) {
		for (int t = y + 3; t <= y + h - 5; t++) {
			int i = (t - 65) / 40;
			int j = (x - 65) / 80;
			if (i > HEIGHT_MAP_BLOK) { i = HEIGHT_MAP_BLOK; }
			if (jc != i) {
				switch (TileMapBlok[i][j]) {
				case '1': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 + 80; rty += 1; if (blo[i][j] == 1) {  TileMapBlok[i][j] = '5'; }; break;
				case '2': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 + 80; rty += 1; if (blo[i][j] == 2) {  TileMapBlok[i][j] = '6'; }; break;
				case '3': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 + 80; rty += 1; if (blo[i][j] == 3) {  TileMapBlok[i][j] = '7'; }; break;
				case '4': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 + 80; rty += 1; if (blo[i][j] == 4) { TileMapBlok[i][j] = '8'; }; break;
				case '5': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 + 80; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				case '6': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 + 80; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				case '7': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 + 80; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				case '8': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 + 80; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				}
			}
			jc = i;
		}
		}
		return rty;
	}
	int interactionWithMapd() {
		int ic = 790;
		int rty = 0;
		if (y <= 384 - h) {
		int j = (x - 65 + w) / 80;
		for (int t = 5 + y; t <= y + h - 3; t++) {
			int i = (t - 65) / 40;
			
			if (i > HEIGHT_MAP_BLOK) { i = HEIGHT_MAP_BLOK; }
			if (ic != j) {
				switch (TileMapBlok[i][j]) {
				case '1': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 - w; rty += 1; if (blo[i][j] == 1) { TileMapBlok[i][j] = '5'; }; break;
				case '2': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 - w; rty += 1; if (blo[i][j] == 2) { TileMapBlok[i][j] = '6'; }; break;
				case '3': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 - w; rty += 1; if (blo[i][j] == 3) { TileMapBlok[i][j] = '7'; }; break;
				case '4': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 - w; rty += 1; if (blo[i][j] == 4) { TileMapBlok[i][j] = '8'; }; break;
				case '5': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 - w; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				case '6': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 - w; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				case '7': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 - w; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				case '8': blo[i][j] -= 1; dx = -dx; x = 65 + j * 80 - w; rty += 1; if (blo[i][j] == 0) { rty += 10; TileMapBlok[i][j] = ' '; }; break;
				}
			}
			ic = j;
		}
		}
		return rty;
	}
};

void enemy(int H, int W, int a, int sid, int ur) {
	int b = 0, ch = 0, t = 1;
	if (ur == 10) {
		while (b < a) {
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					ch = rand() % 16;
					t += sid;
					srand(t);
					if (ch == 0) { if (TileMapBlok[i][j] == ' ') { TileMapBlok[i][j] = '1'; b += 1; } }
					if (b >= a) break;
					if (ch == 5) { if (TileMapBlok[i][j] == ' ') { TileMapBlok[i][j] = '2'; b += 1; } }
					if (b >= a) break;
					if (ch == 7) { if (TileMapBlok[i][j] == ' ') { TileMapBlok[i][j] = '3'; b += 1; } }
					if (b >= a) break;
					if (ch == 11) { if (TileMapBlok[i][j] == ' ') { TileMapBlok[i][j] = '4'; b += 1; } }
					if (b >= a) break;
				}
				if (b >= a) break;
			}
		}
	}
	if (ur == 11) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (i == 0) { TileMapBlok[i][j] = '4'; b += 1; }
				if (i == 2) { TileMapBlok[i][j] = '3'; b += 1; }
				if (i == 4) { TileMapBlok[i][j] = '2'; b += 1; }
				if (i == 6) { TileMapBlok[i][j] = '1'; b += 1; }
			}
		}
	}
	if (ur == 12) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (i == 0) { if (j == 2 or j == 3 or j == 4) TileMapBlok[i][j] = '4'; b += 1; }
				if (i == 1) { if (j == 1 or j == 2 or j == 4 or j == 5) TileMapBlok[i][j] = '4'; b += 1; }
				if (i == 2) { if (j == 1 or j == 5) TileMapBlok[i][j] = '4'; b += 1; }
				if (i == 3) { if (j == 1 or j == 5) TileMapBlok[i][j] = '4'; b += 1; }
				if (i == 4) { if (j == 1 or j == 5) TileMapBlok[i][j] = '4'; b += 1; }
				if (i == 5) { if (j == 1 or j == 2 or j == 4 or j == 5) TileMapBlok[i][j] = '4'; b += 1; }
				if (i == 6) { if (j == 2 or j == 3 or j == 4) TileMapBlok[i][j] = '4'; b += 1; }
				
				if (i == 1) { if (j == 3) TileMapBlok[i][j] = '1'; b += 1; }
				if (i == 2) { if (j == 2 or j == 3 or j == 4) TileMapBlok[i][j] = '1'; b += 1; }
				if (i == 3) { if (j == 2 or j == 3 or j == 4) TileMapBlok[i][j] = '1'; b += 1; }
				if (i == 4) { if (j == 2 or j== 3 or j == 4) TileMapBlok[i][j] = '1'; b += 1; }
				if (i == 5) { if (j == 3) TileMapBlok[i][j] = '1'; b += 1; }
				
				if (i == 0) { if (j == 0 or j == 6) TileMapBlok[i][j] = '3'; b += 1; }
				if (i == 7) { TileMapBlok[i][j] = '3'; b += 1; }
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////

// Ёта функци€:
// 1. считывает из файла 'filepath' рекорды
// 2. записывает в переменную 'recordsToUpdate' обновленные рекорды
void DrawRecords(String filepath, int recordsMaxSize, RenderWindow* w, Font font)
{
	string recordline;
	ifstream f("records.txt");

	if (!f.is_open())
	{
		cout << "\n[E] ERROR: cannot find file ";
		return;
	}

	pair<String, int> records[RECORDS_MAX_RANK];

	int r = 0;
	while (getline(f, recordline))
	{
		int i = recordline.length() - 1;
		string scoreString = "";
		while (!(recordline[i] == ' '))
		{
			scoreString = recordline[i] + scoreString;
			i--;
		}
		string Name = "";
		i--;
		while (i >= 0)
		{
			Name = recordline[i] + Name;
			i--;
		}
		records[r] = (pair<string, int>(Name, stoi(scoreString)));
		r++;
	}
	f.close();

	int i = 0;
	Text recordName("", font, 35);
	Text recordScore("", font, 35);
	while (!(records[i].first == "") && (i < recordsMaxSize))
	{
		string rName = records[i].first;
		int rScore = records[i].second;

		recordName.setString(rName);
		recordName.setPosition(730, 120 + 60 * i);
		recordScore.setString(to_string(rScore));
		recordScore.setPosition(940, 120 + 60 * i);

		w->draw(recordName);
		w->draw(recordScore);
		i++;

		// cout << "\n"
		// 	 << rName << ", " << rScore;
	}
}

// Ёта функци€:
// 1. считывает из файла 'filepath' рекорды
// 2. добавл€ет в рекорды новые очки 'playerScore' игрока с именем 'playerName' (если у игрока есть рекорд, то он обновл€етс€ в том случае, если новые очки больше старых)
// 3. записывает в файл 'filepath' обновленные рекорды
// 4. сообщает игроку в консоль о сохранении его очков
void UpdateRecords(string filepath, string playerName, int playerScore, int recordsMaxSize)
{
	string recordline;
	ifstream f(filepath);

	if (!f.is_open())
	{
		cout << "\n[E] ERROR: cannot find file '" + filepath + "'";
		return;
	}

	pair<string, int> records[RECORDS_MAX_RANK];

	int r = 0;
	while (getline(f, recordline))
	{
		int i = recordline.length() - 1;
		string scoreString = "";
		while (!(recordline[i] == ' '))
		{
			scoreString = recordline[i] + scoreString;
			i--;
		}
		string Name = "";
		i--;
		while (i >= 0)
		{
			Name = recordline[i] + Name;
			i--;
		}
		records[r] = (pair<string, int>(Name, stoi(scoreString)));
		r++;
	}
	f.close();

	bool playerHasRecord = false;

	int k = 0;

	while (k < r)
	{
		if (records[k].first == playerName)
		{
			playerHasRecord = true;
			break;
		}
		k++;
	}

	int updateResultIndex; // если 0 - рекорд был, и теперь он обновилс€ (т.е. улучшилс€)
	// если 1 - рекорд был, но его не удалось побить
	// если 2 - это первый результат игрока, попавший в топ
	// если 3 - набранных очков не достаточно, чтобы попасть в топ

	if (playerHasRecord)
	{
		if (records[k].second < playerScore)
		{
			records[k] = pair<string, int>(playerName, playerScore);
			for (int i = k; i > 0; i--)
			{
				if (records[i].second > records[i - 1].second)
				{
					auto temp = records[i];
					records[i] = records[i - 1];
					records[i - 1] = temp;
				}
				else
				{
					break;
				}
			}
			updateResultIndex = 0;
		}
		else
		{
			updateResultIndex = 1;
		}
	}
	else
	{
		bool canBeInRecords = false;
		int i = 0;
		while (i < recordsMaxSize)
		{
			if (playerScore > records[i].second)
			{
				canBeInRecords = true;
				break;
			}
			i++;
		}

		if (canBeInRecords)
		{
			for (int p = recordsMaxSize - 1; p > i; p--)
			{
				records[p] = records[p - 1];
			}
			records[i] = pair<string, int>(playerName, playerScore);
			updateResultIndex = 2;
		}
		else
		{
			updateResultIndex = 3;
		}
	}

	ofstream f1(filepath);

	int i = 0;
	while (!(records[i].first == "") && i < recordsMaxSize)
	{
		string name = records[i].first;
		int score = records[i].second;
		f1 << name << " " << score << endl;
		i++;
	}
	f1.close();

	switch (updateResultIndex)
	{
	case 0:
		cout << "\n[*] Your record has just been updated!";
		break;
	case 1:
		cout << "\n[*] This time you didn't manage to beat your previous result!";
		break;
	case 2:
		cout << "\n[*] Now your result is in the top " + to_string(recordsMaxSize) + (string)"!";
		break;
	case 3:
		cout << "\n[*] Not bad, but it's not enough to get into the top " + to_string(recordsMaxSize) + (string)"!";
		break;
	default:
		break;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void ris(RenderWindow& window, Player enem, int rtr) {
	for (int i = 0; i < HEIGHT_MAP_BLOK; i++)
	{
		for (int j = 0; j < WIDTH_MAP_BLOK; j++)
		{
			switch (TileMapBlok[i][j])
			{
			case '1':enem.sprite.setTextureRect(IntRect(20, 470, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); if (rtr == 0) { blo[i][j] = 2; }; break;
			case '2':enem.sprite.setTextureRect(IntRect(20, 319, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); if (rtr == 0) { blo[i][j] = 4; }; break;
			case '3':enem.sprite.setTextureRect(IntRect(20, 244, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); if (rtr == 0) { blo[i][j] = 6; }; break;
			case '4':enem.sprite.setTextureRect(IntRect(20, 169, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); if (rtr == 0) { blo[i][j] = 8; }; break;
			case '5':enem.sprite.setTextureRect(IntRect(209, 470, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); break;
			case '6':enem.sprite.setTextureRect(IntRect(209, 319, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); break;
			case '7':enem.sprite.setTextureRect(IntRect(209, 244, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); break;
			case '8':enem.sprite.setTextureRect(IntRect(209, 169, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); break;
			}
		}
	}
}

void ris1(RenderWindow& window, Player kar, Player fon) {
	for (int i = 0; i < HEIGHT_MAP; i++)
	{
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == ' ') fon.sprite.setTextureRect(IntRect(31 + (j - 1) * 40, (i - 1) * 40, 40, 40)); fon.sprite.setPosition(25 + j * 40, 25 + i * 40); window.draw(fon.sprite);
			if (TileMap[i][j] == '0') kar.sprite.setPosition(25 + j * 40, 25 + i * 40); window.draw(kar.sprite);
		}
	}
}

void risc(RenderWindow& window, Player c, int hp) {
	for (int poiu = 0; poiu <= (hp - 2) / 8; poiu++) {
		int tp = hp - 8 * poiu;
		if (tp > 9) { tp = 9; }
		for (int i = 0; i < tp - 1; i++) { c.sprite.setScale(0.5, 0.5); c.sprite.setPosition(720 + 40 * i, 440 + poiu * 40); window.draw(c.sprite); c.sprite.setScale(0.4, 0.4); }
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int menu(RenderWindow& window, int lkm, String my_Name, int score, Player c, int hp, Player kar, Player fon, Player enem, int rtr, Text text, Font font, Player zad, Player pl, Text textr, int ur) {
	int O = ur;
	Image menuT1, menuT2, menuT3, menuT21, menuT22, menuT23, menuT4;
	Texture menuTexture1, menuTexture2, menuTexture3, menuzTex, menuTexture21, menuTexture22, menuTexture23, menuTexture4;
	if (lkm == 1) { menuT1.loadFromFile("images/continued.png"); menuT3.loadFromFile("images/inmenu.png"); menuT2.loadFromFile("images/save.png"); menuT4.loadFromFile("images/exit.png"); }
	if (lkm == 2) { menuT1.loadFromFile("images/restart.png"); menuT21.loadFromFile("images/1.png"); menuT22.loadFromFile("images/2.png"); menuT23.loadFromFile("images/0.png"); menuT3.loadFromFile("images/exit.png"); }
	if (lkm == 0) { menuzTex.loadFromFile("images/fm.png"); menuT2.loadFromFile("images/exit.png"); menuT21.loadFromFile("images/1.png"); menuT22.loadFromFile("images/2.png"); menuT23.loadFromFile("images/0.png");}
	menuT1.createMaskFromColor(Color::White);
	menuT2.createMaskFromColor(Color::White); 
	menuT3.createMaskFromColor(Color::White);
	menuT4.createMaskFromColor(Color::White);
	menuT21.createMaskFromColor(Color::White);
	menuT22.createMaskFromColor(Color::White);
	menuT23.createMaskFromColor(Color::White);
	if (lkm == 1) { menuTexture1.loadFromImage(menuT1); menuTexture2.loadFromImage(menuT2); menuTexture3.loadFromImage(menuT3); menuTexture4.loadFromImage(menuT4); }
	if (lkm == 2) { menuTexture1.loadFromImage(menuT1); menuTexture3.loadFromImage(menuT3); menuTexture21.loadFromImage(menuT21); menuTexture22.loadFromImage(menuT22); menuTexture23.loadFromImage(menuT23); }
	if (lkm == 0) { menuTexture2.loadFromImage(menuT2); menuTexture21.loadFromImage(menuT21); menuTexture22.loadFromImage(menuT22); menuTexture23.loadFromImage(menuT23); }
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuz(menuzTex), menu21(menuTexture21), menu22(menuTexture22), menu23(menuTexture23), menu4(menuTexture4);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setScale(4, 3);
	menu2.setScale(4, 3);
	menu3.setScale(4, 3);
	menu4.setScale(4, 3);
	menu1.setPosition(145, 100);
	menu2.setPosition(145, 260);
	menu3.setPosition(145, 420);
	menu4.setPosition(145, 580);
	if (lkm == 0) {
		menu21.setPosition(145, 150);
		menu22.setPosition(285, 150);
		menu23.setPosition(425, 150);
	}
	if (lkm == 2) {
		if (ur == 10) { menu21.setPosition(205, 235); menu22.setPosition(365, 235); }
		if (ur == 11) { menu22.setPosition(205, 235); menu23.setPosition(365, 235); }
		if (ur == 12) { menu21.setPosition(205, 235); menu23.setPosition(365, 235); }
		menu3.setPosition(145, 330);
	}
	int cx = c.x, cy = c.y;
	while (isMenu)
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape) and lkm == 1) { while (Keyboard::isKeyPressed(Keyboard::Escape)) {}; isMenu = false; }
		if (Keyboard::isKeyPressed(Keyboard::Escape) and lkm == 2) { while (Keyboard::isKeyPressed(Keyboard::Escape)) {}; O = 0; isMenu = false; }
		if (lkm != 0 and IntRect(145, 100, 400, 126).contains(Mouse::getPosition(window))) { menuNum = 1; }
		if (lkm != 2 and IntRect(145, 260, 400, 126).contains(Mouse::getPosition(window))) { menuNum = 2; }
		if (lkm == 0) {
			if (IntRect(145, 150, 120, 84).contains(Mouse::getPosition(window))) { menuNum = 21; }
			if (IntRect(285, 150, 120, 84).contains(Mouse::getPosition(window))) { menuNum = 22; }
			if (IntRect(425, 150, 120, 84).contains(Mouse::getPosition(window))) { menuNum = 23; }
		}
		if (lkm == 2 and ur == 10) {
			if (IntRect(205, 235, 120, 84).contains(Mouse::getPosition(window))) { menuNum = 21; }
			if (IntRect(365, 235, 120, 84).contains(Mouse::getPosition(window))) { menuNum = 22; }
		}
		if (lkm == 2 and ur == 11) {
			if (IntRect(205, 235, 120, 84).contains(Mouse::getPosition(window))) { menuNum = 22; }
			if (IntRect(365, 235, 120, 84).contains(Mouse::getPosition(window))) { menuNum = 23; }
		}
		if (lkm == 2 and ur == 12) {
			if (IntRect(205, 235, 120, 84).contains(Mouse::getPosition(window))) { menuNum = 21; }
			if (IntRect(365, 235, 120, 84).contains(Mouse::getPosition(window))) { menuNum = 23; }
		}
		if (IntRect(145, 420, 400, 126).contains(Mouse::getPosition(window))) { menuNum = 3; }
		if (IntRect(145, 580, 400, 126).contains(Mouse::getPosition(window))) { menuNum = 4; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (lkm == 0) {
				if (menuNum == 21) { O = 11; isMenu = false; }
				if (menuNum == 22) { O = 12; isMenu = false; }
				if (menuNum == 23) { O = 10; isMenu = false; }

				if (menuNum == 2) { O = 0;  isMenu = false;}
			}
			if (lkm == 1) {
				if (menuNum == 1) isMenu = false;

				if (menuNum == 2) { while (Mouse::isButtonPressed(Mouse::Left)) {} UpdateRecords("records.txt", my_Name, score, RECORDS_MAX_RANK); }

				if (menuNum == 3) { isMenu = false; O = 1; }

				if (menuNum == 4) { isMenu = false; O = 0;}
			}
			if (lkm == 2) {
				if (menuNum == 1) { O = ur + 100; isMenu = false; }

				if (menuNum == 21) { O = 111; isMenu = false; }
				if (menuNum == 22) { O = 112; isMenu = false; }
				if (menuNum == 23) { O = 110; isMenu = false; }

				if (menuNum == 3) { O = 0; isMenu = false; }
			}
		}
		window.clear();
		if (lkm != 0) {
			window.draw(zad.sprite);
			ris1(window, kar, fon);
			c.sprite.setPosition(cx, cy);
			window.draw(c.sprite);
			window.draw(pl.sprite);
			ris(window, enem, rtr);
			risc(window, c, hp);
			window.draw(text);
			DrawRecords("records.txt", RECORDS_MAX_RANK, &window, font);
		}
		if (lkm == 0) { window.draw(menuz); window.draw(menu2); window.draw(menu21); window.draw(menu22); window.draw(menu23);}
		if (lkm == 1) { window.draw(menu1); window.draw(menu2); window.draw(menu3); window.draw(menu4); }
		if (lkm == 2) { window.draw(menu1); window.draw(textr); window.draw(menu3); }
		if (lkm == 2) {
			if (ur == 10) { window.draw(menu21); window.draw(menu22); }
			if (ur == 11) { window.draw(menu22); window.draw(menu23); }
			if (ur == 12) { window.draw(menu23); window.draw(menu21); }
		}
		window.display();
	}
	return O;
}
 
////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int O = 1; int bok = 0;
	int chush = 0;
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Asking player name:
	
	string my_Name = "";
	cout << "\n[*] Type your name";
	cout << "\n >  ";
	getline(cin, my_Name);
	while (my_Name.length() < 2 || my_Name.length() > 10)
	{
		cout << "\n[*] Your name should be more than 2 and less than 10 characters long. Try another name: ";
		cout << "\n >  ";
		getline(cin, my_Name);
	}
	Music music;
	music.openFromFile("images/mu.ogg");
	music.play();

	while (O == 1 or O == 11 or O == 10 or O == 12) {
		int lkm = 0;
		int hp = 2;

		RenderWindow window(sf::VideoMode(1080, 930), "T_T");

		Font u;
		u.loadFromFile("images/sansation.ttf");
		Text textr("", u, 90);
		textr.setString("GAME OVER");
		textr.setPosition(85, 470);
		Text textre("", u, 90);
		textre.setString("LEVEL WIN");
		textre.setPosition(108, 470);

		int kjh = 0, mnb = 0, rtr = 0, sc = 0, kod = 0;
		bool Records_After_Game_Over_Updated = false;
		int wfhj = 0; int dfgh = 0;
		int tscore = 0; float zy = 0; float zx = 0;
		int sid, f = 0, h = 0, ge = 0;

		sid = rand();

		Font font;
		Text text("", font, 40);

		int xr = 0, yr = 0;

		xr = rand() % 840;
		yr = rand() % 150;

		int b = 0, score = 0, Mscore = 0;

		Player zad("zad.jpg", 0, 0, xr, yr, 1080, 930, 1, 1);
		Player pl("Arkanoid.png", 296, 760, 397, 18, 154, 40, 0.65, 0.65);
		Player fon("fon.jpg", 0, 0, 0, 0, 40, 40, 1, 1);
		Player kar("Arkanoid.png", 0, 0, 726, 512, 60, 60, 0.6666, 0.6666);
		Player enem("Arkanoid.png", 0, 0, 0, 0, 170, 57, 0.470588, 0.701754);
		Player c("Arkanoid.png", 334, 730, 808, 548, 76, 76, 0.4, 0.4);

		if (O == 1) O = menu(window, lkm, my_Name, lkm, c, hp, kar, fon, enem, rtr, text, font, zad, pl, textr, O);

		Clock clock;
		float CurrentFrame = 0;
		int m = 0;
		int k = 0;
		lkm = 1;

		while (window.isOpen())
		{
			if (O == 10) bok = blok;
			if (O == 11) bok = 28;
			if (O == 12) bok = 40;
			
			int jhlsdjhgl = 0;
			if (b >= bok and (O == 11 or O == 12)) { O = menu(window, 2, my_Name, score, c, hp, kar, fon, enem, rtr, text, font, zad, pl, textre, O); hp += 1; }
			if (b >= bok and O == 10) { f = 0; }
			if (f == 0) {

				sid += rand() * 1111;
				if (wfhj == 0) { tscore += Mscore; }
				else { hp -= sid % 2 * 0; tscore += Mscore; }
				Mscore = 0;
				b = 0;
				k = 0;
				m = 0;
				rtr = 0;
				c.dx = 0; c.dy = 0;
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 7; j++) {
						blo[i][j] = 0;
						TileMapBlok[i][j] = ' ';
					}
				}
				enemy(HEIGHT_MAP_BLOK, WIDTH_MAP_BLOK, blok, sid, O);
				kod = 0;
			}

			lkm = 1;

			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;

			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					O = 0;
				}
			}

			if (m > 0) {
				if (Keyboard::isKeyPressed(Keyboard::Left) or Keyboard::isKeyPressed(Keyboard::A)) { pl.dir = 1; pl.speed = 0.3; c.dir = 1; c.speed = 0.3; m += 1; kod += 1; }
				if (Keyboard::isKeyPressed(Keyboard::Right) or Keyboard::isKeyPressed(Keyboard::D)) { pl.dir = 0; pl.speed = 0.3; c.dir = 0; c.speed = 0.3; m += 1; kod += 1; }
				if (Keyboard::isKeyPressed(Keyboard::LShift)) { kod += 1; pl.speed *= 2; }
				if (Keyboard::isKeyPressed(Keyboard::LControl)) { kod += 1; pl.speed *= 0.5; }
				if (Keyboard::isKeyPressed(Keyboard::Escape)) { while (Keyboard::isKeyPressed(Keyboard::Escape)) {} O = menu(window, lkm, my_Name, score, c, hp, kar, fon, enem, rtr, text, font, zad, pl, textr, O); clock.restart(); }
				

				pl.update(time);
				c.plat(pl.x, pl.dx, pl.h, pl.w);
				pl.stenki();
				if (m == 2) {
					c.updatez(time);
				}
				c.updatex(time);
				if (c.stenkiz()) { hp -= 1; mnb = 0; m = 0; c.dx = 0; c.dy = 0; pl.dx = 0; pl.dy = 0; }

				int fghj = 0;
				if (fghj == 0) { jhlsdjhgl += c.interactionWithMapw(); fghj += jhlsdjhgl; }
				if (fghj == 0) { jhlsdjhgl += c.interactionWithMaps(); fghj += jhlsdjhgl; }
				if (fghj == 0) { jhlsdjhgl += c.interactionWithMapa(); fghj += jhlsdjhgl; }
				if (fghj == 0) { jhlsdjhgl += c.interactionWithMapd(); fghj += jhlsdjhgl; }
				b += jhlsdjhgl / 10;
			}

			if (c.y <= 385) {
				int i1 = (c.y - 65) / 40;
				int j1 = (c.x - 65) / 80;
			}
			font.loadFromFile("images/sansation.ttf");
			std::ostringstream scorew;
			score = 100 * b;
			if (Mscore < score) Mscore = score;
			score += tscore;
			scorew << score;
			text.setString(my_Name + "  " + scorew.str());
			text.setPosition(730, 40);
			if (m == 0) { pl.sprite.setPosition(296, 760); pl.x = 296; pl.y = 760; c.sprite.setPosition(334, 730); c.x = 334; c.y = 730; f = 0; }
			window.clear();

			window.draw(zad.sprite);
			for (int i = 0; i < HEIGHT_MAP; i++)
			{
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					if (TileMap[i][j] == ' ') fon.sprite.setTextureRect(IntRect(31 + (j - 1) * 40, (i - 1) * 40, 40, 40)); fon.sprite.setPosition(25 + j * 40, 25 + i * 40); window.draw(fon.sprite);
					if (TileMap[i][j] == '0') kar.sprite.setPosition(25 + j * 40, 25 + i * 40); window.draw(kar.sprite);
				}
			}
			window.draw(pl.sprite);
			window.draw(c.sprite);
			for (int i = 0; i < HEIGHT_MAP_BLOK; i++)
			{
				for (int j = 0; j < WIDTH_MAP_BLOK; j++)
				{
					switch (TileMapBlok[i][j])
					{
					case '1':enem.sprite.setTextureRect(IntRect(20, 470, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); if (rtr == 0) { blo[i][j] = 2; }; break;
					case '2':enem.sprite.setTextureRect(IntRect(20, 319, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); if (rtr == 0) { blo[i][j] = 4; }; break;
					case '3':enem.sprite.setTextureRect(IntRect(20, 244, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); if (rtr == 0) { blo[i][j] = 6; }; break;
					case '4':enem.sprite.setTextureRect(IntRect(20, 169, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); if (rtr == 0) { blo[i][j] = 8; }; break;
					case '5':enem.sprite.setTextureRect(IntRect(209, 470, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); break;
					case '6':enem.sprite.setTextureRect(IntRect(209, 319, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); break;
					case '7':enem.sprite.setTextureRect(IntRect(209, 244, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); break;
					case '8':enem.sprite.setTextureRect(IntRect(209, 169, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); break;
					}
				}
			}
			window.draw(text);
			for (int poiu = 0; poiu <= (hp - 2) / 8; poiu++) {
				int tp = hp - 8 * poiu;
				if (tp > 9) { tp = 9; }
				for (int i = 0; i < tp - 1; i++) { c.sprite.setScale(0.5, 0.5); c.sprite.setPosition(720 + 40 * i, 440 + poiu * 40); window.draw(c.sprite); c.sprite.setScale(0.4, 0.4); }
			}

			if (hp < 1) {
				if (!Records_After_Game_Over_Updated)
				{
					UpdateRecords("records.txt", my_Name, score, RECORDS_MAX_RANK);
					Records_After_Game_Over_Updated = true;
				}

				m = -30;
			}

			DrawRecords("records.txt", RECORDS_MAX_RANK, &window, font);

			window.display();
			

			if (hp < 1) {
				O = menu(window, 2, my_Name, score, c, hp, kar, fon, enem, rtr, text, font, zad, pl, textr, O);
			}
			
			if (f == 0) { m += 1; }
			f += 1; rtr += 1;
			if (O == 10) {
				if (Keyboard::isKeyPressed(Keyboard::RControl) and (kod > blok)) { kod += 1; b = bok; }
				if (Keyboard::isKeyPressed(Keyboard::RControl)) { kod += 1; wfhj = 1; }
			}
			if (O == 0 or O == 1) { window.close(); }
			if (O == 111 or O == 112 or O == 110) { O -= 100; window.close(); }
		}
	}
	
	return 0;
}