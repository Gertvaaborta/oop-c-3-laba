#ifndef ARRAY_H
#define ARRAY_H

#include "Figure.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include <vector>
#include <memory>

class Array {
private:
    std::vector<std::unique_ptr<Figure>> figures;
    
public:
    Array() = default;
    Array(const Array& other);
    Array(Array&& other) noexcept;
    
    ~Array() = default;
    
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    
    void addFigure(std::unique_ptr<Figure> figure);
    void removeFigure(size_t index);
    size_t size() const;
    Figure* getFigure(size_t index) const;
    
    void printAllCenters() const;
    void printAllAreas() const;
    double getTotalArea() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Array& array);
    
private:
    void copyFigures(const Array& other);
};

#endif
