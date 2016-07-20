#include "ofxMSAInteractiveObject.h"
class ofxDraggable : public ofxMSAInteractiveObject {
public:  
    ofBaseDraws *content; // this will point to your image, video, grabber etc.  
      
    ofxDraggable() {  
        content = NULL;
        saveX = 0;
        saveY = 0;
        onPressed = false;
        isDraggedOut = false;
    }
    void setPos(float x , float y)
    {
        ofRectangle::setPosition(x, y);
        saveX = x;
        saveY = y;
    }
      
    void onPress(int mx, int my, int button) {  
        isDraggedOut = false;
        // save the offset of where the mouse was clicked...  
        // ...relative to the position of the object  
        saveX = mx - this->x;  
        saveY = my - this->y;
        onPressed = true;
    }  
      
    void onDragOver(int mx, int my, int button) {
        if(!onPressed) return;
        this->x = mx - saveX;    // update x position  
        this->y = my - saveY;    // update mouse y position  
    }
    void onDragOutside(int mx, int my, int button) {
        if(!onPressed) return;
        isDraggedOut = true;
        this->x = mx - saveX;    // update x position
        this->y = my - saveY;    // update mouse y position
    }
    void onRelease(int x, int y, int button)
    {
        onPressed = false;
        isDraggedOut = false;
    }
    
      
    void draw() {  
        if(content) {  
            width = content->getWidth();  
            height = content->getHeight();  
            content->draw(x, y, width, height);  
              
            // add a border if mouse is pressed or over the object  
            if(isMouseDown()) {
                ofNoFill();
                ofSetHexColor(0xFF0000);
                ofDrawRectangle(x, y, width, height);
            } else if(isMouseOver()){  
                ofNoFill();  
                ofSetHexColor(0x00FF00);  
                ofDrawRectangle(x, y, width, height);
            }  
        }  
    }  
      
protected:
bool isDraggedOut;
    bool onPressed;
    int saveX, saveY;  
};  