//
//  ofxPatchbay.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#ifndef ofxPatchbay_h
#define ofxPatchbay_h

#include <iostream>
#include <map>
#include <set>
#include "ofMain.h"
#include "ofxPatchbayInput.h"

using namespace std;

class ofxPatchbay 
{
public:

	//TODO:
	ofxPatchbay();

	void update();
	void registerAllInputs();

	void connectB(string controller, string controllable);
	void disconnectB(string controller, string controllable);

	void connect1f(string controller, string controllable);
	void connect2f(string controller, string controllable);

	void disconnect1f(string controller, string controllable);
	void disconnect2f(string controller, string controllable);

	void disconnectAll();
	void disconnectAll1f();
	void disconnectAll2f();
	void disconnectAllB();

	void registerControllableB(string, function<void(bool)>);
	void registerControllerB(string, function<bool()>);

	void registerControllable1f(string, function<void(float)>);
	void registerController1f(string, function<float()>);

	void registerControllable2f(string, function<void(ofVec2f)>);
	void registerController2f(string, function<ofVec2f()>);

	void print();
	void printConnections();
	void print1f();
	void print2f();
	void printB();

	string getConnections();

	// ofParameters
	void addParameter(ofParameter<float>& param) {
		input.addParameter(param);
	}
	void addParameter(ofParameter<bool>& param) {
		input.addParameter(param);
	}

	void setupParameters() {
		input.registerParams(this);
	}
	void clearParameters() {
		input.unregisterParams(this);
	}

protected:
	map<string, set<string>> connectionsB;
	map<string, set<string>> connections1f;
	map<string, set<string>> connections2f;

	map<string, function<void(bool)>> controllableB;
	map<string, function<bool()>> controllerB;

	map<string, function<void(float)>> controllable1f;
	map<string, function<float()>> controller1f;

	map<string, function<void(ofVec2f)>> controllable2f;
	map<string, function<ofVec2f()>> controller2f;

	ofxPatchbayInput input;


	//----


	vector<ofParameter<float>> paramsControllers;
	vector<ofParameter<float>> paramsTargets;

public:

	//--------------------------------------------------------------
	void addController(ofParameter<float>& param) {
		paramsControllers.push_back(param);
		addParameter(paramsControllers.back());
	}

	//--------------------------------------------------------------
	void addTarget(ofParameter<float>& param) {
		paramsTargets.push_back(param);

		// define and name outputs
		registerControllable1f(param.getName(), [&](float value) {
			param.set(value);
			});
	}

	//--------------------------------------------------------------
	void link(int indexControlller, int indexTarget) {
		if (indexControlller > paramsControllers.size() - 1 || indexTarget > paramsTargets.size() - 1)
		{
			ofLogError(__FUNCTION__) << "Out of range index for controller or target";
			return;
		}

		connect1f(paramsControllers[indexControlller].getName(), paramsTargets[indexTarget].getName());
		ofLogWarning(__FUNCTION__) << "Link: " << indexControlller << ", " << indexTarget;
	}

	//--------------------------------------------------------------
	void unlink(int indexControlller, int indexTarget) {
		if (indexControlller > paramsControllers.size() - 1 || indexTarget > paramsTargets.size() - 1)
		{
			ofLogError(__FUNCTION__) << "Out of range index for controller or target";
			return;
		}

		disconnect1f(paramsControllers[indexControlller].getName(), paramsTargets[indexTarget].getName());
		ofLogWarning(__FUNCTION__) << "Unlink: " << indexControlller << ", " << indexTarget;
	}
};

#endif /* ofxPatchbay_h */
