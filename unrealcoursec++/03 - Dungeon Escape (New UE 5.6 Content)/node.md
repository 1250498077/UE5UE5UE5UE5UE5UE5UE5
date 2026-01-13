



# 002 Creating The Project
创建一个level，然后
![alt text](image.png)
这里设置成开始  
![alt text](image-1.png)

创建一个box  
![alt text](image-2.png)
设置大小作为地图的大小  
![alt text](image-3.png)
修改这个方块名为地面  
![alt text](image-4.png)

修改成这个就可以看到地面了   
![alt text](image-5.png)
设置游戏开始胶囊  
![alt text](image-6.png)



# 003 Lighting Setup

加上直射光  
![alt text](image-7.png)

加上天空  
![alt text](image-8.png)

调整直射光可以调整太阳位置  
![alt text](image-9.png)


加上大气层  
![alt text](image-10.png)

加上云  
![alt text](image-11.png)

加上天空光  
![alt text](image-12.png)


去掉天空光会发现没有被照射的地方是纯黑的  
![alt text](image-13.png)

天空光设置这个可以瞬间变成黄昏  
![alt text](image-14.png)


将我们这些光照移到文件夹里面  
![alt text](image-15.png)



# 004 Materials

可以给不同的面不同的材质  

一次性给球体全部赋予材质， 先选中材质， 再拖动立方球体  
![alt text](image-16.png)


再拖动一个球体  
![alt text](image-17.png)

细节面板改成相减  
![alt text](image-18.png)


勾选上这个代表只是把这个面给删掉  
![alt text](image-19.png)


# 005 Game Mode



ue默认创建的蓝图类里面继承这个东西  
![alt text](image-20.png)
可以在c++里面看到类，我们也可以基于这个class创建一个人物蓝图，也可以基于它的子蓝图在创建一个子蓝图  
![alt text](image-21.png)




我们现在手动创建这么一个蓝图类，基于的是现有的一个蓝图    

![alt text](image-22.png)
进入细节之后我们隐藏它，两个我们都要隐藏    
![alt text](image-23.png)


这里讲到游戏模式  
![alt text](image-24.png)
游戏模式里面什么都没有  
![alt text](image-25.png)
重点是这里，游戏模式类似于定义从哪个main函数开始，因为可能会有多个main函数？
直接设置这里我们角色即可
![alt text](image-205.png)
![alt text](image-26.png)

或者在项目设置这里切换我们的main函数  
![alt text](image-206.png)
这里可以看到我们使用的是哪个游戏模式  
![alt text](image-207.png)


# 006 Inheritance vs Composition

# 007 Actor Components
component就是工具方法的意思，但是因为也有生命周期，所以也不能被叫工具方法，因为类只能单继承，所以需要component


创建compoennt  
![alt text](image-28.png)
可以看到继承的是这个东西   
![alt text](image-29.png)


添加简单方法  
![alt text](image-30.png)

使用component   
![alt text](image-31.png)


# 008 Pointers 101
指针和引用的概念  

![alt text](image-32.png)

![alt text](image-33.png)


修改新的变量也会改掉原来的值  
![alt text](image-34.png)

直接赋值相当于copy  
![alt text](image-35.png)
这样子相当于给个引用  
![alt text](image-36.png)

# 009 Pointer Practice

简单的例子  
![alt text](image-37.png)





![alt text](image-39.png)
打印  
![alt text](image-38.png)



![alt text](image-41.png)

![alt text](image-42.png)


# 010 GetOwner
获取当前使用这个compoennt的  
![alt text](image-43.png)
加个*代表获取他的引用  
![alt text](image-44.png)

![alt text](image-45.png)
设置
![alt text](image-46.png)


# 011 FMathVInterpConstantTo

![alt text](image-47.png)



利用c++的api去实现移动  
![alt text](image-48.png)

# 012 Owner Goes Back

这是设置来回的代码  
![alt text](image-49.png)



# 013 FVector Equals


![alt text](image-50.png)




# 015 C++ Compilation Steps

![alt text](image-51.png)




# 016 Box Component
创建一个box
![alt text](image-52.png)

![alt text](image-53.png)

将别的box copy过来  
![alt text](image-54.png)
我们选中一个mesh，想添加trigger，但是发现找不到  
![alt text](image-55.png)

copy这个  
![alt text](image-56.png)





然后再copy过来  

![alt text](image-57.png)

保存编译之后，我们在ue就可以搜索到这个trigger

![alt text](image-58.png)
![alt text](image-59.png)



# 017 The Constructor

简单设置就可以让碰撞触发了  
![alt text](image-62.png)


