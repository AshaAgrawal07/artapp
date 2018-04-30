#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	gui.setup();
	
	//the entire window will be the canvas
	bg_r_val = 255;
	bg_g_val = 255;
	bg_b_val = 255;
	bg_a_val = 255;
	ofBackground(bg_r_val, bg_g_val, bg_b_val, bg_a_val);

	//setup the toggle for pen/eraser
	gui.add(pen_eraser.setup("Pen//Eraser", false, 200, 30));

	//create the color slider
	gui.add(red.setup("Red", 100, 0, 255, 200, 30));
	gui.add(green.setup("Green", 100, 0, 255, 200, 30));
	gui.add(blue.setup("Blue", 100, 0, 255, 200, 30));
	gui.add(alpha.setup("Alpha", 100, 0, 255, 200, 30));

	//create the width/thickness slider
	gui.add(thickness.setup("Pen width", 10, 0, 1000));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	pen_eraser.draw();
	red.draw();
	green.draw();
	blue.draw();
	alpha.draw();
	thickness.draw();
	
	//inspired by ofxVectorGraphicsExample
	if (single_stroke.size() > 0) {

		int numPts = single_stroke.size();
		tool.setColor(red.operator const ofColor_<unsigned char> &().r, green.operator const ofColor_<unsigned char> &().g, 
			blue.operator const ofColor_<unsigned char> &().b, alpha.operator const ofColor_<unsigned char> &().a);
		tool.setLineWidth(thickness.operator const int &());
		tool.noFill();
		tool.beginShape();

		int rescaleRes = 1;

		for (int i = 0; i < numPts; i++) {
			if (i == 0 || i == numPts - 1) {
				tool.curveVertex(single_stroke[i].x, single_stroke[i].y);
			}
			if (i % rescaleRes == 0) {
				tool.curveVertex(single_stroke[i].x, single_stroke[i].y);
			}
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
	single_stroke[single_stroke.size() - 1].x = x;
	single_stroke[single_stroke.size() - 1].y = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//inspired by vectorGraphicsExample
	single_stroke.clear();
	single_stroke.push_back(ofPoint());
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
	if (pen_eraser) {
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
