//
// Created by Alex Foreman on 9/20/15.
//


#include "Cluster.h"

namespace Clustering {

    Cluster::Cluster(const Cluster &clusterToCopy) {

        size = clusterToCopy.size;
        if (size != 0){
            LNodePtr rightSide = clusterToCopy.points;
            LNodePtr newCluster = new LNode();

            points = newCluster;

            while (rightSide->next != nullptr) {
                newCluster->p = rightSide->p;
                newCluster->next = new LNode();
                newCluster = newCluster->next;
                rightSide = rightSide->next;
            }
            //newCluster->next = new LNode();
            newCluster->p = rightSide->p;
            newCluster->next = nullptr;
        }
    }

    Cluster &Cluster::operator=(const Cluster &assigningCluster) {
        // Check for self assignment
        if (this == &assigningCluster){
            std::cout << "DO NOT SELF ASSIGN" << std::endl;
            return *this;
        }

        // DANGEROUS, ONLY CALL ON THE MASTER CLUSTER IF YOU CALL WITH +=,
        // otherwise masterCluster loses all of its points.
        //if (!(this->destroyAllPoints))
            //this->~Cluster();

        this->~Cluster();

        points = nullptr;
        size = assigningCluster.size;

        LNodePtr leftSide = new LNode();

        points = leftSide;
        LNodePtr rightSide = assigningCluster.points;


        while (rightSide->next != nullptr) {
            leftSide->p = rightSide->p;
            leftSide->next = new LNode();
            leftSide = leftSide->next;
            rightSide = rightSide->next;
        }
        leftSide->p = rightSide->p;
        leftSide->next = nullptr;

        return *this;
    }

    Cluster::~Cluster() {
        LNodePtr nodeToDelete = points;
        LNodePtr cursor = points;
        while (cursor != nullptr) {
            cursor = cursor->next;
            //if (destroyAllPoints){
            //    delete nodeToDelete->p;
            //}
            delete nodeToDelete->p;
            delete nodeToDelete;
            nodeToDelete = cursor;
            size--;
        }
        points = nullptr;
    }

    void Cluster::add(const PointPtr &pointToAdd) {
        // This will only happen if the point passed in is passed in the case of c1.add(c2.remove(p1))
        // where p1 is not in cluster 2.
        if (pointToAdd == nullptr) {
            //std::cout << "The Point you are trying to add cannot be added. " << std::endl;
            //std::cout << "This is because the argument passed in is a null pointer. " << std::endl;
        }
            // Test to see if the Linked List is empty, if so create a new Node that the points points to.
            // Then store the point address into that node, and make the LNodePtr next a null pointer.
        else if (size == 0) {
            //std::cout << "The cluster was empty adding a new point... " << std::endl;
            LNodePtr tempNode = new LNode();
            tempNode->p = pointToAdd;
            tempNode->next = nullptr;
            points = tempNode;
            size++;
        }
            //  The Linked list is not empty, so find where in the list the point belongs.
            //  If it is at the end set its next to nullptr.
        else {
            //std::cout << "The cluster was not empty, finding where to put the point now... " << std::endl;
            LNodePtr cursor = points;
            LNodePtr nextNode = points->next;
            // Does it need to be added at the points;
            if (*(cursor->p) > *pointToAdd) {
                // The point to add should be added at the top
                addAbove(pointToAdd, cursor);
            } else if (size == 1) {
                if (*(cursor->p) < *pointToAdd) {
                    addBottom(cursor, pointToAdd);
                } else {
                    // The value of the points are equal
                    // So test by value of memory address
                    if(cursor->p > pointToAdd){
                        addAbove(pointToAdd, cursor);
                    } else if (cursor->p < pointToAdd) {
                        addBottom(cursor, pointToAdd);
                    } else {
                        // Points are equal!!!
                    }
                }
            } else {
                bool shouldAdd = true;
                if (*(cursor->p) == *pointToAdd) {
                    if (pointToAdd < cursor->p) {
                        addAbove(pointToAdd, cursor);
                        shouldAdd = false;
                    } else if (cursor->p == pointToAdd) {
                        shouldAdd = false;
                    } else {
                        // Dont do anything
                    }
                }
                // The point should be added at the middle or end
                if (shouldAdd) {
                    while (nextNode->next != nullptr) {
                        if (*(nextNode->p) > *pointToAdd) {
                            addBetween(cursor, pointToAdd, nextNode);
                            shouldAdd = false;
                            break;
                        } else {
                            if(*pointToAdd == *(nextNode->p)) {
                                if (pointToAdd < nextNode->p) {
                                    addBetween(cursor, pointToAdd, nextNode);
                                    shouldAdd = false;
                                    break;
                                } else if (pointToAdd == nextNode->p) {
                                    // Points are equal
                                    shouldAdd = false;
                                    break;
                                } else {

                                }
                            }
                            cursor = cursor->next;
                            nextNode = nextNode->next;
                        }
                    }
                }
                if (shouldAdd) {
                    if (*pointToAdd > *(nextNode->p)){
                        addBottom(nextNode, pointToAdd);
                    } else if(*pointToAdd < *(nextNode->p)) {
                        addBetween(cursor, pointToAdd, nextNode);
                    } else {
                        if (pointToAdd < nextNode->p) {
                            addBetween(cursor, pointToAdd, nextNode);
                        } else if (pointToAdd == nextNode->p) {
                            // Dont do anything
                        } else {
                            addBottom(nextNode, pointToAdd);
                        }
                    }
                }
            }
        }
    }

