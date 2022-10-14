#include "ofxParameter.h"

///*
ofxParameterFloats::ofxParameterFloats() {
	ofAddListener(params.parameterChangedE(), this, &ofxParameterFloats::Changed_params); // setup()
}

ofxParameterFloats::~ofxParameterFloats() {
	ofRemoveListener(params.parameterChangedE(), this, &ofxParameterFloats::Changed_params); // exit()
}

void ofxParameterFloats::addParameter(ofParameter<float>& param) {
	parameters.push_back(param);

	params.add(param);
}

void ofxParameterFloats::Changed_params(ofAbstractParameter &e)
{
	string name = e.getName();
	ofLogNotice() << "Changed: " << name << " : " << e;

	//if (name == p.getName())
	//{
	//}
}
//*/


ofxParameterBools::ofxParameterBools() {
	ofAddListener(params.parameterChangedE(), this, &ofxParameterBools::Changed_params); // setup()
}

ofxParameterBools::~ofxParameterBools() {
	ofRemoveListener(params.parameterChangedE(), this, &ofxParameterBools::Changed_params); // exit()
}

void ofxParameterBools::addParameter(ofParameter<bool>& param) {
	parameters.push_back(param);

	params.add(param);
}

void ofxParameterBools::Changed_params(ofAbstractParameter& e)
{
	string name = e.getName();
	ofLogNotice() << "Changed: " << name << " : " << e;

	//if (name == p.getName())
	//{
	//}
}



/*
ofxParameterAbs::ofxParameterAbs() {
	ofAddListener(params.parameterChangedE(), this, &ofxParameterAbs::Changed_params); // setup()
}

ofxParameterAbs::~ofxParameterAbs() {
	ofRemoveListener(params.parameterChangedE(), this, &ofxParameterAbs::Changed_params); // exit()
}

void ofxParameterAbs::addParameter(ofAbstractParameter& param) {
	parameters.push_back(param);

	params.add(param);
}

void ofxParameterAbs::Changed_params(ofAbstractParameter& e)
{
	string name = e.getName();
	ofLogNotice() << "Changed: " << name << " : " << e;

	//if (name == p.getName())
	//{
	//}
}
*/