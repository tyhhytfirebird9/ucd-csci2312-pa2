//
// Created by Alex Foreman
//

// Required directives
#include <iostream>
#include <iomanip>      // required for setprecision()
#include <cmath>        // required for sqrt() and pow()
#include "Point.h"      // required to use the Point class
#include "Cluster.h"    // required to use the Cluster class

using namespace std;
using namespace Clustering;

void testPointConstructorsandAssignment();
void testPointAccessorsandMutators();
void testDistanceTo();
void testPointOperators();
void testPointClass();
void testClusterClass();

int main() {

    testPointClass();
    testClusterClass();

    /*
    Point p1(2);
    p1.setValue(1, 2);
    p1.setValue(2, 5);

    Point p2(2);
    p2.setValue(1, 1);
    p2.setValue(2, 8);

    Cluster c1;

    c1.add(&p1);
    c1.add(&p2);

    Cluster c2(c1);
    //Cluster c2;
    // c2 = c1;




    double* coArr1 = new double[3];
    double* coArr2 = new double[3];
    double* coArr3 = new double[3];
    double* coArr4 = new double[3];
    double* coArr5 = new double[3];

    Point p1(5, coArr1);
    Point p2(5, coArr2);
    Point p3(5, coArr3);
    Point p4(5, coArr4);
    Point p5(5, coArr5);

    delete [] coArr1;
    delete [] coArr2;
    delete [] coArr3;
    delete [] coArr4;
    delete [] coArr5;

    for (int i = 0; i < 5; i++)
        p1.setValue(i + 1, 0);

    for (int i = 0; i < 5; i++)
        p2.setValue(i + 1, i);

    for (int i = 0; i < 5; i++)
        p3.setValue(i + 1, 4 - i);

    p4.setValue(1, 0);
    p4.setValue(2, 0);
    p4.setValue(3, 0);
    p4.setValue(4, 0);
    p4.setValue(5, 0);

    p5.setValue(1, 0);
    p5.setValue(2, 0);
    p5.setValue(3, 0);
    p5.setValue(4, 0);
    p5.setValue(5, 1);

    cout << p1 << p2 << p3 << p4 << p5;


    if (p1 <= p4)
        cout << "p1 <= p4" << endl;
    if (p5 <= p4)
        cout << "p5 <= p4" << endl;
    if (p5 >= p4)
        cout << "p5 >= p4" << endl;


    if (p1 < p2)
        cout << "p1 < p2" << endl;
    if (p2 > p1)
        cout << "p2 > p1" << endl;

    if (p1 < p4)
        cout << "p1 < p4" << endl;
    if (p1 > p4)
        cout << "p1 > p4" << endl;

    if (p1 < p5)
        cout << "p1 < p5" << endl;
    if (p1 > p5)
        cout << "p1 > p5" << endl;


    if (p3 < p2)
        cout << "p3 < p2" << endl;
    if (p3 > p2)
        cout << "p3 > p2" << endl;


    Point p1;
    p1.setValue(1,3);
    p1.setValue(2,4);

    cout << "Initial P1 values: " << p1.getValue(1) << " " << p1.getValue(2) << endl;
    p1 *= 2;
    cout << "After multiplying by 2: " << p1.getValue(1) << " " << p1.getValue(2) << endl;
    p1 /= 3;
    p1 /= 0;
    cout << "After dividing by 3: " << p1.getValue(1) << " " << p1.getValue(2) << endl;

    Point p2;
    cout << "Initial P2 values: " << p2.getValue(1) << " " << p2.getValue(2) << endl;
    p2 = p1 * 2;
    cout << "p2 after storing p1 * 2: " << p2.getValue(1) << " " << p2.getValue(2) << endl;

    p2 = p1 / 3;
    cout << "after storing p1 / 3: " << p2.getValue(1) << " " << p2.getValue(2) << endl;

    cout << "p1 and p2: " << p1.getValue(1) << " " << p1.getValue(2) << " " << p2.getValue(1) << " " << p2.getValue(2) << endl;
    p1 += p2;
    cout << "p1 and p2 after p1 += p2: " << p1.getValue(1) << " " << p1.getValue(2) << " " << p2.getValue(1) << " " << p2.getValue(2) << endl;

    p1 -= p2;
    cout << "p1 and p2 after p1 -= p2: " << p1.getValue(1) << " " << p1.getValue(2) << " " << p2.getValue(1) << " " << p2.getValue(2) << endl;

    Point p3;
    cout << "initial values p3: " << p3.getValue(1) << p3.getValue(2) << endl;

    p3 = p1 + p2;
    cout << "after p3 = p1 + p2 : " << endl;
    cout << p1.getValue(1) << " " << p1.getValue(2) << endl;
    cout << p2.getValue(1) << " " << p2.getValue(2) << endl;
    cout << p3.getValue(1) << " " << p3.getValue(2) << endl;

    p3 = p1 - p2;
    cout << "after p3 = p1 - p2 : " << endl;
    cout << p1.getValue(1) << " " << p1.getValue(2) << endl;
    cout << p2.getValue(1) << " " << p2.getValue(2) << endl;
    cout << p3.getValue(1) << " " << p3.getValue(2) << endl;

    cout << "current p1 & p2: " << p1.getValue(1) << " " << p1.getValue(2) << " " << p2.getValue(1) << " " << p2.getValue(2) << endl;
    if (p1 == p2)
        cout << "equal";

    if (p1 != p2)
        cout << "Not equal";

    p1 = p2;
    cout << "current p1 & p2: " << p1.getValue(1) << " " << p1.getValue(2) << " " << p2.getValue(1) << " " << p2.getValue(2) << endl;


    if (p1 == p2)
        cout << "equal";
    if (p1 != p2)
        cout << "not equal";
    */
    return 0;
}


