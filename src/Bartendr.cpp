#include "Bartendr.h"


void Bartendr::init()
{
	//TODO: read from file or static??
	//FILE *fp;
	ifstream in("iPhone Signal.txt");

	int s;
	for( s = 0 ; (in>>signalTable[s].cellID) ; s++)
	{
		in>>signalTable[s].signalStrength>>signalTable[s].neighbor1
		  >>signalTable[s].neighbor2>>signalTable[s].neighbor3>>signalTable[s].time;


		cout<< "cellID: "<<signalTable[s].cellID << " Signal strength : " <<signalTable[s].signalStrength << " Neighbor 1: " <<signalTable[s].neighbor1
				<< " Neighbor 2: " <<signalTable[s].neighbor2<< " Neighbor 3: "<<signalTable[s].neighbor3<< " Time: "<<signalTable[s].time<<"\n";
	}

	int i;
	appsBartendr[0] = 'L'; //Lifestyle and productivity
	appsBartendr[1] = 'E'; //Entertainment
	appsBartendr[2] = 'T'; //Travel and transportation
	appsBartendr[3] = 'H'; //Health and medical
	appsBartendr[4] = 'S'; //Sports and news
	for (i=0 ; i< numApps ; i++)
	{
		appBar[i].name = appsBartendr[i];
		appBar[i].time = rand() % 5;
	}
	appBar[0].energy = 115.60;
	appBar[1].energy = 115.45;
	appBar[2].energy = 109.82;
	appBar[3].energy = 130.05;
	appBar[4].energy = 86.70;
	//initialize cellID
}

int Bartendr::getScreenStatus()
{
	int screen = rand()%2;
	if(screen)
		cout<<"Screen is ON!!!!\n\n";
	else
		cout<<"Screen is OFF!!!!\n\n";
	return screen;
}


int Bartendr::getCurrentSignal()
{
	ifstream in("cellArray");

		    int s,data;
		    for( s = 0 ; (in>>cellData[s].currCellID) ; s++) //9629
		    {
		        in>>cellData[s].currSignal>>cellData[s].currNeighbor1
		          >>cellData[s].currNeighbor2>>cellData[s].currNeighbor3;

//		        cout<< "cellID: "<<cellData[s].currCellID << " Signal strength : " <<cellData[s].currSignal << " Neighbor 1: " <<cellData[s].currNeighbor1
//		        		<< " Neighbor 2: " <<cellData[s].currNeighbor2<< " Neighbor 3: "<<cellData[s].currNeighbor3<<"\n";
		    }
	int i = rand()%size_of_cellID_array;
//	cout << "i:" <<i << "\n";
	currSignalStrength.currCellID = cellData[i].currCellID;
	currSignalStrength.currNeighbor1 = cellData[i].currNeighbor1;
	currSignalStrength.currNeighbor2 = cellData[i].currNeighbor2;
	currSignalStrength.currNeighbor3 = cellData[i].currNeighbor3;
	currSignalStrength.currSignal = cellData[i].currSignal;
	//cout << "cellid:" << cellData[i].currCellID<<"\n";
	cout << "cellID picked : " << currSignalStrength.currCellID << "\n";
	cout << "cellID Signal Strength : " << currSignalStrength.currSignal << "\n";
	return 0;
}

int Bartendr::getTableData()
{
	//loop through table to find matching cellID
	for (int t =0; t < numPoints; t++)
	{
		if (currSignalStrength.currCellID == signalTable[t].cellID)
		{
			currTime = signalTable[t].time;
			cout << "CurrTime selected " << currTime << "\n";
			break;
		}
		if ( signalTable[t+1].signalStrength >= goodSignal )
		{
			futureSignalStrenth.cellID = signalTable[t+1].cellID;
			futureSignalStrenth.neighbor1 = signalTable[t+1].neighbor1;
			futureSignalStrenth.neighbor2 = signalTable[t+1].neighbor2;
			futureSignalStrenth.neighbor3 = signalTable[t+1].neighbor3;
			futureSignalStrenth.time = signalTable[t+1].time;
			futureSignalStrenth.signalStrength = signalTable[t+1].signalStrength;

		}
		else
		{
			futureSignalStrenth.cellID = -1;
		}
		cout << "Future signal cell ID " << futureSignalStrenth.cellID << "\n";
	}
	//populate signal strength and neighbors for comparison
	//update currTime
	//check if current neighbors match with the table data
	//check future signal [i+1] and populate cellID if good else -1
	return 0;
}

double Bartendr::checkSignal()
{
	if(currSignalStrength.currSignal >= goodSignal)
	{
		cout<<"Signal strength is GOOD =" <<currSignalStrength.currSignal<<"\n";
		if(futureSignalStrenth.cellID > 0)
		{
			return currTime + futureSignalStrenth.time;
		}
		else
		{
			return currTime;
		}
	}
	//TODO: does the main call sleep() or is it to be done in Bartendr??
	return 0;
}

void Bartendr::sync(double time)
{

	for (int i = 0; i< numApps; i++)
	{
		while(time>0)
		{
			cout << "Time remaining to sync : " << time << "\n";
			cout << "Current app being being synced : " << appBar[i].name << "\n";
			cout << "Current app time = " << appBar[i].time << "\n";
			cout << "Energy consumed by App " << appBar[i].name << " is : "<< appBar[i].energy * appBar[i].time  << "\n\n";
			time -= appBar[i].time;
			break;
		}

	}
}

void Bartendr::pause()
{
	//Time in ms
	sleep(sleepTime);
	return;
}

