#pragma once

#include "ofMain.h"
#include "ofxPatchbay.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

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

    ofRectangle rect;
    float scale;
    ofColor color = ofColor(255,0,0);
    ofxPatchbay patchbay;

	ofParameter<float>pi1{ "pi1", 0, 0, 1 };
	ofParameter<float>pi2{ "pi2", 0, 0, 1 };
	ofParameter<float>pi3{ "pi3", 0, 0, 1 };
	ofParameter<float>pi4{ "pi4", 0, 0, 1 };

	ofParameter<float>po1{ "po1", 0, 0, 1 };
	ofParameter<float>po2{ "po2", 0, 0, 1 };
	ofParameter<float>po3{ "po3", 0, 0, 1 };
	ofParameter<float>po4{ "po4", 0, 0, 1 };

	ofxPanel gui;
	ofParameterGroup gInput{ "gInput" };
	ofParameterGroup gOutput{ "gOutput" };


};
