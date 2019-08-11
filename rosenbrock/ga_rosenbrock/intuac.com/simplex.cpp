// Source: "Software Design ...", John A Robinson, Newnes, 2004, page 342.
//
// Implementation of simplex class
// John Robinson
// Version 0.1
// 26 August 2003
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "simplex.h"
using namespace std;
simplex::simplex(const int ndims, double (*f)(const double *)) {
	num_dims = ndims;
	num_vertices = ndims+1;
	vertices = new double *[num_vertices];
	for (int i = 0; i < num_vertices; i++)
		vertices[i] = new double[num_dims];
	fvals = new double[num_vertices];
	sums = new double[num_dims]; // Stores sums of all vertices
	lowbounds = new double[num_dims];
	highbounds = new double[num_dims];
	for (int i = 0; i < num_dims; i++)
		lowbounds[i] = highbounds[i] = 0;
	function = f;
	srand((int) time(NULL));
	}
simplex::~simplex () {
	for (int i = 0; i < num_vertices; i++)
		delete [] vertices[i];
	delete [] fvals;
	delete [] sums;
	delete [] vertices;
	delete [] lowbounds;
	delete [] highbounds;
	}
int simplex::findkeyvertices() {
// Finish initializing the simplex by working out the 
// sums, highest, secondhighest, lowest
	for (int j = 0; j < num_dims; j++)
		sums[j] = 0;
	for (int i = 0; i < num_vertices; i++) {
		// fvals[i] = (function)(vertices[i]);
		for (int j = 0; j < num_dims; j++)
			sums[j] += vertices[i][j];
		}
	if (fvals[1] > fvals[0]){
		highest = 1;
		secondhighest = lowest = 0;
		}
	else {
		highest = 0;
		secondhighest = lowest = 1;
		}
	for (int i = 2; i < num_vertices; i++) {
		if (fvals[i] > fvals[highest]){
			secondhighest = highest;
			highest = i;
			}
		else if (fvals[i] > fvals[secondhighest])
			secondhighest = i;
		else if (fvals[i] < fvals[lowest])
			lowest = i;
		}
	return 0;
	}
int simplex::bound(const int dim, const double lowval, const double highval) {
// Bound dimension
	if ((dim < 0) || (dim >= num_dims))
		return -1;
	if (lowval >= highval) {
		cout << "bound(" << dim << "," << lowval << "," << highval << ")";
		cout << " is not allowed: Have to have positive range\n";
		return -1;
		}
	lowbounds[dim] = lowval;
	highbounds[dim] = highval;
	return 0;
	}
int simplex::init(const int dim) {
// Helper function to initialize one dimension
// with random values between bounds
	if ((dim < 0) || (dim >= num_dims))
		return -1;
	double min = lowbounds[dim];
	double range = highbounds[dim] - min;
	if (range <= 0.0) {
		cout << "init(" << dim << "): ";
		cout << "range = " << range << ". Can't initialize ";
		cout << "without a positive range.\n";
		cout << "Did you remember to call bound() ";
		cout << "for all dimensions before initat() ";
		cout << "or initrand()?\n";
		return -1;
		}
	for (int i = 0; i < num_vertices; i++) 
		vertices[i][dim] = (double)rand()/(RAND_MAX/range)+min;
	return 0;
	}
int simplex::initrand() {
// Initialize all dimensions randomly
	for (int i = 0; i < num_dims; i++)
		if (init(i) < 0)
			return -1;
	for (int i = 0; i < num_vertices; i++) 
		fvals[i] = (function)(vertices[i]);
	findkeyvertices();
	return 0;
	}
double simplex::initfrom(const double source[], double dest[], int dim, const double startfval) {
// Helper function for initat. Initialize vertex dest from vertex
// source by a 1D search along dimension dim
// Returns function value for vertex
	double stepsize;
	double range = highbounds[dim] - lowbounds[dim];
	if (range == 0.0)
		// Bounds/ranges not set. Arbitrary choice for step
		stepsize = 0.1;
	else
		// May need to be able to set granularity
		stepsize = (range/32);
	// First copy vertex
	for (int j = 0; j < num_dims; j++)
		dest[j] = source[j];
	// Try to move in positive direction along dimension
	dest[dim] += stepsize;
	double fval1, fval2;
	// Got do deal with exceptional cases of start point being
	// near the dimensional limits
	if (dest[dim] > highbounds[dim]) {
		// Try going other way
		stepsize = -stepsize;
		dest[dim] += 2*stepsize;
		fval1 = (function)(dest);
		if (fval1 > startfval) 
			// We have to accept this one anyway because
			// the other way is out of bounds
			return fval1;
		// else we can carry on looking in the same direction
		}
	else {
		fval1 = (function)(dest);
		if (fval1 > startfval) {
			// Try going other way
			stepsize = -stepsize;
			dest[dim] += 2*stepsize;
			if (dest[dim] < lowbounds[dim]) {
				// Go back to first choice: Even
				// though it wasn't as good as
				// startpoint, this direction is
				// out of bounds.
				dest[dim] -= 2*stepsize;
				return fval1;
				}
			// else
			fval2 = (function)(dest);
			if (fval2 > startfval) {
				if (fval2 > fval1) {
					// Go back to first choice: Even
					// though it wasn't as good as
					// startpoint, it was better
					// than this one.
					dest[dim] -= 2*stepsize;
					return fval1;
					}
				return fval2;
				}
			// If got to here fval1 was worse than startfval
			// but fval2 was better, so...
			fval1 = fval2;
			}
		// else fval1 was better than startfval.
		}
	// However we've got to here dest[] is better than
	// source, so we'll keep moving in the same direction
	// so long as there is improvement
	fval2 = fval1;
	while (fval2 <= fval1) {
		fval1 = fval2;
		dest[dim] += stepsize;
		if ((dest[dim] > highbounds[dim])||
				(dest[dim] < lowbounds[dim]))
			fval2 = fval1 + 1.0;  // To end loop
		else
			fval2 = (function)(dest);
		}
	// Have now gone one step too far, so...
	dest[dim] -= stepsize;
	return fval1;
	}
		
		
