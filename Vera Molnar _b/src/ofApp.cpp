#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cellSize = 140;
    
    
    for(int x = 0; x < 4; x++){
        for(int y = 0; y < 4; y++){
            int i = y * 4 + x;
            // y * w + x
            originalVecPoints[i] = ofPoint((x * cellSize / 4),(y * cellSize / 4));
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(mySeed);
    ofBackground(50);
    int rows = 5;
    int cols = 5;
    
    for(int y = 0; y < cols; y++){
        for(int x = 0; x < rows; x++){
            
            if(y % 2 == 0){
                _x = x;
                lineaPar = true;
            }else{
                _x = rows - x -1;
                lineaPar = false;
            }
            cout << "_x: " << _x << endl;
            
            ofPushMatrix();
            
            ofTranslate(_x * cellSize * spacing + 20, y * cellSize * spacing + 20);
            
            // Just drawing the bg dots template
            if(debugPoints){
                ofSetColor(80,80,80);
                for(int i = 0; i < 16; i++){
                    ofDrawCircle (originalVecPoints[i], 1);
                }
            }
            
            
            ofSetColor(255,255,255);
            
            
            if(x == 0){
                if(y > 0){
                    //ofSetColor(255,0,255);
                    // New line
                    newVertex = round( ofRandom(0, 16));
                    ofPoint correctedLast = originalVecPoints[lastVertex];
                    correctedLast.y -= cellSize * spacing;
                    ofDrawLine(correctedLast, originalVecPoints[newVertex]);
                    lastVertex = newVertex;
                }
            }else{
                //ofSetColor(255,255,0);
                // I connect the previous drawing with the new one
                newVertex = round( ofRandom(0, 16));
                ofPoint correctedLast = originalVecPoints[lastVertex];
                if(lineaPar){
                    correctedLast.x -= cellSize * spacing;
                }else{
                    correctedLast.x += cellSize * spacing;
                }
                
                ofDrawLine(correctedLast, originalVecPoints[newVertex]);
                lastVertex = newVertex;
            }
            
            ofSetColor(255,255,255);
            // I draw all the lines for a new shape
            // Number of lines for this shape
            int numOfLines = round( ofRandom(7,12) );
            for(int i = 0; i < numOfLines; i++){
                if( lastVertex < 0 ){
                    lastVertex == round( ofRandom(0, 16));
                    cout << "NEW VERTEX" << endl;
                }
                if(i > 0){
                    newVertex = round( ofRandom(0, 16));
                }
                ofDrawLine(originalVecPoints[lastVertex], originalVecPoints[newVertex]);
                lastVertex = newVertex;
            }
            
            ofPopMatrix();
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    mySeed = (int)(ofGetElapsedTimef()*5);
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
