#include <cstdio>
#include <vector>
#include <iostream>
#include <stdio.h>
using std::vector;

int main() {

	int numDays,totalHours,min,max;

	scanf("%d %d", &numDays, &totalHours);

	// declare 2D vector
	vector< vector<int> > dailyStudy;
	vector<int> bookend{ -999 };
	dailyStudy.push_back(bookend);
	for (int i = 1; i <= numDays; i++){
		scanf("%d %d", &min, &max);
		// make new entry for current day
		vector<int> day{ min, max, max };
		dailyStudy.push_back(day);
	}

	int currentTotal = 0, tempTotal, d = 1;
	bool solnFound = false;
	while (d != 0) {
		//select path greedily
		tempTotal = currentTotal + dailyStudy[d][1];

		if (tempTotal > totalHours || tempTotal < totalHours && d == numDays){
			if (dailyStudy[d][1] != dailyStudy[d][0]){
				dailyStudy[d][1]--;
			}
			else if (dailyStudy[d][1] == dailyStudy[d][0]){
				//reset
				do{
					dailyStudy[d][1] = dailyStudy[d][2];
					d--;
					if (d != 0 ) currentTotal -= dailyStudy[d][1];
					else break;
				} while (dailyStudy[d][1] == dailyStudy[d][0]);
				if (d != 0) dailyStudy[d][1]--;
			}
		}
		else if (tempTotal == totalHours){
			solnFound = true;
			break;
		}
		else {
			d++;
			currentTotal = tempTotal;
		}
	}

	if (solnFound){
		std::cout << "YES\n";
		for (int i = 1; i < dailyStudy.size(); i++)
		{
			std::cout << dailyStudy[i][1] << " ";
		}
	} else std::cout << "NO";

	return 0;
}