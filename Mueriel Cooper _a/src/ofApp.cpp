#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("Helvetica.ttc", 30, true, true, true);
    
    for(int i = 0; i < (sizeof(letras)/sizeof(letras[0])); i++){
        letras[i].position.x = ofRandom(0, ofGetWidth());
        letras[i].position.y = ofRandom(0, ofGetWidth());
        letras[i].letra;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < (sizeof(letras)/sizeof(letras[0])); i++){
        font.drawString("A", letras[i].position.x, letras[i].position.y);
    }
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
