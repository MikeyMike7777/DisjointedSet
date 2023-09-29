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

#include <iostream>
#include <cmath>
#include "DisjointedSet.h"

using namespace std;


/* main
*  parameters:
*      argc -- the number of arguments from the command line
*      argv -- the command line argument values
*  return value: 0 (indicating a successful run)
*
* This function uses a disjointedSet and Point class to find constellations
* from a set of stars and their locations in multiple test cases.
*/
int main() {
    int tests, stars;
    double x, y, topDistance, distX, distY, distance;
    Point p;
    vector<Point> points;
    disjointSet set;
    
    cin >> tests;
    
    //get test sets
    for(int i = 0; i < tests; i++){
        cin >> stars;
        cin >> topDistance;
        set.initSet(stars);
        //fill vector star locations
        for(int j = 0; j < stars; j++){
            cin >> x;
            p.setX(x);
            cin >> y;
            p.setY(y);
            points.push_back(p);
        }
        //go through each star
        for(int j = 0; j < stars; j++){
            //check each star if not already in the same set
            for(int k = 0; k < stars; k++){
                if(!set.isSameSet(j, k)){
                    //calculate distance
                    distX = points[k].getX() - points[j].getX();
                    distX *= distX;
                    distY = points[k].getY() - points[j].getY();
                    distY *= distY;
                    distance = sqrt(distX+distY);
                    //if star is less than distance to other star, union sets
                    if(distance < topDistance){
                        set.unionSet(j, k);
                    }
                }
            }
        }
        points.clear();
        cout << "Case" << i+1 << ": " << set.countSets(stars) << endl;
    }
    
    return 0;
}





