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
    uchar data[0]; //������ôд��ʹ��ָ��Ļ���C#�ж�ȡ����̫�鷳���ö�����ָ��
};

//���е����ӿھ�ʹ��malloc�����ڴ���䣬����ʹ��new
Export_Dll uchar* Dll_API SSIM_Image(const char* imgPath1, const char* imgPath2);

Export_Dll double Dll_API SSIM_Percent(const char* imgPath1, const char* imgPath2);

Export_Dll void Dll_API Release(void* ptr);