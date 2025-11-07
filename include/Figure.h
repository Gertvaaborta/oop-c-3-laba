#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <cmath>

class Figure {
protected:
    std::vector<std::pair<double, double>> vertices;
    
public:
    Figure() = default;
    Figure(const std::vector<std::pair<double, double>>& verts);
    Figure(const Figure& other);
    virtual ~Figure() = default;
    
    virtual std::pair<double, double> getCenter() const = 0;
    virtual double getArea() const = 0;
    virtual void printVertices() const = 0;
    virtual void readFromStream(std::istream& is) = 0;
    
    virtual Figure& operator=(const Figure& other);
    virtual Figure& operator=(Figure&& other) noexcept;
    virtual bool operator==(const Figure& other) const;
    
    virtual operator double() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend std::istream& operator>>(std::istream& is, Figure& figure);
    
    const std::vector<std::pair<double, double>>& getVertices() const;
};

#endif