    const PointPtr &Cluster::remove(const PointPtr &pointToDelete) {
        // If the cluster is empty dont do anything just pass point back
        if (points == nullptr){
            // just return the point so it can be added to the other cluster in case of c1.add(c2.remove())
            return pointToDelete;
        } else {
            // It is now safe to assume at least one node.
            LNodePtr cursor = points;
            if (size == 1 && cursor->p != pointToDelete) {
                return pointToDelete;
            } else if (size == 1 && cursor->p == pointToDelete) {
                // There is only one node and it is the one to delete
                cursor->next = nullptr;
                points = nullptr;
                size--;
                delete cursor;
                return pointToDelete;
            } else if (size > 1 && cursor->p == pointToDelete) {
                // There are more than one nodes and the first is the one to delete
                points = cursor->next;
                cursor->next = nullptr;
                size--;
                delete cursor;
                return pointToDelete;
            } else {
                // There are more than one nodes and the node to delete is not the first
                // The point may not be in the cluster as well.
                // Store a pointer to the previous point and move the cursor to the next point
                // Also create a pointer to hold the node to be removed;
                LNodePtr prevNode = cursor;
                cursor = cursor->next;

                // This loop starts at the second node
                while (cursor != nullptr) {
                    if (cursor->p == pointToDelete) {
                        LNodePtr pointToRemove = cursor;
                        cursor = cursor->next;
                        prevNode->next = cursor;
                        size--;
                        delete pointToRemove;
                        return pointToDelete;
                    } else {
                        prevNode = cursor;
                        cursor = cursor->next;
                    }
                }
                return pointToDelete;
            }
        }
    }

    void Cluster::addAbove(const PointPtr &pointToAdd, LNodePtr &nodeBelow) {
        LNodePtr nodeToAdd = new LNode();
        nodeToAdd->p = pointToAdd;
        nodeToAdd->next = nodeBelow;
        points = nodeToAdd;
        size++;
    }

    void Cluster::addBottom(LNodePtr &endNode, const PointPtr &pointToAdd) {
        LNodePtr nodeToAdd = new LNode();
        nodeToAdd->p = pointToAdd;
        nodeToAdd->next = nullptr;
        endNode->next = nodeToAdd;
        size++;
    }

    void Cluster::addBetween(LNodePtr &aboveNode, const PointPtr &pointToAdd, const LNodePtr &belowPoint) {
        LNodePtr nodeToAdd = new LNode();
        nodeToAdd->p = pointToAdd;
        nodeToAdd->next = belowPoint;
        aboveNode->next = nodeToAdd;
        size++;
    }

