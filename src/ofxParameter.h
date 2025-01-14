
#ifndef ofxParameter_h
#define ofxParameter_h

#include "ofMain.h"

///*
class ofxParameterFloats {
public:
	ofxParameterFloats();
	~ofxParameterFloats();

	vector<ofParameter<float>> parameters;
	void addParameter(ofParameter<float>& param);

	ofParameterGroup params{ "Params" };
	void Changed_params(ofAbstractParameter &e);

	int getSize() {
		return parameters.size();
	}
};
//*/

class ofxParameterBools{
public:
	ofxParameterBools();
	~ofxParameterBools();

	vector<ofParameter<bool>> parameters;
	void addParameter(ofParameter<bool>& param);

	ofParameterGroup params{ "Params" };
	void Changed_params(ofAbstractParameter& e);

	int getSize() {
		return parameters.size();
	}
};


/*
class ofxParameterAbs{
public:
	ofxParameterAbs();
	~ofxParameterAbs();

	vector<ofAbstractParameter> parameters;
	void addParameter(ofAbstractParameter& param);

	ofParameterGroup params{ "Params" };
	void Changed_params(ofAbstractParameter& e);

	int getSize() {
		return parameters.size();
	}
};
*/


#endif /* ofxParameter_h */
