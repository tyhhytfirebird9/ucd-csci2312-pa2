//  FILE: Point.h
//  CLASS PROVIDED: Point (a class for a point on a variable-dimension plane)

#ifndef CLUSTERING_POINT_H
#define CLUSTERING_POINT_H

#include <iostream>

namespace Clustering {

    class Point {
        int dim; // Number of dim
        double *values; // Values

    public:
        // Constructors
        //Point();                // default constructor
        Point(int);             // constructor for just dimension
        Point(int, double*);    // constructor for dimension and values


        // BIG THREE: copy constructor, overloaded assignment operator=, destructor
        // Copy constructor
        Point(const Point&);
        // Overloaded assignment operator=
        Point &operator=(const Point&);
        // Destructor
        ~Point();


        // Mutator and Accessor methods
        int getDims() const { return dim; }
        void setValue(int, double);
        double getValue(int) const;


        // Functions
        double distanceTo(const Point &) const; // Calculates the distance between two points


        // Overloaded operators
        // Members
        Point &operator*=(double);
        Point &operator/=(double);
        const Point operator*(double) const; // prevents (p1*2) = p2
        const Point operator/(double) const;


        double &operator[](int index) { return values[index - 1]; }

        // Friends
        friend Point &operator+=(Point&, const Point&);     // Must have both arguments because it is a friend
        friend Point &operator-=(Point&, const Point&);     // Must have both arguments because it is a friend
        friend const Point operator+(const Point&, const Point&);
        friend const Point operator-(const Point&, const Point&);

        friend bool operator==(const Point&, const Point&);
        friend bool operator!=(const Point&, const Point&);

        friend bool operator<(const Point&, const Point&);
        friend bool operator>(const Point&, const Point&);
        friend bool operator<=(const Point&, const Point&);
        friend bool operator>=(const Point&, const Point&);

        friend std::ostream &operator<<(std::ostream&, const Point&);
        friend std::istream &operator>>(std::istream&, Point&);

        friend void dimEquivTest(const Point&, const Point&);
    };
}
#endif // CLUSTERING_POINT_H