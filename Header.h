#include <SFML\Graphics.hpp>
const int HEIGHT_MAP = 22;//размер карты высота
const int WIDTH_MAP = 16;//размер карты ширина 
const int HEIGHT_MAP_BLOK = 8;
const int WIDTH_MAP_BLOK = 7;
const int blok = 30;
const int blok1 = 28;
const int RECORDS_MAX_RANK = 5;

sf::String TileMap[HEIGHT_MAP] = {
	"0000000000000000",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0              0",
	"0000000000000000",
};

sf::String TileMapBlok[HEIGHT_MAP_BLOK] = {
	"       ",
	"       ",
	"       ",
	"       ",
	"       ",
	"       ",
	"       ",
	"       ",
};

int blo[HEIGHT_MAP_BLOK][WIDTH_MAP_BLOK] = {
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
};