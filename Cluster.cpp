//
// Created by Alex Foreman on 9/20/15.
//

#include "Cluster.h"

namespace Clustering {

    Cluster::Cluster(const Cluster &clusterToCopy) {

        size = clusterToCopy.size;
        head = new LNode();

        *(head->p) = *(clusterToCopy.head->p);

        LNodePtr inCluster, copyCluster;
        inCluster = clusterToCopy.head;
        copyCluster = head;

        while (inCluster->next != nullptr) {
            copyCluster->next = new LNode;
            *(copyCluster->p) = *(inCluster->p);
            copyCluster = copyCluster->next;
            inCluster = inCluster->next;
        }
        copyCluster->next = new LNode;
        *(copyCluster->p) = *(inCluster->p);
        inCluster->next = nullptr;

    }

    Cluster &Cluster::operator=(const Cluster &assigningCluster) {
        head->next = nullptr;
        size = assigningCluster.size;
        *(head->p) = *(assigningCluster.head->p);

        LNodePtr leftSide, rightSide;
        leftSide = head;
        rightSide = assigningCluster.head;

        while (rightSide->next != nullptr) {
            leftSide->next = new LNode;
            *(leftSide->p) = *(rightSide->p);
            rightSide = rightSide->next;
            leftSide = leftSide->next;
        }
        leftSide->next = new LNode;
        *(leftSide->p) = *(rightSide->p);
        leftSide->next = nullptr;


    }

    Cluster::~Cluster() {

    }

    //c1.add(p2);
    void Cluster::add(const PointPtr &pointToAdd) {
        if (size == 0) {
            LNodePtr tempNode = new LNode();
            tempNode->p = pointToAdd;
            tempNode->next = nullptr;
            head = tempNode;
            size++;

            // delete tempNode;
            // tempNode = nullptr;
        }
        else
        {
            // Above
            if (head->p >/*this is not using the overloaded operator */ pointToAdd) {
                LNodePtr tempNode = new LNode();
                tempNode->p = pointToAdd;
                tempNode->next = head;
                head = tempNode;
                size++;
            } else {
                LNodePtr prevNode = new LNode();
                LNodePtr nextNode = new LNode();
                LNodePtr tempNode = new LNode();

                tempNode->p = pointToAdd;
                tempNode->next = nullptr;

                prevNode = head;

                if (prevNode->next == nullptr) {
                    // Temp node goes here
                }
                else {
                    nextNode = prevNode->next;
                }

                // To iterate
                // prevNode = nextNode
                // nextNode = nextNode->next
                //  if (pointToAdd < next) { }
            }
            // Middle
            // Below
        }

    }

    const PointPtr &Cluster::remove(const PointPtr &pointToDelete) {

    }

    namespace clustering {
        std::ostream &operator<<(std::ostream &os, const Cluster &clusterToRead) {

        }

        std::istream &operator>>(std::istream &is, Cluster &clusterToWrite) {

        }

        bool operator==(const Cluster &, const Cluster &) {

        }
    }

    Cluster &Cluster::operator+=(const Cluster &rightSide) {

    }

    Cluster &Cluster::operator-=(const Cluster &rightSide) {

    }

    Cluster &Cluster::operator+=(const Point &rightSide) {

    }

    Cluster &Cluster::operator-=(const Point &rightSide) {

    }

    namespace Clustering {
        const Cluster operator+(const Cluster &leftSide, const Cluster &rightSide) {

        }

        const Cluster operator-(const Cluster &leftSide, const Cluster &rightSide) {

        }

        const Cluster operator+(const Cluster &leftSide, const PointPtr &rightSide) {

        }

        const Cluster operator-(const Cluster &leftSide, const PointPtr &rightSide) {

        }
    }
}