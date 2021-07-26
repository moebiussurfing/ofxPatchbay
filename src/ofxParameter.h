
#ifndef ofxParameter_h
#define ofxParameter_h

#include "ofMain.h"

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


#endif /* ofxParameter_h */
