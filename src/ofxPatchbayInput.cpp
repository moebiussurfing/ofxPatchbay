//
//  ofxPatchbayInput.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#include "ofxPatchbayInput.h"
#include "ofxPatchbay.h"

//TODO:
void ofxPatchbayInput::registerInputs(ofxPatchbay* patchbay) {
	//	registerParam(patchbay);
}

// ofParameters

void ofxPatchbayInput::registerParams(ofxPatchbay* patchbay) {
	for (int i = 0; i < parameters.getSize(); ++i) {
		string name = "param-" + ofToString(i + 1);
		patchbay->registerController1f(name, [&, i] {
			return parameters.parameters[i].get();
			});
	}

	for (int i = 0; i < parametersB.getSize(); ++i) {
		int sz = parameters.getSize();
		int ii = sz + (i + 1);
		string name = "param-" + ofToString(ii);
		patchbay->registerControllerB(name, [&, i] {
			return parametersB.parameters[i].get();
			});
	}

	//	/*
	//	if (p.type() == typeid(ofParameter<float>).name())
	//	{
	//		ofParameter<float> pm = p.cast<float>();
	//		ofLogNotice() << " type:float value:" << pm.get();
	//	}
	//	else if (p.type() == typeid(ofParameter<int>).name())
	//	{
	//		ofParameter<int> pm = p.cast<int>();
	//		ofLogNotice() << " type:int value:" << pm.get();
	//	}
	//	else if (p.type() == typeid(ofParameter<bool>).name())
	//	{
	//		ofParameter<bool> pm = p.cast<bool>();
	//		ofLogNotice() << " type:bool state: " << (pm.get() ? " TRUE" : " FALSE");
	//	}
	//	*/
	//}
}

void ofxPatchbayInput::unregisterParams(ofxPatchbay* patchbay) {
	//TODO:
	// Add unregister to allow adding new params on runtime...
	//for (int i = 0; i < parameters.getSize(); ++i) {
	//	string name = "param-" + ofToString(i+1);
	//	patchbay->registerController1f(name, [&, i] {
	//		return parameters.parameters[i].get();
	//	});
	//}
}