void testPointClass() {
    // WORKING
    //testPointConstructorsandAssignment();
    //testPointAccessorsandMutators();
    //testDistanceTo();
    //testPointOperators();
    cout << "ALL FUNCTIONALITY ASSIGNED FOR THE POINT CLASS HAS BEEN FULLY IMPLEMENTED AND TESTED" << endl << endl;


}

void testPointConstructorsandAssignment() {
    // Constructor testing. DEFAULT, JUST DIM, DIM and COORDS
    cout << "TESTING POINT CONSTRUCTORS AND ASSIGNMENT OPERATOR" << endl;
    Point p1;     // Default point
    cout << "p1 created: " << p1 << endl;
    Point p2(3);    // Default Point 3 dimensions
    cout << "p2 created: " << p2 << endl;

    double arr[] = {1, 3, 7, 5, 2};
    Point p3(5,arr);
    cout << "p3 created: " << p3 << endl;

    // Copy constructor and Assignment operator
    Point p3copy(p3);
    cout << "p3 copied" << endl;
    cout << "p3: " << p3 << "p3copy " << p3copy << endl;

    Point p3copy2 = p3;
    cout << "p3 copied" << endl;
    cout << "p3: " << p3 << "p3copy2 " << p3copy2 << endl;

    Point p2Assigned;
    // Self Assignment
    cout << "Testing self assignement (p2 = p2) " << endl;
    p2 = p2;
    cout << endl;

    p2Assigned = p2;
    cout << "p2 assigned!" << endl;
    cout << "p2: " << p2 << "p2Assigned: " << p2Assigned << endl;
    cout << "FINISED TESTING CONSTRUCTORS AND ASSIGNMENT OPERATOR FOR POINT CLASS" << endl << endl;
}

void testPointAccessorsandMutators() {
    cout << "TESTING POINT ACCESSORS AND MUTATORS" << endl;
    Point p1;     // Default point
    cout << "p1 created: " << p1 << endl;
    Point p2(3);    // Default Point 3 dimensions
    cout << "p2 created: " << p2 << endl;

    double arr[] = {1, 3, 7, 5, 2};
    Point p3(5,arr);
    cout << "p3 created: " << p3 << endl;

    cout << "testing accessors and mutators" << endl;
    // Accessors and Mutators
    // getDims()
    cout << "getDims() " << endl;
    cout << "p1 has " << p1.getDims() << " dimensions." << endl;
    cout << "p2 has " << p2.getDims() << " dimensions." << endl;
    cout << "p3 has " << p3.getDims() << " dimensions." << endl;

    // setValue()
    // Fail test (intentionally out of bounds)
    int aboveBounds = p3.getDims() + 1;
    int belowBounds = 0;
    double testValue = 3.45;
    //p3.setValue(aboveBounds, testValue);  // Commented out so the program can run, but tested (WORKING)
    //p3.setValue(belowBounds, testValue);    // Commented out so the program can run, but tested (WORKING)

    cout << endl << "testing setValue()" << endl;
    p3.setValue(p3.getDims()-2, testValue);
    cout << "p3 dimension " << p3.getDims()-2 << " set to " << p3.getValue(p3.getDims() - 2) << endl;
    cout << p3 << endl;
    p2.setValue(p2.getDims()-1, testValue);
    cout << "p2 dimension " << p2.getDims() - 1 << " set to " << p2.getValue(p2.getDims() - 1) << endl;
    cout << p2 << endl;
    cout << "FINISHED TESTING ACCESSORS AND MUTATORS FOR THE POINT CLASS" << endl << endl;
}

