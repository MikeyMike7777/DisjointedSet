/*
Author: Michael Mathews
Assignment Title: Assignment 9.1
Assignment Description: Find the constellations based on the closest of stars.
 To find constellations, use a disjointed set and output how many
 constellations are in each test case.
Due Date: 10/31/22
Date Created: 10/31/22
Date Last Modified: 10/31/22
*/

//No changes made to this file from what was provided
//Only addition was defining and settig value for const int MAX_STARS

#ifndef DisjointedSet_h
#define DisjointedSet_h

#include <vector>
using namespace std;

const int MAX_STARS = 1000;

class disjointSet{
private:
    vector<int> pset;
public:
    disjointSet(){
        pset.assign(MAX_STARS, 0);
    }
    void initSet(int N){
        for(size_t i = 0; i < N; i++){
            pset[i] = i;
        }
    }
    int findSet(int i){
        if(pset[i] == i){
            return i;
        }
        else{
            return (pset[i]=findSet(pset[i]));
        }
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        pset[findSet(i)] = findSet(j);
    }
    int countSets(int N){
        int count = 0;
        for (size_t i = 0; i < N; i++) {
            if(pset[i] == i) {
                count++;
            }
        }
        return count;
    }
};


class Point {
private:
    double x, y;
public:
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void setX(int point){
        x = point;
    }
    void setY(int point){
        y = point;
    }
};

#endif /* DisjointedSet_h */
