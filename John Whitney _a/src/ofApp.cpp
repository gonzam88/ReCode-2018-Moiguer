#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    float t = ofGetElapsedTimef() * .2;
    ofPoint center(400,400);
    ofBackground(0);
    
    float maxRadius = 120;
    float minRadius = 60;
    float expansionSpeed = 2;
    float tToRadius = ofMap(sin(t * expansionSpeed) , -1, 1, maxRadius, minRadius);
    
    float dotCountSpeed = 7;
    int dotCount = ofMap(sin(t * dotCountSpeed), -1, 1, 100, 100);
    
    float petalos = ofMap(cos(t * 0.8), 1, -1, 1, 20); // Cantidad de petalos
    //ofPoint center(mouseX,mouseY);
    //ofPoint center(400, 400);
    ofSetLineWidth(10);
    float r = ofMap(sin(t), -1, 1, 0, 255);
    float b = ofMap(sin(t*1.2), -1, 1, 0, 255);
    float alphaLineaInversa = ofMap(sin(t), -1, 1, 255, 0);
    
    ofColor origColor (r,0,b);
    ofSetColor(origColor);
    for(int i = 0; i < dotCount; i++){
        
        float theta = ofMap(i, 0, dotCount-1, 0, TWO_PI) + (t * 0.01) + 1;
        float radius = ofMap( 5 * cos(petalos * theta), -1, 1, 0, tToRadius);
        
        // Draw the dots
        float x = radius * sin(theta) + center.x;
        float y = radius * cos(theta) + center.y;
        ofDrawCircle(x, y, 3);
        
        // Draw the lines
        float xa = (radius * 0.85) * sin(theta) + center.x;
        float ya = (radius * 0.85) * cos(theta) + center.y;
        
        float xb = (radius * 0.6) * sin(theta) + center.x;
        float yb = (radius * 0.6) * cos(theta) + center.y;
        ofDrawLine(xa, ya, xb, yb);
    }
    
    // Linea Inversa
    petalos = ofMap(cos(t * 0.8), 1, -1, 30, 7);
    ofColor complementaryColor = origColor.getInverted();
    complementaryColor.setBrightness(50);
    ofSetColor(complementaryColor);
    
    for(int i = 0; i < dotCount; i++){
        
        float theta  = ofMap(i, dotCount, 0, TWO_PI, 0) +  1;
        float radius = ofMap( 10 * cos(petalos * theta), -1, 1, tToRadius, 0);
        
        // Draw the dots
        float x = radius * sin(theta) + center.x;
        float y = radius * cos(theta) + center.y;
        //ofDrawCircle(x, y, 3);
        
        // Draw the lines
        float xa = (radius * 0.85) * sin(theta) + center.x;
        float ya = (radius * 0.85) * cos(theta) + center.y;
        
        float xb = (radius * 0.6) * sin(theta) + center.x;
        float yb = (radius * 0.6) * cos(theta) + center.y;
        ofDrawLine(xa, ya, xb, yb);
        
         xa = (radius * 5) * sin(theta) + center.x;
         ya = (radius * 5) * cos(theta) + center.y;
        
         xb = (radius * 2) * sin(theta) + center.x;
         yb = (radius * 2) * cos(theta) + center.y;
        ofDrawLine(xa, ya, xb, yb);
    }
    
    // Linea A por Encima (lissajous)
    //ofDrawCircle(lissajousPoint(, 5);
    float lisaSpeed = ofMap(sin(t * 0.3), -1, 1, 0.5, 2);
    ofSetColor(255,255,255);
    for(int i = 0; i < 10; i++){
        ofDrawLine( lissajousPoint(3.7+i, 3.5+1, t ), lissajousPoint(5.1+i, 2.7+1, t * lisaSpeed));
    }
    
    
    // Linea A por Encima (lissajous)
    //ofDrawCircle(lissajousPoint(, 5);
    for(int i = 0; i < 10; i++){
        ofDrawLine( lissajousPoint(7.2+i, 9.9+1, t ), lissajousPoint(8.1+i, 1.3+1, t * (3-lisaSpeed)));
    }
    
    
    
}

//--------------------------------------------------------------
ofPoint ofApp::lissajousPoint(float a, float b, float t){
    ofPoint pt;
    pt.x = ofMap(sin(t * a), -1, 1, 0, 800);
    pt.y = ofMap(sin(t * b), -1, 1, 0, 800);
    return pt;
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
    pointsAmount++;
    if(pointsAmount == 50){
        pointsAmount = 0;
    }
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
