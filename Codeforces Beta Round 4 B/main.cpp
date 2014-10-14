#include <cstdio>
#include <vector>
#include <iostream>
#include <stdio.h>

using std::vector;

int main() {

	int numDays,totalHours,min,max;

	scanf_s("%d %d", &numDays, &totalHours);

	// declare 2D vector to store information on each of the days available to study in
	vector< vector<int> > dailyStudy;
	vector<int> bookend;//so we can start a 1 instead of 0, that way dailyStudy[1] contains info for the first day.
	dailyStudy.push_back(bookend);

	for (int i = 1; i <= numDays; i++){
		scanf_s("%d %d", &min, &max);
		// make new entry for current day
		vector<int> day;
		//forced to use old style initialization because codeforces compiler is c10. c11 allows list initialization for vectors
		//so vector<int> day {min,max,max} should be used normally (ie with more recent compilers).
		day.push_back(min);
		day.push_back(min);
		day.push_back(max);
		dailyStudy.push_back(day);
	}

	int d = 1, minTotal = 0, maxTotal = 0;

	for (int i = 1; i <= numDays; i++){
		minTotal += dailyStudy[i][0];
		maxTotal += dailyStudy[i][2];
	}

	bool solnFound;
	
	if (minTotal < totalHours) {
		while (1) {
			while (dailyStudy[d][1] != dailyStudy[d][2]){
				dailyStudy[d][1]++;
				minTotal++;
				if (minTotal == totalHours) {
					solnFound = true;
					goto end;
				}
			}
			d++;
			if (d > numDays) {
				solnFound = false;
				break;
			}
		}
	}
	else if (minTotal == totalHours) solnFound = true;
	else solnFound = false;

	end:
	if (solnFound){
		std::cout << "YES\n";
		for (int i = 1; i <= numDays; i++)
		{
			std::cout << dailyStudy[i][1] << " ";
		}
	} else std::cout << "NO";

	return 0;
}