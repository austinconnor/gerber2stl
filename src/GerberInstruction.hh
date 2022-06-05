#pragma once



class GerberInstruction{
    public:
    enum TYPE {DRAW,FLY,FLASH};
    enum POLARITY {LIGHT, DARK};

    float x, y;
    
    TYPE type;
    POLARITY polarity;



};