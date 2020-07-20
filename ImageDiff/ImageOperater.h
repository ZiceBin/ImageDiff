#pragma once
#include "global.h"


class ImageOperater
{
public:
    ImageOperater()
    {
        m_nImgLen = 0;
        m_bpImgContent = nullptr;
    }

    ret_code Init(const string& strPath);
    ret_code Read();
    ret_code Save(const string& strPath);

private:
    string m_strImgPath;

    unsigned int m_nImgLen;
    byte* m_bpImgContent;
};

