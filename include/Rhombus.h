#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

class Rhombus : public Figure {
private:
    double diagonal1; // большая диагональ
    double diagonal2; // меньшая диагональ
    
public:
    Rhombus() = default;
    Rhombus(double d1, double d2);
    Rhombus(const std::vector<std::pair<double, double>>& verts);
    Rhombus(const Rhombus& other);
    
    std::pair<double, double> getCenter() const override;
    double getArea() const override;
    void printVertices() const override;
    void readFromStream(std::istream& is) override;
    
    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;
    bool operator==(const Rhombus& other) const;
    
    double getDiagonal1() const;
    double getDiagonal2() const;
    
private:
    void calculateVertices();
};

#endif
