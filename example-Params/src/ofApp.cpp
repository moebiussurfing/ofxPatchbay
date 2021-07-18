#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	gInput.add(pi1);
	gInput.add(pi2);
	gInput.add(pi3);
	gInput.add(pi4);
	
	gOutput.add(po1);
	gOutput.add(po2);
	gOutput.add(po3);
	gOutput.add(po4);

	patchbay.registerControllable1f("po1", [&](float value) {
		po1.set(value);
	});

	patchbay.registerControllable1f("po2", [&](float value) {
		po2.set(value);
	});

	patchbay.registerControllable1f("po3", [&](float value) {
		po3.set(value);
	});

	patchbay.registerControllable1f("po4", [&](float value) {
		po4.set(value);
	});

	rect = ofRectangle(0, 0, 100, 100);

	patchbay.connect1f("mouse-x", "po1");
	patchbay.connect1f("mouse-y", "po2");
	patchbay.connect1f("mouse-x", "po3");
	patchbay.connect1f("mouse-y", "po4");
	//patchbay.connect1f("mouse-btn", "po3");
	//patchbay.connect1f("mouse-btn-right", "po4");

	gui.setup();
	gui.add(gInput);
	gui.add(gOutput);

}

//--------------------------------------------------------------
void ofApp::update() {
	patchbay.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2 * po1, ofGetHeight() / 2 * po2);
	ofBackground(255 * po3);
	ofSetColor(color);
	scale = po4;
	ofDrawRectangle(rect.x - scale * rect.width / 2, rect.y - scale * rect.height, scale*rect.width, scale*rect.height);
	ofPopMatrix();

	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_BACKSPACE)
	{
		patchbay.disconnect1f("mouse-x", "po1");
		patchbay.disconnect1f("mouse-y", "po2");
		patchbay.disconnect1f("mouse-x", "po3");
		patchbay.disconnect1f("mouse-y", "po4");
	}
	if (key == '3')
	{
		patchbay.connect1f("mouse-x", "po4");
		patchbay.connect1f("mouse-y", "po3");
		patchbay.connect1f("mouse-x", "po2");
		patchbay.connect1f("mouse-y", "po1");
	}
	if (key == '1')
	{
		patchbay.connect1f("mouse-x", "po2");
		patchbay.connect1f("mouse-y", "po3");
		patchbay.connect1f("mouse-x", "po1");
		patchbay.connect1f("mouse-y", "po2");
	}
	if (key == '2')
	{
		patchbay.connect1f("mouse-x", "po1");
		patchbay.connect1f("mouse-y", "po2");
		patchbay.connect1f("mouse-x", "po4");
		patchbay.connect1f("mouse-y", "po3");
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
