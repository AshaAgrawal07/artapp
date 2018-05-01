#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxVectorGraphics.h"
#include <vector>
#include <stack>


#include "tool.h"
#include "eraser.h"
#include "pen.h"

class ofApp : public ofBaseApp{

	

	int bg_r_val;
	int bg_g_val;
	int bg_b_val;
	int bg_a_val;

	//vector <vector<ofPoint>> strokes;
	//vector <ofPoint> single_stroke;

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
		
		//toggles between pen and eraser
		void ofApp::togglePressed(const void* sender, bool& pressed);

		//exits and saves the drawing
		void exit();
		
		//draw shapes using the buttons
		//void buttonPressed(const void* sender);

		ofxPanel gui;
		ofxToggle pen_eraser;
		ofxColorSlider colorslider;
		Tool tool;
		ofxIntSlider thickness;
		bool hide = false;

		ofPolyline currentpolyline;
		ofVec2f lastpoint;
		vector<ofPolyline> strokes;
};