int simplex::initat(const double startpoint[]) {
// Initialize simplex using simple 1D line searches about startpoint.
	for (int j = 0; j < num_dims; j++) {
		if ((startpoint[j] < lowbounds[j])||
				(startpoint[j] > highbounds[j])) {
			cout << "initat:startpoint[" << j;
			cout << "] = " << startpoint[j];
			cout << " is out of bounds for that dimension.\n";
			cout << "Did you remember to call bound() ";
			cout << "for all dimensions before initat()?\n";
			return -1;
			}
		vertices[0][j] = startpoint[j];
		}
	fvals[0] = (function)(vertices[0]);
	for (int i = 1; i < num_vertices; i++)
		fvals[i] = initfrom(vertices[i-1],vertices[i],i-1,fvals[i-1]);
	findkeyvertices();
	return 0;
	}
int simplex::initat() {
// Initialize one dimension randomly, then rest using line searches.
	// First use init() to initial all dims, all vertices randomly
	for (int i = 0; i < num_dims; i++)
		if (init(i) < 0)
			return -1;
	// But now we only use first one
	fvals[0] = (function)(vertices[0]);
	for (int i = 1; i < num_vertices; i++)
		fvals[i] = initfrom(vertices[i-1],vertices[i],i-1,fvals[i-1]);
	findkeyvertices();
	return 0;
	}
int simplex::initequ(const double startpoint[], const double size) {
// Equilateral simplex
// Initialize based on Haftka and Guerdal's rule (1992)
	// First step as initat
	for (int j = 0; j < num_dims; j++) {
		if ((startpoint[j] < lowbounds[j])||
				(startpoint[j] > highbounds[j])) {
			cout << "initHG:startpoint[" << j;
			cout << "] = " << startpoint[j];
			cout << " is out of bounds for that dimension.\n";
			cout << "Did you remember to call bound() ";
			cout << "for all dimensions before initHG()?\n";
			return -1;
			}
		vertices[0][j] = startpoint[j];
		}
	fvals[0] = (function)(vertices[0]);
	double sqrt2 = sqrt(2.0);
	double sqrtnplus1 = sqrt((double)num_dims+1.0);
	double p = (size/(num_dims*sqrt2))*(sqrtnplus1+num_dims-1);
	double q = (size/(num_dims*sqrt2))*(sqrtnplus1-1);
	// cout << "p = " << p << endl;
	// cout << "q = " << q << endl;
	for (int i = 1; i < num_vertices; i++) {
		// cout << "vertex " << i << endl;
		for (int j = 0; j < num_dims; j++) {
			vertices[i][j] = vertices[0][j];
			if (j == i-1)
				vertices[i][j] += p;
			else
				vertices[i][j] += q;
			}
		fvals[i] = (function)(vertices[i]);
		}
	findkeyvertices();
	// cout << "out" << endl;
	}
int simplex::replace_highest(double *rep, double repval) {
// Replace highest vertex with rep. Invariant: lowest. sums, highest,
// secondhighest all maintained here
	for (int i = 0; i < num_dims; i++) {
		sums[i] -= vertices[highest][i];
		vertices[highest][i] = rep[i];
		sums[i] += vertices[highest][i];
		}
	// cout << "Replacing " << fvals[highest] << " with " << repval << endl;
	fvals[highest] = repval;
	if (fvals[highest] >= fvals[secondhighest]) {
		// cout << "Replaced highest still worst than second highest\n";
		return 0;
		}
	int temp = highest;
	highest = secondhighest;
	if (fvals[temp] < fvals[lowest])
		lowest = temp;
	secondhighest = temp;
	for (int i = 0; i < num_vertices; i++) {
		if (i == highest)
			continue;
		if (fvals[i] > fvals[secondhighest])
			secondhighest = i;
		}
	return 1;
	}
