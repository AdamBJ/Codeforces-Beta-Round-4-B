#include <cstdio>
#include <vector>
#include <iostream>
#include <stdio.h>
using std::vector;

int main() {

	int numDays,totalHours,min,max;

	scanf("%d %d", &numDays, &totalHours);

	// declare 2D vector to store information on each of the days available to study in
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

		if (tempTotal > totalHours || tempTotal < totalHours && d == numDays){ //if we're over or under total hours we need to make a change
			if (dailyStudy[d][1] != dailyStudy[d][0]){ //if there are still untried hour quantities for the current day, try another one
				dailyStudy[d][1]--;
			}
			else if (dailyStudy[d][1] == dailyStudy[d][0]){//if we don't have any hour quantities left we can try for this day, go up a level and try there
				do{
					dailyStudy[d][1] = dailyStudy[d][2];//reset the current day before going up a level
					d--;
					if (d != 0 ) currentTotal -= dailyStudy[d][1];//if d == 0 at this point we've determined that no solutions are possible.
					else break;
				} while (dailyStudy[d][1] == dailyStudy[d][0]);
				if (d != 0) dailyStudy[d][1]--;//we've found a level with untried hour quantities. try a new one
			}
		}
		else if (tempTotal == totalHours){
			solnFound = true;
			break;
		}
		else {//if we're here we've found a quantity that works for the current day. move to the next day
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