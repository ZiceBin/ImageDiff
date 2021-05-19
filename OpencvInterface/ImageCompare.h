#pragma once

#include "stdafx.h"

class ImageCompare
{
public:
    ImageCompare();
    ~ImageCompare();

    int Init(const std::string& img1,const std::string& img2);

    Mat SSIM_Compare();

private:
    std::string _imagePath1;
    std::string _imagePath2;

    Mat _img1;
    Mat _img2;
};

