#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    // Busco el ID del microscopio y lo seteo
    vector<ofVideoDevice> devices = microscope.listDevices();
    int myDeviceId = 0;
    for(int i = 0; i < devices.size(); i++){
        if(devices[i].deviceName == "Teslong Camera"){ // Microscope device name
            myDeviceId = i;
            break;
        }
    }
    microscope.setDeviceID(myDeviceId);
    microscope.setup(1280, 720); // Default microscope resolution
    
    // Circle points
    int cres = 100; //circle resolution
    for (int i = 0; i < cres; i++) {
        float angle = ofMap(i, 0, cres, 0, 2 * PI);
        float x = ofGetHeight()/2 * cos(angle);
        float y = ofGetHeight()/2 * sin(angle) ;
        ofPoint temp(x,y);
        circleVectors.push_back(temp);
    }
    
    ofSetFullscreen(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    microscope.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    // draw the miscroscope webcam
    float heightRatio = ofGetHeight() / 720.0;
    microscope.draw(0, 0, 1280 * heightRatio, ofGetHeight() );
    
    // Draw the circle cutout
    ofSetColor(0);
    
    ofBeginShape();
    // First a square shape
        ofVertex(0, 0);
        ofVertex(ofGetWidth(), 0);
        ofVertex(ofGetWidth(), ofGetHeight());
        ofVertex(0, ofGetHeight());
        // Make new shape (which substracts from square)
        ofNextContour();

    
        // Draw circle points
        float Xoffset = ofGetWidth() / 2;
        float Yoffset = ofGetHeight() / 2;
        for(int i = 0; i < circleVectors.size(); i++){
            ofVertex(circleVectors[i].x + Xoffset,
                     circleVectors[i].y + Yoffset);
        }

    ofEndShape();
    
    ofSetColor(100);
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
