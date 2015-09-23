//
// Created by Alex Foreman on 9/20/15.
//

#include "Cluster.h"

namespace Clustering {

    Cluster::Cluster(const Cluster &clusterToCopy) {

        size = clusterToCopy.size;

        LNodePtr rightSide = new LNode();
        LNodePtr leftSide = new LNode();

        head = leftSide;
        rightSide->next = clusterToCopy.head;
        rightSide = rightSide->next;

        while (rightSide->next != nullptr) {
            leftSide->p = rightSide->p;
            leftSide->next = new LNode();
            leftSide = leftSide->next;
            rightSide = rightSide->next;
        }
        leftSide->next = new LNode();
        leftSide->p = rightSide->p;
        leftSide->next = nullptr;
    }

    Cluster &Cluster::operator=(const Cluster &assigningCluster) {
        // Maybe do this to deallocate all associated memory?
        this->~Cluster();
        LNodePtr leftSide = new LNode();
        LNodePtr rightSide = new LNode();

        head = nullptr;
        size = assigningCluster.size;

        head = leftSide;
        rightSide->next = assigningCluster.head;
        rightSide = rightSide->next;

        while (rightSide->next != nullptr) {
            leftSide->p = rightSide->p;
            leftSide->next = new LNode();
            leftSide = leftSide->next;
            rightSide = rightSide->next;
        }
        leftSide->next = new LNode();
        leftSide->p = rightSide->p;
        leftSide->next = nullptr;

        return *this;
    }

    Cluster::~Cluster() {

    }

    void Cluster::add(const PointPtr &pointToAdd) {
        if (size == 0) {
            LNodePtr tempNode = new LNode();
            tempNode->p = pointToAdd;
            tempNode->next = nullptr;
            head = tempNode;
            size++;
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

    std::ostream &operator<<(std::ostream &os, const Cluster &clusterToRead) {

    }

    std::istream &operator>>(std::istream &is, Cluster &clusterToWrite) {

    }

    bool operator==(const Cluster &, const Cluster &) {

    }

    Cluster &Cluster::operator+=(const Cluster &rightSide) {

    }

    Cluster &Cluster::operator-=(const Cluster &rightSide) {

    }

    Cluster &Cluster::operator+=(const Point &rightSide) {

    }

    Cluster &Cluster::operator-=(const Point &rightSide) {

    }

    const Cluster operator+(const Cluster &leftSide, const Cluster &rightSide) {

    }

    const Cluster operator-(const Cluster &leftSide, const Cluster &rightSide) {

    }

    const Cluster operator+(const Cluster &leftSide, const PointPtr &rightSide) {

    }

    const Cluster operator-(const Cluster &leftSide, const PointPtr &rightSide) {

    }

}