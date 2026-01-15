

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


# 008 Variable Declaration in Condition


![alt text](image-44.png)


# 009 Forward Declaration
讲了一下c++语法，同一文件可以定义多个类
![alt text](image-45.png)


![alt text](image-46.png)

# 010 Move Input
创建移动资产  
![alt text](image-47.png)

创建映射上下文，选中一个action资产  
![alt text](image-48.png)


添加这个  
![alt text](image-49.png)
以及这个  
![alt text](image-51.png)

加这个函数  
![alt text](image-50.png)

.cpp写入这个  
下面的this代表当前坦克这个实例，背下来就行了  
![alt text](image-54.png)

双击打开坦克  
![alt text](image-53.png)

![alt text](image-52.png)
点击打印  
![alt text](image-55.png)



# 011 Input Action Value Type
# 012 AddActorLocalOffset
Mapping Context 是“按键 → 行为”的映射集合 + 场景切换器  
action是什么？  
MoveAction	移动	Axis2D  
LookAction	视角	Axis2D  
JumpAction	跳跃	Bool  
FireAction	开火	Bool  
ZoomAction	开镜	Bool / Float  
![alt text](image-56.png)


这样子写我不知道为啥  
![alt text](image-57.png)


.cpp这样子  
ATank::MoveInput 不是每一帧都会被调用。  
它只在「对应 Input Action 处于激活状态时」，并且使用了 ETriggerEvent::Triggered，才会在每一帧被调用。  
![alt text](image-58.png)

打印出来就是 1  

![alt text](image-59.png)

加一个这样子的东西  
![alt text](image-60.png)




# 013 AddActorLocalRotation

![alt text](image-61.png)

接下來的挑戰  
![alt text](image-62.png)

创建一个input action  
![alt text](image-63.png)

双击打开更改这个   
![alt text](image-64.png)

在原先的上下文这里加入这个  
![alt text](image-65.png)


在坦克实例代码这里加入这个  
![alt text](image-66.png)

然后在.h文件加入这个  
![alt text](image-67.png)

加入这行代码  
![alt text](image-68.png)

旋转角度  
![alt text](image-69.png)

旋转角度设置  
![alt text](image-70.png)

双击打开  
![alt text](image-72.png)

选择这个  
![alt text](image-73.png)



打开坦贝实例，这里可以设置抬臂的延迟，上下延迟和左右延迟，延迟时间都可以设置  
![alt text](image-74.png)

修改这里的值  
![alt text](image-75.png)


# 014 Line Trace From Cursor



```
// 每一帧都会被 UE 调用一次（只要这个 Actor 开启了 Tick）
void ATank::Tick(float DeltaTime)
{
    // 调用父类（AActor）的 Tick
    // 父类里可能有引擎内部逻辑，几乎永远要保留
    Super::Tick(DeltaTime);

    // ② 拿到“控制这个坦克的 Controller”
    // Controller 是控制权的抽象，不关心是人还是 AI
    // 获取当前控制这个 Tank 的 Controller
    // GetController() 返回的是 AController*（可能是 AI，也可能是玩家）
    APlayerController* PlayerController =
        Cast<APlayerController>(GetController());

    // 判断：是否是“玩家控制器”
    // 如果是 AI 控制（AAIController），这里会是 nullptr
    if (PlayerController)
    {
        // 用来保存“射线检测”的结果
        // 包括命中点、命中的 Actor、组件等信息
        FHitResult HitResult;

        // 真正发射射线的地方
        // 从【摄像机 → 鼠标位置】向世界发射一条射线
        // 用来检测鼠标当前指向世界中的哪个位置
        // 垂直于摄像机平面的方向（摄像机视线方向），穿过鼠标像素点的射线
        PlayerController->GetHitResultUnderCursor(
            ECC_Visibility,   // 使用 Visibility 碰撞通道
            false,            // false = 使用简单碰撞（性能更好）
            HitResult         // 输出参数，保存检测结果
        );

        // 在射线命中的位置画一个红色的调试球
        // 仅用于调试，可视化鼠标指向的位置
        DrawDebugSphere(
            GetWorld(),               // 当前世界
            HitResult.ImpactPoint,    // 命中的世界坐标
            25.f,                     // 球的半径
            12,                       // 球的精细度
            FColor::Red               // 红色
        );
    }
}

```

我们可以看到这个玩意  
![alt text](image-76.png)

创建透明碰撞体 
![alt text](image-77.png)

设置他们的宽高  
![alt text](image-78.png)

设置这个通道为  visibility  
![alt text](image-79.png)

# 015 Rotating The Turret

炮塔旋转，因为炮塔和坦克都可以旋转，所以我们在父类实现  
![alt text](image-80.png)

添加方法  
![alt text](image-81.png)


```
// 炮塔旋转函数：使炮塔平滑地朝向目标位置
void ABasePawn::RotateTurret(FVector LookAtTarget)
{
    // 1. 计算从炮塔当前位置指向目标的方向向量
    // LookAtTarget: 目标的世界坐标
    // TurretMesh->GetComponentLocation(): 炮塔的当前世界坐标
    // VectorToTarget: 从炮塔指向目标的向量
    FVector VectorToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
    
    // 2. 将方向向量转换为旋转角度，只保留水平旋转(Yaw)
    // Pitch(俯仰) = 0.0f: 不向上或向下倾斜
    // Yaw(偏航): 从方向向量提取，控制水平旋转
    // Roll(翻滚) = 0.0f: 不左右倾斜
    FRotator LookAtRotation = FRotator(0.0f, VectorToTarget.Rotation().Yaw, 0.0f);
    
    // 3. 使用插值函数平滑过渡到目标旋转
    // 参数1: 当前旋转角度
    // 参数2: 目标旋转角度
    // 参数3: 帧间隔时间(Delta Time)，确保不同帧率下旋转速度一致
    // 参数4: 插值速度(10.0f)，数值越大旋转越快，越小越平滑
    FRotator InterpolatedRotation = FMath::RInterpTo(
        TurretMesh->GetComponentRotation(),  // 炮塔当前的旋转
        LookAtRotation,                       // 计算出的目标旋转
        GetWorld()->GetDeltaSeconds(),        // 上一帧到当前帧的时间间隔
        10.0f                                 // 旋转速度系数
    );
    
    // 4. 将插值后的旋转应用到炮塔网格体上
    TurretMesh->SetWorldRotation(InterpolatedRotation);
}
```

调用这个方法    
![alt text](image-82.png)










