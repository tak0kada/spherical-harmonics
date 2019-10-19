#include "spherical-harmonics/sh/spherical_harmonics.hpp"
#include <iostream>
#include <memory>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

int main()
{
    // Eigen::Quaterniond q(Eigen::AngleAxisd(M_PI/4.0, Eigen::Vector3d::UnitZ()));
    Eigen::Matrix3d q;
    q << 1, 0, 0,
         0, 1, 0,
         0, 0, 1;
    std::unique_ptr<sh::Rotation> rot(sh::Rotation::Create(3, q));

    for (auto mat : rot->band_rotations_)
    {
        std::cout << mat << std::endl;
    }
}
