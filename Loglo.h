#pragma once

#include "ofMain.h"


class Loglo{
    public:
        Loglo();
        void setup(int x, int y);
        void update(int x, int y);
        void draw();
    
        ofSoundStream soundStream;
        vector <float> soundBuffer;
        int bufferSize;
        
        ofFbo bitmap;
        int width;
        int height;
        int locX;
        int locY;
};
