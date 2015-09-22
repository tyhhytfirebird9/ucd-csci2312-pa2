//
// Created by Alex Foreman on 9/20/15.
//

#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"
#include <iostream>

namespace Clustering {

    typedef Point *PointPtr;
    typedef struct LNode *LNodePtr;

    struct LNode{
        PointPtr p;
        LNodePtr next;
    };

    class Cluster {
    private:
        int size;
        LNodePtr head;

    public:
        Cluster() : size(0), head(nullptr) {};

        // The Big Three: Copy constructor, Assignment operator=, destructor
        // Copy Constructor
        Cluster(const Cluster &);
        // Assignment operator=
        Cluster &operator=(const Cluster&);
        // Destructor
        ~Cluster();

        // Set functions: They allow calling c1.add(c2.remove(p));
        void add(const PointPtr &);
        const PointPtr &remove(const PointPtr &);

        // Overloaded operators
        // IO
        friend std::ostream &operator<<(std::ostream&, const Cluster&);
        friend std::istream &operator>>(std::istream&, Cluster&);

        // Set-preserving operators (do not duplicate points in space)
        // - Friends
        friend bool operator==(const Cluster&, const Cluster&);

        // - Members
        Cluster &operator+=(const Cluster&); // Union (returns a cluster with all points in both clusters)
        Cluster &operator-=(const Cluster&); // (asymmetric) difference (returns cluster with only points that are in neither cluster)

        Cluster &operator+=(const Point&); // adds a Point to the Cluster
        Cluster &operator-=(const Point&); // removes a Point to the Cluster

        // Set-destructive operators (duplicate points in space)
        // -Friends
        friend const Cluster operator+(const Cluster&, const Cluster&);
        friend const Cluster operator-(const Cluster&, const Cluster&);

        friend const Cluster operator+(const Cluster&, const PointPtr&);
        friend const Cluster operator-(const Cluster&, const PointPtr&);

    };
}

#endif // CLUSTERING_CLUSTER_H