    std::ostream &operator<<(std::ostream &os, const Cluster &clusterToPrint) {
        // No instructions for how this should work have been given, currently set up for testing
        LNodePtr cursor = clusterToPrint.points;
        if (clusterToPrint.size == 0){
            std::cout << "This cluster is empty" << std::endl;
        }
        //std::cout << "This cluster contains the points:  " << std::endl;
        for(int i = 0; i < clusterToPrint.size; i++){
            std::cout << i + 1 << ". " << *(cursor->p);
            cursor = cursor->next;
        }
        return os;
    }

    std::istream &operator>>(std::istream &is, Cluster &cluster) {
        // IMPLEMENTATION INTENTIONALLY LEFT BLANK
        return is;
    }

    bool operator==(const Cluster &leftSide, const Cluster &rightSide) {
        if (leftSide.size  != rightSide.size)
            return false;

        LNodePtr leftCursor = leftSide.points;
        LNodePtr rightCursor = rightSide.points;
        while (leftCursor != nullptr && rightCursor != nullptr) {
            if (leftCursor->p != rightCursor->p){
                return false;
            } else {
                leftCursor = leftCursor->next;
                rightCursor = rightCursor->next;
            }
        }
        return true;
    }

    bool operator!=(const Cluster &leftSide, const Cluster &rightSide) {
        return !(leftSide == rightSide);
    }

    // Set Destructive: Will make the calling Cluster the UNION of both clusters
    Cluster &Cluster::operator+=(const Cluster &rightSide) {
        const Cluster tempCluster = *this;
        *this = tempCluster + rightSide;
        return *this;
    }

    // Set destructive: Will make calling Cluster the asymmetric difference.
    Cluster &Cluster::operator-=(const Cluster &rightSide) {
        const Cluster tempCluster = *this;
        *this = tempCluster - rightSide;
        return *this;
    }

    // Set preservative. Will add a new point to the Linked list with the values of rightSide.
    Cluster &Cluster::operator+=(const Point &rightSide) {
        PointPtr newPoint = new Point(rightSide);
        this->add(newPoint);
        return *this;
    }

    // Set preservative. Removes ALL points in the cluster with the same values as rightSide.
    Cluster &Cluster::operator-=(const Point &rightSide) {
        PointPtr newPoint = new Point(rightSide);
        LNodePtr cursor = points;
        while (cursor != nullptr){
            if (*(cursor->p) == rightSide){
                PointPtr pointToRemove = cursor->p;
                cursor = cursor->next;
                remove(pointToRemove);
            } else {
                cursor = cursor->next;
            }
        }
        delete newPoint;
        return *this;
    }

    // Set Destructive ALWAYS. Creates a cluster that contains all points in leftSide AND rightSide
    const Cluster operator+(const Cluster &leftSide, const Cluster &rightSide) {
        // UNION c1 = (p1, p3, p6) + c2 = (p4, p9, p12) then return c3 = (p1, p3, p4, p6, p9, p12)
        Cluster unionCluster(leftSide);
        LNodePtr cursor = rightSide.points;
        while (cursor != nullptr) {
            unionCluster.add(cursor->p);
            cursor = cursor->next;
        }
        return unionCluster;
    }

    // Set destructive ALWAYS. Creates a cluster with points only in the leftSide cluster NOT rightSide cluster
    const Cluster operator-(const Cluster &leftSide, const Cluster &rightSide) {
        Cluster asyDifCluster(leftSide);
        LNodePtr cursor = rightSide.points;
        while (cursor != nullptr){
            asyDifCluster.remove(cursor->p);
            cursor = cursor->next;
        }
        return asyDifCluster;
    }

    // Set destructive, iff the point is added to two clusters.
    const Cluster operator+(const Cluster &leftSide, const PointPtr &rightSide) {
        Cluster newCluster(leftSide);
        newCluster.add(rightSide);
        return newCluster;
    }

    // Set destructive: Returns a new Cluster with all points contained in leftSide, except the argument point.
    const Cluster operator-(const Cluster &leftSide, const PointPtr &rightSide) {
        Cluster newCluster(leftSide);
        newCluster.remove(rightSide);
        return newCluster;
    }
}