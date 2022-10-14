//
//  ofxPatchbayInput.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#ifndef ofxPatchbayInput_h
#define ofxPatchbayInput_h

#include <iostream>
#include "ofxParameter.h"

using namespace std;

class ofxPatchbay;

class ofxPatchbayInput {

public:

	void registerInputs(ofxPatchbay* patchbay);

	// ofParams
	void registerParams(ofxPatchbay* patchbay);
	void unregisterParams(ofxPatchbay* patchbay);

	void addParameter(ofParameter<float>& param) {
		parameters.addParameter(param);
	}

	void addParameter(ofParameter<bool>& param) {
		parametersB.addParameter(param);
	}

protected:

	ofxParameterFloats parameters;
	ofxParameterBools parametersB;
	//ofxParameterAbs parameters;
};

#endif /* ofxPatchbayInput_h */
