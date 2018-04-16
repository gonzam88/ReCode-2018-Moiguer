#pragma once

#include "ofMain.h"
#include "ofxMidi.h"

class ofApp : public ofBaseApp, public ofxMidiListener{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void newMidiMessage(ofxMidiMessage& eventArgs);
		
    ofEasyCam cam;
    
    ofPoint frames[30][24];
    
    ofxMidiIn midiIn;
    ofxMidiMessage midiMessage;
    
    int spheSize = 0;
    int matrixSize = 10;
    float camRotation;
    float camDist;
    float sphereThreshold;
    
    
    
};