![alt text](image-61.png)
会连续打印  
![alt text](image-63.png)

![alt text](image-64.png)


# 018 FindComponentByClass

.h文件添加这个变量  
![alt text](image-65.png)

![alt text](image-66.png)
这样子选中这个门  
![alt text](image-67.png)

现在实现一个逻辑，一个碰撞体发生碰撞，会触发另一个物体的动作方法，这里的教程是把门的动作方法传入到碰撞体  
![alt text](image-68.png)
再定义一个，用来装东西   
![alt text](image-69.png)
下面这个方法是在这个 Actor 身上，找一个类型是 UMover 的组件
![alt text](image-71.png)





# 019 True and False Values


![alt text](image-72.png)


![alt text](image-73.png)


把代码改成这样子也可以  
![alt text](image-74.png)


# 020 Using Delegates
![alt text](image-75.png)

.h文件  
![alt text](image-76.png)

.cpp文件  
![alt text](image-77.png)

在beginpplay方法
![alt text](image-78.png)

# 021 Actor Tags

让一张椅子下落触发碰撞事件  
![alt text](image-79.png)

设置物理属性，添加重量模拟  
![alt text](image-80.png)

再勾选这个  
![alt text](image-81.png)





接下来实现在actor上添加tag，然后获取tag，只有指定的tag才可以触发事件  
![alt text](image-82.png)
![alt text](image-84.png)




# 022 Logical And Operator

![alt text](image-85.png)



# 023 Refactoring Code


# 024 Public & Private


![alt text](image-87.png)


![alt text](image-86.png)
私有变量可以这样子访问  
![alt text](image-88.png)
.h文件  
![alt text](image-89.png)
.cpp文件这样子定义方法  
![alt text](image-90.png)


# 025 Keeping Count
讲了一下碰撞计数  


![alt text](image-91.png)


![alt text](image-92.png)

# 026 BP_PressurePlate

创建一个蓝图类  
![alt text](image-94.png)
我们可以在蓝图里面添加我们创建的类  
![alt text](image-95.png)
本来是有一个默认的根场景  
![alt text](image-96.png)
然后就变成这样  
![alt text](image-97.png)
调整好大小后  
![alt text](image-98.png)

![alt text](image-99.png)

![alt text](image-100.png)

![alt text](image-101.png)

让它自己动，将之前写的move类加入进来  
![alt text](image-102.png)

![alt text](image-103.png)


# 027 Adding Tags in C++


![alt text](image-104.png)

![alt text](image-105.png)
创建一行代码   
![alt text](image-106.png)
![alt text](image-108.png)
创建一个蓝图类  
![alt text](image-107.png)


# 028 CreateDefaultSubobject

通过代码的方式设置层级  
![alt text](image-109.png)

![alt text](image-110.png)

# 029 Lock Blueprint

![alt text](image-111.png)



![alt text](image-112.png)

蓝图类结构长这样  
![alt text](image-113.png)  
可以在这里设置这个玻璃   
![alt text](image-208.png)  

点击这个可以看到在代码看到的 tag  
![alt text](image-115.png)



# 030 Collision

这个章节主要讲解actor之间的碰撞  
一个actor可以设置成跟所有物体类型碰撞，也可以设置成跟特定类型碰撞  
选中物体，看这个，默认是default  
![alt text](image-116.png)
是将当前的物体设置成什么类型  
![alt text](image-117.png)


如果设置成自定义的话， 下面这个方框可以设置和其他物体的交互情况  
![alt text](image-118.png)



这张图是 UE 碰撞系统（Collision）里最核心、也是最容易把新手搞懵的一块。
我直接用一句话总览 + 分区拆解 + 典型误解给你讲清楚。

一句话总览（先建立直觉）

这整块面板的本质是在回答 3 个问题：
1️⃣ 我这个物体算“哪一类东西”？
2️⃣ 别的东西 / 射线 来碰我时，我怎么反应？
3️⃣ 是真的“挡住”，还是只是“知道碰到了”？

一、Collision Enabled（是否参与碰撞）
Collision Enabled (Query and Physics)

这是一个总开关：

Query：
👉 能不能被「射线检测 / Sweep / Overlap 查询」命中
（比如：射击、视线、鼠标点击）

Physics：
👉 能不能参与真实物理碰撞
（挡人、挡箱子、受力）

常见组合：

设置	含义
No Collision	完全透明，啥都碰不到
Query Only	看得见、点得到，但不挡人
Physics Only	能被物理推，但射线检测不到
Query and Physics	最常用：又挡又能被检测
二、Object Type（我“是什么东西”）
Object Type: WorldStatic

