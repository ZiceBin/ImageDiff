#include "DllExport.h"
#include <iostream>

int main()
{
    double abSimilar = SSIM_Percent("a.jpg", "b.jpg");
    double aaSimilar = SSIM_Percent("a.jpg", "a.jpg");

    std::cout << "abSimilar" << abSimilar << std::endl;
    std::cout << "aaSimilar" << aaSimilar << std::endl;

    return 0;
}