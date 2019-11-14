#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // listen on the given port
    ofLog() << "listening for osc messages on port " << PORT;
    receiver.setup(PORT);
    
    //fill vector
    for (int i = 0; i < numDevices ; i++) {
        std::vector <float> temp;
        riot_data.push_back(temp);
        for (int j = 0; j < 21 ; j++) {
            riot_data[i].push_back(0.0);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        //recive messages from one device only
        /*
        if(m.getAddress() == "/0/raw"){
            for (int i = 0; i < 21; i++){
                riot_data[0][i] = (m.getArgAsFloat(i));
            }
        }
         */
        // multiple devices
        // allow any message with wildcard "/*/raw
        if(ofIsStringInString(m.getAddress(), "/raw")){
            int dev_id = ofToInt(m.getAddress().substr(1,1));
            for (int i = 0; i < 21; i++){
                riot_data[dev_id][i] = (m.getArgAsFloat(i));
            }
        }
    }
    
    //print out the X axis accelerometer channel from the first device
    std::cout << riot_data[0][0] << std::endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    stringstream s;
    for(int i = 0; i < 21; i++){
        s << labels[i] << ": ";
        s << riot_data[0][i] << endl;
    }
    s << endl;
    ofSetColor(255);
    ofDrawBitmapString(s.str(), 50, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
