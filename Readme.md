##1.3.4题目4：光头强摘苹果

###完成效果：  
![](http://i2.piimg.com/d2d7c8e53c2b286f.png)  


###【问题描述】  
用 C 语言编写一个简单的“光头强摘苹果”游戏。光头强跳跃在各个移动滑块上，摘取树上的苹果，一定时长内摘取苹果数目多为胜。要求实现基本功能，选择实现扩展功能。  

###【基本功能要求】  
游戏主界面如图1所示：  
![](http://7xrn7f.com1.z0.glb.clouddn.com/16-4-25/85935707.jpg)
###一、主界面
1.	主界面分为三个区域：游戏区、按钮区和信息显示区。
2.	游戏画面同学可参照网上“光头强摘苹果”游戏的画面。
3.	按钮区应包括游戏主要按钮。如开始、暂停等
4.	信息显示区至少需要显示用户名、历史最高得分、当前得分、游戏倒计时等信息。  

###二、具体要求
1.	程序运行时先出现系统登录界面，输入用户名等信息，再显示主界面。
2.	游戏区中光头强起始位置在区域左下方，第一、三排滑块自右向左漂移，第二排滑块自左向右漂移，熊大位于区域的右边在三排滑块位置上下往返运动。
3.	单击“开始”游戏开始，滑块开始漂移，熊大开始运动，同时开始计时。光头强由←↑→↓键控制左右移动和上下跳跃，四个键配合使用使光头强踩上横移的滑块随之一起移动或跳下滑块，当滑块上有苹果时，按下空格键摘下苹果，累计苹果数。
4.	游戏结束时玩家和摘取的苹果数写入文件。游戏结束的条件有：①规定时间到；②光头强跳上滑块后必须逐级跃上跃下，且不能从滑块落下；③光头强不能随滑块移动出区域边界；④熊大会按一定频率在三排位置上匀速上下移动，当熊大与光头强处于同一排时，熊大正监视该排，光头强不能摘苹果，否则游戏结束。。
5.	三个层次的滑块数量以及哪些滑块上有苹果由程序随机产生。滑块移动的速度，熊大移动的速度，光头强移动的速度以及游戏时间由同学自行设置，注意这些参数需要反复通过实验调节，使得程序运行更加流畅。
6.	要求完成程序时注意游戏画面中的三排滑块随着移入和移出的边界，其在内存中的数据结构也要随之创建和删除，不可以用固定的滑块反复使用。  
  

####【扩展功能要求】
1.	能够显示玩家排行榜。这个功能需要从文件中获取每个玩家的最高得分，并按得分排序。
2.	增加和美化界面元素，是游戏更具趣味性。如：光头强向上跳跃时可能被滑块撞回，而不是直接站上。光头强跳跃时考虑到重力，且使曲线更加真实优美等
3.	游戏可以通过调整各种参数分级。
4.	添加更多的按钮功能。
5.	同时用键盘和鼠标控制游戏。
6.	任何可行的附加功能。
 
