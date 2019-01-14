#pragma once
#include<iostream>
#include<time.h>
#define N 15
using namespace std;
int InitGame(int a[N + 2][N + 2],int b[N + 2][N + 2],int c[N + 2][N + 2]);
void Show(int a[N + 2][N + 2], int b[N + 2][N + 2], int c[N + 2][N + 2]);
void Show(int a[N + 2][N + 2]);
void RunGame();
int  Dliang(int x, int y, int a[N + 2][N + 2], int b[N + 2][N + 2], int c[N + 2][N + 2]);
int  Dlei(int x, int y, int a[N + 2][N + 2], int b[N + 2][N + 2], int c[N + 2][N + 2]);