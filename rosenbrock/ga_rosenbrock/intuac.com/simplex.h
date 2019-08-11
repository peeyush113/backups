// Source: "Software Design ...", John A Robinson, Newnes, 2004, page 340
// simplex class
// John Robinson
// Version 0.1
// 26 August 2003
#include <cmath>
using namespace std;
class simplex {
	double **vertices;
	double *fvals;
	double *sums;
	double *lowbounds;
	double *highbounds;
	double (*function)(const double *vals);
	int highest, secondhighest, lowest;
	int num_dims;
	int num_vertices;
	double initfrom(const double source[], double dest[], int dim, double startval);
	// Helper function for initat. Initialize vertex dest from vertex
	// source by a 1D search along dimension dim. See comments on
	// initialization functions below
	int init(const int dim);
	// Initialize dimension with random values in range previously
	// set by call to bound()
	int replace_highest(double *rep, double repval);
	// Replace highest vertex with rep. Invariant: lowest. sums, highest,
	// secondhighest all maintained here
	int findkeyvertices();
	// Finish initializing the simplex by working out the 
	// sums, highest, secondhighest, lowest vertices
	// (which are all used internally to calculate simplex moves)
public:
	simplex(const int ndims, double (*f)(const double *));
	// Instantiate the simplex with the number of dimensions
	// and the criterion function to minimize
	~simplex ();
	int bound(const int dim, const double lowval, const double highval);
	// Bound a dimension between specified low and high limits

	// Can initialize the simplex in various ways:
	// initrand() provides random initialization values.
	// initat() functions take either
	// a given start vertex or choose one randomly, then initialize
	// the others from it by 1D line searches.
	int initrand();
	// Initialize all dimensions randomly within ranges previously
	// set by calls to bound()
	int initat(const double startpoint[]);
	// Initialize first dimension, then rest using line searches
	int initat();
	// Initialize one dimension randomly, then rest using line searches
	int initequ(const double startpoint[], const double size);
	// Initialize equilateral simplex
	// based on Haftka and Guerdal's rule (1992)
	int move(double tolerance);
	// Does one simplex move: Keeps testing alternative possible steps
	// until one makes things better. I.e. one call corresponds to one
	// iteration of the simplex algorithm.
	// Returns 0 if the difference between highest and lowest function
	// values in the simplex is less than specified tolerance.
	// Otherwise returns an integer signalling what kind of move has
	// been made:
	// return value 1: simple reflection
	// return value 2: reflection followed by extension
	// return value 3: contraction (may have been preceded by a simple
	//			reflection)
	// return value 4: contract about lowest
	double *getv(const int vertex) const;
	// Get pointer to list of coords for the specified vertex.
	// Returns 0 if vertex is outside range of dimensions.
	double getfval(const int vertex) const;
	// Get function value for specified vertex
	double *getmin() const;
	// Get pointer to list of coords for current minimum vertex.
	double getminval() const;
	// Get function value for current minimum vertex
	double getmaxval() const;
	// Get function value for current maximum vertex
	void print() const;	
	// Debugging function that prints out the current coords and function
	// values. The vertices are always printed in the same order: the
	// highest and lowest are marked with 'H' and 'L' respectively.
	// Prints out whole simplex on a single line.
	};
