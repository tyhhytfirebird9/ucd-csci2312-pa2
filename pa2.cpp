//
// Created by Alex Foreman
//

// Required directives
#include <iostream>
#include <iomanip>      // required for setprecision()
#include "Point.h"      // required to use the Point class
#include "Cluster.h"    // required to use the Cluster class

using namespace std;
using namespace Clustering;

// ALL POINT CLASS TEST FUNCTIONS
void testPointClass();
void testPointConstructorsandAssignment();
void testPointAccessorsandMutators();
void testDistanceTo();
void testPointOperators();  // CALLS THE NEXT THREE FUNCTIONS TO BREAK UP TESTS
void testPointMultandDiv();
void testPointPlusandMinus();
void testPointEquivandCompare();

// ALL CLUSTER CLASS TEST FUNCTIONS
void testClusterClass();
void testClusterConstructorsandAssignment();
void testClusterAddandRemove();
void testClusterEquiv();
void testClusterUNIONandASYDIF();
void testClusterADDandREMOVEByObject();
void testClusterADDandREMOVEByPointer();

int main() {

    testPointClass();
    testClusterClass();

    return 0;
}

void testPointClass() {
    // WORKING
    cout << "TESTING FUNCTIONALITY FOR THE POINT CLASS" << endl;
    testPointConstructorsandAssignment();
    testPointAccessorsandMutators();
    testDistanceTo();
    testPointOperators();
    cout << "ALL FUNCTIONALITY ASSIGNED FOR THE POINT CLASS HAS BEEN FULLY IMPLEMENTED AND TESTED" << endl << endl;

}
void testClusterClass() {
    cout << "TESTING FUNCTIONALITY FOR THE CLUSTER CLASS" << endl << endl;
    // Testing Constructors and Assignment operators
    testClusterConstructorsandAssignment();

    // Testing Add and Remove
    testClusterAddandRemove();

    // Testing Equivalence
    testClusterEquiv();

    // Testing UNION and Asymmetric Difference
    testClusterUNIONandASYDIF();

    // Testing Add and Remove point by object
    testClusterADDandREMOVEByObject();

    // Testing Add and remove point by pointer
    testClusterADDandREMOVEByPointer();


    cout << "ALL FUNCTIONALITY ASSIGNED FOR THE CLUSTER CLASS HAS BEEN FULLY IMPLEMENTED AND TESTED" << endl << endl;
}

