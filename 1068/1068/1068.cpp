#include <stdio.h>
#include <math.h>

int main()
{
	double x0, y0, z0, x1, y1, z1;
	while (scanf("%lf %lf %lf %lf %lf %lf", &x0, &y0, &z0, &x1, &y1, &z1) != EOF) {
		double r = sqrt( (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) + (z1-z0)*(z1-z0) );
		double s = 4.0 / 3.0 * acos(-1.0) * r * r * r;
		printf("%.3f %.3f\n", r, s);
	}

	return 0;
}