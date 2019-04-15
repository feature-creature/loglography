#include "Loglo.h"

Loglo::Loglo(){}

void Loglo::setup(int x, int y){
    locX = x;
    locY = y;
    width = 100;
    height = 100;
	
	soundStream.printDeviceList();

	// visuals
	ofNoFill();
    ofSetColor(255,255,255,255);
    bitmap.allocate(width,height,GL_RGBA); 

}

void Loglo::update(int x, int y){
    bitmap.begin();
    ofTranslate(x,y,0);
    ofDrawRectangle(0,0,20,20);
    bitmap.end();

}

void Loglo::draw(){
	
    bitmap.draw(locX,locY);

    ofPushStyle();
    ofPushMatrix();
        ofTranslate(32, 170, 0);
        ofSetLineWidth(3);
 
        ofBeginShape();
        for (unsigned int i = 0; i < soundBuffer.size(); i++){
        	ofVertex(i*2, 100 -soundBuffer[i]*180.0f);
        }
    	ofEndShape(false);
 
    ofPopMatrix();
    ofPopStyle();

}

