//
//  ofxPatchbayInput.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#ifndef ofxPatchbayInput_h
#define ofxPatchbayInput_h

#include <iostream>
#include "ofxMidiInput.h"
#include "ofxMouseInput.h"
#include "ofxKeyboardInput.h"
#include "ofxAudioInput.h"
#include "ofxParameter.h"

using namespace std;

class ofxPatchbay;

class ofxPatchbayInput {

public:
    void registerInputs(ofxPatchbay *patchbay, bool kb, bool mouse, bool midi, bool audio, bool bparam);
    void registerKeyboardInputs(ofxPatchbay *patchbay);
    void registerMouseInputs(ofxPatchbay *patchbay);
    void registerMidiInputs(ofxPatchbay *patchbay);
    void registerAudioInputs(ofxPatchbay *patchbay);

	// ofParams
    void registerParams(ofxPatchbay *patchbay);
    void unregisterParams(ofxPatchbay *patchbay);

	void addParameter(ofParameter<float>& param) {
		parameters.addParameter(param);
	}

protected:

    ofxMidiInput midi;
    ofxMouseInput mouse;
    ofxKeyboardInput keyboard;
    ofxAudioInput audio;

    //ofxParameterAbs parameters;
    ofxParameterFloats parameters;
};

#endif /* ofxPatchbayInput_h */
