#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

// listening port
#define PORT 8888

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxOscReceiver receiver;
    
        //store data for multiple R-IoT modules
        std::vector< std::vector<float> > riot_data;
        //assign number of devices
        int numDevices = 1;
    
        const std::vector< string > labels = {"ACC_X", "ACC_Y", "ACC_Z", "GYRO_X", "GYRO_Y", "GYRO_Z", "MAG_X", "MAG_Y", "MAG_Z", "TEMP", "IO", "A1", "A2", "C", "Q1", "Q2", "Q3", "Q4", "PITCH", "YAW", "ROLL", "HEAD"};

};
