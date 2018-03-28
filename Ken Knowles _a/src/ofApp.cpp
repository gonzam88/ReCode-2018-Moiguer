#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.setup(320,240);
    
    
    bpmToMillis = 60000 / bpm;
    
    hh.load("hihat.wav");
    kick.load("kick");
    snare.load("snare.wav");
    snare.setVolume(.05);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    millisEllapsed += ofGetLastFrameTime() * 1000;

    playSound = false;
    
    if(millisEllapsed >= bpmToMillis){
        currBeat++;
        currBeat = currBeat & 7;
        millisEllapsed = 0;
        grabber.update();
        playSound = true;
    }
    
    //cout << currBeat << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    ofSetColor( 255 );
    
    grabber.draw(0,0);
    ofTranslate(640, 100);
    
    ofSetColor( 40 );
    
    ofPushMatrix();
    ofTranslate(currBeat * 40, 0);
    ofDrawRectangle(-10,-10, 25, 250);
    ofPopMatrix();
    for (int i = 0; i < grabber.getWidth(); i+=40){
        for (int j = 0; j < grabber.getHeight(); j+=70){
            ofColor pixel = grabber.getPixels().getColor(i,j);
            float brightness = pixel.getBrightness();
            
            ofPushMatrix();
            
            ofTranslate(i,j+10);
            
            int soundCat = round( ofMap(brightness, 0, 255, 0, 3) );
            ofSetColor(200);
            bool isThisBeat = i/40 == currBeat;
            switch(soundCat){
                case 0:
                    // NADA
                    break;
                case 1:
                    ofDrawCircle(0, 0, 5);
                    if(isThisBeat && playSound) snare.play();
                    
                    break;
                case 2:
                    ofDrawRectangle(0, 0, 10, 10);
                    if(isThisBeat && playSound) hh.play();
                    
                    break;
                case 3:
                    ofRotateZ(45);
                    ofDrawRectangle(0, 0, 10, 10);
                    if(isThisBeat && playSound) kick.play();
                    
                    break;
            }
            ofPopMatrix();
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
