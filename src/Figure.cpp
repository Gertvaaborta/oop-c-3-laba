#include "Figure.h"

Figure::Figure(const std::vector<std::pair<double, double>>& verts) : vertices(verts) {}

Figure::Figure(const Figure& other) : vertices(other.vertices) {}

Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

bool Figure::operator==(const Figure& other) const {
    return vertices == other.vertices;
}

Figure::operator double() const {
    return getArea();
}

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    figure.printVertices();
    return os;
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    figure.readFromStream(is);
    return is;
}

const std::vector<std::pair<double, double>>& Figure::getVertices() const {
    return vertices;
}
