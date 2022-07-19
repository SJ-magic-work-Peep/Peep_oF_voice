/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/
/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	font.load("font/RictyDiminished-Regular.ttf", 20/* font size in pixels */, true/* _bAntiAliased */, true/* _bFullCharacterSet */, false/* makeContours */, 0.3f/* simplifyAmt */, 72/* dpi */);
	
	/********************
	********************/
	ofSetBackgroundAuto(true);
	
	ofSetWindowTitle("DMX test");
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetWindowShape(MAIN_WINDOW_W, MAIN_WINDOW_H);
	ofSetEscapeQuitsApp(false);
	
	/********************
	********************/
	ofSeedRandom();
	
	ofEnableAntiAliasing();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA); // OF_BLENDMODE_DISABLED, OF_BLENDMODE_ALPHA, OF_BLENDMODE_ADD
	
	/********************
	********************/
	voice.setup();
}

/******************************
******************************/
void ofApp::update(){
	int now = ofGetElapsedTimeMillis();
	
	ofSoundUpdate();
	voice.update(now);
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(20);
	
	char buf[100];
	if(voice.get_state() == VOICE::STATE::stop){
		sprintf(buf, "stop");
	}else if(voice.get_state() == VOICE::STATE::interval){
		sprintf(buf, "interval");
	}else{
		sprintf(buf, "waitEnd");
	}
	font.drawString(buf, 100, 100);
}

/******************************
******************************/
void ofApp::keyPressed(int key){
	switch(key){
		case ' ':
			voice.PlayStart();
			break;
			
		case 's':
			voice.PlayStop();
			break;
	}
}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
