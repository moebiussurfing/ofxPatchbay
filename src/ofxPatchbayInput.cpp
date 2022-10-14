//
//  ofxPatchbayInput.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#include "ofxPatchbayInput.h"
#include "ofxPatchbay.h"

void ofxPatchbayInput::registerInputs(ofxPatchbay* patchbay, bool kb, bool mouse, bool midi, bool audio, bool bparam) {
	if (kb) {
		registerKeyboardInputs(patchbay);
	}
	if (mouse) {
		registerMouseInputs(patchbay);
	}
	if (midi) {
		registerMidiInputs(patchbay);
	}
	if (audio) {
		registerAudioInputs(patchbay);
	}

	//if (bparam) {
	//	registerParam(patchbay);
	//}
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

	//for (int i = 0; i < parameters.getSize(); ++i) {
	//	string name = "param-" + ofToString(i + 1);

	//	///*
	//	patchbay->registerController1f(name, [&, i] {
	//		return parameters.parameters[i].get();
	//	});
	//	//*/


	//	/*
	//	patchbay->registerController1f(name, [&, i] {

	//		if (parameters.parameters[i].type() == typeid(ofParameter<float>).name())
	//		{
	//			return parameters.parameters[i].cast<float>().get();
	//		}
	//		//
	//		//else if (parameters.parameters[i].type() == typeid(ofParameter<bool>).name())
	//		//{
	//		//	return parameters.parameters[i].cast<bool>().get();
	//		//}
	//		//
	//		});
	//	*/

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

void ofxPatchbayInput::registerKeyboardInputs(ofxPatchbay* patchbay) {
	for (char i = 32; i < 127; ++i) {
		string name = "kb-";
		name.append(1, i);
		patchbay->registerController1f(name, [&, i] {
			return ofGetKeyPressed(i);
			});
	}
}

void ofxPatchbayInput::registerMouseInputs(ofxPatchbay* patchbay) {
	patchbay->registerController1f("mouse-x", [&] {
		return mouse.getX();
		});

	patchbay->registerController1f("mouse-y", [&] {
		return mouse.getY();
		});

	patchbay->registerController2f("mouse-xy", [&] {
		return mouse.getXY();
		});

	patchbay->registerController1f("mouse-btn", [&] {
		return mouse.getPressed(0);
		});

	patchbay->registerController1f("mouse-btn-right", [&] {
		return mouse.getPressed(1);
		});
}

void ofxPatchbayInput::registerMidiInputs(ofxPatchbay* patchbay) {
	for (int i = 0; i < NUM_MIDI_CHANNEL; i++) {
		patchbay->registerController1f("midi-cc-" + to_string(i), [&, i] {
			return midi.control[i];
			});
	}
	for (int i = 0; i < NUM_MIDI_CHANNEL; i++) {
		patchbay->registerController1f("midi-prog-" + to_string(i), [&, i] {
			return midi.program[i];
			});
	}
	for (int i = 0; i < NUM_MIDI_CHANNEL; i++) {
		patchbay->registerController1f("midi-note-" + to_string(i), [&, i] {
			return (midi.notesOn.find(i) != midi.notesOn.end()) ? 1 : 0;
			});
	}
}

void ofxPatchbayInput::registerAudioInputs(ofxPatchbay* patchbay) {
	patchbay->registerController1f("audio-rms", [&] {
		return audio.getRMS();
		});
}
