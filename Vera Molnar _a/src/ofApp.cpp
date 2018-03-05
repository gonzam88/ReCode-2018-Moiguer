#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(192, 192, 192, 0.5);
    
    ofSeedRandom(0);
    
    float cellSpace = 100;
    float sqSize = 80;
    float offset = 10;
    ofSetColor(0);
    ofTranslate(100, 50);
    float rndmSpeed = 0.1;
    ofSetLineWidth(0.1);
    
    
    for(int x = 0; x < 6; x++){
        for(int y = 0; y < 6; y++){
            if( y == 0 && (x == 0 || x == 1 || x == 2 || x == 3) ) continue;
            
            int maxRep = 100;
            
            
            float repetitions = 1 - (float)y / 5;
            repetitions = pow( repetitions, 3);
            repetitions *= maxRep;
            repetitions++;
            
            
            for(int i = 0; i < (int)repetitions; i++ ){
            
                ofPoint a(x * cellSpace + offset, y * cellSpace + offset);
                ofPoint b(x * cellSpace + offset + sqSize, y * cellSpace + offset);
                ofPoint c(x * cellSpace + offset + sqSize , y * cellSpace + offset + sqSize );
                ofPoint d(x * cellSpace + offset , y * cellSpace + offset + sqSize);
                
                rndmSpeed = ofMap(y, 0, 5, 0.5, 0.1);
                
                ofPoint center = (a + b + c + d) / 4.0;
                
//                float randomOffset = ofRandom(0.5, 1.5);
//                a = center + (a-center) * randomOffset;
//                randomOffset = ofRandom(0.5, 1.5);
//                b = center + (b-center) * randomOffset;
//                randomOffset = ofRandom(0.5, 1.5);
//                c = center + (c-center) * randomOffset;
//                randomOffset = ofRandom(0.5, 1.5);
//                d = center + (d-center) * randomOffset;
                
                
                a.x = a.x + (ofRandom(-mouseY,mouseY) * rndmSpeed );
                b.x = b.x + (ofRandom(-mouseY,mouseY) * rndmSpeed );
                c.x = c.x + (ofRandom(-mouseY,mouseY) * rndmSpeed );
                d.x = d.x + (ofRandom(-mouseY,mouseY) * rndmSpeed );

                a.y = a.y + (ofRandom(-mouseX,mouseX) * rndmSpeed );
                b.y = b.y + (ofRandom(-mouseX,mouseX) * rndmSpeed );
                c.y = c.y + (ofRandom(-mouseX,mouseX) * rndmSpeed );
                d.y = d.y + (ofRandom(-mouseX,mouseX) * rndmSpeed );

                ofDrawLine(a,b);
                ofDrawLine(b,c);
                ofDrawLine(c,d);
                ofDrawLine(d,a);
            }
        }
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
