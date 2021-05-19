# ImageDiff

基于SSIM实现了图片对比功能
- OpencvInterface：使用opencv实现了SSIM算法，并导出为dll接口，
    - dll接口SSIM_Percent返回一个相似度值

- PythonDemo：python版本的ssim算法实现
- SDK：opencv库，含dll，lib，以及头文件，版本是4.4
- test_ImageDiff：测试工程

> 注意，对比的图片分辨率需要相同

使用方法
- 使用VS2019打开OpencvInterface工程，编译相应版本的OpencvInterface.dll， 输出路径为x64/你的版本/xxx
- 从SDK/x64/(你的版本)/bin/  下拷贝依赖的dll到和上面相同目录
- 在你的C++工程中添加 x64/你的版本/OpencvInterface.lib，
    - 引用 ./OpencvInterface/DllExport.h
    - 添加头文件目录 ./SDK/opencv/include
- 可以愉快的使用dll了

