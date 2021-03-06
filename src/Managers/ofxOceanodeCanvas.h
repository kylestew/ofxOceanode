//
//  ofxOceanodeCanvas.h
//  example-basic
//
//  Created by Eduard Frigola on 19/06/2017.
//
//

#ifndef ofxOceanodeCanvas_h
#define ofxOceanodeCanvas_h

#ifndef OFXOCEANODE_HEADLESS

#include "ofMain.h"
#include "ofxDatGui.h"

class ofxOceanodeContainer;
class ofxDatGui;
class ofxDatGuiDropdown;

class ofxOceanodeCanvas{
public:
    //ofxOceanodeCanvas(){};
    ~ofxOceanodeCanvas(){};
    
    
    void setup();
    void update(ofEventArgs &args){};
    void draw(ofEventArgs &args){};
    
    void keyPressed(ofKeyEventArgs &e);
    void keyReleased(ofKeyEventArgs &e){};
    void mouseMoved(ofMouseEventArgs &e){};
    void mouseDragged(ofMouseEventArgs &e);
    void mousePressed(ofMouseEventArgs &e);
    void mouseReleased(ofMouseEventArgs &e){};
    void mouseScrolled(ofMouseEventArgs &e);
    void mouseEntered(ofMouseEventArgs &e){};
    void mouseExited(ofMouseEventArgs &e){};
    
    void setContainer(shared_ptr<ofxOceanodeContainer> c){container = c;};
    
    void newModuleListener(ofxDatGuiDropdownEvent e);
private:
    glm::vec3 getMatrixScale(const glm::mat4 &m);
    glm::mat4 translateMatrixWithoutScale(const glm::mat4 &m, glm::vec3 translationVector);
    
    glm::vec2 screenToCanvas(glm::vec2 p);
    glm::vec2 canvasToScreen(glm::vec2 p);
    
    shared_ptr<ofxOceanodeContainer> container;
    ofxDatGui *popUpMenu;
    vector<ofxDatGuiDropdown*> modulesSelectors;
    
    ofParameter<glm::mat4> *transformationMatrix;
    glm::vec2 dragCanvasInitialPoint;
    
    ofEventListeners listeners;
    
    ofEventListener changedTransformationMatrix;
};

#endif

#endif /* ofxOceanodeCanvas_h */
