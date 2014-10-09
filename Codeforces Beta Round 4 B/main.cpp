#include <cstdio>
#include <vector>
#include <iostream>
#include <stdio.h>
using std::vector;

int main() {

	int d,totalHours,min,max;

	scanf("%d %d", &d, &totalHours);

	// declare 2D vector
	vector< vector<int> > dailyStudy;
	vector<int> bookend{ -999 };
	dailyStudy.push_back(bookend);
	for (int i = 1; i <= d; i++){
		scanf("%d %d", &min, &max);
		// make new entry for current day
		vector<int> day{ min, max, max };
		dailyStudy.push_back(day);
	}

	for (int i = 0; i < dailyStudy.size(); i++)
	{
		for (int q = 0; q < dailyStudy[i].size(); q++)
		std::cout << dailyStudy[i][q] << "\n";
	}
	return 0;
}