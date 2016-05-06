//============================================================================
// Name        : Hush.cpp
// Author      : Neha Jothi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

#define numApps 5

struct app
{
	char name;
	float energy;
	float BFC;
	//All times are in ms
	double time;
};

class Hush
{
	friend class Bartendr;
public:
	queue<char> schedule;
	char appsGlobal[numApps];
	app Apps[5];
	app currApp;
	//TODO : Not sure if we need this!
	int syncStatus;

	// 0 if screen is OFF , 1 if screen is ON.
	void init();
	int getScreenStatus();
	int calculateBFC();

	int syncApp(double time);
	void pause(double time);
};
