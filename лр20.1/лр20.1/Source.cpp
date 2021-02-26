#include <SDL.h>
#include<stdio.h>
#include<iostream>
#include <locale.h>
using namespace std;
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT  480
#define pi 3.14
bool initial() {
	bool go = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL не смог запуститься! SDL_Error: %s\n", SDL_GetError());
	}
	

	
	return go;
}
void quit() {
	

	SDL_Quit();
}
void noutbuk() {
	if (initial()) {
		int x, y;
		cout << "Введите координаты положения ноутбука(левый верхний угол)" << endl;
		cin >> x >> y;
		//окно
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"Цыганкова", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Окно не может быть создано! SDL_Error: %s\n", SDL_GetError());

		}
		//рисовальщик
		SDL_Renderer* renderer = NULL;
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL)
		{
			printf("Рисовальщик не может быть создан! SDL_Error: %s\n", SDL_GetError());

		}
		//задаем цвет рисовальщику
		SDL_SetRenderDrawColor(renderer, 100, 100, 255, 0);
		//закрашиваем всю область окна
		SDL_RenderClear(renderer);
		//задаем новый цвет
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		int w1 = 120;
		int h1 = 70;

		SDL_Rect rect1 = { x,y, w1, h1 };//x,y координаты левого верхнего w,h ширина, высота
		SDL_RenderFillRect(renderer, &rect1);//закрашеный прямоугольник

		SDL_SetRenderDrawColor(renderer, 130, 255, 255, 255);
		int w2 = 100;
		int h2 = 50;
		SDL_Rect rect2 = { x + 10,y + 10 , w2, h2 };//x,y координаты левого верхнего w,h ширина, высота
		SDL_RenderFillRect(renderer, &rect2);// закрашеный прямоугольник
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_RenderDrawLine(renderer, x, y + h1, x - 30, h1 + y + 45);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		int w3 = w1 + 30 + 30;
		int h3 = 10;
		SDL_Rect rect3 = { x - 30,h1 + y + 45, w3, h3 };//x,y координаты левого верхнего w,h ширина, высота
		SDL_RenderFillRect(renderer, &rect3);// закрашеный прямоугольник
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLine(renderer, x + w1, y + h1, x + w1 + 30, y + h1 + 45);
		//задаем новый цвет
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLine(renderer, x, y + h1 + 20, x + w1, y + h1 + 20);
		SDL_RenderDrawLine(renderer, x + h1 / 2, y + h1 + 40, x + w1 - h1 / 2, y + h1 + 40);

		//показываем результат
		SDL_RenderPresent(renderer);
		//задержка
		SDL_Delay(5000);
		//И удаляем из памяти окно
		SDL_DestroyWindow(window);
		window = NULL;
		//удаляем рисовальщик
		SDL_DestroyRenderer(renderer);
		renderer = NULL;

		quit();

	}
	else
		quit();

}
void okruz() {
	if (initial()) {

		int x, y;
		int x0, y0, r;
		cout << "Введите координаты центра окружности" << endl;
		cin >> x0 >> y0;
		cout << "Введите радиус окружности" << endl;
		cin >> r;
		while (r > x0 || r > y0) {
			cout << "Окружность не может быть построена. Введите меньший радиус." << endl;
			cin >> r;
		}
		//окно
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"Цыганкова", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			printf("Окно не может быть создано! SDL_Error: %s\n", SDL_GetError());

		}
		//рисовальщик
		SDL_Renderer* renderer = NULL;
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL)
		{
			printf("Рисовальщик не может быть создан! SDL_Error: %s\n", SDL_GetError());

		}
		//задаем цвет рисовальщику
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		//закрашиваем всю область окна
		SDL_RenderClear(renderer);
		//задаем новый цвет
		SDL_SetRenderDrawColor(renderer, 0, 0, 250, 0);

		for (int i = 1; i < 3600; i++) {

			double t = i * (pi / 180);
			x = int(r * cos(t) + x0);
			y = int(r * sin(t) + y0);
			SDL_RenderDrawPoint(renderer, x, y);
		}



		//показываем результат
		SDL_RenderPresent(renderer);
		//задержка
		SDL_Delay(5000);

		//И удаляем из памяти окно
		SDL_DestroyWindow(window);
		//удаляем рисовальщик
		SDL_DestroyRenderer(renderer);
		SDL_Quit();

	}
	else
		SDL_Quit();
}
void graf() {
	if (initial()) {
		float y, a, b;
		float xleft, xright;
		int a1;//цена деления, шаг???



		cout << "Введите диапазон по х" << endl;
		cin >> xleft >> xright;
		while (xleft > xright) {
			cout << "Диапазон введен неверно. Попробуйте еще раз." << endl;
			cin >> xleft >> xright;
		}
		cout << "Введите коэффициенты параболы (а и b)" << endl;
		cin >> a >> b;
		cout << "Введите размер цены деления" << endl;
		cin >> a1;


		//окно
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"Цыганкова", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			printf("Окно не может быть создано! SDL_Error: %s\n", SDL_GetError());

		}
		//рисовальщик
		SDL_Renderer* renderer = NULL;
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL)
		{
			printf("Рисовальщик не может быть создан! SDL_Error: %s\n", SDL_GetError());

		}
		//задаем цвет рисовальщику
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		//закрашиваем всю область окна
		SDL_RenderClear(renderer);
		//задаем новый цвет
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

		//ось х
		for (int i = 0; i < SCREEN_WIDTH; i++) {
			SDL_RenderDrawPoint(renderer, i, SCREEN_HEIGHT / 2);
			
		}
		//стрелки
		SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2,0, SCREEN_WIDTH / 2+5, 5);
		SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2 -5, 5);
		//деления по икс
		for (int i = SCREEN_WIDTH / 2; i < SCREEN_WIDTH; i += a1) {
			SDL_RenderDrawLine(renderer, i, SCREEN_HEIGHT / 2 + 5, i, SCREEN_HEIGHT / 2 - 5);
		}
		for (int i = SCREEN_WIDTH / 2; i > 0; i -= a1) {
			SDL_RenderDrawLine(renderer, i, SCREEN_HEIGHT / 2 + 5, i, SCREEN_HEIGHT / 2 - 5);
		}

		//ось у
		for (int i = 0; i < SCREEN_HEIGHT; i++) {
			SDL_RenderDrawPoint(renderer, SCREEN_WIDTH / 2, i);
		}
		//стрелки
		SDL_RenderDrawLine(renderer, SCREEN_WIDTH, SCREEN_HEIGHT / 2, SCREEN_WIDTH-5, SCREEN_HEIGHT / 2-5);
		SDL_RenderDrawLine(renderer, SCREEN_WIDTH, SCREEN_HEIGHT / 2, SCREEN_WIDTH -5, SCREEN_HEIGHT / 2 + 5);
		
		//деления по y
		for (int i = SCREEN_HEIGHT / 2; i < SCREEN_HEIGHT; i += a1) {
			SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2 + 5, i, SCREEN_WIDTH / 2 - 5, i);
		}
		for (int i = SCREEN_HEIGHT / 2; i > 0; i -= a1) {
			SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2 + 5, i, SCREEN_WIDTH / 2 - 5, i);
		}

		//график

		for (float i = xleft; i <= xright; i += 0.01) {
			y = a * i * i + b;
			SDL_RenderDrawPoint(renderer, i * a1 + SCREEN_WIDTH / 2, -y * a1 + SCREEN_HEIGHT / 2);
		}

		//показываем результат
		SDL_RenderPresent(renderer);
		//задержка
		SDL_Delay(5000);

		//И удаляем из памяти окно
		SDL_DestroyWindow(window);
		//удаляем рисовальщик
		SDL_DestroyRenderer(renderer);
		SDL_Quit();

	}
	else
		SDL_Quit();
}
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int z;

	do {
		cout << "Выберите номер задания:" << endl;
		cout << "1.Ноутбук" << endl;
		cout << "2.Окружность" << endl;
		cout << "3.График y=a*x^2+b" << endl;
		cout << "Для выхода из программы введите 0." << endl;
		cin >> z;
	switch (z) {
		case 1: 
			noutbuk();
			break;
		case 2:
			okruz();
			break;
		case 3:
			graf();
			break;
		default: exit(0);
	}
	} while (z != 0);
	
return 1;
}
