#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    /*
    
    float t = ofGetElapsedTimef() * .2;
    float angle = ofMap(t, 0, 1, 0, TWO_PI);
    float radius = ofMap( 3 * cos(3 * angle), -1, 1, 0, 100);
    ofPoint center(400,400);
    
    float x = radius * sin(angle) + center.x;
    float y = radius * cos(angle) + center.y;
    
    ofDrawCircle(x, y, 5);
    line.addVertex(x, y);
    
    //ofDrawCircle( line.getPointAtPercent(0).x, line.getPointAtPercent(0).y, 5);
    
    if(line.size() > 300){
        line.getVertices().erase(line.getVertices().begin());
    }
    line.draw();
     */
    
    ofBackground(0);
    
    //int dotCount = 100;
    
    
    float t = ofGetElapsedTimef() * .2;
    
    float maxRadius = 120;
    float minRadius = 60;
    float expansionSpeed = 2;
    float tToRadius = ofMap(sin(t * expansionSpeed) , -1, 1, maxRadius, minRadius);
    
    float dotCountSpeed = 7;
    int dotCount = ofMap(sin(t * dotCountSpeed), -1, 1, 100, 100);
    
    float coso = ofMap(cos(t * 0.8), 1, -1, 1, 20);
    //ofPoint center(mouseX,mouseY);
    ofPoint center(400, 400);
    
    float r = ofMap(sin(t), -1, 1, 0, 255);
    float b = ofMap(sin(t*1.2), -1, 1, 0, 255);
    ofSetColor(r,0,b);
    
    for(int i = 0; i < dotCount; i++){
        
        float theta = ofMap(i, 0, dotCount-1, 0, TWO_PI) + (t * 0.4);
        float radius = ofMap( 3 * cos(coso * theta), -1, 1, 0, tToRadius);
        
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
    
    // Linea A por Encima (lissajous)
    //ofDrawCircle(lissajousPoint(, 5);
    float g = ofMap(sin(t*2), -1, 1, 0, 255);
    ofSetColor(0,g,0);
    for(int i = 0; i < 10; i++){
        ofDrawLine( lissajousPoint(3.7+i, 3.5+1, t ), lissajousPoint(5.1+i, 2.7+1, t));
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
