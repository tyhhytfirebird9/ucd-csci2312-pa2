// FILE: Point.cpp
// CLASS IMPLEMENTED: Point

#include "Point.h"
#include <cmath>
#include <cassert>


// Default constructor
namespace Clustering {
    Point::Point() : Point(2) { }

    Point::Point(int dimensions) {
        dim = dimensions;
        values = new double[dimensions];
        for (int i = 0; i < dimensions; i++)
            values[i] = 0;
    }

    Point::Point(int dimensions, double *coordinates) {
        dim = dimensions;
        values = new double[dimensions];
        for (int i = 0; i < dim; i++)
            values[i] = coordinates[i];
    }

    Point::Point(const Point &pointToCopy) {
        dim = pointToCopy.dim;
        values = new double[dim];
        for (int i = 0; i < dim; i++)
            values[i] = pointToCopy.values[i];
    }

    Point &Point::operator=(const Point &assigningPoint) {
        if (this == &assigningPoint) {
            std::cout << "these are the same points!" << std::endl;
            return *this;
        } else {
            delete[] values;
            values = nullptr;

            dim = assigningPoint.dim;
            values = new double[dim];
            for (int i = 0; i < dim; i++)
                values[i] = assigningPoint.values[i];
        }
        return *this;
    }

    Point::~Point() {
        dim = 0;
        delete [] values;
        values = nullptr;
    }

    void Point::setValue(int dimension, double coordinate) {
        assert(dimension > 0 && dimension - 1 < dim);
        values[dimension - 1] = coordinate;
    }

    double Point::getValue(int dimension) const {
        assert(dimension > 0 && dimension - 1 < dim);
        return values[dimension - 1];
    }

    double Point::distanceTo(const Point &toPoint) const {
        assert(dim == toPoint.dim);
        double sum = 0;
        for (int i = 0; i < dim; i++)
            sum += pow((values[i] - toPoint.values[i]), 2);
        return sqrt(sum);
    }

    Point &Point::operator*=(double factor) {
        for (int i = 0; i < dim; i++)
            values[i] *= factor;
        return *this;
    }

    Point &Point::operator/=(double factor) {
        //assert(factor != 0);
        if (factor == 0) {
            std::cout << "Cannot divide by zero!!" << std::endl;
            return *this;
        }
        for (int i = 0; i < dim; i++)
            values[i] /= factor;
        return *this;
    }

    const Point Point::operator*(double factor) const {
        Point returnPoint(*this);
        returnPoint *= factor;
        return returnPoint;
        // IS RETURN POINT GETTING DESTRUCTED?
    }

    const Point Point::operator/(double factor) const {
        assert(factor != 0);
        Point returnPoint(*this);
        returnPoint /= factor;
        return returnPoint;
    }

    Point &operator+=(Point &leftSide, const Point &rightSide) {
        dimEquivTest(leftSide, rightSide);
        for (int i = 0; i < rightSide.dim; i++)
            leftSide.values[i] += rightSide.values[i];
        return leftSide;
    }

    Point &operator-=(Point &leftSide, const Point &rightSide) {
        dimEquivTest(leftSide, rightSide);
        for (int i = 0; i < leftSide.dim; i++)
            leftSide.values[i] -= rightSide.values[i];
        return leftSide;
    }

    const Point operator+(const Point &leftSide, const Point &rightSide) {
        dimEquivTest(leftSide, rightSide);
        Point returnPoint(leftSide);
        returnPoint += rightSide;
        return returnPoint;
    }

    const Point operator-(const Point &leftSide, const Point &rightSide) {
        dimEquivTest(leftSide, rightSide);
        Point returnPoint(leftSide);
        returnPoint -= rightSide;
        return returnPoint;
    }

    bool operator==(const Point &leftSide, const Point &rightSide) {
        dimEquivTest(leftSide, rightSide);
        for (int i = 0; i < leftSide.dim; i++)
            if (leftSide.values[i] != rightSide.values[i])
                return false;
        return true;
    }

    bool operator!=(const Point &leftSide, const Point &rightSide) {
        dimEquivTest(leftSide, rightSide);
        return !(leftSide == rightSide);
    }

    bool operator<(const Point &leftSide, const Point &rightSide) {
        dimEquivTest(leftSide, rightSide);
        for (int i = 0; i < leftSide.dim; i++) {
            if (leftSide.values[i] < rightSide.values[i])
                return true;
            if (leftSide.values[i] > rightSide.values[i])
                return false;
        }
        return false;
    }

    bool operator>(const Point &leftSide, const Point &rightSide) {
        dimEquivTest(leftSide, rightSide);
        for (int i = 0; i < leftSide.dim; i++) {
            if (leftSide.values[i] > rightSide.values[i])
                return true;
            if (leftSide.values[i] < rightSide.values[i])
                return false;
        }
        return false;
    }

    bool operator<=(const Point &leftSide, const Point &rightSide) {
        if (leftSide == rightSide)
            return true;
        if (leftSide < rightSide)
            return true;
        return false;
    }

    bool operator>=(const Point &leftSide, const Point &rightSide) {
        if (leftSide == rightSide)
            return true;
        if (leftSide > rightSide)
            return true;
        return false;
    }

    std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << "This point has: " << point.dim << " dimensions." << std::endl;
        os << "Its coordinates are: ";
        for (int i = 0; i < point.dim; i++)
            os << point.values[i] << " ";
        os << std::endl;
        return os;
    }

    std::istream &operator>>(std::istream &is, const Point &point) {
        // Needs implementation
        return is;
    }

    void dimEquivTest(const Point &leftPoint, const Point &rightPoint) {
        assert(leftPoint.dim == rightPoint.dim);
    }




}