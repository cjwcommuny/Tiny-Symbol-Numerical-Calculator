# Numerical Calculator 总报告

## 问题与背景

Matlab、Octave是知名的带图形化界面的数值/符号计算器，在矩阵、方程、绘图方面拥有着强大的功能。本项目开发了一款带图形界面的迷你数值计算器，实现了数值计算与符号计算的基本功能，实现了函数绘制的一些基本功能。

## 分工与开发计划

### 本组成员：

* 陈佳伟 
* 晏港 
* 姚力铭

### 工程分工

- 陈佳伟：MVVM框架搭建、持续集成配置；曲线绘制；矩阵算行列式；组装集成组员的代码（view、viewmodel层）

- 晏港：多项式语法解析器；多项式数据结构；高阶方程求解；多项式表达式积分

- 姚力铭：矩阵语法解析器；矩阵数据结构；矩阵的运算（包括加减乘、转置和求逆）；线性方程组的求解

  

### 开发计划

1. 陈佳伟搭建MVVM框架的同时，晏港与姚力铭分别同时开发多项式语法解析器与矩阵语法解析器
2. 陈佳伟整合多项式语法解析器和矩阵语法解析器；同时晏港与姚力铭并行开发其他功能
3. 陈佳伟开发曲线绘制等功能；晏港开发多项式相关功能；姚力铭开发矩阵有关功能（每开发一次功能由陈佳伟整合一次）





## 每轮迭代效果说明

* 第一轮迭代效果：完成MVVM框架的搭建，基本完成矩阵表达式解析器与多项式表达式解析器，没有实际功能
* 第二轮迭代效果：完成基本GUI开发， 集成矩阵表达式解析与多项式表达式解析功能，并附加相关数据结构的运算
* 第三轮迭代效果：完成矩阵的运算（加减乘、转置求逆）；完成高阶方程求数值解的功能
* 第四轮迭代效果：完成函数曲线的绘制功能，完成线性方程组求解功能
* 第五轮迭代效果：完成异常处理、非法字符串处理错误提示以及 Bug 的修正



## 最终运行效果图

### 语法高亮

![语法高亮](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/语法高亮.PNG)



### 不定积分



![最终效果图1](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/最终效果图1.PNG)



### 绘制曲线



![总体截图](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/总体截图.PNG)



### 矩阵加法、减法、乘法

![addition](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/addition.PNG)



![矩阵减法](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/矩阵减法.PNG)



![矩阵乘法](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/矩阵乘法.PNG)

### 矩阵求逆

![矩阵乘法](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/求逆.PNG)



### 矩阵转置

![转置](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/转置.PNG)



### 求行列式

![行列式](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/行列式.PNG)



### 求解线性方程组

![线性方程组](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/线性方程组.PNG)



### 求解高阶方程

![一次方程](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/一次方程.PNG)

![二次方程](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/二次方程.PNG)



![三次](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/三次.PNG)



### 错误表达式判定

![非法字符](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/非法字符.PNG)



![括号不匹配](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/括号不匹配.PNG)



![非法函数名](https://github.com/ZJU-CPP-SUMMER-TERM/project/raw/master/doc/images/非法函数名.PNG)