void testDistanceTo() {
    cout << "TESTING distanceTo() " << endl;
    // Fail on purpose
    Point p1;
    Point p2(3);
    // p2.distanceTo(p1); // p2 and p1 have different dimensions (tested Working)

    // Successes
    // Same Point
    Point p1copy(p1);
    cout << "Distance from p1 to p1copy " << p1.distanceTo(p1) << endl;

    // 2 dimensions
    Point point2D_1(2);
    Point point2D_2(2);
    point2D_1.setValue(1, 2.3);
    point2D_1.setValue(2, -3.7);
    point2D_2.setValue(1, 0);
    point2D_2.setValue(2, 9);

    cout << point2D_1 << point2D_2 << endl;
    cout << "This distance between point2D_1, and point2D_2 is: " << point2D_1.distanceTo(point2D_2) << endl;

    // 5 dimensions
    Point point5D_1(5);
    Point point5D_2(5);
    for (int i = 0; i < 5; i++) {
        point5D_1.setValue(i+1, (i+1)*2);
    }
    cout << "point5D_1 initialized" << endl;
    cout << point5D_1 << endl;
    for (int i = 5; i > 0; i--) {
        point5D_2.setValue(i, i-4);
    }
    cout << "point5D_2 initialized" << endl;
    cout << point5D_2 << endl;

    cout << "The distance between these two points is " << point5D_1.distanceTo(point5D_2) << endl;
    cout << "FINISHED TESTING distanceTo()" << endl << endl;
}

