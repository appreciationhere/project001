reg的信号类型往往代表触发器，在always块中赋值；默认的是wire,定义位宽[3:0] 4位;posedge , negedge，begin,end；   PS.wire类型(只能赋值一次) , 赋值是连续赋值(连线)，3种时延(assign # 10  '' ，wire #10 Z  = A & B , wire # 10 Z)赋值延时10个单位时间

数值表示

常量数字b,d,h,o，表示方式有3种 1.位宽'-进制-数字 2.进制-数字(至少32位位宽) 3.数字；在位宽前面加个 - 号表示负数，实数可用 e表示，负数可表示小数；字符串是用的ascll字符队列存储

运算和定位

运算符：{ }拼接运算符({a,b,c} == abc , { 4{b} }  = {b, b, b, b })，/是整除,下划线是为了增强程序的可读性,a[x]是位运算符；a[bit+ : width] , a[bit- : width] 表示访问从bit位开始+ - ,位宽位width；* * ：求幂 ； === 全等 ；~,^a这个向量操作数逐位进行操作，最终产生一个 1bit 结果

数据类型

常量参数  parameter 关键词；向量：reg ，wire ；integer ；real ； time ； 多维数组：在定义时的变量后面加上 [ ] [ ] ，例：reg [3:0] cont[4:0] 5个大小为4bit的reg数组；    PS.  reg的信号类型往往代表触发器，在always块中赋值；默认的是wire,定义位宽[3:0] 4位 ; wire类型(只能赋值一次) , 赋值是连续赋值(连线) ；real表示实数 ；一般让time = $time（一般为64bit)，$time 获取当前仿真时间

时序控制

时延控制  语句前面加 #10  右值前加 #10；边沿触发事件控制：posedge,negedge表示跳变，未指明则都会触发，event 事件变量定义，触发信号用 ->表示；always@里面可以加 * or ， *代表所有输入信号为敏感信号

语句块

begin，end ；fork，join ；   PS.  可以在begin ：’name' 来给模块命名 ，通过模块名.'name'.i被其他模块引用；disable 可终止命名块的执行和结束，类似于continue ; fork  是并行执行的 ，无论里面怎么写都是并行执行

循环语句

只能在always和initial块中使用，可以加延时； while ; for ; repeat( loop) ；forever只能用$finish退出

过程连续赋值

assign ,deassign ：赋值对象是reg类型，赋值过程是连续赋值，reg中值被保留直到被重新赋值 ； force，release：不论类型，一般用于交互式调试

带参数例化

高层可以改变低层的parameter ; defparam  ’name‘.'parameter'    ;     '模块名' #(.'name'('值') , .'name'(‘值’))  ； PS. 第一种必须给模块取名再.引用 ；第二种是对引入的该所有模块进行赋值，模块里面必须要在开头 定义 #(parameter  AW = 2 , parameter DW = 3)

函数

function [3:0]  'name'  ； input ...； endfunction一般函数执行时是使用的同一片空间(不能递归) 在函数定义时在function后面加automatic 就会调用一次分配新的空间，函数中把  ’name‘  当做寄存器返回值进行操作                                  PS. 函数不能包含任何时序控制逻辑，函数只能调用函数，至少有一个输入

任务

可以调用任务和函数，没有返回值，有无输入输出都可以；input 看作是wire类型，对 output 信号赋值时也不要用关键字 assign。为避免时序错乱，建议 output 信号采用阻塞赋值 ； task 'name' (input...  output... );  endtask ; 因为任务可以看做是过程性赋值，所以任务的 output 端信号返回时间是在任务中所有语句执行完毕之后。任务内部变量也只有在任务中可见，如果想具体观察任务中对变量的操作过程，需要将观察的变量声明在模块之内、任务之外，可谓之"全局变量"。;  也有automatic

消抖

因为信号传递的速度，所有系统会认为按下了很多次(抖动),用cont记录低电平的时间，到了大于某个值的时候判定为按下，同时高电平的时候为0; 用状态0 ，1表示

RAM

使用官方提供的IP，将数据展示存储起来； 设置位宽和深度，wea 为1是写，地址从0开始，读数据有一定的延迟。

同步复位和异步复位

模块设计思想

例按键控制灯：分为消抖模块和灯跳转模块，直接通过key_o来建立联系，操作是用一个a.v文件将两个模块的b.v，c.v文件连接起来，a.v里面应要定义一个中间变量将两个模块连接起来 ；input端内部只能用wire类型；悬空时out可以删除，input必须设置为0或者1；可以用 generate  endgenerate进行重复的模块例化，一般里面加for语句，i必须定义为genvar i；

编译指令 `

 define ,   undef , ifndef endif ;   include ;  timesale  '时间单位' / '时间精度' ;    PS. 一个文件下的时间单位和精度单位取决于最小的 ；  ps.   define 引用时要加 `

过程结构

initial ： 多用于初始化和信号检测，一般和#延时使用，多个initial是并行执行的，每个只执行一次

组合逻辑电路

所有的敏感信号都要考虑进去，建议用 * ，是针对赋值的，如果少了一个 敏感信号就可能发送寄存器锁存

仿真激励

module 'name';  reg clk ;wire led ...  ; initial 初始化   always块时钟赋值，$time 获取当前时间; $display 打印 ; $finish 结束仿真

RAM

 组合逻辑全部用阻塞赋值； 时序逻辑电路全部用非阻塞赋值  比如给next_state以及给wea和ena的赋值是阻塞赋值，给cont计数器和状态机最后一段用非阻塞赋值 ；ram读数据会比实际地址慢两个时钟周期；





















当一个变量的赋值条件是另外一个变量的某个值时，建议两个变量用同一个时钟周期，建议if else不超过 3层嵌套
