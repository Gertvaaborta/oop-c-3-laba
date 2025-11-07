#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"

class Pentagon : public Figure {
private:
    double side_length;
    
public:
    Pentagon() = default;
    Pentagon(double side);
    Pentagon(const std::vector<std::pair<double, double>>& verts);
    Pentagon(const Pentagon& other);
    
    std::pair<double, double> getCenter() const override;
    double getArea() const override;
    void printVertices() const override;
    void readFromStream(std::istream& is) override;
    
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
    bool operator==(const Pentagon& other) const;
    
    double getSideLength() const;
    
private:
    void calculateVertices();
};

#endif