int simplex::move(double tolerance) {
// Invariant: highest, secondhighest, lowest and sums, all maintained
// by replace_highest
	// cout << "move" << endl;
	int i;
	if (fvals[highest] - fvals[lowest] < tolerance)
		return 0;
	double highval = fvals[highest];
	double tryextendval, tryreflectval, trycontractval;
	// Try reflection
	double average[num_dims];
	double tryreflect[num_dims];
	int outofbounds = 0;
	for (i = 0; i < num_dims; i++) {
		average[i] = (sums[i]-vertices[highest][i])/num_dims;
		tryreflect[i] = 2*average[i]-vertices[highest][i];
		if (tryreflect[i] < lowbounds[i])
			outofbounds = 1;
		else if (tryreflect[i] > highbounds[i])
			outofbounds = 1;
		}
	if (outofbounds) // Reject this point
		tryreflectval = highval;
	else	// in bounds, so calculate its value
		tryreflectval = (function)(tryreflect);
	// cout << "sums(" << sums[0] << "," << sums[1] << ")\n";
	// cout << "avg(" << average[0] << "," << average[1] << ")\n";
	// cout << "ref(" << tryreflect[0] << "," << tryreflect[1];
	// cout << ") = " << tryreflectval << endl;
	if (tryreflectval < fvals[lowest]) {
		// Try to go further
		double tryextend[num_dims];
		for (i = 0; i < num_dims; i++) {
			tryextend[i] = 3*average[i]-2*vertices[highest][i];
			if (tryextend[i] < lowbounds[i])
				break;
			else if	(tryextend[i] > highbounds[i])
				break;
			}
		if (i == num_dims)
			tryextendval = (function)(tryextend);
		else	// Premature break: Reject this point
			tryextendval = highval;
		// cout << "ext(" << tryextend[0] << "," << tryextend[1];
		// cout << ") = " << tryextendval << endl;
		if (tryextendval < tryreflectval) {
			replace_highest(tryextend,tryextendval);
			return 2;	// Extended
			}
		replace_highest(tryreflect,tryreflectval);
		return 1;	// Reflected
		}
	// When compiled with g++ -O2, would sometimes pass next test,
	// fail replace_highest test, then drop though to the
	// following replace_highest. I don't understand it, but I
	// do know that when I inserted:
	// cout << "try ";
	// here, it stopped it. Also, using g++ -O stopped it.

	if (tryreflectval < fvals[highest]) {
		if(replace_highest(tryreflect,tryreflectval))
			// Replacement better than secondhighest too
			return 1;
		// cout << "Taken ref, but also got to contract\n";
		}
	// If got to here we've got to try a contraction
	double trycontract[num_dims];
	for (i = 0; i < num_dims; i++) 
		trycontract[i] = (average[i]+vertices[highest][i])/2;
	trycontractval = (function)(trycontract);
	// cout << "con(" << trycontract[0] << "," << trycontract[1];
	// cout << ") = " << trycontractval << endl;
	if (trycontractval < fvals[highest]) {
	// Accept any improvement over highest
		replace_highest(trycontract, trycontractval);
		return 3;
		}
	// Got to contract the whole thing
	for (i = 0; i < num_vertices; i++) {
		if (i == lowest)
			continue;
		for (int j = 0; j < num_dims; j++) {
			vertices[i][j] = (vertices[i][j] +
				vertices[lowest][j])/2;
			}
		fvals[i] = (function)(vertices[i]);
		}
	findkeyvertices();
	return 4;
	}
	
double *simplex::getv(const int vertex) const {
	if ((vertex < 0) || (vertex > num_dims))
		return 0;
	return vertices[vertex];
	}
double simplex::getfval(const int vertex) const {
	if ((vertex < 0) || (vertex > num_dims))
		return 0;
	return fvals[vertex];
	}
double *simplex::getmin() const {
	return vertices[lowest];
	}
double simplex::getminval() const {
	return fvals[lowest];
	}
double simplex::getmaxval() const { // Provided for debugging purposes
	return fvals[highest];
	}
void simplex::print() const {
	double *verts;
	double currval;
	double highval = getmaxval();
	double lowval = getminval();
	for (int i = 0; i < num_vertices; i++) {
		verts = getv(i);
		currval = getfval(i);
		if (currval == lowval)
			cout << 'L';
		else if (currval == highval)
			cout << 'H';
		else
			cout << ' ';
		cout << "f(";
		for (int j = 0; j < num_dims-1; j++) 
			cout << setw(6) << setprecision(5) << verts[j] << ", "; 
		cout << setw(6) << setprecision(5) << verts[num_dims-1] << ") = "; 
		cout << setw(8) << setprecision(7) << currval << "    ";
		}
	cout << endl;
	}
