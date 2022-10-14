//
//  ofxPatchbay.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#include "ofxPatchbay.h"

ofxPatchbay::ofxPatchbay() {
    input.registerInputs(this);
}

//--

void ofxPatchbay::registerControllableB(string name, function<void (bool)> func) {
    controllableB[name] = func;
}

void ofxPatchbay::registerControllerB(string name, function<bool ()> func) {
    controllerB[name] = func;
}

void ofxPatchbay::registerControllable1f(string name, function<void (float)> func) {
    controllable1f[name] = func;
}

void ofxPatchbay::registerController1f(string name, function<float ()> func) {
    controller1f[name] = func;
}

void ofxPatchbay::registerControllable2f(string name, function<void (ofVec2f)> func) {
    controllable2f[name] = func;
}

void ofxPatchbay::registerController2f(string name, function<ofVec2f ()> func) {
    controller2f[name] = func;
}

//--

void ofxPatchbay::connectB(string controller, string controllable) {
    if (controllerB.find(controller) == controllerB.end()) {
        ofLog(OF_LOG_WARNING, "Controller: " + controller + " not registered as yet");
    }
    connectionsB[controller].insert(controllable);
}

void ofxPatchbay::disconnectB(string controller, string controllable) {
    if (controllerB.find(controller) == controllerB.end()) {
        ofLog(OF_LOG_WARNING, "Controller: " + controller + " not registered as yet");
    }
    connectionsB[controller].erase(controllable);
}

void ofxPatchbay::connect1f(string controller, string controllable) {
    if (controller1f.find(controller) == controller1f.end()) {
        ofLog(OF_LOG_WARNING, "Controller: " + controller + " not registered as yet");
    }
    connections1f[controller].insert(controllable);
}

//--

void ofxPatchbay::disconnect1f(string controller, string controllable) {
    if (controller1f.find(controller) == controller1f.end()) {
        ofLog(OF_LOG_WARNING, "Controller: " + controller + " not registered as yet");
    }
    connections1f[controller].erase(controllable);
}

void ofxPatchbay::disconnectAll() {
    disconnectAll1f();
    disconnectAll2f();
    disconnectAllB();
}

void ofxPatchbay::disconnectAll1f() {
    connections1f.clear();
}

void ofxPatchbay::disconnectAll2f() {
    connections2f.clear();
}

void ofxPatchbay::disconnectAllB() {
    connectionsB.clear();
}

//--

void ofxPatchbay::connect2f(string controller, string controllable) {
    if (controller1f.find(controller) == controller1f.end()) {
        ofLog(OF_LOG_WARNING, "Controller: " + controller + " not registered as yet");
    }
    connections2f[controller].insert(controllable);
}

void ofxPatchbay::disconnect2f(string controller, string controllable) {
    if (controller1f.find(controller) == controller1f.end()) {
        ofLog(OF_LOG_WARNING, "Controller: " + controller + " not registered as yet");
    }
    connections2f[controller].erase(controllable);
}

//--

void ofxPatchbay::update() {
    
    for(auto& connection : connectionsB) {
        auto controller = controllerB[connection.first];
        if (controller == NULL) {
            ofLog(OF_LOG_WARNING, "process(): Controller " + connection.first + " not found");
        } else {
            auto value = controller();
            for (auto& controllableName : connection.second) {
                auto controllable = controllableB[controllableName];
                if (controllable == NULL) {
                    ofLog(OF_LOG_WARNING, "process(): Controllable " + controllableName + " not found");
                } else {
                    controllable(value);
                }
            }
        }
    }
    
    for(auto& connection : connections1f) {
        auto controller = controller1f[connection.first];
        if (controller == NULL) {
            ofLog(OF_LOG_WARNING, "process(): Controller " + connection.first + " not found");
        } else {
            auto value = controller();
            for (auto& controllableName : connection.second) {
                auto controllable = controllable1f[controllableName];
                if (controllable == NULL) {
                    ofLog(OF_LOG_WARNING, "process(): Controllable " + controllableName + " not found");
                } else {
                    controllable(value);
                }
            }
        }
    }
    
    for(auto& connection : connections2f) {
        auto controller = controller2f[connection.first];
        if (controller == NULL) {
            ofLog(OF_LOG_WARNING, "process(): Controller " + connection.first + " not found");
        } else {
            auto value = controller();
            for (auto& controllableName : connection.second) {
                auto controllable = controllable2f[controllableName];
                if (controllable == NULL) {
                    ofLog(OF_LOG_WARNING, "process(): Controllable " + controllableName + " not found");
                } else {
                    controllable(value);
                }
            }
        }
    }
}

//--

void ofxPatchbay::print() {
    printB();
    print1f();
    print2f();
}

void ofxPatchbay::print1f() {
    cout<<"\nControllable 1fs:"<<endl;
    for (auto& item : controllable1f) {
        cout<<item.first<<endl;
    }
    cout<<"\nController 1fs:"<<endl;
    for (auto& item : controller1f) {
        cout<<item.first<<endl;
    }
    cout<<"\nConnection 1fs:"<<endl;
    for (auto& item : connections1f) {
        cout<<item.first<<": [";
        for (auto& to : item.second) {
            cout<<to<<", ";
        }
        cout<<"]"<<endl;
    }
}

void ofxPatchbay::printB() {
    cout<<"\nControllable Bs:"<<endl;
    for (auto& item : controllableB) {
        cout<<item.first<<endl;
    }
    cout<<"\nController Bs:"<<endl;
    for (auto& item : controllerB) {
        cout<<item.first<<endl;
    }
    cout<<"\nConnection Bs:"<<endl;
    for (auto& item : connectionsB) {
        cout<<item.first<<": [";
        for (auto& to : item.second) {
            cout<<to<<", ";
        }
        cout<<"]"<<endl;
    }
}

void ofxPatchbay::print2f() {
    cout<<"\nControllable 2fs:"<<endl;
    for (auto& item : controllable2f) {
        cout<<item.first<<endl;
    }
    cout<<"\nController 2fs:"<<endl;
    for (auto& item : controller2f) {
        cout<<item.first<<endl;
    }
    cout<<"\nConnection 2fs:"<<endl;
    for (auto& item : connections2f) {
        cout<<item.first<<": [";
        for (auto& to : item.second) {
            cout<<to<<", ";
        }
        cout<<"]"<<endl;
    }
}

void ofxPatchbay::printConnections() {
    cout<<"\nConnection Bs:"<<endl;
    for (auto& item : connectionsB) {
        cout<<item.first<<": [";
        for (auto& to : item.second) {
            cout<<to<<", ";
        }
        cout<<"]"<<endl;
    }
    cout<<"\nConnection 1fs:"<<endl;
    for (auto& item : connections1f) {
        cout<<item.first<<": [";
        for (auto& to : item.second) {
            cout<<to<<", ";
        }
        cout<<"]"<<endl;
    }
    cout<<"\nConnection 2fs:"<<endl;
    for (auto& item : connections2f) {
        cout<<item.first<<": [";
        for (auto& to : item.second) {
            cout<<to<<", ";
        }
        cout<<"]"<<endl;
    }
}
