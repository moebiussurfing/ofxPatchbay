#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	//patchbay = ofxPatchbay(false, false, false, false, true);

	// input params (controllers)
	gInput.add(pi1);
	gInput.add(pi2);
	gInput.add(pi3);
	gInput.add(pi4);
	gInput.add(bi5);
	gInput.add(bi6);

	// output params (targets)
	gOutput.add(po1);
	gOutput.add(po2);
	gOutput.add(po3);
	gOutput.add(po4);
	gOutput.add(bo5);
	gOutput.add(bo6);

	//-

	// define inputs
	patchbay.addParameter(pi1);
	patchbay.addParameter(pi2);
	patchbay.addParameter(pi3);
	patchbay.addParameter(pi4);
	patchbay.addParameter(bi5);
	patchbay.addParameter(bi6);
	patchbay.setupParameters();

	//-

	// define and name outputs
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
	patchbay.registerControllableB("bo5", [&](bool value) {
		bo5.set(value);
	});
	patchbay.registerControllableB("bo6", [&](bool value) {
		bo6.set(value);
	});

	//-

	// connect
	patchbay.connect1f("param-1", "po1");
	patchbay.connect1f("param-2", "po2");
	patchbay.connect1f("param-3", "po3");
	patchbay.connect1f("param-4", "po4");
	patchbay.connectB("param-5", "bo5");
	patchbay.connectB("param-6", "bo6");

	str2 = "";
	str2 += "1 -> 1 \n";
	str2 += "2 -> 2 \n";
	str2 += "3 -> 3 \n";
	str2 += "4 -> 4 \n";
	str2 += "5 -> 5 \n";
	str2 += "6 -> 6";

	//-

	// gui

	guiInput.setup("In");
	guiInput.add(gInput);

	guiOutput.setup("Out");
	guiOutput.add(gOutput);

	rect = ofRectangle(0, 0, 100, 100);
}

//--------------------------------------------------------------
void ofApp::update() {
	patchbay.update();

	guiInput.setPosition(10, 10);
	guiOutput.setPosition(ofGetWidth() - 200 - 10, 10);
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2 * po1, ofGetHeight() / 2 * po2);
	scale = po3;
	ofBackground(255 * po4);
	ofSetColor(color);
	ofDrawRectangle(rect.x - scale * rect.width / 2, rect.y - scale * rect.height, scale*rect.width, scale*rect.height);
	ofPopMatrix();

	// help
	string str1 = "";
	str1 += "RETURN PRINT CONNECTIONS \n";
	str1 += "BACKSPACE TO DISCONNECT ALL \n";
	str1 += "KEYS 1-2-3-4: SELECT PRESETS \n";
	ofDrawBitmapStringHighlight(str1, 20, ofGetHeight() / 2);

	// patching preset
	ofDrawBitmapStringHighlight(str2, ofGetWidth() - 70, ofGetHeight() / 2);
	
	guiInput.draw();
	guiOutput.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	// set configurations

	if (key == OF_KEY_RETURN) patchbay.printConnections();

	if (key == OF_KEY_BACKSPACE)
	{
		patchbay.disconnectAll();
	}
	if (key == '1')
	{
		patchbay.disconnectAll();
		
		patchbay.connect1f("param-1", "po1");
		patchbay.connect1f("param-2", "po2");
		patchbay.connect1f("param-3", "po3");
		patchbay.connect1f("param-4", "po4");
		patchbay.connectB("param-5", "bo5");
		patchbay.connectB("param-6", "bo6");

		str2 = "";
		str2 += "1 -> 1 \n";
		str2 += "2 -> 2 \n";
		str2 += "3 -> 3 \n";
		str2 += "4 -> 4 \n";
		str2 += "5 -> 5 \n";
		str2 += "6 -> 6";
	}
	if (key == '2')
	{
		patchbay.disconnectAll();

		patchbay.connect1f("param-1", "po4");
		patchbay.connect1f("param-2", "po3");
		patchbay.connect1f("param-3", "po2");
		patchbay.connect1f("param-4", "po1");
		patchbay.connectB("param-5", "bo6");
		patchbay.connectB("param-6", "bo5");

		str2 = "";
		str2 += "1 -> 4 \n";
		str2 += "2 -> 3 \n";
		str2 += "3 -> 2 \n";
		str2 += "4 -> 1 \n";
		str2 += "5 -> 6 \n";
		str2 += "6 -> 5";
	}
	if (key == '3')
	{
		patchbay.disconnectAll();

		patchbay.connect1f("param-1", "po3");
		patchbay.connect1f("param-2", "po4");
		patchbay.connect1f("param-3", "po1");
		patchbay.connect1f("param-4", "po2");
		patchbay.connectB("param-5", "bo5");
		patchbay.connectB("param-6", "bo6");

		str2 = "";
		str2 += "1 -> 3 \n";
		str2 += "2 -> 4 \n";
		str2 += "3 -> 1 \n";
		str2 += "4 -> 2 \n";
		str2 += "5 -> 5 \n";
		str2 += "6 -> 6";
	}
	if (key == '4')
	{
		patchbay.disconnectAll();

		patchbay.connect1f("param-1", "po2");
		patchbay.connect1f("param-2", "po1");
		patchbay.connect1f("param-3", "po4");
		patchbay.connect1f("param-4", "po3");
		patchbay.connectB("param-5", "bo6");
		patchbay.connectB("param-6", "bo5");

		str2 = "";
		str2 += "1 -> 2 \n";
		str2 += "2 -> 1 \n";
		str2 += "3 -> 4 \n";
		str2 += "4 -> 3 \n";
		str2 += "5 -> 6 \n";
		str2 += "6 -> 5";
	}
}