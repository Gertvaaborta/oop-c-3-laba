#include <gtest/gtest.h>
#include "Rhombus.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Array.h"
#include <memory>
#include <cmath>

TEST(RhombusTest, BasicArea) {
    Rhombus rhombus(6.0, 8.0);
    EXPECT_DOUBLE_EQ(rhombus.getArea(), 24.0);
}

TEST(RhombusTest, Center) {
    Rhombus rhombus(6.0, 8.0);
    auto center = rhombus.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 0.0);
    EXPECT_DOUBLE_EQ(center.second, 0.0);
}

TEST(PentagonTest, BasicArea) {
    Pentagon pentagon(5.0);
    double expected_area = (5.0 * 5.0 * 5.0) / (4.0 * std::tan(M_PI / 5.0));
    EXPECT_NEAR(pentagon.getArea(), expected_area, 1e-10);
}

TEST(PentagonTest, Center) {
    Pentagon pentagon(5.0);
    auto center = pentagon.getCenter();
    EXPECT_NEAR(center.first, 0.0, 1e-10);
    EXPECT_NEAR(center.second, 0.0, 1e-10);
}

TEST(HexagonTest, BasicArea) {
    Hexagon hexagon(4.0);
    double expected_area = (3.0 * std::sqrt(3.0) * 4.0 * 4.0) / 2.0;
    EXPECT_DOUBLE_EQ(hexagon.getArea(), expected_area);
}

TEST(HexagonTest, Center) {
    Hexagon hexagon(4.0);
    auto center = hexagon.getCenter();
    EXPECT_NEAR(center.first, 0.0, 1e-10);
    EXPECT_NEAR(center.second, 0.0, 1e-10);
}

TEST(ArrayTest, AddAndSize) {
    Array array;
    array.addFigure(std::make_unique<Rhombus>(6.0, 8.0));
    array.addFigure(std::make_unique<Pentagon>(5.0));
    EXPECT_EQ(array.size(), 2);
}

TEST(ArrayTest, TotalArea) {
    Array array;
    array.addFigure(std::make_unique<Rhombus>(6.0, 8.0)); // area = 24
    array.addFigure(std::make_unique<Hexagon>(2.0)); // area = 10.3923
    double total = array.getTotalArea();
    EXPECT_NEAR(total, 24.0 + 10.3923, 1e-3);
}

TEST(PolymorphismTest, VirtualMethods) {
    Array figures;
    
    figures.addFigure(std::make_unique<Rhombus>(6.0, 8.0));
    figures.addFigure(std::make_unique<Pentagon>(5.0));
    figures.addFigure(std::make_unique<Hexagon>(4.0));
    
    double totalArea = 0.0;
    for (size_t i = 0; i < figures.size(); ++i) {
        totalArea += figures.getFigure(i)->getArea();
    }
    
    double expected = 24.0 + (5.0 * 25.0) / (4.0 * std::tan(M_PI / 5.0)) + (3.0 * std::sqrt(3.0) * 16.0) / 2.0;
    EXPECT_NEAR(totalArea, expected, 1e-3);
}

TEST(OperatorTest, DoubleConversion) {
    Rhombus rhombus(6.0, 8.0);
    double area = static_cast<double>(rhombus);
    EXPECT_DOUBLE_EQ(area, 24.0);
}
