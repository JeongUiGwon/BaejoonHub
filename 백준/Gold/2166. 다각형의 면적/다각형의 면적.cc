#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<double, double>> polygon_coord;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		double x, y;
		cin >> x >> y;

		polygon_coord.push_back({ x, y });
	}

	double res = 0;

	for (int i = 1; i < N - 1; i++)
	{
		double x1 = polygon_coord[0].first;
		double x2 = polygon_coord[i].first;
		double x3 = polygon_coord[i + 1].first;
		double y1 = polygon_coord[0].second;
		double y2 = polygon_coord[i].second;
		double y3 = polygon_coord[i + 1].second;

		double tmp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
		tmp /= 2;

		res += tmp;
	}

	printf("%.1lf", abs(res));

	return 0;
}