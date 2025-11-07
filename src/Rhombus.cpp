#include "Rhombus.h"
#include <iostream>
#include <cmath>

Rhombus::Rhombus(double d1, double d2) : diagonal1(d1), diagonal2(d2) {
    calculateVertices();
}

Rhombus::Rhombus(const std::vector<std::pair<double, double>>& verts) : Figure(verts) {
    if (verts.size() == 4) {
        diagonal1 = std::abs(verts[0].first - verts[2].first) * 2;
        diagonal2 = std::abs(verts[1].second - verts[3].second) * 2;
    }
}

Rhombus::Rhombus(const Rhombus& other) : Figure(other), diagonal1(other.diagonal1), diagonal2(other.diagonal2) {}

std::pair<double, double> Rhombus::getCenter() const {
    if (vertices.empty()) return {0, 0};
    
    double sum_x = 0, sum_y = 0;
    for (const auto& vertex : vertices) {
        sum_x += vertex.first;
        sum_y += vertex.second;
    }
    return {sum_x / vertices.size(), sum_y / vertices.size()};
}

double Rhombus::getArea() const {
    return (diagonal1 * diagonal2) / 2.0;
}

void Rhombus::printVertices() const {
    std::cout << "Rhombus vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        std::cout << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i != vertices.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

void Rhombus::readFromStream(std::istream& is) {
    is >> diagonal1 >> diagonal2;
    calculateVertices();
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        Figure::operator=(other);
        diagonal1 = other.diagonal1;
        diagonal2 = other.diagonal2;
    }
    return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
        diagonal1 = other.diagonal1;
        diagonal2 = other.diagonal2;
    }
    return *this;
}

bool Rhombus::operator==(const Rhombus& other) const {
    return Figure::operator==(other) && 
           diagonal1 == other.diagonal1 && 
           diagonal2 == other.diagonal2;
}

double Rhombus::getDiagonal1() const {
    return diagonal1;
}

double Rhombus::getDiagonal2() const {
    return diagonal2;
}

void Rhombus::calculateVertices() {
    vertices.clear();
    vertices.push_back({diagonal1 / 2, 0});
    vertices.push_back({0, diagonal2 / 2});
    vertices.push_back({-diagonal1 / 2, 0});
    vertices.push_back({0, -diagonal2 / 2});
}
