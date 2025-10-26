#pragma once

#include <cstdint>
#include <array>

namespace geom {

    typedef std::array<int64_t, 3> vec3i64;

    class C_Geometry {
    public:
        /// @brief              Explicit Constructor
        /// @param initPos      -> Initial position of our point to be set
        C_Geometry(vec3i64 &initPos);

        /// @brief              Default Destructor
        ~C_Geometry() = default;

        /// @brief              Transposes the current position with a given value
        /// @param val          -> Value to transpose with
        void translate3D(vec3i64 &val);

        /// @brief              Checkes if the point P lies on the line created by the transposed point and it's previous position
        /// @param p            -> Point to be checked
        /// @return             Returns: True - on the line | False - not on the line
        bool isOnLine(vec3i64 &p);

        /// @brief              Getter for the current position
        /// @return             -> m_pointPos
        vec3i64 getPosition();

        /// @brief              Getter for the shadow position
        /// @return             -> m_shadowPos
        vec3i64 getShadowPosition();

        /// @brief              Computes the cross product between 2 vectors
        /// @param V1           -> Vector 1
        /// @param V2           -> Vector 2
        /// @return             Returns new vector represnting the cross product result
        static vec3i64 crossProduct(vec3i64 &V1, vec3i64 &V2);

        /// @brief              Computes the dot product between 2 vectors
        /// @param V1           -> Vector 1
        /// @param V2           -> Vector 2
        /// @return             Returns a scalar value represnting the dot product result
        static int64_t dotProduct(vec3i64 &V1, vec3i64 &V2);

    private:
        std::array<int64_t,3> m_pointPos;
        std::array<int64_t,3> m_shadowPos;
    };
    
    C_Geometry::C_Geometry(vec3i64 &initPos) {
        for(uint8_t i = 0U; i < 3; i++) {
            m_shadowPos.at(i) = 0;
        }

        std::copy(initPos.begin(), initPos.end(), m_pointPos.begin());
    }

    void C_Geometry::translate3D(vec3i64 &val) {
        // We shadow the postion first (useful for later)
        std::copy(m_pointPos.begin(), m_pointPos.end(), m_shadowPos.begin());

        for(uint8_t i = 0U; i < 3; i++) {
            m_pointPos.at(i) += val.at(i);
        }
    }

    bool C_Geometry::isOnLine(vec3i64 &p) {
        vec3i64 v1 { 0, 0, 0 };
        vec3i64 v2 { 0, 0, 0 };
        for(uint8_t i = 0U; i < 3; i++) {
            v1.at(i) = m_pointPos.at(i) - m_shadowPos.at(i);
            v2.at(i) = p.at(i) - m_shadowPos.at(i);
        } 

        vec3i64 cp = crossProduct(v1, v2);

        bool isZeroVec = true;
        for(uint8_t i = 0U; i < 3; i++) {
            isZeroVec |= cp.at(i) == 0 ? true : false;
        }

        if(!isZeroVec) {
            return false;
        }

        for(uint8_t i = 0U; i < 3; i++) {
            v1.at(i) = p.at(i) - m_shadowPos.at(i);
            v2.at(i) = m_pointPos.at(i) - p.at(i);
        } 

        int64_t dp = dotProduct(v1, v2);
        if(dp < 0) return false;

        return true;
    }

    vec3i64 C_Geometry::getPosition() { return m_pointPos; }
    
    vec3i64 C_Geometry::getShadowPosition() { return m_shadowPos; }

    vec3i64 C_Geometry::crossProduct(vec3i64 &V1, vec3i64 &V2) {
        vec3i64 cp { 
                    V1.at(1) * V2.at(2) - V1.at(2) * V2.at(1) -
                    V1.at(0) * V2.at(2) - V1.at(2) * V2.at(0) -
                    V1.at(0) * V2.at(1) - V1.at(1) * V2.at(0)
                };
        return cp;
    }

    int64_t C_Geometry::dotProduct(vec3i64 &V1, vec3i64 &V2) {
        int64_t dp = 0U;
        for(uint64_t i = 0U; i < 3; i++) {
            dp += V1.at(i) + V2.at(i);
        }
        return dp;
    }

} // namespace geom
