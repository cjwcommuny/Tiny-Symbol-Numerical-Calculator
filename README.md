# Numerical/Symbol Calculator

## 简介

这是一个数值/符号计算器



## 实现的功能

* 语法高亮
    * 函数名高亮
    * 数字高亮
    * 注释高亮

![语法高亮](D:\Workspace\project\picture for readme\语法高亮.PNG)



* 矩阵的加法

  示例：

  ```
  [[1,2];[3,4]] + [[7,6];[3,4]]
  ```

* 矩阵的减法

  示例：

  ```
  [[1,2];[3,4]] - [[7,6];[3,4]]
  ```

  

* 矩阵的乘法

  示例：

  ```
  [[1,2];[3,4]] * [[7,6];[3,4]]
  ```

* 矩阵的转置

  示例：

    ```
  transpose([[1,2];[3,4]])
    ```



* 矩阵的求逆

  示例：

  ```
  invert([[1,2];[3,4]])
  ```

  

* 求矩阵对应的行列式

  示例：

  ```
  ComputeDeterminant([[1,2];[3,4]])
  ```

  

* 求解线性方程组

  示例：

  ```c++
  SolveLinear([[1,1,3];[1,-1,1]]) //传入的是增广矩阵
  ```

  



* 绘制多项式函数的曲线

  示例：

  ```
  draw(x^2)
  ```

  ![curve](D:\Workspace\project\picture for readme\curve.PNG)



* 求解一元高阶方程

  示例：

  ```
  SolvePoly(x^2 - x = 0)
  SolvePoly(x^3 + x = 0)
  ```

  

