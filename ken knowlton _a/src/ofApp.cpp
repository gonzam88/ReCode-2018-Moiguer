#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("Helvetica", 100, true,true,true);
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(48, 39, 40);
}

//--------------------------------------------------------------
void ofApp::update(){
    string st;
    st = "T";
    float ran = ofRandom(1);
    if( ran > 0.6){
      st = "E";
    }else if (ran > 0.3){
      st = "L";
    }
    
    font.drawString(st, ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
    
}

//--------------------------------------------------------------
void ofApp::draw(){

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
