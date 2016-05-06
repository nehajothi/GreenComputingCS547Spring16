#include "Hush.h"

void Hush::init()
{
	int i;
	appsGlobal[0] = 'L'; //Lifestyle and productivity
	appsGlobal[1] = 'E'; //Entertainment
	appsGlobal[2] = 'T'; //Travel and transportation
	appsGlobal[3] = 'H'; //Health and medical
	appsGlobal[4] = 'S'; //Sports and news
	for (i=0 ; i< numApps ; i++)
	{
		Apps[i].name = appsGlobal[i];
		Apps[i].BFC = 0;
		Apps[i].time = rand() % 5000;
	}
	Apps[0].energy = 115.60;
	Apps[1].energy = 115.45;
	Apps[2].energy = 109.82;
	Apps[3].energy = 130.05;
	Apps[4].energy = 86.70;
	return;
}


int Hush::getScreenStatus()
{
	return rand()%2;
}

//version1 : all BFC's are generated randomly
int Hush::calculateBFC()
{
	int i,j;
	float temp[numApps];
	for (i=0 ; i< numApps ; i++)
	{
		Apps[i].BFC  = ((float) rand() / (RAND_MAX));
		temp[i] = Apps[i].BFC ;
		cout << "BFC of" << Apps[i].name << "is :" << Apps[i].BFC  <<"\n";
	}
	sort(temp, temp + numApps);
	for (i=numApps-1 ; i>=0 ; i--)
	{
		//TODO: this is just a quick fix!
		for (j=0;j<numApps;j++)
		{
			if(Apps[j].BFC == temp[i])
			{
				schedule.push (Apps[j].name);
				cout <<  Apps[j].name << "\n";
			}
		}
	}
	return 0;
}

int Hush::syncApp(double time)
{
	int i;
	while(time > 0)
	{
		cout << "Time remaining for sync" << time << "\n";
		currApp.name = schedule.front();
		//TODO: this is just a quick fix!
		for (i=0;i<numApps;i++)
		{
			if(Apps[i].name == currApp.name)
			{
				currApp.BFC = Apps[i].BFC;
				currApp.time = Apps[i].time;
				currApp.energy = Apps[i].energy;
				break;
			}
		}
		cout << "Current app being being synched" << currApp.name << "\n";
		cout << "Current app time" << currApp.time << "\n";
		if(currApp.time > time)
		{
			//pause(time);
			cout << "Energy consumed by App:" << currApp.name << " is :"<< currApp.energy * currApp.time << "\n:";
			currApp.time -= time;
			Apps[i].time = currApp.time;
			time =0;
		}
		else
		{
			//pause(currApp.time);
			if (!schedule.empty())
			{
				schedule.pop();
				//Apps[i].time = 0;
				cout << "Energy consumed by App:" << currApp.name << " is :"<< currApp.energy * currApp.time << "\n:";
				time -= Apps[i].time;
			}
			else
			{
				cout << "Done syncing all apps!\n";
				break;
			}
		}
	}
	return 0;
}

void Hush::pause(double time)
{
	//Time in ms
	sleep(time);
	return;
}
