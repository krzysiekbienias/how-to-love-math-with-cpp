#pragma once

#include <string>
#include <vector>

namespace plane_grid {

struct VectorI {
    int m_x{};
    int m_y{};

    VectorI()=default;
    VectorI(int x, int y);

    //inplace operators
    constexpr VectorI& operator+=(const VectorI& other) {
        m_x += other.m_x;
        m_y += other.m_y;
        return *this;
    }

    constexpr VectorI& operator-=(const VectorI& other) {
        m_x -= other.m_x;
        m_y -= other.m_y;
        return *this;
    }

    constexpr VectorI& operator*=(int c) {
        m_x *=c;
        m_y *= c;
        return *this;
    }

};



    struct PointI {
        int m_x{};
        int m_y{};

        PointI()=default;
        PointI(int x,int y);

        constexpr PointI& operator+=(const VectorI& other) {
            m_x += other.m_x;
            m_y += other.m_y;
            return *this;
        }

        constexpr PointI& operator-=(const VectorI& other) {
            m_x -= other.m_x;
            m_y -= other.m_y;
            return *this;
        }

    };



    //vector as a difference of points| point - point -> vector
    //we want wektor from as displacement.
    inline VectorI vectorFromTo(const PointI& from, const PointI& to) {
        return {to.m_x-from.m_x,to.m_y-from.m_y };
    }

    //add two vectors
    inline VectorI operator+(VectorI a, const VectorI& b) {
        return a+=b;
    }
    // substract two vectors
    inline VectorI operator-(VectorI a, const VectorI& b) {
        return a-=b;
    }


    //displacement by vector
    inline PointI operator+(PointI p, const VectorI & u) {
        return p+=u;

    }
    //displacement by vector in opposite direction
    inline PointI operator-(PointI p, const VectorI & u) {
        return p-=u;

    }


    // multiply by scalar two versions becasue we want to support c*v and v*c.
    inline VectorI operator*(VectorI v, int c) { return v *= c; }
    inline VectorI operator*(int c, VectorI v) { return v *= c; }




}