#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    BackgroundImage.loadImage("wallpaper.jpg"); //画像を読み込む
    
    
    ofBackground(0,0,0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true); //画面の垂直同期をONに
    ofEnableAlphaBlending(); //透明度を有効化
   //ofToggleFullscreen(); //フルスクリーンにする。
    
    boxsize = 5; //boxの大きさ
    for (int i=0; i<NUM; i++ ){
        //boxの位置をランダムにする。
        mBox[i].setPosition(ofRandom(-500, 500),ofRandom(-500, 500),ofRandom(-500, 500));
        mBox[i].set(boxsize); //boxのサイズを１５に。
    }
    
    sound.loadSound("アーマードコア BGM silent line.mp3"); //音楽を読み込む。
    sound.play(); //音楽を再生する。
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    BackgroundImage.draw(0, 0, ofGetWidth(),ofGetHeight());
    
    ofTranslate(ofGetHeight()/2, ofGetWidth()/2); //原点(0,0,0)が縦と横の中心になる。
    
    
    
    vec.set(mouseX-p.x, mouseY-p.y);
    
    
    
    cam.begin();
    
    
    
    ofPushMatrix();
    
    ofRotateY(ofGetFrameNum()); //Y軸を軸にして回転させる。
    
    int alpha = abs(vec.x) + abs(vec.y);  //x方向の速度　＋　Y方向の速度
    ofSetColor(100, 200, 255, 255 - alpha);
    
    
    for (int i=0; i<NUM; i++) {
        mBox[i].draw(); //たくさんの小さいboxを描画。
    }
    
    ofPopMatrix();
    
    
    ofSetColor(255,255,255,(ofGetFrameNum()*6)%120); //（boxの色を指定(点滅)）
    box.setPosition(0, 0, 0); //boxの位置を画面の中心に
    box.set(50);
    box.draw();
    
    ofSetColor(255, 255, 255, 255); //ワイヤーフレームの色
    box.drawWireframe(); //ワイヤーフレームを描画
    
    
    

    cam.end();
    
    
    
    p.x = mouseX; //前のマウスのポイントを保存。(pointX)
    p.y = mouseY; //前のマウスのポイントを保存。(pointY)
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
