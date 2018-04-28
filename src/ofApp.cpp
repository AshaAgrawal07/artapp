#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	gui.setup();
	
	//setup the toggle for pen/eraser
	gui.add(pen_eraser.setup("Pen//Eraser", false));

	//create the color slider
	gui.add(colors.setup("Color", ofColor(100, 100, 100, 100), ofColor(0, 0), ofColor(255, 255)));

	//create the width/thickness slider
	gui.add(thickness.setup("Pen width", 10, 0, 1000));

	//the entire window will be the canvas
	ofBackground(0, 10, 0, 255);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//inspired by ofxVectorGraphicsExample
	if (single_stroke.size() > 0) {

		int numPts = single_stroke.size();

		tool.setColor(tool.r_val, tool.g_val, tool.b_val, tool.a_val);
		tool.noFill();
		tool.beginShape();

		int rescaleRes = 6;

		for (int i = 0; i < numPts; i++) {
			if (i == 0 || i == numPts - 1) {
				tool.curveVertex(single_stroke[i].x, single_stroke[i].y);
			}
			if (i % rescaleRes == 0) tool.curveVertex(single_stroke[i].x, single_stroke[i].y);
		}

		tool.endShape();
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
	//inspired by vectorGraphicsExample
	
	single_stroke.push_back(ofPoint());
	single_stroke[single_stroke.size()-1].x = x;
	single_stroke[single_stroke.size()-1].y = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	single_stroke.clear();
	single_stroke[0].x = x;
	single_stroke[0].y = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	strokes.push(single_stroke);
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
	if (true) {
		tool = Eraser(bg_r_val, bg_g_val, bg_b_val, bg_a_val, 10);
	}
	else {
		tool = Pen(bg_r_val, bg_g_val, bg_b_val, bg_a_val, 10);
	}
}

//void ofApp::buttonPressed(const void * sender)
//{
//}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
