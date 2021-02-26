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
		printf("SDL �� ���� �����������! SDL_Error: %s\n", SDL_GetError());
	}
	

	
	return go;
}
void quit() {
	

	SDL_Quit();
}
void noutbuk() {
	if (initial()) {
		int x, y;
		cout << "������� ���������� ��������� ��������(����� ������� ����)" << endl;
		cin >> x >> y;
		//����
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"���������", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("���� �� ����� ���� �������! SDL_Error: %s\n", SDL_GetError());

		}
		//�����������
		SDL_Renderer* renderer = NULL;
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL)
		{
			printf("����������� �� ����� ���� ������! SDL_Error: %s\n", SDL_GetError());

		}
		//������ ���� ������������
		SDL_SetRenderDrawColor(renderer, 100, 100, 255, 0);
		//����������� ��� ������� ����
		SDL_RenderClear(renderer);
		//������ ����� ����
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		int w1 = 120;
		int h1 = 70;

		SDL_Rect rect1 = { x,y, w1, h1 };//x,y ���������� ������ �������� w,h ������, ������
		SDL_RenderFillRect(renderer, &rect1);//���������� �������������

		SDL_SetRenderDrawColor(renderer, 130, 255, 255, 255);
		int w2 = 100;
		int h2 = 50;
		SDL_Rect rect2 = { x + 10,y + 10 , w2, h2 };//x,y ���������� ������ �������� w,h ������, ������
		SDL_RenderFillRect(renderer, &rect2);// ���������� �������������
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_RenderDrawLine(renderer, x, y + h1, x - 30, h1 + y + 45);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		int w3 = w1 + 30 + 30;
		int h3 = 10;
		SDL_Rect rect3 = { x - 30,h1 + y + 45, w3, h3 };//x,y ���������� ������ �������� w,h ������, ������
		SDL_RenderFillRect(renderer, &rect3);// ���������� �������������
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLine(renderer, x + w1, y + h1, x + w1 + 30, y + h1 + 45);
		//������ ����� ����
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLine(renderer, x, y + h1 + 20, x + w1, y + h1 + 20);
		SDL_RenderDrawLine(renderer, x + h1 / 2, y + h1 + 40, x + w1 - h1 / 2, y + h1 + 40);

		//���������� ���������
		SDL_RenderPresent(renderer);
		//��������
		SDL_Delay(5000);
		//� ������� �� ������ ����
		SDL_DestroyWindow(window);
		window = NULL;
		//������� �����������
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
		cout << "������� ���������� ������ ����������" << endl;
		cin >> x0 >> y0;
		cout << "������� ������ ����������" << endl;
		cin >> r;
		while (r > x0 || r > y0) {
			cout << "���������� �� ����� ���� ���������. ������� ������� ������." << endl;
			cin >> r;
		}
		//����
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"���������", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			printf("���� �� ����� ���� �������! SDL_Error: %s\n", SDL_GetError());

		}
		//�����������
		SDL_Renderer* renderer = NULL;
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL)
		{
			printf("����������� �� ����� ���� ������! SDL_Error: %s\n", SDL_GetError());

		}
		//������ ���� ������������
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		//����������� ��� ������� ����
		SDL_RenderClear(renderer);
		//������ ����� ����
		SDL_SetRenderDrawColor(renderer, 0, 0, 250, 0);

		for (int i = 1; i < 3600; i++) {

			double t = i * (pi / 180);
			x = int(r * cos(t) + x0);
			y = int(r * sin(t) + y0);
			SDL_RenderDrawPoint(renderer, x, y);
		}



		//���������� ���������
		SDL_RenderPresent(renderer);
		//��������
		SDL_Delay(5000);

		//� ������� �� ������ ����
		SDL_DestroyWindow(window);
		//������� �����������
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
		int a1;//���� �������, ���???



		cout << "������� �������� �� �" << endl;
		cin >> xleft >> xright;
		while (xleft > xright) {
			cout << "�������� ������ �������. ���������� ��� ���." << endl;
			cin >> xleft >> xright;
		}
		cout << "������� ������������ �������� (� � b)" << endl;
		cin >> a >> b;
		cout << "������� ������ ���� �������" << endl;
		cin >> a1;


		//����
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"���������", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			printf("���� �� ����� ���� �������! SDL_Error: %s\n", SDL_GetError());

		}
		//�����������
		SDL_Renderer* renderer = NULL;
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL)
		{
			printf("����������� �� ����� ���� ������! SDL_Error: %s\n", SDL_GetError());

		}
		//������ ���� ������������
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		//����������� ��� ������� ����
		SDL_RenderClear(renderer);
		//������ ����� ����
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

		//��� �
		for (int i = 0; i < SCREEN_WIDTH; i++) {
			SDL_RenderDrawPoint(renderer, i, SCREEN_HEIGHT / 2);
			
		}
		//�������
		SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2,0, SCREEN_WIDTH / 2+5, 5);
		SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2 -5, 5);
		//������� �� ���
		for (int i = SCREEN_WIDTH / 2; i < SCREEN_WIDTH; i += a1) {
			SDL_RenderDrawLine(renderer, i, SCREEN_HEIGHT / 2 + 5, i, SCREEN_HEIGHT / 2 - 5);
		}
		for (int i = SCREEN_WIDTH / 2; i > 0; i -= a1) {
			SDL_RenderDrawLine(renderer, i, SCREEN_HEIGHT / 2 + 5, i, SCREEN_HEIGHT / 2 - 5);
		}

		//��� �
		for (int i = 0; i < SCREEN_HEIGHT; i++) {
			SDL_RenderDrawPoint(renderer, SCREEN_WIDTH / 2, i);
		}
		//�������
		SDL_RenderDrawLine(renderer, SCREEN_WIDTH, SCREEN_HEIGHT / 2, SCREEN_WIDTH-5, SCREEN_HEIGHT / 2-5);
		SDL_RenderDrawLine(renderer, SCREEN_WIDTH, SCREEN_HEIGHT / 2, SCREEN_WIDTH -5, SCREEN_HEIGHT / 2 + 5);
		
		//������� �� y
		for (int i = SCREEN_HEIGHT / 2; i < SCREEN_HEIGHT; i += a1) {
			SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2 + 5, i, SCREEN_WIDTH / 2 - 5, i);
		}
		for (int i = SCREEN_HEIGHT / 2; i > 0; i -= a1) {
			SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2 + 5, i, SCREEN_WIDTH / 2 - 5, i);
		}

		//������

		for (float i = xleft; i <= xright; i += 0.01) {
			y = a * i * i + b;
			SDL_RenderDrawPoint(renderer, i * a1 + SCREEN_WIDTH / 2, -y * a1 + SCREEN_HEIGHT / 2);
		}

		//���������� ���������
		SDL_RenderPresent(renderer);
		//��������
		SDL_Delay(5000);

		//� ������� �� ������ ����
		SDL_DestroyWindow(window);
		//������� �����������
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
		cout << "�������� ����� �������:" << endl;
		cout << "1.�������" << endl;
		cout << "2.����������" << endl;
		cout << "3.������ y=a*x^2+b" << endl;
		cout << "��� ������ �� ��������� ������� 0." << endl;
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
