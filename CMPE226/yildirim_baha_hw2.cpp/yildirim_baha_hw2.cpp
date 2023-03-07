
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <array>
#include <time.h>
#include "Queue.h"
using namespace std;

template <class T>
class Snake {
private:
    char game_field[20][20];
    array<int,2> snake_head;
    Queue<T> bodyQueue;
    int snake_size;
    int counter;
    int next_size;
    void display(){
		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++){
				cout << game_field[i][j];
			}
			cout << endl;
		}
	}
public:
	Snake(){
		snake_head[0] = 5;
		snake_head[1] = 5;
		snake_size = 1;
		srand(time(NULL));
		next_size = rand()%5+1;
		counter = 0;
		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++){
				if((snake_head[0] == i) && (snake_head[1] == j)) {
					game_field[i][j] = -78;
					continue;
				}
				game_field[i][j] = -80;
			}
		}
	}
	void gameLoop(){
		display();
		char move_dir = _getch();
		int y = snake_head[0];
	 	int x = snake_head[1];
		switch(move_dir){
			case 'w':
			case 'W':
				if((game_field[y-1][x] == -78) || (y-1<0)){
					cout << "Game Over" << endl;
					return;
				}
				bodyQueue.add(snake_head);
				if(bodyQueue.size() >= snake_size){
					array<int,2> temp = bodyQueue.remove();
					game_field[temp[0]][temp[1]] = -80;
				}
				snake_head[0] = y-1;
				game_field[y-1][x] = -78;
				counter++;
				if(counter == next_size){
					counter = 0;
					snake_size++;
					next_size = rand()%5+1;
				}
				system("cls");
				gameLoop();
				break;
			case 'a':
			case 'A':
				if((game_field[y][x-1] == -78) || (x-1<0)){
					cout << "Game Over" << endl;
					return;
				}
				bodyQueue.add(snake_head);
				if(bodyQueue.size() >= snake_size){
					array<int,2> temp = bodyQueue.remove();
					game_field[temp[0]][temp[1]] = -80;
				}
				snake_head[1] = x-1;
				game_field[y][x-1] = -78;
				counter++;
				if(counter == next_size){
					counter = 0;
					snake_size++;
					next_size = rand()%5+1;
				}
				system("cls");
				gameLoop();
				break;
			case 's':
			case 'S':
				if((game_field[y+1][x] == -78) || (y+1>=20)){
					cout << "Game Over" << endl;
					return;
				}
				bodyQueue.add(snake_head);
				if(bodyQueue.size() >= snake_size){
					array<int,2> temp = bodyQueue.remove();
					game_field[temp[0]][temp[1]] = -80;
				}
				snake_head[0] = y+1;
				game_field[y+1][x] = -78;
				counter++;
				if(counter == next_size){
					counter = 0;
					snake_size++;
					next_size = rand()%5+1;
				}
				system("cls");
				gameLoop();
				break;
			case 'd':
			case 'D':
				if((game_field[y][x+1] == -78) || (x+1>=20)){
					cout << "Game Over" << endl;
					return;
				}
				bodyQueue.add(snake_head);
				if(bodyQueue.size() >= snake_size){
					array<int,2> temp = bodyQueue.remove();
					game_field[temp[0]][temp[1]] = -80;
				}
				snake_head[1] = x+1;
				game_field[y][x+1] = -78;
				counter++;
				if(counter == next_size){
					counter = 0;
					snake_size++;
					next_size = rand()%5+1;
				}
				system("cls");
				gameLoop();
				break;
		}
	}
};

int main()
{
    Snake<array<int,2>> snake;
    snake.gameLoop();
    return 0;
}