void testPointConstructorsandAssignment() {
    // Constructor testing. DEFAULT, JUST DIM, DIM and COORDS
    cout << "TESTING POINT CONSTRUCTORS AND ASSIGNMENT OPERATOR" << endl;
    PointPtr p1 = new Point(3);
    cout << "p1 created: " << *p1 << endl;

    double arrp2[] = {1, 3, 4};
    PointPtr p2 = new Point(3, arrp2);    // Default Point 3 dimensions
    cout << "p2 created: " << *p2 << endl;


    double arr[] = {1, 3, 7, 5, 2};
    PointPtr p3 = new Point(5,arr);
    cout << "p3 created: " << *p3 << endl;

    // Copy constructor and Assignment operator
    PointPtr p3copy = new Point(*p3);
    cout << "p3 copied" << endl;
    cout << "p3: " << *p3 << "p3copy " << *p3copy << endl;

    PointPtr p3copy2 = new Point(3);
    *p3copy2 = *p3;
    cout << "p3 copied" << endl;
    cout << "p3: " << *p3 << "p3copy2 " << *p3copy2 << endl;

    PointPtr p2Assigned = new Point(3);
    // Self Assignment
    cout << "Testing self assignement (p2 = p2) " << endl;
    *p2 = *p2;
    cout << endl;

    *p2Assigned = *p2;
    cout << "p2 assigned!" << endl;
    cout << "p2: " << *p2 << "p2Assigned: " << *p2Assigned << endl;
    cout << "FINISED TESTING CONSTRUCTORS AND ASSIGNMENT OPERATOR FOR POINT CLASS" << endl << endl;
}
void testPointAccessorsandMutators() {
    cout << "TESTING POINT ACCESSORS AND MUTATORS" << endl;
    Point p1(3);     // Default point
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
    //int aboveBounds = p3.getDims() + 1;
    //int belowBounds = 0;
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
    Point p1(3);
    //Point p2(3);
    // p2.distanceTo(p1); // p2 and p1 have different dimensions (tested Working)

    // Successes
    // Same Point
    Point p1copy(p1);
    cout << "Distance from p1 to p1copy " << p1.distanceTo(p1copy) << endl;

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
    // Test *, /, *=, and /=
    testPointMultandDiv();

    // Test +, -, += and -=
    testPointPlusandMinus();

    // Test Equivalence and Comparitors
    testPointEquivandCompare();

    cout << "THE COUT OPERATOR HAS BEEN USED BUT NO IMPLEMENTATION INSTRUCTIONS HAVE BEEN GIVEN FOR THE PROJECT" << endl;
    cout << "THE CIN OPERATOR IS CURRENTLY NOT IMPLEMENTED AS NOT INSTRUCTTIONS HAVE BEEN GIVEN FOR IT" << endl;
    cout << "FINISHED TESTING OVERLOADED OPERATORS FOR THE POINT CLASS" << endl << endl;
}
void testPointEquivandCompare() {
    PointPtr p1 = new Point(3);
    p1->setValue(1, 1);
    p1->setValue(2, 2);
    p1->setValue(3, 3);

    PointPtr p2 = new Point(*p1);

    // TESTING ==, !=
    cout << "Testing p1 == p2 & p1 != p2" << endl;
    cout << "p1 " << *p1 << "p2 " << *p2;
    if (*p1 == *p2)
        cout << "p1 and p2 are equivalent" << endl;
    if (*p1 != *p2)
        cout << "p1 and p2 are not equivalent" << endl;
    cout << endl;

    cout << "setting p1 and p2 to be equivalent" << endl;
    *p1 = *p2;
    cout << "p1 " << *p1 << "p2 " << *p2;
    if (*p1 == *p2)
        cout << "p1 and p2 are equivalent" << endl;
    if (*p1 != *p2)
        cout << "p1 and p2 are not equivalent" << endl;
    cout << endl;

    // TESTING FAIL CASE FOR == and != (WORKING)
    //PointPtr point2D = new Point(2);
    // These Should fail because the dimensions are not the same.
    //if (*p1 != *point2D)
    //    cout << "These Points are not equivalent" << endl;
    //if (*p2 == *point2D)
    //    cout << "These Points are equivalent" << endl;

    // TESTING <, >, <=, >=
    // < and >
    cout << "Testing p1 < p2 " << endl;
    cout << "p1 " << *p1 << endl << "p2 " << *p2 << endl;
    cout << "The points are currently equivalent so we expect any >=, or <= to print. " << endl;
    cout << "We also expect <, and > to fail" << endl;
    if (*p1 < *p2)
        cout << "p1 < p2" << endl;
    if (*p1 <= *p2)
        cout << "p1 <= p2" << endl;
    if (*p2 < *p1)
        cout << "p2 < p1" << endl;
    if (*p2 <= *p1)
        cout << "p2 <= p1" << endl;
    if (*p1 > *p2)
        cout << "p1 > p2" << endl;
    if (*p1 >= *p2)
        cout << "p1 >= p2" << endl;
    if (*p2 > *p1)
        cout << "p2 > p1" << endl;
    if (*p2 >= *p1)
        cout << "p2 >= p1" << endl;
    cout << endl;

    cout << "Now changing p1's second value to 1" << endl;
    p1->setValue(2, 1);
    cout << "We expect p1 > p2, p1 >= p2, p2 < p1, and p2 <= p1 to print" << endl;
    if (*p1 < *p2)
        cout << "p1 < p2" << endl;
    if (*p1 <= *p2)
        cout << "p1 <= p2" << endl;
    if (*p2 < *p1)
        cout << "p2 < p1" << endl;
    if (*p2 <= *p1)
        cout << "p2 <= p1" << endl;
    if (*p1 > *p2)
        cout << "p1 > p2" << endl;
    if (*p1 >= *p2)
        cout << "p1 >= p2" << endl;
    if (*p2 > *p1)
        cout << "p2 > p1" << endl;
    if (*p2 >= *p1)
        cout << "p2 >= p1" << endl;
    cout << endl;

    cout << "Now changing p2's first value to 2" << endl;
    p2->setValue(1, 2);
    cout << "We now expect p2 > p1, p2 >= p1, p1 < p2, and p1 <= p2 to print" << endl;
    if (*p1 < *p2)
        cout << "p1 < p2" << endl;
    if (*p1 <= *p2)
        cout << "p1 <= p2" << endl;
    if (*p2 < *p1)
        cout << "p2 < p1" << endl;
    if (*p2 <= *p1)
        cout << "p2 <= p1" << endl;
    if (*p1 > *p2)
        cout << "p1 > p2" << endl;
    if (*p1 >= *p2)
        cout << "p1 >= p2" << endl;
    if (*p2 > *p1)
        cout << "p2 > p1" << endl;
    if (*p2 >= *p1)
        cout << "p2 >= p1" << endl;
    cout << endl;
}
void testPointPlusandMinus(){
    PointPtr p1 = new Point(3);
    p1->setValue(1, 6);
    p1->setValue(2, 4.2);
    p1->setValue(3, -2.5);

    cout << "p1 initialized " << endl;
    cout << *p1 << endl;

    PointPtr p2 = new Point(3);
    p2->setValue(1, 2.3);
    p2->setValue(2, 3.4);
    p2->setValue(3, -1.9);

    cout << "p2 initialized " << endl;
    cout << *p2 << endl;

    // TESTING += and -=
    // +=
    cout << "testing p1 += p2" << endl;
    cout << "p1" << endl << *p1 << "p2" << endl << *p2;
    *p1 += *p2;
    cout << "The sum is: " << endl;
    cout << "p1" << endl << *p1 << endl;

    // -=
    cout << "testing p1 -= p2" << endl;
    cout << "p1" << endl << *p1 << "p2" << endl << *p2;
    *p1 -= *p2;
    cout << "The difference is: " << endl;
    cout << "p1" << endl << *p1 << endl;

    // TESTING + and -
    // +
    cout << "Testing p1 + p2" << endl;
    cout << "p1" << endl << *p1 << "p2" << endl << *p2;
    PointPtr p3 = new Point(3);
    *p3 = *p1 + *p2;
    cout << "p3" << endl << *p3 << endl;

    // -
    cout << "Testing p2 - p1" << endl;
    cout << "p2" << endl << *p2 << "p1" << endl << *p1;
    *p3 = *p2 - *p1;
    cout << "p3" << endl << *p3 << endl;

    // TESTING FAIL CASE FOR +=, -=, + and - (WORKING)
    // These should all crash the program because the dimensions are not the same.
    //PointPtr point2D = new Point(2);
    //*p1 += *point2D;        // COMMENTED OUT TO
    //*p2 -= *point2D;        // PROVENT MAIN FROM
    //*p3 = *p2 + *point2D;    // CRASHING THE
    //*p3 = *p1 - *point2D;    // PROGRAM
}
void testPointMultandDiv(){
    PointPtr p1 = new Point(3);
    p1->setValue(1, 6);
    p1->setValue(2, 4.2);
    p1->setValue(3, -2.5);

    cout << "p1 initialized " << endl;
    cout << *p1 << endl;

    // TESTING *= and /=
    // *=
    cout << "testing p1 *= 3 " << endl;
    *p1 *= 3;
    cout << *p1 << endl;

    // /=
    // First divide by 0
    cout <<  "testing p1 /= 0" << endl;
    *p1 /= 0;
    cout << "if divided by 0 /= returns point unaltered " << endl;
    cout << *p1 << endl;

    // Then by a number
    cout << "testing p1 /= 4.2" << endl;
    *p1 /= 4.2;
    cout << *p1 << endl;

    // TESTING * and /
    // *
    PointPtr p2 = new Point(3);
    cout << "Created p2 with three dimensions" << endl << *p2;

    cout << "Testing p2 = p1 * 5.6" << endl;
    *p2 = *p1 * 5.6;
    cout << "p1" << endl << *p1 << "p2" << endl << *p2 << endl;

    // /
    // first divide by 0 (TEST SUCCEEDS PROGRAM MEANT TO FAIL)
    //cout << "testing p2 = p1 / 0" << endl;
    //*p2 = *p1 / 0;
    //cout << "p1" << endl << *p1 << "p2" << endl << *p2 << endl;

    // now divide by a number
    cout << "testing p2 = p1 / 7" << endl;
    *p2 = *p1 / 7;
    cout << "p1" << endl << *p1 << "p2" << endl << *p2 << endl;
}

