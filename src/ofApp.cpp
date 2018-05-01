#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	gui.setup();
	
	//the entire window will be the canvas, minus the area where where the toggle and the sliders are
	bg_r_val = 0;
	bg_g_val = 0;
	bg_b_val = 0;
	bg_a_val = 255;
	ofBackground(bg_r_val, bg_g_val, bg_b_val, bg_a_val);

	//setup the toggle for pen/eraser
	gui.add(pen_eraser.setup("Pen//Eraser", false, 200, 30));

	//create the color slider
	gui.add(colorslider.setup("Color", 100, ofColor::fromHex(0,0), 255, 200, 30));

	//create the width/thickness slider
	gui.add(thickness.setup("Pen width", 10, 0, 500));

	leftbuttonpressed = false;

	gui.loadFromFile("drawing.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
	if (leftbuttonpressed) {
		ofVec2f mouseposition(ofGetMouseX(), ofGetMouseY());
		currentpolyline.curveTo(mouseposition);
		lastpoint = mouseposition;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	//first redraw 
	for (int i = 0; i < strokes.size(); i++) {
		ofPolyline oldpoly = strokes[i];
		oldpoly.draw();
	}

	ofSetColor(colorslider);
	tool.setLineWidth(thickness.operator const int &());
	tool.noFill();
	tool.beginShape();

	currentpolyline.draw();
	tool.endShape();

	if (!hide) {
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//basically control+z but only with the 'z' for simplicity purposes
	if (toupper(key) == 'Z') {
		strokes.pop_back();
	}
	else if (toupper(key) == 'S') {
		hide = true;
		exit();
	}
	else if (toupper(key) == 'H') {
		hide = !hide;
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_LEFT) {
		leftbuttonpressed = true;
		currentpolyline.curveTo(x, y);
		currentpolyline.curveTo(x, y);
		lastpoint.set(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_LEFT) {
		leftbuttonpressed = false;
		currentpolyline.curveTo(x, y);
		strokes.push_back(currentpolyline);
		currentpolyline.clear();
	}
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
	if (pen_eraser) {
		tool = Eraser(bg_r_val, bg_g_val, bg_b_val, bg_a_val, 10);
	} else {
		tool = Pen(colorslider.operator const ofColor_<unsigned char> &().r, colorslider.operator const ofColor_<unsigned char> &().g,
			colorslider.operator const ofColor_<unsigned char> &().b, colorslider.operator const ofColor_<unsigned char> &().a, 10);
	}
}

void ofApp::exit()
{
	gui.saveToFile("drawing.xml");
	std::cout << "saved" << std::endl;
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