这是在说：

“别人眼里，我属于哪一类物体？”

常见类型你可以这样理解：

类型	直觉含义
WorldStatic	不动的世界物体（墙、地面）
WorldDynamic	会动的物体（门、平台）
Pawn	角色
PhysicsBody	可被物理推动的物体
Vehicle	载具
Camera	摄像机
Custom	你自己定义的

⚠️ Object Type 不是“我怎么对别人”，而是“别人怎么区分我”

三、Collision Responses（别人碰我时我咋办）
Ignore / Overlap / Block（三选一）

这是整套碰撞系统的核心语义：

选项	含义
Ignore	当它不存在
Overlap	穿过去，但触发事件
Block	挡住，不能穿
四、Trace Responses（射线对我的反应）
Visibility / Camera

这是给 射线（LineTrace / Sweep）用的

典型理解：

Visibility

枪线

视线

鼠标点选

Camera

摄像机防穿墙

第三人称镜头拉远

你这里全是 Block，意思是：

👉 枪线打到我会被挡
👉 摄像机不能穿过我

五、Object Responses（“某类物体”碰我时）

这部分非常关键：

比如这一行：
Pawn → Block


意思是：

角色（Pawn）撞到我，会被挡住

如果你改成：

Pawn → Overlap


就会变成：

人可以穿过去，但能触发 Overlap 事件
（比如传送门 / 触发区域）

六、把你这张图“翻译成人话”

结合你图里的设置，完整语义是：

我是一个 世界静态物体（WorldStatic）

我参与 射线检测 + 物理碰撞

任何东西（Pawn / WorldDynamic / WorldStatic）
👉 撞到我都会 被挡住

枪线、视线、摄像机
👉 都会被我挡住

👉 典型用途：墙、地面、不可穿越障碍物

七、新手 90% 会误解的点（你一定会踩）
❌ 误解 1：我勾了 Block，为什么还能穿？

原因通常是：

对方也要 Block 你

碰撞是 双方结果取最“弱”的那个

👉 Ignore > Overlap > Block
只要一方是 Ignore → 就当没发生

❌ 误解 2：Overlap 不挡人，为啥还能触发事件？

因为：

Overlap = 空间重叠检测

Block = 物理阻挡

这是两套不同系统。

❌ 误解 3：Object Type 决定我挡不挡人

错 ❌
真正决定的是：

Object Type × Object Responses 的组合

八、给你一个“程序员式心智模型”

你可以把碰撞系统当成一个二维规则表：

我是什么类型？
×
我对对方类型的反应？
=
最终行为


UE 每一帧都在做这个矩阵判断。

九、结合你在做 FPS / 恐怖游戏，给你几个实用配置
墙 / 地面

ObjectType: WorldStatic

Pawn: Block

Visibility: Block

Camera: Block

触发器（空气墙 / 区域）

Collision Enabled: Query Only

Pawn: Overlap

其他：Ignore

摄像机防穿墙盒

ObjectType: WorldStatic

Camera: Block

Pawn: Ignore

# 031 Setting Visibility

![alt text](image-119.png)
get和set方法需要现在.h定义  
![alt text](image-121.png)

![alt text](image-120.png)

![alt text](image-125.png)



# 032 Enhanced Input System

下面是单个动作  
![alt text](image-122.png)
这是控制器  
![alt text](image-123.png)
打开控制器可以将单个动作添加进来  
![alt text](image-124.png)

![alt text](image-126.png)

![alt text](image-127.png)


创建一个动作  
![alt text](image-128.png)
加一个东西  
![alt text](image-129.png)


# 033 Input System in C++
这里说的是好像是，将e键绑定到动作，然后将动作绑定到c++函数，实现当这个动作执行的时候，我们的代码逻辑层面要做什么  

打开  
![alt text](image-130.png)
打开这个  
![alt text](image-131.png)
可以看到控制器  
![alt text](image-132.png)

![alt text](image-133.png)

![alt text](image-134.png)

下面是角色的动作资产  
![alt text](image-136.png)


打开我们的蓝图类  
![alt text](image-135.png)
点击这个  
![alt text](image-137.png)
对应的ue编辑器是这里  
![alt text](image-138.png)

下面这个又是新的东西  
![alt text](image-139.png)


![alt text](image-140.png)


下面定义了一系列方法  
![alt text](image-141.png)
按照我们之前加的，我们在这里加一个  
![alt text](image-142.png)

在创建一个这个  
![alt text](image-143.png)


