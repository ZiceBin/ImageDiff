// OpenCV_SSIM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//K1 = 0.01 K2 = 0.03 L��ͼ��ĻҶȶ�̬��Χ����ͼ����������;��� ��������δuint8,��L=255
//c1 = (K1*L)^2  
//c2 = (K2*L)^2

//int main()
//{
//    Mat BlurImage1;
//    Mat BlurImage2;
//    Mat SrcImage1 = imread("11.jpg");
//    Mat SrcImage2 = imread("12.jpg");
//    int channels1 = SrcImage1.channels();
//    int channels2 = SrcImage2.channels();
//    int channels = min(channels1, channels2);
//    //blur(SrcImage, BlurImage1, Size(5, 5));
//    //blur(SrcImage,BlurImage2,Size(10,10));
//    Scalar SSIM = Compare_SSIM(SrcImage1, SrcImage2);
//    //Scalar SSIM2 = Compare_SSIM(SrcImage, BlurImage2);
//
//    double sum = 0.0f;
//    for (auto depthIndex = 0; depthIndex < channels; ++depthIndex)
//    {
//        sum += SSIM[depthIndex];
//    }
//    sum /= channels;
//    printf("���ƶȰٷֱȣ�%f\n", sum);
//    //imshow("ԭͼ",SrcImage);
//    //imshow("ģ��5*5",BlurImage1);
//    //imshow("ģ��10*10", BlurImage2);
//    return 0;
//}