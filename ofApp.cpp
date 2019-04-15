#include "ofApp.h"
#include <math.h>

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundColor(155);
    //ofSetRectMode(OF_RECTMODE_CENTER);

	loglographSize = 9;

    loglograph.clear();

    for (int i=0; i < loglographSize; i++){
        Loglo tempLoglo;
        tempLoglo.setup((i%3)*100,floor(i/3)*100);
        loglograph.push_back(tempLoglo);
    }

    soundStream.printDeviceList();
    bufferSize = 256;

    for (int i=0; i < loglographSize; i++){
        loglograph[i].soundBuffer.assign(bufferSize,0.0);
    }

    ofSoundStreamSetup(10,1,44100,bufferSize,4);


}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i < loglographSize; i++){
		loglograph[i].update(40,40);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i < loglographSize; i++){
		loglograph[i].draw();
	}
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

void ofApp::audioIn(ofSoundBuffer & input){
    //calculate RMS (~volume) for each sample   
    for (size_t i = 0; i < input.getNumFrames(); i++){
        loglograph[i].soundBuffer[i]= input[i*2]*0.5;
    }
          
    bufferCounter++;
}
          
