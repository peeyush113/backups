// Source: "Software Design ...", John A Robinson, Newnes, 2004, page 350
// Test of simplex on 2D Rosenbrock banana function
#include "simplex.h"
#include <iostream>
double valueat(const double *dims) {
	double x1 = dims[0];
	double x2 = dims[1];
	double f = 100*(x2-x1*x1)*(x2-x1*x1) + (1-x1)*(1-x1);
	return f;
	}
	
int main(int argc, char *argv[]) {
	simplex s(2, valueat);
	for (int i = 0; i < 2; i++)
		s.bound(i,-3,3);
	if (argc == 4) {
		double startcoords[2];
		startcoords[0] = atof(argv[1]);
		startcoords[1] = atof(argv[2]);
		double size = atof(argv[3]);
		s.initequ(startcoords,size);
		}
	else {
		cerr << "Usage: rosenbrock x1start x2start initsize\n";
		return -1;
		}
	cout << "Start simplex:\n";
	s.print();
	int movetype;
	int cnt = 0;
	while(movetype = s.move(0.0001)) {
		// cout << "After move type " << movetype << endl;
		// s.print();
		cnt++;
		}
	cout << "End simplex:\n";
	s.print();
	cout << "Found minimum at\n";
	double *verts = s.getmin();
	cout << "f(" << verts[0] << "," ;
	cout << verts[1];
	cout << ") = " << s.getminval();
	cout << " in " << cnt << " iterations\n";
	}
