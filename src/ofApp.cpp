#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//the next few lines are gotten from the example for ofxShivaVG
	ofSetFrameRate(100.0f);
	ofSetCurveResolution(100);
	_defaultRenderer = ofGetCurrentRenderer();
	_shivaVGRenderer = ofPtr<ofxShivaVGRenderer>(new ofxShivaVGRenderer);
	ofSetCurrentRenderer(_shivaVGRenderer);

	_shivaVGRenderer->setLineJoinStyle(VG_JOIN_ROUND);
	_shivaVGRenderer->setLineCapStyle(VG_CAP_ROUND);
	//------

	gui.setup();
	
	//setup the toggle for pen/eraser
	gui.add(pen_eraser.setup("Pen//Eraser", false));

	//create the color slider
	gui.add(colors.setup("Color", ofColor(100, 100, 100, 100), ofColor(0, 0), ofColor(255, 255)));

	//create the width/thickness slider
	gui.add(thickness.setup("Pen width", 10, 0, 1000));

	//the entire window will be the canvas
	ofBackground(255, 255, 255, 255);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//inspired by ofxVectorGraphicsExample
	if (strokes.size() > 0) {

		int numPts = strokes.size();

		output.setColor(0x0088EE);
		output.noFill();
		output.beginShape();

		int rescaleRes = 6;

		for (int i = 0; i < numPts; i++) {
			if (i == 0 || i == numPts - 1) {
				output.curveVertex(strokes[i].x, strokes[i].y);
			}
			if (i % rescaleRes == 0) output.curveVertex(strokes[i].x, strokes[i].y);
		}

		output.endShape();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//basically control+z but only with the 'z' for simplicity purposes
	//pops the most recent stroke off the stack of strokes
	if (toupper(key) == 'Z') {
		strokes.pop();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	//we add a new point to our line
	//used from vectorGraphicsExample, though changed from vector to stack implementation
	
	strokes.push(ofPoint());
	strokes.top.x = x;
	strokes.top.y = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	mouseDragged(x, y, button);
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

void ofApp::togglePressed(const void* sender, bool& pressed)
{
	std::cout << "Toggle Pressed" << std::endl;
	//if toggle is false, then its on pen, else its on eraser
}

void ofApp::buttonPressed(const void * sender)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
