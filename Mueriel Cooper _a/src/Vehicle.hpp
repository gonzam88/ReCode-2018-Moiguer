//
//  Vehicle.hpp
//  Mueriel Cooper _a
//
//  Created by gonza m on 3/21/18.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include "ofMain.h"

class Vehicle{
public:
    string character;
    char letra;
    ofPoint position;
    ofPoint rotation;
    ofPoint velocity;
    ofPoint acceleration;
    
    float maxSpeed;
    void Seek(ofPoint target);
};

#endif /* Vehicle_hpp */
