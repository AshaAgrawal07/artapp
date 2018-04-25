#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxSvg.h"
#include "ofxColorGradient.h"
#include "ofxShivaVGRenderer.h"

class ofApp : public ofBaseApp{
	//enum to represent the pen/function being used
	enum Function {
		PEN,
		ERASER,
		SHAPE
	};

	ofxPanel gui;
	ofxToggle pen_eraser;
	ofxColorGradient<ofColor> color_ramp;

	int bg_r_val;
	int bg_g_val;
	int bg_b_val;
	int bg_a_val;

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
		
		//draw shapes using the buttons
		void buttonPressed(const void* sender);

		std::stack <ofPoint> strokes;

private:

	ofPtr<ofBaseRenderer> _defaultRenderer;
	ofPtr<ofxShivaVGRenderer> _shivaVGRenderer;
};
