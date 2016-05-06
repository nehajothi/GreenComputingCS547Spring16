//============================================================================
// Name        : Green.cpp
// Author      : Neha Jothi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Hush.h"
#include "Bartendr.h"
using namespace std;



int main() {
	double syncTime;
	Bartendr bartendr;
	int count = 1;
	Hush hush;
	bartendr.init();
	hush.init();

	//Bartendr + Hush

	while (count <= 10)
	{
		cout << "********************* Run : " << count << " **********************\n";
		if (!bartendr.getScreenStatus())
		{
			cout << "\n\n########## Beginning of only HUSH simulation ##########\n\n";
			syncTime = 200;
			hush.calculateBFC();
			hush.syncApp(syncTime);
			syncTime = bartendr.checkSignal();
			cout << "\n\n########## End of only HUSH simulation ##########\n\n";

			cout << "\n\n########## Beginning of only BARTENDR simulation ##########\n\n";
			bartendr.getCurrentSignal();
			bartendr.getTableData();

			cout << "SyncTime that was selected by Bartendr is " << syncTime << "\n";
			bartendr.sync(syncTime);
			cout << "\n\n########## End of only BARTENDR simulation ##########\n\n";

			//bartendr.getCurrentSignal();
			//bartendr.getTableData();
			//syncTime = bartendr.checkSignal();
			//cout << "SyncTime that was selected by Bartendr is " << syncTime << "\n";
			//if (!hush.getScreenStatus())
			 cout << "\n\n########## Beginning of HUSH + BARTENDR simulation ##########\n\n";
			//hush.calculateBFC();
			//	cout << "After we calculate BFC" << "\n";
			hush.syncApp(syncTime);
			 cout << "\n\n########## End of HUSH + BARTENDR simulation ##########\n\n";
			//	cout << "After sync" << "\n";
			//bartendr.pause();
		}
		count++;
	}

//	//Hush alone
//	syncTime = 200;
//	cout << "\n\n########## Beginning of only HUSH simulation ##########\n\n";
//	while (count <= 10)
//	{
//		cout << "********************* Run : " << count << " **********************\n";
//		if (!hush.getScreenStatus())
//		{
//				hush.calculateBFC();
//			//	cout << "After we calculate BFC" << "\n";
//				bartendr.getCurrentSignal();
//				hush.syncApp(syncTime);
//			//	cout << "After sync" << "\n";
//
//		}
//		count++;
//	}

	//Bartendr alone
//    cout << "\n\n########## Beginning of only BARTENDR simulation ##########\n\n";
//	while (count <= 10)
//	{
//		cout << "********************* Run : " << count << " **********************\n";
//		if (!bartendr.getScreenStatus())
//		{
//			bartendr.getCurrentSignal();
//			bartendr.getTableData();
//			syncTime = bartendr.checkSignal();
//			cout << "SyncTime that was selected by Bartendr is " << syncTime << "\n";
//			bartendr.sync(syncTime);
//		}
//		count++;
//	}

	return 0;
}
