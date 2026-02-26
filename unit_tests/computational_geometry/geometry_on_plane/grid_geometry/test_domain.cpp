#include "computational_geometry/geometry_on_plane/grid_geometry/domain.hpp"
#include <gtest/gtest.h>



using plane_grid::PointI;
using plane_grid::VectorI;
using plane_grid::vectorFromTo;

TEST(VectorI, DefaultConstructsToZero) {
    VectorI v;
    EXPECT_EQ(v.m_x, 0);
    EXPECT_EQ(v.m_y, 0);
}

TEST(VectorI, PlusEqualsModifiesInPlaceAndReturnsSelf) {
    VectorI a{1, 2};
    VectorI b{3, 4};

    VectorI& ref = (a += b);
    EXPECT_EQ(&ref, &a);

    EXPECT_EQ(a.m_x, 4);
    EXPECT_EQ(a.m_y, 6);

    // rhs unchanged
    EXPECT_EQ(b.m_x, 3);
    EXPECT_EQ(b.m_y, 4);
}

TEST(VectorI, MinusEqualsModifiesInPlaceAndReturnsSelf) {
    VectorI a{10, 20};
    VectorI b{3, 7};

    VectorI& ref = (a -= b);
    EXPECT_EQ(&ref, &a);

    EXPECT_EQ(a.m_x, 7);
    EXPECT_EQ(a.m_y, 13);
}

TEST(VectorI, MultiplyEqualsScalesInPlaceAndReturnsSelf) {
    VectorI a{3, -6};

    VectorI& ref = (a *= 2);
    EXPECT_EQ(&ref, &a);

    EXPECT_EQ(a.m_x, 6);
    EXPECT_EQ(a.m_y, -12);
}

TEST(VectorI, BinaryPlusDoesNotModifyOperands) {
    VectorI a{1, 2};
    VectorI b{3, 4};

    VectorI c = a + b;
    EXPECT_EQ(c.m_x, 4);
    EXPECT_EQ(c.m_y, 6);

    EXPECT_EQ(a.m_x, 1);
    EXPECT_EQ(a.m_y, 2);
    EXPECT_EQ(b.m_x, 3);
    EXPECT_EQ(b.m_y, 4);
}

TEST(VectorI, BinaryMinusDoesNotModifyOperands) {
    VectorI a{10, 20};
    VectorI b{3, 7};

    VectorI c = a - b;
    EXPECT_EQ(c.m_x, 7);
    EXPECT_EQ(c.m_y, 13);

    EXPECT_EQ(a.m_x, 10);
    EXPECT_EQ(a.m_y, 20);
    EXPECT_EQ(b.m_x, 3);
    EXPECT_EQ(b.m_y, 7);
}

TEST(VectorI, MultiplySupportsBothOrders) {
    VectorI v{2, -3};

    VectorI a = v * 5;
    EXPECT_EQ(a.m_x, 10);
    EXPECT_EQ(a.m_y, -15);

    VectorI b = 5 * v;
    EXPECT_EQ(b.m_x, 10);
    EXPECT_EQ(b.m_y, -15);

    // original unchanged
    EXPECT_EQ(v.m_x, 2);
    EXPECT_EQ(v.m_y, -3);
}

TEST(VectorI, ChainingPlusEqualsWorks) {
    VectorI a{1, 1};
    VectorI b{2, 2};
    VectorI c{3, 3};

    a += b += c; // b -> (5,5), a -> (6,6)

    EXPECT_EQ(b.m_x, 5);
    EXPECT_EQ(b.m_y, 5);
    EXPECT_EQ(a.m_x, 6);
    EXPECT_EQ(a.m_y, 6);
}

TEST(PointI, DefaultConstructsToZero) {
    PointI p;
    EXPECT_EQ(p.m_x, 0);
    EXPECT_EQ(p.m_y, 0);
}

TEST(PointI, PlusEqualsVectorDisplacesInPlaceAndReturnsSelf) {
    PointI p{10, 20};
    VectorI u{3, -7};

    PointI& ref = (p += u);
    EXPECT_EQ(&ref, &p);

    EXPECT_EQ(p.m_x, 13);
    EXPECT_EQ(p.m_y, 13);

    // vector unchanged
    EXPECT_EQ(u.m_x, 3);
    EXPECT_EQ(u.m_y, -7);
}

TEST(PointI, MinusEqualsVectorDisplacesInPlaceAndReturnsSelf) {
    PointI p{10, 20};
    VectorI u{3, -7};

    PointI& ref = (p -= u);
    EXPECT_EQ(&ref, &p);

    EXPECT_EQ(p.m_x, 7);
    EXPECT_EQ(p.m_y, 27);
}

TEST(PointI, PointPlusVectorReturnsNewPointAndDoesNotModifyOriginal) {
    PointI p{1, 2};
    VectorI u{10, -5};

    PointI q = p + u;

    EXPECT_EQ(q.m_x, 11);
    EXPECT_EQ(q.m_y, -3);

    EXPECT_EQ(p.m_x, 1);
    EXPECT_EQ(p.m_y, 2);
}

TEST(PointI, PointMinusVectorReturnsNewPointAndDoesNotModifyOriginal) {
    PointI p{1, 2};
    VectorI u{10, -5};

    PointI q = p - u;

    EXPECT_EQ(q.m_x, -9);
    EXPECT_EQ(q.m_y, 7);

    EXPECT_EQ(p.m_x, 1);
    EXPECT_EQ(p.m_y, 2);
}

TEST(PlaneGrid, VectorFromToIsCorrect) {
    PointI from{1, 2};
    PointI to{10, -5};

    VectorI v = vectorFromTo(from, to);

    EXPECT_EQ(v.m_x, 9);
    EXPECT_EQ(v.m_y, -7);
}

TEST(PlaneGrid, VectorFromToComposesWithPointDisplacement) {
    PointI a{3, 4};
    PointI b{-2, 10};

    VectorI ab = vectorFromTo(a, b);

    // a displaced by vector(a->b) should land at b
    PointI result = a + ab;

    EXPECT_EQ(result.m_x, b.m_x);
    EXPECT_EQ(result.m_y, b.m_y);
}