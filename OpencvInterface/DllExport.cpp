#include "DllExport.h"
#include "ImageCompare.h"

uchar* Dll_API SSIM_Image(const char* imgPath1, const char* imgPath2)
{
    ImageCompare comparer;
    comparer.Init(imgPath1, imgPath2);

    auto result = comparer.SSIM_Compare();
    int width = result.size().width;
    int height = result.size().height;
    int channels = result.channels();
    int length = width * height * channels;
    Mat_Struct* res = static_cast<Mat_Struct*>(malloc(sizeof(Mat_Struct) + length)); //传递给dll外部，不要在这里释放

    res->width = width;
    res->height = height;
    res->channels = channels;
    memcpy(res->data, result.data, length);

    return (uchar*)res;
}

double Dll_API SSIM_Percent(const char* imgPath1, const char* imgPath2)
{
    double sum = 0.0f;
    ImageCompare comparer;
    comparer.Init(imgPath1, imgPath2);

    auto result = comparer.SSIM_Compare();
    auto meanResult = mean(result);
    int channels = result.channels();
    
    for (auto depthIndex = 0; depthIndex < channels; ++depthIndex)
    {
        sum += meanResult[depthIndex];
    }
    sum /= channels;

    return sum;
}

void Dll_API Release(void* ptr)
{
    if (ptr)
    {
        free(ptr);
        ptr = nullptr;
    }
}
