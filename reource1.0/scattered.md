protect：对于子女和朋友是public，else private ;

[ ],(), . , -> 从左到右 ；                           -  ， ++ ，*(指针)  , & , ! ,(类型)  从右往左; 和对象相关的都是右

定义前加0b表示二进制数 ,int a = 0b00000001; 按位与的优先级和与一样，比等于低 ；typedef enum IRQn { Software0_IRQn = 0; Software1_IRQn = 1; ... } IRQn_Type     当函数有参数IRQn_Type 时，直接可以 int i = 0      (IRQn_Type)i 进行传参；typedef void (*system_irq_handler_t) (unsigned int giccIar, void *param)   表示定义了一个system_irq_handler_t类型的函数指针，当以之为参数时，必须传一个参数列表对应的函数的地址

memset 是对较大的数组或结构体进行清零初始化的最快方法(),因为是针对char型的所以int型也要写成sizeof(a) ; s.find(s1)在s中返回s1第一次出现的下标没找到返回string::npos；cin接收到空格或者回车就退出，但cin.getline()接收到回车才退出 ;  delete []a 释放数组空间 ; memcpy 对字符型数组的复制
1e9 = 1000000000;
![](images/2022-11-06-01-25-37.png)
![](images/2022-11-06-01-25-53.png)
![](images/2022-11-06-01-26-09.png)
const int fff = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
iostream迭代器: 
