/*
		CurrentFrame += 0.007 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		pl.sprite.setTextureRect(IntRect(397 + 15 * int(CurrentFrame) + 154 * int(CurrentFrame), 18, 154, 40));


	
		void menu(RenderWindow& window) {
		Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
		menuTexture1.loadFromFile("images/111.png");
		menuTexture2.loadFromFile("images/222.png");
		menuTexture3.loadFromFile("images/333.png");
		aboutTexture.loadFromFile("images/about.png");
		menuBackground.loadFromFile("images/Penguins.jpg");
		Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
		bool isMenu = 1;
		int menuNum = 0;
		menu1.setPosition(100, 30);
		menu2.setPosition(100, 90);
		menu3.setPosition(100, 150);
		menuBg.setPosition(345, 0);


		while (isMenu)
		{
			menu1.setColor(Color::White);
			menu2.setColor(Color::White);
			menu3.setColor(Color::White);
			menuNum = 0;
			window.clear(Color(129, 181, 221));

			if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
			if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
			if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню
				if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
				if (menuNum == 3) { window.close(); isMenu = false; }

			}

			window.draw(menuBg);
			window.draw(menu1);
			window.draw(menu2);
			window.draw(menu3);

			window.display();
		}

	}



	Font font;
	font.loadFromFile("shrift/CyrilicOld.ttf");
	Text text("", font, 20);
	text.setColor(Color::White);
	text.setPosition(730, 40);

	int sh = 1, score = 0, xr, yr;
	xr = (rand() % 840); yr = (rand() % 150);

	Player zad("zad.jpg", 0, 0, xr, yr, 1080, 930, 1);

	void enemy(int H, int W, int a) {
	int b = a, ch = 0;
	while (b) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				srand(time(0));
				ch = rand() % 16;
				if (ch == 0) { if (TileMapBlok[i][j] == ' ') { TileMapBlok[i][j] = '1'; b -= 1; } }
				if (ch == 5) { if (TileMapBlok[i][j] == ' ') { TileMapBlok[i][j] = '2'; b -= 1; } }
				if (ch == 7) { if (TileMapBlok[i][j] == ' ') { TileMapBlok[i][j] = '3'; b -= 1; } }
				if (ch == 11) { if (TileMapBlok[i][j] == ' ') { TileMapBlok[i][j] = '4'; b -= 1; } }
			}
		}
	}
}

	enemy(HEIGHT_MAP_BLOK, WIDTH_MAP_BLOK, blok);

	if (TileMapBlok[i][j] == ' ')
				if (TileMapBlok[i][j] == '1') enem.sprite.setTextureRect(IntRect(20, 470, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); enem.imhp = 1;
				if (TileMapBlok[i][j] == '2') enem.sprite.setTextureRect(IntRect(20, 319, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); enem.imhp = 2;
				if (TileMapBlok[i][j] == '3') enem.sprite.setTextureRect(IntRect(20, 244, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); enem.imhp = 3;
				if (TileMapBlok[i][j] == '4') enem.sprite.setTextureRect(IntRect(20, 169, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); enem.imhp = 4;

				
				for (int i = 0; i < HEIGHT_MAP_BLOK; i++) {
				for (int j = 0; j < WIDTH_MAP_BLOK; j++) {
					if

					switch (TileMapBlok[i][j])
					{
					case '1':enem.sprite.setTextureRect(IntRect(20, 470, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); blo[i][j] = 1; break;
					case '2':enem.sprite.setTextureRect(IntRect(20, 319, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); blo[i][j] = 2; break;
					case '3':enem.sprite.setTextureRect(IntRect(20, 244, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); blo[i][j] = 3; break;
					case '4':enem.sprite.setTextureRect(IntRect(20, 169, 170, 57)); enem.sprite.setScale(0.470588, 0.701754); enem.sprite.setPosition(65 + j * 80, 65 + i * 40); window.draw(enem.sprite); blo[i][j] = 4; break;
					}
				}
			}
	if (TileMapBlok[i][j] == '1')
		{
			if (dy > 0)//если мы шли вниз,
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 2) { TileMapBlok[i][j] = '5'; }; //то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
			}
			if (dy < 0)
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 2) { TileMapBlok[i][j] = '5'; }; //аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
			}
			if (dx > 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 2) { TileMapBlok[i][j] = '5'; }; //если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
			}
			if (dx < 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 2) { TileMapBlok[i][j] = '5'; }; //аналогично идем влево
			}
		}
		if (TileMapBlok[i][j] == '2')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
		{
			if (dy > 0)//если мы шли вниз,
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 4) { TileMapBlok[i][j] = '6'; }; //то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
					}
			if (dy < 0)
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 4) { TileMapBlok[i][j] = '6'; }; //аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
			}
			if (dx > 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 4) { TileMapBlok[i][j] = '6'; }; //если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
			}
			if (dx < 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 4) { TileMapBlok[i][j] = '6'; }; //аналогично идем влево
			}
		}
		if (TileMapBlok[i][j] == '3')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
		{
			if (dy > 0)//если мы шли вниз,
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 6) { TileMapBlok[i][j] = '7'; }; //то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
			}
			if (dy < 0)
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 6) { TileMapBlok[i][j] = '7'; }; //аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
			}
			if (dx > 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 6) { TileMapBlok[i][j] = '7'; }; //если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
			}
			if (dx < 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 6) { TileMapBlok[i][j] = '7'; }; //аналогично идем влево
			}
		}
		if (TileMapBlok[i][j] == '4')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
		{
			if (dy > 0)//если мы шли вниз,
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 8) { TileMapBlok[i][j] = '8'; }; //то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
			}
			if (dy < 0)
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 8) { TileMapBlok[i][j] = '8'; }; //аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
			}
			if (dx > 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 8) { TileMapBlok[i][j] = '8'; };  //если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
			}
			if (dx < 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 8) { TileMapBlok[i][j] = '8'; }; //аналогично идем влево
			}
		}
		if (TileMapBlok[i][j] == '5')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
		{
			if (dy > 0)//если мы шли вниз,
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
			}
			if (dy < 0)
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
			}
			if (dx > 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
			}
			if (dx < 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//аналогично идем влево
			}
		}
		if (TileMapBlok[i][j] == '6')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
		{
			if (dy > 0)//если мы шли вниз,
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
			}
			if (dy < 0)
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
			}
			if (dx > 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
			}
			if (dx < 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//аналогично идем влево
			}
		}
		if (TileMapBlok[i][j] == '7')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
		{
			if (dy > 0)//если мы шли вниз,
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
			}
			if (dy < 0)
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
			}
			if (dx > 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
			}
			if (dx < 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//аналогично идем влево
			}
		}
		if (TileMapBlok[i][j] == '8')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
		{
			if (dy > 0)//если мы шли вниз,
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
			}
			if (dy < 0)
			{
				dy = -dy; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
			}
			if (dx > 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
			}
			if (dx < 0)
			{
				dx = -dx; blo[i][j] -= 1; if (blo[i][j] == 0) { TileMapBlok[i][j] = ' '; }//аналогично идем влево
			}
		}
		if (i != i1 and j != j1) { dx = -dx; dy = -dy; }; if (dy > 0 and dx > 0 and i == i1) { dx = -dx; }; if (dy > 0 and dx > 0 and j == j1) { dy = -dy; }; if (dy > 0 and dx < 0 and i == i1) { dx = -dx; }; if (dy > 0 and dx < 0 and j == j1) { dy = -dy; }; if (dy < 0 and dx < 0 and i == i1) { dx = -dx; }; if (dy < 0 and dx > 0 and j == j1) { dy = -dy; }; if (dy < 0 and dx < 0 and i == i1) { dx = -dx; }; if (dy < 0 and dx < 0 and j == j1) { dy = -dy; };
*/