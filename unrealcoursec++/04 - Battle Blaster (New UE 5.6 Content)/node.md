

# 003 Base Pawn Class
创建一个pawn  
![alt text](image.png)

创建三个东西  
![alt text](image-1.png)


将创建的东西加入到根当中
![alt text](image-2.png)

加入到根组件  
![alt text](image-4.png)





# 004 Child C++ Class


创建一个atank继承 basepawn  
![alt text](image-5.png)


导入 
![alt text](image-6.png)

设置摄像机和抬臂  
![alt text](image-7.png)

写代码加上  
![alt text](image-8.png)

可以到绑定了父类  
![alt text](image-9.png)
当我们拖进去的时候可以看到摄像机  
![alt text](image-10.png)
设置这个  
![alt text](image-11.png)


# 005 Camera & Spring Arm

创建一个类继承tank蓝图  
![alt text](image-12.png)

可以看到全部继承了过来  ·
![alt text](image-13.png)

选择网格体，替换弹簧组件  
![alt text](image-14.png)

创建坦克组件  
![alt text](image-15.png)

我们没有办法改变胶囊体的位置  
![alt text](image-16.png)
选择右视图调节  
![alt text](image-17.png)
将坦克拖下  
![alt text](image-18.png)
选中胶囊体，选择为pawn  
![alt text](image-19.png)
弹簧臂的好处就是自动调整相机位置当被阻挡的时候  
调整弹簧臂组件的长度  
![alt text](image-20.png)
以这个为中心视角去玩游戏  


设置成玩家0即可  
![alt text](image-22.png)


# 006 C++ Game Mode
game mode 的作用  
![alt text](image-21.png)

在这里创建游戏模式  
![alt text](image-23.png)

选择这个  
![alt text](image-24.png)

写这个名字  
![alt text](image-25.png)

以我们刚刚创建的父级来创建一个蓝图类游戏模式  
![alt text](image-26.png)

创建图标长这样  
![alt text](image-27.png)

双击打开，选择我们刚刚创建的pawn设置成这个  
![alt text](image-28.png)

打开项目设置，设置蓝图类为我们刚刚创建的蓝图  
![alt text](image-29.png)

按下F8切换游戏视角  
![alt text](image-30.png)

可以看到存在一定的距离  
![alt text](image-31.png)

设置一下胶囊体的距离    
![alt text](image-32.png)

这两种方式都可以设置游戏模式，下面这个会覆盖项目设置的游戏模式  
![alt text](image-33.png)


# 007 Input Mapping Context

创建一个上下文input context  
![alt text](image-34.png)

创建之后长这样   
![alt text](image-35.png)

在ue自带的引擎文件里面用这个    
![alt text](image-36.png)
使用这个类来实现我们的系统  
![alt text](image-37.png)

这样子导入  
![alt text](image-38.png)

使用这个  
![alt text](image-39.png)

![alt text](image-40.png)

添加输入映射上下文  
![alt text](image-41.png)
双击打开  
![alt text](image-42.png)

选择这个  
![alt text](image-43.png)








