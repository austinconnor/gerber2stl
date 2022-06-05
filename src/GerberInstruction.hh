#pragma once



class GerberInstruction{
    public:
    static enum TYPE {DRAW,FLY,FLASH};
    static enum POLARITY {LIGHT, DARK};

    float x, y;
    
    TYPE type;
    POLARITY polarity;

    
};