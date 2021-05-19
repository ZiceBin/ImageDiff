#pragma once
#include "stdafx.h"

#define Export_Dll extern "C" _declspec(dllexport) 
#define Dll_API __stdcall

#pragma pack(1)
struct DllExportBase
{
    int version;
    int length;
    int dataLen;
};

struct Mat_Struct
{
    int width;
    int height;
    int channels;
    uchar data[0]; //必须这么写，使用指针的话，C#中读取数据太麻烦，得读两次指针
};

//所有导出接口均使用malloc进行内存分配，不许使用new
Export_Dll uchar* Dll_API SSIM_Image(const char* imgPath1, const char* imgPath2);

Export_Dll double Dll_API SSIM_Percent(const char* imgPath1, const char* imgPath2);

Export_Dll void Dll_API Release(void* ptr);