void testClusterConstructorsandAssignment(){
    cout << "Testing Cluster Constructors and Assignement operator. " << endl << endl;
    Cluster c1;
    PointPtr p1 = new Point(3);
    PointPtr p2 = new Point(3);
    PointPtr p3 = new Point(3);

    for (int i = 1; i <= 3; i++){
        p1->setValue(i, (i+1)*2);
    }
    for (int i = 1; i <= 3; i++){
        p2->setValue(i, (i+2)/3.0);
    }
    for (int i = 1; i <= 3; i++){
        p3->setValue(i, (i+5)/3.0);
    }

    cout << "Cluster c1 initialized " << endl;
    cout << "c1: " << endl << c1 << endl;
    c1.add(p1);
    c1.add(p2);
    c1.add(p3);

    cout << "p1, p2, and p3 have been added to c1" << endl;
    cout << "c1: " << endl << c1 << endl;


    Cluster c2 = c1;
    cout << "Copy constructor using Cluster c2 = c1" << endl;
    cout << "c1: " << endl << c1 << endl << "c2" << endl << c2 << endl;

    Cluster c3(c1);
    cout << "Copy constructor using Cluster c3(c1)" << endl;
    cout << "c1: " << endl << c1 << endl << "c3: " << endl << c3 << endl;


    Cluster c4;
    c4 = c1;
    cout << "Assignment operator" << endl;
    cout << "Checking for self assignment " << endl;
    c1 = c1;

    cout << "Now c4 = c1" << endl;
    cout << "c1: " << endl << c1 << endl << "c4: " << endl << c4 << endl;

    cout << "End testing for Copy constructor and Assignment operator for the cluster class" << endl << endl;
}
void testClusterAddandRemove(){
    Cluster c1;
    PointPtr p1 = new Point(3);
    PointPtr p2 = new Point(3);
    PointPtr p3 = new Point(3);

    for (int i = 1; i <= 3; i++){
        p1->setValue(i, (i+1)*2);
    }
    for (int i = 1; i <= 3; i++){
        p2->setValue(i, (i+2)/3.0);
    }
    for (int i = 1; i <= 3; i++){
        p3->setValue(i, (i+5)/3.0);
    }

    PointPtr p4 = new Point(3);
    *p4 = *p1;

    cout << "Testing add and remove" << endl;
    cout << "current c1: " << endl << c1 << endl;

    cout << "removing from an empty list (c1.remove(p1))" << endl;
    c1.remove(p1);
    cout << "c1: " << endl << c1 << endl;

    c1.add(p1);
    cout << "adding a point (c1.add(p1))" << endl;
    cout << "c1: " << endl << c1 << endl;

    c1.add(p2);
    c1.add(p3);
    cout << "adding the next two points " << endl;
    cout << "c1: " << endl << c1 << endl;

    c1.add(p4);
    cout << "adding a point with the same values as a previous point" << endl;
    cout << "c1: " << endl << c1 << endl;

    cout << "Points with the same values are organized by memory address" << endl << endl;

    c1.remove(p2);
    cout << "testing remove of first node. " << endl;
    cout << "c1: " << endl << c1 << endl;

    c1.add(p2);
    c1.remove(p4);
    c1.remove(p1);
    cout << "testing remove of last node" << endl;
    cout << "c1: " << endl << c1 << endl;

    c1.add(p1);
    c1.add(p4);
    c1.remove(p3);
    cout << "testing remove of middle node" << endl;
    cout << "c1: " << endl << c1 << endl;

    c1.add(p3);
    cout << "testing adding the same point twice" << endl;
    cout << "current c1: " << endl << c1 << endl;
    c1.add(p1);
    cout << "after c1.add(p1)" << endl;
    cout << "now c1: " << endl << c1 << endl;

    c1.add(c1.remove(p2));
    cout << "testing c1.add(c1.remove(p2))" << endl;
    cout << "c1: " << endl << c1 << endl;

    cout << "End testing for add and remove functions for Cluster class" << endl;
}
void testClusterEquiv(){
    cout << "Testing the equivalence functions for the cluster class" << endl << endl;
    Cluster c1;
    PointPtr p1 = new Point(3);
    PointPtr p2 = new Point(3);
    PointPtr p3 = new Point(3);

    for (int i = 1; i <= 3; i++){
        p1->setValue(i, (i+1)*2);
    }
    for (int i = 1; i <= 3; i++){
        p2->setValue(i, (i+2)/3.0);
    }
    for (int i = 1; i <= 3; i++){
        p3->setValue(i, (i+5)/3.0);
    }

    PointPtr p4 = new Point(3);
    *p4 = *p1;

    Cluster c2;

    c1.add(p1);
    c2.add(p2);
    c1.add(p3);
    c2.add(p4);

    cout << "This operator will return false if the sizes arent the same" << endl;
    c1.remove(p1);
    cout << "c1: " << endl << c1 << endl;
    cout << "c2: " << endl << c2 << endl;

    if (c1 == c2)
        cout << "These clusters are equal" << endl;
    if (c1 != c2)
        cout << "These clusters are not equal" << endl;

    cout << endl;
    c1.add(p1);
    c1.add(p2);
    c2.add(p3);
    cout << "This operator will also return false if the all points are not the same point by memory" << endl;
    cout << "c1: " << endl << c1 << endl;
    cout << "c2: " << endl << c2 << endl;
    if (c1 == c2)
        cout << "These clusters are equal" << endl;
    if (c1 != c2)
        cout << "These clusters are not equal" << endl;
    cout << "In this case c1 and c2 may look equal, but c1 contains p1, and c2 contains p1 4, 6, 8 but c2 has ";
    cout << "p4 4, 6, 8. They have different memory addresses." << endl << endl;

    c1.add(p4);
    c2.add(p1);
    cout << "This operator will return true if the clusters are exactly equal (they have all the same points)" << endl;
    cout << "c1: " << endl << c1 << endl;
    cout << "c2: " << endl << c2 << endl;
    if (c1 == c2)
        cout << "These clusters are equal" << endl;
    if (c1 != c2)
        cout << "These clusters are not equal" << endl;

    cout << endl << "End testing equivalence operators for the cluster class" << endl;


}
void testClusterUNIONandASYDIF(){
    cout << "Testing the UNION and Asymmetric difference functions for the cluster class" << endl << endl;
    Cluster c1;
    PointPtr p1 = new Point(3);
    PointPtr p2 = new Point(3);
    PointPtr p3 = new Point(3);

    for (int i = 1; i <= 3; i++){
        p1->setValue(i, (i+1)*2);
    }
    for (int i = 1; i <= 3; i++){
        p2->setValue(i, (i+2)/3.0);
    }
    for (int i = 1; i <= 3; i++){
        p3->setValue(i, (i+5)/3.0);
    }

    PointPtr p4 = new Point(3);
    *p4 = *p1;
    p4->setValue(2, 3);

    Cluster c2;
    Cluster c3;
    Cluster c4;

    c1.add(p1);
    c1.add(p2);
    c2.add(p4);
    cout << "Testing c1 += c2" << endl;
    cout << "current c1: " << endl << c1 << endl << "current c2: " << endl << c2 << endl;
    c1 += c2;
    cout << "Union c1: " << endl << c1 << endl;

    c1.add(p3);
    c2.add(p1);
    c2.add(p2);
    cout << "Testing c1 -= c2" << endl;
    cout << "current c1: " << endl << c1 << endl << "current c2: " << endl << c2 << endl;
    c1 -= c2;
    cout << "Asymmetric Difference c1: " << endl << c1 << endl;

    c1.add(p1);
    c1.add(p2);
    c1.remove(p3);
    c1.remove(p4);
    c2.remove(p1);
    c2.remove(p2);
    c2.add(p3);
    c2.remove(p4);
    cout << "Testing c3 = c1 + c2" << endl;
    cout << "current c1: " << endl << c1 << endl << "current c2: " << endl << c2 << endl;
    cout << "current c3: " << endl << c3 << endl;
    c3 = c1 + c2;
    cout << "union c3: " << endl << c3 << endl;


    c3.add(p4);
    cout << "Tesing c4 = c3 - c1" << endl;
    cout << "current c3: " << endl << c3 << endl << "current c1: " << endl << c1 << endl;
    cout << "current c4: " << endl << c4 << endl;
    c4 = c3 - c1;
    cout << "Asymmetric Difference c4: " << endl << c4 << endl;


    cout << "End Testing for Union and Asymmetric Difference of the cluster class" << endl << endl;
}
void testClusterADDandREMOVEByObject(){
    cout << "Testing adding and removing Point by object to a Cluster" << endl << endl;

    Cluster c1;
    Point p1(3);
    p1.setValue(1, 4);
    p1.setValue(2, 1.3);
    p1.setValue(3, 2);


    cout << "Testing adding a point (c1 += p1)" << endl;
    cout << "current c1: " << endl << c1 << endl;
    c1 += p1;
    cout << "new c1: " << endl << c1 << endl;
    c1 += p1;
    c1 += p1;
    c1 += p1;
    c1 += p1;
    c1 += p1;

    p1.setValue(2,4);
    c1 += p1;
    c1 += p1;
    c1 += p1;
    c1 += p1;
    p1.setValue(2,1.3);

    cout << "Testing removing all points that have the same values as the object point (c1 -= p1)" << endl;
    cout << "current c1: " << endl << c1 << endl;
    c1 -= p1;
    cout << "new c1: " << endl << c1 << endl;

    cout << "End testing adding and removing new Point by object" << endl << endl;
}
void testClusterADDandREMOVEByPointer(){
    cout << "Testing Adding and Removing Points by pointer" << endl << endl;
    Cluster c1;
    PointPtr p1 = new Point(3);
    PointPtr p2 = new Point(3);
    PointPtr p3 = new Point(3);

    for (int i = 1; i <= 3; i++){
        p1->setValue(i, (i+1)*2);
    }
    for (int i = 1; i <= 3; i++){
        p2->setValue(i, (i+2)/3.0);
    }
    for (int i = 1; i <= 3; i++){
        p3->setValue(i, (i+5)/3.0);
    }

    PointPtr p4 = new Point(3);
    *p4 = *p1;

    Cluster c2;
    Cluster c3;

    c2.add(p1);
    c2.add(p2);
    cout << "Testing adding a point by pointer (c1 = c2 + p3)" << endl;
    cout << "current c1:" << endl << c1 << endl << "current c2: " << endl << c2 << endl;
    c1 = c2 + p3;
    cout << "result c1: " << endl << c1 << endl;

    cout << "Testing removing a point by pointer (c3 = c1 - p4)" << endl;
    cout << "current c3:" << endl << c3 << endl << "current c1: " << endl << c1 << endl;
    c3 = c1 - p1;
    cout << "result c3: " << endl << c3 << endl;

    cout << "End Testing adding and removing a Point by pointer" << endl << endl;
}
