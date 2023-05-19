#include "engine/box/rectangle.h"

using namespace Engine;

template <typename T> Engine::Rectangle<T>::Rectangle(double x, double y) {
    this->relVertices.push_back(std::pair<double, double>(0, 0));
    this->relVertices.push_back(std::pair<double, double>(x, 0));

    this->relVertices.push_back(std::pair<double, double>(x, y));
    this->relVertices.push_back(std::pair<double, double>(0, y));
}

// Bottom-left point first; then counter clockwise
template <typename T>
Engine::Rectangle<T>::Rectangle(double x1, double x2, double y1, double y2) {
    if (x1 < x2) // x1 is minx
    {
        if (y1 < y2) // y1 is miny
        {
            this->relVertices.push_back(std::pair<double, double>(x1, y1));
            this->relVertices.push_back(std::pair<double, double>(x2, y1));
            this->relVertices.push_back(std::pair<double, double>(x2, y2));
            this->relVertices.push_back(std::pair<double, double>(x1, y2));
        } else { // y2 is miny
            this->relVertices.push_back(std::pair<double, double>(x1, y2));
            this->relVertices.push_back(std::pair<double, double>(x2, y2));
            this->relVertices.push_back(std::pair<double, double>(x2, y1));
            this->relVertices.push_back(std::pair<double, double>(x1, y1));
        }
    } else {
        if (y1 < y2) {
            this->relVertices.push_back(std::pair<double, double>(x2, y1));
            this->relVertices.push_back(std::pair<double, double>(x1, y1));
            this->relVertices.push_back(std::pair<double, double>(x1, y2));
            this->relVertices.push_back(std::pair<double, double>(x2, y2));
        } else {
            this->relVertices.push_back(std::pair<double, double>(x2, y2));
            this->relVertices.push_back(std::pair<double, double>(x1, y2));
            this->relVertices.push_back(std::pair<double, double>(x1, y1));
            this->relVertices.push_back(std::pair<double, double>(x2, y1));
        }
    }
}

template <typename T>
Engine::Intersection<T> Rectangle<T>::checkIntersection(Rectangle<T>* r) {
    std::pair<double, double>* this_pos = this->getPos();
    std::pair<double, double>* that_pos = r->getPos();

    Intersection<T> coll = Intersection<T>();

    int xcol1 = (this->relVertices.at(1).first + this_pos->first) -
                (r->getVertices().at(0).first + that_pos->first);

    int xcol2 = (r->getVertices().at(1).first + that_pos->first) -
                (this->relVertices.at(0).first + this_pos->first);
    int xcol = 0;

    int ycol1 = (this->relVertices.at(2).second + this_pos->second) -
                (r->getVertices().at(1).second + that_pos->second);

    int ycol2 = (r->getVertices().at(2).second + that_pos->second) -
                (this->relVertices.at(1).second + this_pos->second);

    int ycol = 0;

    if (xcol1 > 0 && xcol2 > 0) {
        xcol1 < xcol2
            ? (xcol = xcol1)
            : (xcol = -xcol2); // Vector must be going from 'this' to 'that'
    }
    if (ycol1 > 0 && ycol2 > 0) {
        ycol1 < ycol2 ? (ycol = ycol1) : (ycol = -ycol2);
    }

    coll.intersectionVector = std::pair<double, double>(xcol, ycol);
    if (ycol != 0 && xcol != 0) {
        coll.intersecting = this->getOwner();
        coll.intersected = r->getOwner();
        return coll;
    } else {
        coll.intersecting = NULL;
        return coll;
    }
}