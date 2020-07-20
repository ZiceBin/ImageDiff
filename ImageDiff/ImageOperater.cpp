#include "ImageOperater.h"

ret_code ImageOperater::Init(const string& strPath)
{
    ret_code result = ret_code::retInvalidCode;
    if (strPath.length() < 1 || strPath.length() > _MAX_PATH)
    {
        return ret_code::retPathTooLong;
    }

    result = ret_code::retOK;
    return result;
}

ret_code ImageOperater::Read()
{
    ret_code result = ret_code::retInvalidCode;

    result = ret_code::retOK;
    return result;
}