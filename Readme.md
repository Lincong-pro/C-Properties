Learn some basic properties concerning on brand-new C++ properties!

#### 编码问题

> 编码问题解决办法：先在 vscode 中书写中文，然后才可以在 Visual Studio 中进行书写，这只是利用其中的一些 bug，比较麻烦！

##### 彻底解决方法

[`详细参照网址`]('https://blog.csdn.net/Michael_fchou/article/details/104349977')

- 根据笔者的实验，上述确实很好的解决了在 vscode 中创建以及在 Visual Studio 2019 使用 qDebug 和 cout 中文乱码问题。

- 下载 Force UTF-8(No BOM)

  ![image-20210824181231046](https://raw.githubusercontent.com/Lincong-pro/C-Properties/master/img/image-20210824181231046.png)

- 更改电脑区域设置

  ![image-20210824181341568](https://raw.githubusercontent.com/Lincong-pro/C-Properties/master/img/image-20210824181341568.png)

> cd toolchains
> robocopy ./ %CONDA_PREFIX% h2o.cmake
> robocopy ./ %CONDA_PREFIX%/Library/plugins applocal.ps1
> robocopy ./ %CONDA_PREFIX%/Library/plugins qtdeploy.ps1
> robocopy ./ %CONDA_PREFIX% applocal.ps1
