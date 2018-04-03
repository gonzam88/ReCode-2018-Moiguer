#include "ofApp.h"
#include "data.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 24; j++){
            float x = data3d[ i * 24 * 3  + j * 3 + 0 ];
            float y = data3d[ i * 24 * 3  + j * 3 + 1 ];
            float z = data3d[ i * 24 * 3  + j * 3 + 2 ];
            frames[i][j].set(x,y,z);
        }
    }
    
    for(int i = 0; i < 24; i++){
        indicesShuffle.push_back(i);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    // you don't have to touch this either:)
    //----------------------------- copy data into array
    ofPoint data3d[24];
    
    int frameNumber =(int)(ofGetFrameNum()*0.4) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[ frameNumber][i];
    }
    
    cam.begin();
    cam.enableOrtho();
    
    
    ofSetColor(255);
    
    for (int i = 0; i < 24; i++){
        
        
        
        //ofDrawLine(data3d[i], data3d[0]);
        //ofDrawSphere(data3d[i], 0.5);
        
        //        float x = data3d[i].x;
        //        float y = data3d[i].y;
        //        float z = data3d[i].z;
        //        z += ofSignedNoise(x*0.01, y*0.01, time) * ofMap(sin(time), -1, 1, 0, 400);
        //
        //        ofDrawSphere(ofPoint(x,y,z), 5);
        
        //ofDrawBitmapString(ofToString(i), data3d[i]);
    }
    
    for(int j = 0; j < 3; j++){
        vector<ofPoint> randomPoints;
        
        for(int i = 0; i < 3; i++){
            int which = ofRandom(0, 24);
            randomPoints.push_back( data3d[which] );
            
            indicesShuffle.erase(indicesShuffle.begin() + which);
            indicesShuffle.push_back(which);
        }
        
        ofDrawTriangle(randomPoints[0].x, randomPoints[0].y, randomPoints[1].x, randomPoints[1].y, randomPoints[2].x, randomPoints[2].y);
    }
    
    
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