触发这个事件的时候调用下面这个方法  
![alt text](image-145.png)
打开它  
![alt text](image-144.png)
这里选择上我们的动作  
![alt text](image-146.png)

按下e就打印了  
![alt text](image-147.png)


# 034 Line and Shape Tracing

![alt text](image-148.png)

随便点击一个物品，就可以看到这个  
![alt text](image-149.png)

可以将物体设置成这个
![alt text](image-150.png)


可以将物体设置成这个
![alt text](image-151.png)


# 035 UWorld Object

打印了一下关卡开始时候的时间  

![alt text](image-152.png)



# 036 Start & End Points
画一条线  
![alt text](image-209.png)

![alt text](image-153.png)
相机绑定在角色头部
可以通过鼠标控制视角
设置了合适的 FOV 和模型缩放
调整了相机相对于头部的位置和角度，以获得最佳的第一人称视角





获取第一人称相机的世界坐标位置，这是射线的起始点

GetForwardVector(): 获取相机的前向向量（朝向）
* MaxInteractionDistance: 乘以最大交互距离（比如 200cm）
Start +: 从起点向前延伸
结果：射线的终点位置
如果 MaxInteractionDistance = 200.0f，就是检测相机前方 2 米范围内的物体
可视化显示射线，方便调试
GetWorld(): 当前世界
Start, End: 射线的起点和终点
FColor::Red: 红色线条
false: 不持久显示（每帧重绘）
5.0f: 线条粗细为 5 个单位
![alt text](image-154.png)




# 037 Sphere Collision Shape


在一个位置创建球体  

![alt text](image-155.png)

![alt text](image-156.png)

![alt text](image-158.png)

![alt text](image-157.png)


# 038 C++ References


![alt text](image-159.png)


![alt text](image-161.png)


![alt text](image-162.png)


![alt text](image-163.png)


![alt text](image-164.png)

# 039 Pass By Reference

![alt text](image-165.png)

![alt text](image-166.png)

![alt text](image-167.png)


# 040 SweepSingleByChannel
```
FHitResult HitResult;
bool HasHit = GetWorld()->SweepSingleByChannel(
    HitResult,                    // 存储命中结果
    Start, End,                   // 起点和终点
    FQuat::Identity,              // 旋转（无旋转）
    ECC_GameTraceChannel2,        // 碰撞通道
    InteractionSphere             // 球形检测体
);
```
![alt text](image-168.png)


# 041 Else If Statement


![alt text](image-169.png)




# 042 Casting

获取被碰撞物体的实例，强转
导入需要强转的类
![alt text](image-170.png)

强转，就可以获取类里面的方法  
![alt text](image-171.png)

cast强转语法  
![alt text](image-172.png)



# 043 TArray
数组  
![alt text](image-173.png)

添加到数组，删除元素  
![alt text](image-174.png)

可以看到面板增加了  
![alt text](image-175.png)


# 044 Removing From Array

![alt text](image-176.png)

![alt text](image-177.png)


# 045 Taking Items Back





# 046 Dungeon Assets
目录整理  
![alt text](image-178.png)
![alt text](image-179.png)

![alt text](image-180.png)


复制一份  
![alt text](image-181.png)



![alt text](image-182.png)
项目设置这里加载默认关卡  
![alt text](image-183.png)
找到地板  
![alt text](image-184.png)
去掉这个  
![alt text](image-185.png)
添加一份碰撞  
![alt text](image-186.png)


# 047 Spot Lights


创建一个普通的actor  
![alt text](image-187.png)
添加一个我们之前创建的类  
![alt text](image-188.png)



将地板拖进来  
![alt text](image-189.png)
调整触发器大小和模型重合  
![alt text](image-190.png)

给牢笼加一个移动类  
![alt text](image-191.png)

移动y轴-500 ，设置移动时间为6秒  
![alt text](image-192.png)

trigger调用的是笼子实例的移动方法  
![alt text](image-193.png)


创建一个这样子的蓝图  
![alt text](image-194.png)
拖动  
![alt text](image-195.png)

把蓝图放到桌子上  
![alt text](image-196.png)

为了让玩家知道哪里触发，在需要的地方加一个聚光灯  
![alt text](image-197.png)
聚光灯有外锥体和内锥体  
![alt text](image-198.png)



# 048 Secret Wall

![alt text](image-199.png)

把它拖进来  
![alt text](image-200.png)
搭建好模型，做好触发器组件  
![alt text](image-201.png)
加一个移动器组件  
![alt text](image-202.png)


设置时间和移动距离  
![alt text](image-203.png)

找到触发器，选中门  
![alt text](image-204.png)






