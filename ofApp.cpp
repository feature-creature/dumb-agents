#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // set background color and turn off painting background on draw
    ofBackground(255);
    ofSetBackgroundAuto(false);

    ofSetCircleResolution(10);

    // initialize direction values
    north = 0;
    northEast = 1;
    east = 2;
    southEast = 3;
    south = 4;
    southWest = 5;
    west = 6;
    northWest = 7;

    // initialize circle movemet unit and diameter
    stepSize = 3;
    diam = 3    ;

    // initialize circle location
    locX = ofGetWidth() /2;
    locY = ofGetHeight() /2;

    // initialize colors
    right = ofColor(0,0,0,100);
    left = ofColor(255,255,255,10);

    min = 0;
    max = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    // map mouse x movement to a 0-4 value
    float r1 = ofMap(mouseX,0,ofGetWidth(),0,5);
    // map mouse y movement to a 5-9 value
    float r2 = ofMap(mouseY,0,ofGetHeight(),6,10);
    // pick a number between r1-(r2-1) since max val is out of scope
    int direction = ofRandom(r1,r2);

    // update direction
    if(direction == north){
        locY += stepSize;
    } else if (direction == northEast){
        locY += stepSize;
        locX += stepSize;
    } else if (direction == east){
        locX += stepSize;
    } else if (direction == southEast){
        locY -= stepSize;
        locX += stepSize;
    } else if (direction == south){
        locY -= stepSize;
    } else if (direction == southWest){
        locY -= stepSize;
        locX -= stepSize;
    } else if (direction == west){
        locX -= stepSize;
    } else if (direction == northWest){
        locY += stepSize;
        locX -= stepSize;
    }

    // defend against limits x
    if(locX >= ofGetWidth()){
        locX = 0;
    }else if (locX <= 0){
        locX = ofGetWidth();
    }
    // defend against limits y
    if(locY >= ofGetHeight()){
        locY = 0;
    }else if (locY <= 0){
        locY = ofGetHeight();
    }



}

//--------------------------------------------------------------
void ofApp::draw(){
    // map the x location on the page to a 0 or 1
    float mColor = ofMap(locX,0,ofGetWidth(),0,1);
    // learn what is lerping ??
    //set the color by lerping left with right and 0||1
    ofSetColor(left.getLerped(right, mColor));
    ofDrawEllipse(locX,locY,diam,diam);
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
