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

int main() {

    // TEST COMMENT

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

    /*
    Cluster c2;
    c2 = c1;




    /*
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
