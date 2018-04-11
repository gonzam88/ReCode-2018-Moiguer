#include "ofApp.h"
#include "data.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(10);
    
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
    
    ofPoint data3d[24];
    
    int frameNumber =(int)(ofGetFrameNum()*0.4) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[ frameNumber][i];
    }
//    
//    
//    [24, 57, 13]
//    
//    [12, 65, 23]
    
    trianglesInThisFrame.clear();
    
    int trianglesAmountPerFrame = 1;
    
    for(int j = 0; j < trianglesAmountPerFrame; j++){
        triangle tempTri;
        cout << j << endl;
        if(trianglesInThisFrame.size() > trianglesAmountPerFrame-1){
            cout << j << endl;
//            cout << trianglesInThisFrame[j].points << endl;
            tempTri.points[0] = trianglesInThisFrame[j].points[1];
            tempTri.points[1] = trianglesInThisFrame[j].points[2];
            tempTri.points[2] = data3d[(int)ofRandom(0, 24)];
        }else{
        
        
            for(int i = 0; i < 3; i++){
                
                int which = ofRandom(0, 24);
                tempTri.points.push_back( data3d[which] );
            
                indicesShuffle.erase(indicesShuffle.begin() + which);
                indicesShuffle.push_back(which);
            
            }
        
        }
        
        trianglesInThisFrame.push_back(tempTri);
        
        //ofDrawTriangle(randomPoints[0].x, randomPoints[0].y, randomPoints[1].x, randomPoints[1].y, randomPoints[2].x, randomPoints[2].y);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    // you don't have to touch this either:)
    //----------------------------- copy data into array
    
    
    cam.begin();
    //cam.enableOrtho();
    
    
    ofSetColor(255);
    
    //for (int i = 0; i < 24; i++){
        
        
        
        //ofDrawLine(data3d[i], data3d[0]);
        //ofDrawSphere(data3d[i], 0.5);
        
        //        float x = data3d[i].x;
        //        float y = data3d[i].y;
        //        float z = data3d[i].z;
        //        z += ofSignedNoise(x*0.01, y*0.01, time) * ofMap(sin(time), -1, 1, 0, 400);
        //
        //        ofDrawSphere(ofPoint(x,y,z), 5);
        
        //ofDrawBitmapString(ofToString(i), data3d[i]);
    //}
    
    
    if( history.size() > 1){
        
        for( int i = history.size()-1; i >= 0; i-- ){ // frame of history
            ofSetColor(ofMap(i, 0, maxHistory, 255, 0));
            
           for(int j = 0; j < history[i].size(); j++){
               
                ofDrawTriangle(
                   history[history.size() - 1- i][j].points[0].x, history[history.size() - 1- i][j].points[0].y, (i+1)*50,
                   history[history.size() - 1- i][j].points[1].x, history[history.size() - 1- i][j].points[1].y, (i+1)*50,
                   history[history.size() - 1- i][j].points[2].x, history[history.size() - 1- i][j].points[2].y, (i+1)*50);
            }
            
            
        }
        
    }
    
    ofSetColor(255);
    
    for(int i = 0; i < trianglesInThisFrame.size(); i++){
        
        ofDrawTriangle(
           trianglesInThisFrame[i].points[0].x, trianglesInThisFrame[i].points[0].y,
           trianglesInThisFrame[i].points[1].x, trianglesInThisFrame[i].points[1].y,
           trianglesInThisFrame[i].points[2].x, trianglesInThisFrame[i].points[2].y);
        
    }
    
    
    
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(history.size() > maxHistory){
        // if history is too big, erase first (which is oldest)
        history.erase( history.begin() );
    }
    // Save current triangles
    history.push_back(trianglesInThisFrame);

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
