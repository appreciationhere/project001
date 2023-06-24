MDK独有的main函数之前的启动函数
```
/* $Sub$$main 函数 */
int $Sub$$main(void)
{
  rtthread_startup();
  return 0;
}
```
内核:
rtthread_startup()函数初始化内核,如定时器,调度器,信号等; 建立main线程, 初始化系统堆等;
内存分布:
分为RO:包含了 Code 及 RO-data，表示程序占用 Flash 空间的大小; RW: 包含了 RW-data 及 ZI-data(未初始化全局变量)，表示运行时占用的 RAM 的大小; ROM:包含了 Code、RO-data 以及 RW-data，表示烧写程序所占用的 Flash 空间的大小;
rt_malloc 与 rt_memset 函数
自动初始化机制:
自动初始化机制是指初始化函数不需要被显式调用，只需要在函数定义处通过宏定义的方式进行申明，就会在系统启动过程中被执行; 
初始化函数主动通过这些宏接口进行申明，如 INIT_BOARD_EXPORT(rt_hw_usart_init)，链接器会自动收集所有被申明的初始化函数，放到 RTI 符号段中，该符号段位于内存分布的 RO 段中，该 RTI 符号段中的所有函数在系统初始化时会被自动调用.
内核对象模型:
RT-Thread 内核采用面向对象的设计思想进行设计，系统级的基础设施都是一种内核对象，例如线程，信号量，互斥量，定时器等。内核对象分为两类：静态内核对象和动态内核对象，静态内核对象通常放在 RW 段和 ZI 段中，在系统启动后在程序中初始化；动态内核对象则是从内存堆中创建的，而后手工做初始化。
RT-Thread 采用内核对象管理系统来访问 / 管理所有内核对象，内核对象包含了内核中绝大部分设施，这些内核对象可以是静态分配的静态对象，也可以是从系统内存堆中分配的动态对象。
管理方式:
都由rt_object_information 内核对象容器来进行管理;
在使用一个未初始化的静态对象前必须先对其进行初始化rt_object_init(); 脱离内核, 但内存不会被释放 rt_object_detach(); 
动态对象需要申请内存 rt_object_allocate(); rt_object_delete() 删除动态对象;
判别是否是系统对象, 只需 RT_Object_Class_Static 位置位。通常使用 rt_object_init() 方式初始化的对象都是系统对象, rt_object_is_systemobject();
遍历函数 rt_list_for_each(), 打印函数 rt_kprintf();
```
// 遍历所有互斥量
rt_mutex_t mutex = RT_NULL;
struct rt_list_node *node = RT_NULL;
struct rt_object_information *information = RT_NULL;

information = rt_object_get_information(RT_Object_Class_Mutex);

rt_list_for_each(node, &(information->object_list))
{
    mutex = (rt_mutex_t)rt_list_entry(node, struct rt_object, list);
    /* 比如打印所有mutex的名字 */
    rt_kprintf("name:%s\n", mutex->parent.parent.name);
}

```
内核配置示例:
配置主要是通过修改工程目录下的 rtconfig.h 文件来进行，用户可以通过打开 / 关闭该文件中的宏定义来对代码进行条件编译，最终达到系统配置和裁剪的目的;

