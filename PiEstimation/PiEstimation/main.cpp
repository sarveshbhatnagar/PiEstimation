//
//  main.cpp
//  PiEstimation
//
//  Created by Sarvesh Bhatnagar
//  Copyright © 2019 introtoalgo.com. All rights reserved.
//

#include <iostream>
#include <random>
#include <math.h>

/*
 Change lenSq to modify the length of the square
 arr len to modify # of samples
 */

#define lenSq 20
#define arrLen 10000
#define dev (lenSq/2)


using namespace std;

class Square{
    int length = lenSq;
    int centerX,centerY;
    short aX[arrLen];
    short aY[arrLen];
    int count = 0;
public:
    Square(int len) : centerX(0), centerY(0) {
        length = len;
    }
    bool setVal(int randomX, int randomY){
        if (count < arrLen) {
            aX[count] = randomX;
            aY[count] = randomY;
            count += 1;
            return true;
        }else{
            return false;
        }
    }
    
    void printCount(){
        cout<<count<<endl;
    }
    
    double checkSquare(){
        int inSquare(0) , inCircle(0);
        for (int i = 0; i<count; i++) {
            if (sqrt(pow(aX[i],2) + pow(aY[i],2)) < (length/2)) {
                inCircle +=1;
            }else{
                inSquare += 1;
            }
        }
        
        double pi = (double)inCircle/(double)inSquare;
        
        return pi;
    }
    
};


int main() {
    random_device a;
    int x = a()%lenSq;
    x = x - dev;
    int y = a()%lenSq;
    y = y - dev;
    Square mySquare(lenSq);
    while (mySquare.setVal(x, y)) {
        x = a()%lenSq;
        y = a()%lenSq;
        x -= dev;
        y -= dev;
    }
    
    cout<<"PI  "<<mySquare.checkSquare()<<endl;
    
    
    
    return 0;
}
