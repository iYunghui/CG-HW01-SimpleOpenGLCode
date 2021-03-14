# CG-HW01-SimpleOpenGLCode

## Hardware and software requirement

* Windows 10
* Visual Studio 15 2017 Release Win32

## Program overview

* 透過`src/OpenGL/OpenGLShader`和`src/OpenGL/OpenGLShaderProgram`建立及管理shader，`src/OpenGL/OpenGLVertexArrayObject`處理vertex，`src/Model/Mesh`將teapot繪製到螢幕上
* 透過`src/OpenGL/OpenGLTexture`設定要貼在teapot上的圖
* 透過`src/OpenGL/OpenGLBufferObject`處理各種類別的buffer

## Operations manual

1. 使用 CMake Configure 和 Generate project
2. 從 CMake 打開 project，選擇方案組態(Release)和方案平台(Win32)，在方案總管處選擇Homework01按右鍵build
![](https://i.imgur.com/9jnMbPS.png)
3. build成功後，在資料夾`build/bin/Release`中可找到`Homework01.exe`檔案，在cmd中移到檔案位置輸入指令
    ```
    Homework01.exe "resources/model/Utah_teapot_(solid)_texture.obj" "resources/texture/uv.png" "Shader/BasicVertexShader.vs.glsl" "Shader/BasicFragmentShader.fs.glsl"
    ```
4. 執行畫面
<center class="half">
<img src="https://i.imgur.com/WUxD51v.jpg"/> <img src="https://i.imgur.com/QAXUezu.jpg" />
</center>
