#include "ImageCompare.h"

static const double C1 = 6.5025, C2 = 58.5225; 

Mat Compare_SSIM(Mat image1, Mat image2)
{
    Mat validImage1, validImage2;
    image1.convertTo(validImage1, CV_32F); //��������ת��Ϊ float,��ֹ����������ִ���
    image2.convertTo(validImage2, CV_32F);

    Mat image1_1 = validImage1.mul(validImage1); //ͼ��˻�
    Mat image2_2 = validImage2.mul(validImage2);
    Mat image1_2 = validImage1.mul(validImage2);

    Mat gausBlur1, gausBlur2, gausBlur12;
    GaussianBlur(validImage1, gausBlur1, Size(11, 11), 1.5); //��˹����˼���ͼ���ֵ
    GaussianBlur(validImage2, gausBlur2, Size(11, 11), 1.5);
    GaussianBlur(image1_2, gausBlur12, Size(11, 11), 1.5);

    Mat imageAvgProduct = gausBlur1.mul(gausBlur2); //��ֵ�˻�
    Mat u1Squre = gausBlur1.mul(gausBlur1); //���Ծ�ֵ��ƽ��
    Mat u2Squre = gausBlur2.mul(gausBlur2);

    Mat imageConvariance, imageVariance1, imageVariance2;
    Mat squreAvg1, squreAvg2;
    GaussianBlur(image1_1, squreAvg1, Size(11, 11), 1.5); //ͼ��ƽ���ľ�ֵ
    GaussianBlur(image2_2, squreAvg2, Size(11, 11), 1.5);
    
    imageConvariance = gausBlur12 - gausBlur1.mul(gausBlur2);// ����Э����
    imageVariance1 = squreAvg1 - gausBlur1.mul(gausBlur1); //���㷽��
    imageVariance2 = squreAvg2 - gausBlur2.mul(gausBlur2); 

    auto member = ((2 * gausBlur1 .mul(gausBlur2) + C1).mul(2 * imageConvariance + C2));
    auto denominator = ((u1Squre + u2Squre + C1).mul(imageVariance1 + imageVariance2 + C2));

    Mat ssim;
    divide(member, denominator, ssim);
    return ssim;
}

ImageCompare::ImageCompare()
    :_imagePath1(),
    _imagePath2()
{
}

ImageCompare::~ImageCompare()
{
}

int ImageCompare::Init(const std::string& img1,const std::string& img2)
{
    _imagePath1 = img1;
    _imagePath2 = img2;
    _img1 = imread(_imagePath1);
    _img2 = imread(_imagePath2);

    return true;
}

Mat ImageCompare::SSIM_Compare()
{
    return Compare_SSIM(_img1, _img2);
}
