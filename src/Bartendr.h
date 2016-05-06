//============================================================================
// Name        : Bartendr.cpp
// Author      : Neha Jothi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

#define numPoints 13
#define size_of_cellID_array 17
#define goodSignal 3
#define numApps 5
//Time in ms
#define sleepTime 5000

struct Signal
{
	int cellID;
	float signalStrength;
	int neighbor1;
	int neighbor2;
	int neighbor3;
	double time;
};

//To hold the data from the field test
struct currCellID
{
	int currCellID;
	int currNeighbor1;
	int currNeighbor2;
	int currNeighbor3;
	int currSignal;
};

struct appBartendr
{
	char name;
	float energy;
	//All times are in ms
	double time;
};


class Bartendr
{
public:
	int prevCell;
	currCellID cellData[size_of_cellID_array];
	currCellID currSignalStrength;
	//TODO: next versions can have >1 future points
	Signal futureSignalStrenth;
	Signal signalTable[numPoints];
	double currTime;
	appBartendr appBar[numApps];
	char appsBartendr[numApps];
	void init();
	int getScreenStatus();
	int getCurrentSignal();
	int getTableData();
	double checkSignal();
	void sync(double time);
	void pause();
};