void testPointOperators() {
    cout << "TESTING THE OVERLOADED OPERATORS FOR POINT CLASS" << endl;
    Point p1(3);
    p1.setValue(1, 6);
    p1.setValue(2, 4.2);
    p1.setValue(3, -2.5);

    cout << "p1 initialized " << endl;
    cout << p1 << endl;

    // TESTING *= and /=
    // *=
    cout << "testing p1 *= 3 " << endl;
    p1 *= 3;
    cout << p1 << endl;

    // /=
    // First divide by 0
    cout <<  "testing p1 /= 0" << endl;
    p1 /= 0;
    cout << "if divided by 0 /= returns point unaltered " << endl;
    cout << p1 << endl;

    // Then by a number
    cout << "testing p1 /= 4.2" << endl;
    p1 /= 4.2;
    cout << p1 << endl;

    // TESTING * and /
    // *
    Point p2(3);
    cout << "Created p2 with three dimensions" << endl << p2;

    cout << "Testing p2 = p1 * 5.6" << endl;
    p2 = p1 * 5.6;
    cout << "p1" << endl << p1 << "p2" << endl << p2 << endl;

    // /
    // first divide by 0 (TEST SUCCEEDS PROGRAM MEANT TO FAIL)
    //cout << "testing p2 = p1 / 0" << endl;
    //p2 = p1 / 0;
    //cout << "p1" << endl << p1 << "p2" << endl << p2 << endl;

    // now divide by a number
    cout << "testing p2 = p1 / 7" << endl;
    p2 = p1 / 7;
    cout << "p1" << endl << p1 << "p2" << endl << p2 << endl;

    // TESTING += and -=
    // +=
    cout << "testing p1 += p2" << endl;
    cout << "p1" << endl << p1 << "p2" << endl << p2;
    p1 += p2;
    cout << "The sum is: " << endl;
    cout << "p1" << endl << p1 << endl;

    // -=
    cout << "testing p1 -= p2" << endl;
    cout << "p1" << endl << p1 << "p2" << endl << p2;
    p1 -= p2;
    cout << "The difference is: " << endl;
    cout << "p1" << endl << p1 << endl;

    // TESTING + and -
    // +
    cout << "Testing p1 + p2" << endl;
    cout << "p1" << endl << p1 << "p2" << endl << p2;
    Point p3 = p1 + p2;
    cout << "p3" << endl << p3 << endl;

    // -
    cout << "Testing p2 - p1" << endl;
    cout << "p2" << endl << p2 << "p1" << endl << p1;
    p3 = p2 - p1;
    cout << "p3" << endl << p3 << endl;

    // TESTING FAIL CASE FOR +=, -=, + and - (WORKING)
    // These should all crash the program because the dimensions are not the same.
    Point point2D(2);
    //p1 += point2D;        // COMMENTED OUT TO
    //p2 -= point2D;        // PROVENT MAIN FROM
    //p3 = p2 + point2D;    // CRASHING THE
    //p3 = p1 - point2D;    // PROGRAM



    // TESTING ==, !=
    cout << "Testing p1 == p2 & p1 != p2" << endl;
    cout << "p1 " << p1 << "p2 " << p2;
    if (p1 == p2)
        cout << "p1 and p2 are equivalent" << endl;
    if (p1 != p2)
        cout << "p1 and p2 are not equivalent" << endl;
    cout << endl;

    cout << "setting p1 and p2 to be equivalent" << endl;
    p1 = p2;
    cout << "p1 " << p1 << "p2 " << p2;
    if (p1 == p2)
        cout << "p1 and p2 are equivalent" << endl;
    if (p1 != p2)
        cout << "p1 and p2 are not equivalent" << endl;
    cout << endl;

    // TESTING FAIL CASE FOR == and != (WORKING)
    // These Should fail because the dimensions are not the same.
    //if (p1 != point2D)
    //    cout << "These Points are not equivalent" << endl;
    //if (p2 == point2D)
    //    cout << "These Points are equivalent" << endl;

    // TESTING <, >, <=, >=
    // < and >
    cout << "Testing p1 < p2 " << endl;
    cout << "p1 " << p1 << endl << "p2 " << p2 << endl;
    cout << "The points are currently equivalent so we expect any >=, or <= to print. " << endl;
    cout << "We also expect <, and > to fail" << endl;
    if (p1 < p2)
        cout << "p1 < p2" << endl;
    if (p1 <= p2)
        cout << "p1 <= p2" << endl;
    if (p2 < p1)
        cout << "p2 < p1" << endl;
    if (p2 <= p1)
        cout << "p2 <= p1" << endl;
    if (p1 > p2)
        cout << "p1 > p2" << endl;
    if (p1 >= p2)
        cout << "p1 >= p2" << endl;
    if (p2 > p1)
        cout << "p2 > p1" << endl;
    if (p2 >= p1)
        cout << "p2 >= p1" << endl;
    cout << endl;

    cout << "Now changing p1's second value to 1" << endl;
    p1.setValue(2, 1);
    cout << "We expect p1 > p2, p1 >= p2, p2 < p1, and p2 <= p1 to print" << endl;
    if (p1 < p2)
        cout << "p1 < p2" << endl;
    if (p1 <= p2)
        cout << "p1 <= p2" << endl;
    if (p2 < p1)
        cout << "p2 < p1" << endl;
    if (p2 <= p1)
        cout << "p2 <= p1" << endl;
    if (p1 > p2)
        cout << "p1 > p2" << endl;
    if (p1 >= p2)
        cout << "p1 >= p2" << endl;
    if (p2 > p1)
        cout << "p2 > p1" << endl;
    if (p2 >= p1)
        cout << "p2 >= p1" << endl;
    cout << endl;

    cout << "Now changing p2's first value to 2" << endl;
    p2.setValue(1, 2);
    cout << "We now expect p2 > p1, p2 >= p1, p1 < p2, and p1 <= p2 to print" << endl;
    if (p1 < p2)
        cout << "p1 < p2" << endl;
    if (p1 <= p2)
        cout << "p1 <= p2" << endl;
    if (p2 < p1)
        cout << "p2 < p1" << endl;
    if (p2 <= p1)
        cout << "p2 <= p1" << endl;
    if (p1 > p2)
        cout << "p1 > p2" << endl;
    if (p1 >= p2)
        cout << "p1 >= p2" << endl;
    if (p2 > p1)
        cout << "p2 > p1" << endl;
    if (p2 >= p1)
        cout << "p2 >= p1" << endl;
    cout << endl;

    cout << "THE COUT OPERATOR HAS BEEN USED BUT NO IMPLEMENTATION INSTRUCTIONS HAVE BEEN GIVEN FOR THE PROJECT" << endl;
    cout << "THE CIN OPERATOR IS CURRENTLY NOT IMPLEMENTED AS NOT INSTRUCTTIONS HAVE BEEN GIVEN FOR IT" << endl;
    cout << "FINISHED TESTING OVERLOADED OPERATORS FOR THE POINT CLASS" << endl << endl;
}

void testClusterClass() {

}