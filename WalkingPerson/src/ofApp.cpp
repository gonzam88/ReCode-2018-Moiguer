#include "ofApp.h"
#include "data.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    midiIn.openPort("LPD8");
    // add ofApp as a listener
    midiIn.addListener(this);
    
    // print received messages to the console
    midiIn.setVerbose(true);
    //----------------------------------------------------------------
    // the data is stored in a big flat array, let's copy it into something more managable
    // don't have to touch this :)
    
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 24; j++){
            float x = data3d[ i * 24 * 3  + j * 3 + 0 ];
            float y = data3d[ i * 24 * 3  + j * 3 + 1 ];
            float z = data3d[ i * 24 * 3  + j * 3 + 2 ];
            frames[i][j].set(x,y,z);
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
//
//    Im taking the MIDI part off so that the sketch is automated
//
//    cout << ofxMidiMessage::getStatusString(midiMessage.status) << endl;
//
//    if( midiMessage.control == 1){
//        spheSize = midiMessage.value;
//    }else if(midiMessage.control == 2){
//        matrixAmount = ofMap( midiMessage.value, 0 ,127, 0, 30);
//    }else if(midiMessage.control == 5){
//        camRotation = ofMap(midiMessage.value, 0, 127, 0, TWO_PI);
//    }else if(midiMessage.control == 6){
//        sphereThreshold = ofMap(midiMessage.value, 0, 127, 1, 200);
//    }
    
    float t = ofGetElapsedTimef();
    
    matrixSize = ofMap( sin(t * 0.53), -1, 1, 5, 20);
    camRotation = ofMap( sin(t * 0.32), -1, 1, 0, TWO_PI);
    sphereThreshold = ofMap( sin(t * 0.47), -1, 1, 5, 200);
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
    
    
    // end do not touch
    
    
    //    //----------------------------- 3d
    cam.begin();
    cam.enableOrtho();
    
    float radio = 1000;
    float theta = camRotation;
    float camx = radio * cos(theta);
    float camz = radio * sin(theta);
    float camy = radio * sin(theta);
    cam.setPosition( ofPoint(camx, camy, camz));
    cam.lookAt(ofPoint(0,0,0));
    
    ofSetColor(255);
    
    float time = ofGetElapsedTimef();
    
    for (int i = 0; i < 24; i++){
        
        
        
        //ofDrawLine(data3d[i], data3d[0]);
        ofDrawSphere(data3d[i], spheSize);
        
        //        float x = data3d[i].x;
        //        float y = data3d[i].y;
        //        float z = data3d[i].z;
        //        z += ofSignedNoise(x*0.01, y*0.01, time) * ofMap(sin(time), -1, 1, 0, 400);
        //
        //        ofDrawSphere(ofPoint(x,y,z), 5);
        
        //ofDrawBitmapString(ofToString(i), data3d[i]);
    }
    
    ofSetSphereResolution(5);
    
    for (int x = 0; x < matrixSize; x++){
        for (int y = 0; y < matrixSize; y++){
            for (int z = 0; z < matrixSize; z++){
//                ofVec3f pt(x,y,z);
//                pt -= ofVec3f(5,5,5);
//                pt *= 40;
//                ofDrawCircle(pt, 0.5);
                
                float xpos = ofMap(x, 0, matrixSize, -200, 200);
                float ypos = ofMap(y, 0, matrixSize, -200, 200);
                float zpos = ofMap(z, 0, matrixSize, -200, 200);
                ofVec3f pt(xpos,ypos,zpos);
                
                float d = pt.distance(data3d[0]);
                
                for (int i = 0; i < 24; i++){
                    float tempD = pt.distance(data3d[i]);
                    if(tempD < d){
                        d = tempD;
                    }
                }
                ofDrawSphere(pt, ofMap(d, 0, sphereThreshold, 5, 0.2, true));
                
            }
        }
    }
    
    //ofCircle(data3d[18], 10);
    
    
    cam.end();
}


//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& msg) {
    
    // make a copy of the latest message
    midiMessage = msg;
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
