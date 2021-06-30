#include "gerber.hh"
#include "math_utils.hh"

class Aperture{
public:
    GerberUtils::APERTURE_TYPE aperture_type;
    Shape shape;

    int aperture_id;

    int sides;
    float radius;
    float width;
    float height;


    void GenerateAperture(GerberUtils);
};