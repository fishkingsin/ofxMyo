#include "ofApp.h"
#define SAMPLE_SIZE 512
//--------------------------------------------------------------
void ofApp::setup(){
    m_myo.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
    m_myo.update();
    m_myo.printDebug();
    MyoFrameOrientationData orientationData = m_myo.getCurrFrameOrientionData();

    roll.push_back(orientationData.euler_roll);
	pitch.push_back(orientationData.euler_pitch);
	yaw.push_back(orientationData.euler_yaw);
    if(pitch.size()>SAMPLE_SIZE)
    {
        pitch.erase(pitch.begin());
    }
    if(yaw.size()>SAMPLE_SIZE)
    {
        yaw.erase(yaw.begin());
    }
    if(roll.size()>SAMPLE_SIZE)
    {
        roll.erase(roll.begin());
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    float maxH = 20;
    float half_H = ofGetHeight()*0.5-(maxH*0.5);

    ofPushStyle();
    ofSetHexColor(0x101010);
    for(unsigned int i=1;i<pitch.size();i++){
        
        ofLine(i-1,pitch[i-1]*maxH+half_H,i,pitch[i]*maxH+half_H);
    }
    ofPopStyle();
    ofPushStyle();
    ofSetColor(ofColor::green);
    for(unsigned int i=1;i<yaw.size();i++){
        ofLine(i-1,yaw[i-1]*maxH+half_H,i,yaw[i]*maxH+half_H);
    }
    ofPopStyle();
    
    ofPopStyle();
    ofPushStyle();
    ofSetColor(ofColor::red);
    for(unsigned int i=1;i<roll.size();i++){
        ofLine(i-1,roll[i-1]*maxH+half_H,i,roll[i]*maxH+half_H);
    }
    ofPopStyle();
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
