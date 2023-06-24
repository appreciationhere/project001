# java基础学习

## 第一章

### java重要特点

#### oop

#### java语言是健壮的

 #### 跨平台

#### 解释性语言（需要解释器来执行）

### JDK,JRE（java如何运行）

JDK包含了JRE+开发工具集，JRE包含了JVM和SE的标准类库。通过javac编译，.class文件(字节码文件)通过装载到JVM虚拟机上运行。

### 入门语法

`public class hellow{
	public static void main(String[] args) {
		System.out.println("hellow,world~");
	}
}`



只能有一个public类，编译后每一个类都对应一个.closs文件，文件名必须是public类的名字,可以在类的里面加入main函数，指定运行这个类

### 如何快速学习技术和知识点

1. 需求
   1. 工作需要
   2. 跳槽对方要求
   3. 技术控

2. 传统技术能否解决
   1. 能，不完美
   2. 解决不了

3. 引出我们学习新技术和新知识点
4. 先学习基本原理和基本语法(不要考虑细节)
5. 快速入门(基本程序，ctrud)
6. 开始研究技术的注意事项和使用细节，使用规范，如何优化

### 转义字符，注释和DOS

#### 转义字符

tab键命令补全，\ t制表单位实现对齐\n,\ \一个斜杠,\ ",\ ',\ r一个回车\u###一个Unicode编码的字符

#### 注释

1. 单行和多行注释

2. 文档注释 

   - javadoc的标签

   - javadoc -d D:\java_code\wenjzhushi\java1.0 -author -version Test.java

#### java代码规范

1. 空格的使用和源文件一般用UTF-8保存
2. 行尾风格和次行风格

#### dos的基本原理

- dos系统接收，解析，执行指令然后操作widows系统

- dos的指令md，rd,dir,cd(cd /D c:),tree (tree d:\abc),cls(清屏),ext(退出DOS),copy,del等

### java的数据存储和类型之间的转换



#### java的数据类型

- 基本数据类型

  浮点数的存放形式为符号位+指数位+尾数位(小数都是近似值)

  末尾以l，f，等结尾。Java浮点数的默认值为double型。

  e2/E-2的用法

- 引用数据类型

  - 类
  - 接口
  - 数组

#### 浮点数的规则

- 当我们对运算结果是小数的进行相等判断时要小心(因为通过计算的浮点数的存储是近似的存储)
- 判断大小应该是以两个数的差值的绝对值，在某个精度范围类判断

#### java类的组织形式

##### JDK8，11

- 包一
  - 接口
  - 类
  - 异常等
- 包二
- 包三

####  存储和编码类型

1. Unixcode 强制类型转换输出对应的类型

2. 编码的类型决定了文件中存储的字母数和汉字的字节数

3. 字符和码值的对应关系是通过字符编码表决定的(计算机先找出整型编码再转换成二进制存储)

#### 类型转换

1. 自动类型转化的规则和细节
   1. byte,short,char不能进行自动转换(byte存储时计算机先判断数是否在byte范围内)
   2. boolean不参与自动转换
2. String类型与其他类型的相互转换
   1. 转换为int,float等字符串只能为’数字‘
      1. parseInt(str1)
      2. 使用构造器Integer(str1)
   2. 如何转换为字符型
   3. 其他类型转换为字符串
      1. 定义一个String a = i  + ""；
      2. 包装类可 调用toString()
      3. 或者用String.valueOf(i)

## 第二章

### 属性,数组,对象

#### +号的使用(从左到右,字符串的连接和运算);

#### 各种命名规则

#### 数组(引用类型,数据是对象)

1. 动态初始化
2. 静态初始化
3. 数组的扩容

#### 对象的内存分布

1. 属性是全局变量，方法是局部变量

#### 属性的规则和细节

- 属性属于全局变量，可以在其他类中定义该类获取该类的属性值
- 方法中的局部变量只能在本方法中使用，而且不能+修饰符

#### 类和对象的内存分配机制

- 当定义一个对象并用构造方法时，先在方法区加载一个类的信息，再在堆中开辟一个空间并

  进行0，null的赋值，再赋值为属性的定义值，最后赋值为构造器中的值

### 方法

#### 定义方法

privata的函数和pubilic的函数的区别

#### 方法参数

可变参数如String[],this变量,this的本质是创建类的时候也创建了一个this指针指向创建的

这个类，同时把指针的值返回给创建的类名

#### 参数绑定

指针指向的数据可以通过形参改变

### 构造方法

#### 默认构造方法

可定义多个不同形参的构造方法，也可定义默认初始化，没有返回值，只能用new

初始化，初始化时先设置为默认值再调用构造函数(如果我们自定义了一个构造方法，那么，编译器就*不再*自动创建默认构造方法)

#### 多构造方法的调用

系统根据参数来匹配构造方法，构造方法可互相调用使用this(...)

### 方法重载

一般为相同的返回类型(函数重载和返回值类型无关)，不同的参数

### 继承

通过extends来完成，继承类中不能定义基类中重名的字段

A extends B A是B的子类

#### 继承树

object为默认的最高的基类，且只允许继承于一个类

#### protected

为了使子类和子类的子类能访问基类的字段，在基类的声明中加上proted

#### super

super.   和super()，子类不会继承基类的构造方法，调用子类的构造方法时必须先调用

基类的构造方法，漏了系统会自动+一句super(),可调用复写的方法(只能在构造器中使用)

this()和super()不能在一个构造器中使用.super,this是为了解决基类和子类重名问题

#### 阻止继承

从java15 开始允许使用`sealed`修饰class，并通过`permits`明确写出能够从该class继承的子类名称

#### 向上/下转型

上：向上转型实际上是把一个子类型安全地变为更加抽象的父类型

下：先用A instanceof B判断A是否是B的子类或B类型(运行类型)，再强制类型转化，从Java 14开始可以省略强制类型转换,转换条件是基类必须指向该强制类型转化子类

#### 区分继承和组合

继承是is关系，组合是has关系。

#### new一个子类的内存分配

先加载基类和子类的在方法区，再在堆中分配空间，最后返回该空间的地址

#### 查找属性的步骤

往上找，private停下



### 多态

Java的实例方法调用是基于运行时的实际类型的动态调用，而非变量的声明类型。

多态具有一个非常强大的功能，就是允许添加更多类型的子类实现功能扩展，却不需要修改基于父类的代码

#### 多态的前提是继承，运用向上/下转型

#### 动态绑定机制

调用对象方法时会根据运行类型绑定,属性则没有，运行到那个对象就调用哪个对象的该属性

#### 多态的应用

#### 多态数组

创建基类的数组，初始化指向不同的子类，再用instance of判断子类的类型并转型，再分别调用

各自子类的特点方法

#### 多态参数

方法定义的形参是基类类型，实参类型允许为子类类型

#### 复写

方法定义要一模一样，或子类返回值是基类返回值的子类，@override帮助检查复写是否正确子类

子类方法不能缩小分类方法的访问权限,编译类型(指针类型)和运行类型(指向的类型),属性没有复写

属性的值看编译类型

### object类

#### equals方法

==：是比较运算符来判断基本类型和引用类型(地址)

equals:  一般用于对象判断地址或者判断大小是否相等，-128到127,Integer.valueOf(int)不会创建Integer的新实例,而是从其缓存中返回一个值。

#### hashCode方法

提高有hash结构容器的效率，主要根据地址来编号(将内部地址转换成一个整数,但不是地址)

#### toString方法

默认返回全类名(包名+类名)+@+hashCode，一般重写 快捷键 Alt+Insert,sout (对象)默认输出对象的

toString

#### finalize方法

当free对象(NULL)时会默认调用该方法，调用垃圾回收器有自己的一套gc算法，也可通过System.gc()

主动调用垃圾回收器(可能调用不灵)。该方法很少用

#### final

不能继承,如public final String name,final的属性赋初值可在定义时/构造器/代码块;静态属性只能在定义时或者在静态代码块中初始化,和static搭配效率更高(不会导致类加载)，包装类是final类型的；可在形参中使用



### 抽象类

不能实例化，有抽象方法的类必须定义为抽象类，用abstract来修饰类和方法，抽象方法没有主体代码，子类继承了抽象类的基类必须实现所以抽象方法，除非继续声明为abstract

#### 抽象类的模板设计模式

基类的普通公共方法调用抽象方法(子类中重写)实现代码的模板,实现的化直接创建子类的对象调用基类的普通公共方法就可以实现功能

### 接口

当一个类中没有字段全部是抽象方法时可以把该抽象类定义为 interface Person当定义了接口时就可以不用写abstract,一个类可用implements继承使用多个接口,接口中有方法的具体实现

#### default方法

可以在接口中增加default方法而不必在子类中定义此方法，因为接口没有字段

default void run(){...}所以无法访问字段，但抽象类的普通方法可以访问实例字段

#### 应用场景

在主函数下面写一个静态方法，参数是接口名，方法里面调用重写的方法，可实现统一的管理

当接口和基类有相同的变量名时，可用super.x和接口名.x访问

#### 细节1

不能实例化，方法都是public，抽象类可以不用全部重写方法,接口可以有自己的static方法

#### 细节2

interface可以用extends继承interface，一般实例化的对象都是具体的子类用接口去引用

#### 接口和继承的区别

接口是用于子类的拓展方法实现(设计规范方法让其它类去实现)，继承是创建就有的功能( 解决代码的复用性和可维护性)，接口更加灵活

#### 接口的多态特性

可以定义接口指向实现了该接口的对象实例，多态数组，和向下转型，多态传递现象(extends继承接口，实现子类接口的类创建的对象实例基类和子类的接口都可以指向)

### 静态字段与静态方法

静态字段不属于实例，所有实例共享一个字段，接口中的属性只能(默认)是final，访问形式为接口名.属性，接口只能继承接口类，接口的修饰符只能是public和默认

#### 静态方法

特点是不需要实例就可以通过 类名.方法名(...)就可以访问该方法，但只能访问方法里面的静态字段，该方法常用于工具类;可以被继承，但不能重写，编译阶段就确定

#### 接口的静态字段

interface的字段只能是public static final型，所以可以省略。

## 第三章

### 包

创建不同的文件夹或目录存储类

#### 包的入门

1. 包的作用

2. 包的创建和使用方法

3. 各种快捷键

   

#### 包的内容

##### 不能同时引入不同目录下的相同名字的类的包

##### 包的命名和规范

##### 常用的包和分类

##### 包的引入方法

##### 打包的规范

### 编程的应用

#### 构造器与set的使用

#### 房屋出租系统

##### 界面层

##### 业务层

##### 模型层

### static属性和方法

属性是在类加载时在堆中创建的且所以对象共享该空间；方法里面只能调用该类的static类，用于写一些不需要创建类直接就可以调用的方法成为工具,方法不能重写,但子类中可以有与基类static类相同的类名，它们是相互独立的。普通类是不允许声明为静态的，只有内部类才可以。被static修饰的内部类可以直接作为一个普通类来使用，而不需实例一个外部类

### main函数的理解

### 代码块

#### static 代码块

在类加载的时候运行且只运行一次，和static属性优先级一样，且只能调用静态成员

##### 什么时候类加载

#### 普通 代码块

在创建对象实例时运行，创建一个运行一次，和普通属性初始化，和构造器优先级一样

##### 创建对象时一个类的调用顺序

### 单例设计模式

#### 饿汉式   

 通过new创建static 的属性

#### 懒汉式    

先创建一个指针 ，再在static方法中判断是否为空并创建

### 内部类

#### 局部内部类

可看成局部变量（作用域），定义类只能使用final，本质还是类(可继承)，可访问一切外部成员，外部类要访问只能new一个该类，但外部其他类不能new该对象访问，外部类和内部类可重名，并需通过外部类名.this.变量名来放问重名的外部变量

#### 匿名内部类

本质是对象和内部类

##### 背景

为了解决接口/对象里面的函数实现一次而创建对象的问题等繁琐问题

##### 细节

当写成A  a = new A()；编译类型是左边，运行类型是隐藏的内部类(外部类名+$+编号)，相当于为A的接口，里面只能重写A的函数，用a.  调用；  new A(){}.成员 里面可以有自己的成员。

##### 使用方法

 当调用静态方法f1时写成  f1 ( new 类名(...){} );当形参传递；A类中的函数参数为B接口名并调用B的函数，实现调用A函数时用匿名内部类重写函数当作参数，进行动态绑定

#### 成员内部类

本质是一个成员变量，可加修饰符，可访问外部所以成员，作用域为整个类体，其他外部类要调用成员内部类的**两种方法**，重名时遵守就近原则；但是static成员内部类只能访问外部类的静态变量，**两种方法**有点不一样

### 枚举

#### 自定义枚举

私有化构造器，不提供set方法，在类里面用构造器定义所枚举的**常量**，并用static final修饰

#### enum关键字

本质和自定义一样，只是该类实际上是继承了lang包的Enum类，无参构造器可不写()，所定义的枚举的**常量**必须在enum类的首行，之间用，隔开；只能继承接口

#### 基类Enum的常用方法

常量名.name()  返回常量名；.ordinal()  编号；类名.values()  所有常量数组(可通过tostring方法改写获取到的字符串)；类名.valueOf(常量名)   该常量名的信息  ；类名.常量名.compareTo(类名.常量名)    返回相对位置

### 注解

做为程序的补充信息，表示注解类

#### 常用注解

@override  检查是否真的重写，只能修饰方法；@Deprecated修饰表示已经过时，但仍然可以使用；@SuppressWarnnings ({""})  希望不显示的

#### 元注解

@Target是修饰注解的注解，称为元注解

### 异常

分为error和**exception** ，exception又分为运行异常(不必须处理)和编译异常(必须处理)

#### 异常体系图

常见的5大运行异常

空指针，运算，数组下标，类型转换，数字格式

#### 异常处理机制

try(遇到异常直接跳转)，Catch(有异常才执行)，finally(始终要执行,可有可无)throws抛出异常给调用的一级(默认的编译异常处理方法)； JVM处理异常是直接退出程序输出异常信息

#### try catch finally使用

 try{...}catch (异常种类  a){...} a.getMessage()可得到异常的信息,并通过printStackTraced打印，允许多个catch的存在，但是父类异常必须写在子类异常的后面； try{...} finally{...} 如果try中有异常，finally执行后会直接退出，用于必须执行某个业务逻辑

#### throws使用

默认的处理方式，方法抛出的异常可以是异常或者它的基类，继承的throws也要满足继承关系

#### 自定义异常

先定义一个自己的一个异常类A继承运行异常(可以使用默认的处理方法)，里面重写构造器方法，调用时用throw(thows后面带的异常类型,throw是在方法体内创建对象)  new A(...提示)

## 第四章

### 包装类

继承和接口的体系，JDK5后是自动装箱和拆箱，底层原理都一样；str之间的相互转换.常用方法:判断是不是数字，字母，大小写，空格；大小写的转换等等

### String

继承，接口关系，多种构造器，有value[]属性(privata final char)；final类不能被继承；

#### String的对象特性

String a = str1 + str2 和String a = "hell" + "ow"的分析；两种创建对象的区别；final char[] a = {'1','2'} 的内容是储存到堆中的用a[i] = 可以改变值，但不能改变a的指向

#### String的常用方法

替换，分割，大小写，查找，比较，格式化format("我的名字是%s",name)，字符串转为字符数组toCharArray

#### StringBuffer

对字符串的增强；直接父类是AbstractStringBuilder ,实现 Serializable 可以串行化，存放的属性是char[ ]  value(不是final，在堆中),存放的内容可以随时修改，3种构造器，默认构造器有16 个char型

##### 常用方法

apend delete replace  toString  indexOf   insert  length

#### StringBuilder

继承关系和StringBuilder相同，是它的简易替换没有互斥处理，适用于单线程

### Math

abs(绝对值)，pow(求幂) ，ceil(向上取整)，floor(向下取整)，round(四舍五入)，sqrt，random，max，min

### Arrays

toString，sort(解析运用匿名内部类Comparator接口重写方法，定制排序)， binarySearch(要求有序)，copyOf(a,length)，fill(填充，替换原来的数组)，equals，asList(转换成list集合)

### System类

exit(退出状态)；arraycopy(源数组，原数组拷贝位置，目标数组，目标数组的位置，拷贝长度)(一般用arraysCopy，底层就是用的System.arrayscopy)；当前时间；gc()

### BigInteger和BigDecimal类

初始化用"..."在构造器中创建，四则运算要使用相应方法，小数相除可以设置精度

### 日期类

#### Date类

默认获取当前时间 ；SimpleDateFormat类，定义时间输出格式，可以将格式写成字符串然后转换为改定义形式

#### Calendar类

能够单独的使用方法来指定日期时间等的输出(Hurn-ofday)，需要用getInstance方法初始化

#### LocalDateTime 类

有LocalaDate和LocalTime；DateTimeFormatter的format返回字符串；Instance和Date可以相互转换；提高的Plus和minus可以对当前时间进行加减

### 集合框架体系图

vector arraylist  linkedlist ；treeset hashset；property->hashtable linkedhashmap->hashmap  treemap，动态保存，有add，remove，(tostring已经被重写)等简便方法

### collection接口

可以存放object对象(null)，有contains(查找是否存在) isEmpty clear addAll  removeAll

#### 遍历方式

iterator的使用和再次遍历的重置；增强for，本质是iterator的简化

#### list接口

 添加顺序和取出顺序一致，支持索引；有添加，指定位置添加，添加集合，获取位置元素，索引最开始或者最末尾返回位置，移除(默认第一个),替换(set),按指定位置返回子集合等

##### Arraylist类

 线程不安全，底层是可变数组，增添效率低，改查效率高，重点看add()的源码

##### linkedlist类

线程安全，底层是双线链表，增添效率高，改查效率低

#### set接口

不能通过索引遍历，不能重复，无序(不是添加的数据但是固定的)

##### Hashset类

remove指定删除对象，底层是链表+数组+红黑树(Hashmap)，add()源码重点

##### Linkedhashset类

是hashset类的子类 双向链表存储

##### Treeset类

可以排序（指定排序规则，相等则不会存放进去），底层是treemap，必须实现comparable接口

#### Map接口

与collaction并列存在，key不允许重复，存储原理是用的hashmap里面的静态内部类Node节点(实现了map.entry接口，方便遍历，里面放的entry类型的集合(指向Node)，entry类型里面有<key ，value>)

##### 常用方法

containsKey  put  remove  get  size isEmpty  clear values   entrySet

##### 遍历方法

用keySet(),取出，再get；用values方法；用entrySet获取K-V可以之间输出得到set也可以用entrySet.getValue.getKey方法，用getKet和getValue输出

##### HashMap类

实现map最常用的类，线程不安全，synchronized是实现同步的接口，数组+链表+红黑树

##### Hashtable类

线程安全，不能存放null，是用Hashtable里面的静态内部类存放的，初始化为11，也是0.75，扩容* 2 + 1，

##### Properties类

Hashtable的子类，可以 读取文件

##### TreeMap类

和TreeSet类似

### Collections工具类

操作对象是Set，List，Map等集合，排序方法有reverse，shuffle，sort，swap等，以及查找和替换等

### 泛型

只能是引用类型，可以传入该类和它的子类，默认是objedt

#### 自定义泛型类和接口

类的静态方法不能用使用泛型，使用泛型的数组不能初始化，在创建泛型对象时泛型就已经确定；泛型接口的类型在继承接口或者实现接口时确定，接口属性不能有泛型

#### 泛型方法，继承和通配

泛型方法调用时类型便会确定；泛型不具备继承性；静态方法可用通配符限制泛型的类型

### Junit

单元测试框架；在方法上面加 @Test

## 第五章

### 绘图

用A类继承JPanel类的 并重写paint方法 用paint中的Graphics的方法写出所要画的图型，然后在B类中继承JFrame类，设置一个A类属性，并用构造器new一个A类以及设置this.add等；paint的调用

#### 绘制坦克

建立一个坦克类存放坦克(坐标)，再写一个绘图面板类A，构造器初始化坦克，用A的paint的g.fillRect(..)填充绘图区域(默认为灰色)，在B类的构造器中写this等；写一个绘制不同坦克的方法并添加到paint中

#### 让坦克动

让A类继承KeyListener接口，有KeyTyped(输出字符触发) /KeyPressed(按下键触发)/KeyReleased(松开触发)，加入this.addKeyListner(...)，调用getKeyChar()获取键值KEY

### 多线程和高并发

程序一旦运行就有进程，进程会占用内存空间；进程是的程序运行；线程是进程创建的，一个进程可创建多个线程；并发：单核cpu实现同一时刻，多个任务交替执行；并行：多核cup同一时刻多个任务同时执行

#### 线程的基本使用

继承Thread类，重写实现Runable接口的run方法，在main函数中调用该类的.start方法，及开启了进程；或者A  implement  Runnable 接口，重写run方法，在main中创建Thread类B用构造器将A放入，再调用B的start方法(动态绑定会调用A的run方法)，Runnable更适合多个线程共享的情况

#### 多线程机制

进程只有在所有的进程消失后才会消失，在main中调用的进程A，A不会随着mian进程的消失而消失，A消失时可以返回给main.sleep(...(毫秒))，start0()是本地方法，由JVM机调用(底层是c/c++)，什么时候调用取决于cpu

#### 线程退出和常用方法

线程自己退出和通知线程退出以及线程中断，和中断异常(一般用于中断休眠);setName(),getName(),start,run,setPriority,getPriority,sleep,interrupt，setDaemon(true)(守护线程，调用它的线程结束它业随之结束)

#### 线程插队和礼让

yield 和 join，礼让是让出cup，时间不确定，不一定成功(决定于资源是否紧张)，插队是插队的执行完在执行当前的

#### 线程的七大状态

Runable又分为Run，Ready；

#### 线程同步

可在对象或者方法前加synchronized；方法+的话是同一时刻只能有一个线程执行该方法，哪个时刻，那个线程执行由cup决定；互斥锁是每一个对象都有的，必须是执行同一个对象，可以加在方法上也可以是代码块，默认为this ,也可以是其它对象，static必须是类名.class

#### 线程死锁和释放锁

死锁是线程1和2共同执行到对方占用的synchronized；正常结束或者break，return或者遇到错误和事件，wait()方法

### IO流

#### 文件创建

new File(...,(...)).creatNewFile

##### 目录操作

删除和创建(.mkdirs())

#### IO流的分类

分为字节流(InputStream,OutputStream)和字符流(Reader,Writer),其他都是这4个的子类

##### FileIn(Out)putStream

In:一个字节读入和8个字节读入用.read方法;

out:一个字节读入和指定个字节读入用.write方法;

##### FileReader/Writer

先写入到内存，只有在在关闭或者刷新的时候才会把内存中的内容写入指定文件中，对单个字符或者指定字符进行操作，有Read和Write方法；加true使流指针指向末尾

##### Buffered

关闭只需要关闭外层流(先判断是否为空再关闭);string a = br.readLine()；按行读取，返回为空时读取完毕；close()关闭bufferReader就可以关闭实际的流;默认读取是UTF-8类型，newLine();根据系统添加换行符；构造器可以InputStreamReader

##### ObjectOut/InputStream

Out/InputStream的子类，序列化实际上是保存的值和数据类型，存放的不是纯文本信息；反序列化必须按照对应顺序，可以重写，可以加static和transient反序列化，序列化具有继承性；必须加关键词Serializable，同时可在属性中加上private static final long serialVersionUID = 1L；来增强兼容性

##### System.in/out

in:InputStream编译类型，运行类型是BufferedInputStream，默认设备是键盘；out:编译类型和运行类型都是是PrintStream ，默认设备是显示屏

##### In/OutputStreamReader/Writer

Reader/Writer的子类，构造器可传入一个字节流和编码格式,来完成字节流到字符流的转换

##### PrintStream/Writer

可以直接写出PrintStream out = System.out；只有输出流，可以用Systm.setout(PrintStream对象),方法来修改打印的位置；构造器参数是FileWriter类型，都是用print(...)方法输出;writer必须要有close()才能写进数据(缓存)；

#### Properties类

Hashtable的子类，必须写成  键=值 的格式，默认类型是string；load()加载.properties文件到对象中，list设置输出的对象，get/setProperty(key，(value))获取相应键值，store将数据保存到配置文件( unicode码)

### 坦克大战总结

### 网络编程

服务器的ip地址一般都不变；尽量不要使用0-1024端口；一个电脑有65535个端口；重点是传输层(TCP,UDP)和网络层(ip);

#### TCP和UDP

##### InetAddress类

能得到主机名ip等和指定的域名的地址

##### Socket

使用TCP编程(可靠)或者UDP编程，都应用了传输层和ip协议；服务器端先运行.

##### TCP编程

###### client:

随机端口与服务端通信；new Socket类对象用ip地址和端口初始化(连接服务器),再调用它的.getOut/InputStream()发送数据,用.shutdownOutput()表示发送完成，最后流对象和socket都要关闭

###### servicer:

ServerSocket可以对应多个socket来响应多个客户端；new ServerSocket(端口号)，Socket=serversocket.accept(),再用In/OutputStream=socket.getIn/OutputStream ()接收数据

##### UDP编程

分为发送端和接收端且可以随意变换，数据封装在DatagramSocket对象上，数据包DatagramPacket对象来发送(指定ip地址和端口号)和接收数据，DatagramSocket对发送和接收的数据进行封装

#### 应用案例

1.用字符流实现客户端和服务器端的通信；2。客户端发送图片，服务器端收到图片后保存到src并发送送到图片并退出(先将图片内容全部读入到内存中(用ByteArryOutputStream对象来写入要缓存的内容，再转成字节数组))

#### netstat指令

netstat-an 查看当前主机网络情况，netstat-an | more分页显示，ctrl+c退出指令

#### TCP文件下载

应用需求：客户端发送要下载的文件名，服务端响应并发送对应的文件给客户端，客户端将接收的数据保存到磁盘下；实现步骤：服务端，比较客户端发送的文件名来将对应的内容保存在缓存中，再发送给客户端，客户端先发送文件名，读取服务端返回数据，再得到输出流准备将数据写入到磁盘文件

### 多用户通信系统项目

#### 项目开发流程

1.需求分析(需求分析师)，2设计阶段(1.架构师，设计工作2.原型开发3.组建团队)，3.实现阶段(码农实现完成构架师得模块功能)2%，4.测试阶段，5.实施阶段，6.维护阶段

### 反射

为了解决通过类的地址和方法无法创建该类并调用该方法的问题；能通过外部配置在不修改源码的情况下控制程序；反射机制，Class类，类加载，反射获取类得结构信息；运行较慢，可以关闭访问检测提高速度

#### 基本用法

Class A = Clss.forName(路径)  加载类对象，通过Object B = A.newInstance()得到对象,再Method C = A.getMethod(methodName)，最后C.invoke(B)调用该方法

#### 类在计算机存在的3种形式

1.编译阶段/代码阶段，用java编译生成.class文件；2.Class类阶段(加载阶段),类在堆中进行类加载，一个类只加载一次;3.Runtime运行阶段，在new一个类时它会自动和堆中加载的该类获得关联，知道自己是属于哪一个Class类，因为有了关联所有才可以通过Class类创建该类和调用该类的方法(反射);

#### Class类

一个类只有一个Class对象，可通过Class类的get()方法得到成员变量，getConstructor(String.cclass)得到相应构造器，还可以拿到成员方法等数据等方法；是系统创建的，先加载二进制码文件到方法区，再在堆中映射相应的数据结构方便操作；

#### 如何得到Class对象

不同阶段用不同方法得到Class对象；Class.forName()；类名.class；实例.getClass()；A = 实例.getClass().getClassLoader() 再A.loadClass(路径)；基本数据类型和包装类可以  .class或者.TYPE得到；

#### 类加载

通过反射来实现类动态加载；静态加载是编译时加载相关的类，依赖性太强；动态加载是执行到该代码才加载；类加载时机在前面内容上多一个反射

##### 加载阶段

将字节码文件从不同数据源转化为二进制字节流加载到内存中

##### 连接Linking

验证：Class文件的字节流中包含的信息知否符合当前虚拟机的要求，包括文件格式验证，元数据验证和字节码和符号引用验证等，可以使用Xverify:none 参数来关闭大部分的类验证措施，缩短加载时间；准备：对静态变量分配内存并默认初始化，解析：虚拟机将常量池内的符号引用替换为直接引用的过程

##### Initialization

执行< clinit >的过程，由编译器按语句在源文件中出现的顺序，依次自动收集类中的所有静态变量的赋值动作和静态代码块中的语句进行合并；若多线程同时初始化该类的化只会有一个线程去执行这个类的< clinit >方法(同步机制)，其他都会阻塞等待

#### 通过反射获取类的结构信息

第一组是Class类，第二组是Field类(修饰符和类型属性名)，第三组是Method类，第四组是Constructor类

##### 反射创建实例的方法

先得到Class对象通过Class.forName(...),无参共有构造器：Class.newInstance();有参构造器:Class.getConstructor(String.Class等)/.getDecalaredConstructor返回该参数构造器构造器，公有的直接Constructor.newInstance(实参),私有的要先Constructor.setAccessible再调用构造器构造；

##### 反射访问类中的成员

setAccessible(true)爆破，静态属性的o可以写成null

###### 访问属性

Field f = class对象.getDeclaredField/Field(属性名);私有属性需要爆破才能访问，访问：f.set(o,值),f.get(o)

###### 访问方法

Method m =  class对象.getDeclaredMethod/Method(方法名,XX.class); 返回类型统一用Object接收，其实运行类型是其真实返回类型，Object reV = m.invoke(o,实参列表)；

## MySQL

通过端口连接进行数据的交换，储存在磁盘的方便管理的数据库

### 开启/关闭mysql

net start/stop mysql   关闭/开启服务 quit退出指令；mysql -u root -p 进入本机mysql后台；mysql -h 主机名 -p 端口 -u 用户名 -p密码 (端口，主机名有默认)

### 数据存储类型

#### 整形

INT 2^15 - 1，可＋unsinged在后面 ；BIT('m') .PS. m是位数 1-64之前，所以可表示范围为0- 2^m -1;

#### 小数类型

FLOAT/DOUBLE/DECIMAL('整数位数a','小数位数b')  PS.float为4字节，double为8字节，a最大为65(默认是10)，b为30(默认是10，用0填充 )

#### 文本类型

CHAR('字符大小a') PS.a最大为255,而且长度固定  ; VARCHAR('字节大小b')  PS. b最大为65535,其中3个字节存放大小，故可用为65532，查询速度上char要快些；MEDIUMTEXT / LONGTEXT / TEXT  都可用来存放比较大的数据，编程方式有细微差别，更加灵活

#### 二进制数据类型

#### 日期类型

DATE  年月日 / DATETIME 年月日时分秒 / TIMESTAMP 时间戳 可随时更新时间 在定义后面加上NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATA CURRENT_TIMESTAMP 添加格式：’年-月-日 （时:分:秒）

### 创建和查看数据库

CREATE DATABASE （IF NOT EXISTS）　ｄｂ＿ｎａｍｅ　（ｃｈａｒｉｃｔｅｒ　ｓｅｔ　ｕｔｆ　－　８）　（可以设置字符集和校对规则）；ＳＨＯＷ　ＤＡＴＡＢＡＳＥＳ，ＳＨＯＷ　CREATE DATABEASE db_name

### 对表的操作

#### 删除和备份

DROP DATABASE ’db_name‘ ;在dos下执行 mysqldump -u用户名-p密码数据库表1表2表n > d:\I文件名.sql 实际上是备份的指令数据也可在软件中执行恢复；恢复数据库(注意:进入Mysql命令行再执行)source d: l lbak.sql

#### 创建和查看表

CREATE TABLE ’name‘ (field1 ‘int’  NOT NULL,field2 ‘float’ ) charatcter set   ’zifiji‘ collate '校对规则'  engine ‘  ’      .PS. field 1不可以为空不指定则为该数据库的字符集和校对规则和引擎 ;SELECT * FROM ‘表名’ 来查看表/DESC  ‘表名’  来查看 

#### 修改表

##### 添加：

ALTER TABLE   '表名'   ADD  'filed'  'VARCHAR(32)'  (NOT NULL DEFFAULT ' ')    PS.后面NOT NULL DEFFAULT是不允许为空，并给定初值 ' '

##### 删除：

ALTER TABLE   '表名'  DROP ‘ exsisted filed’

##### 修改： 

修改filed的长度  ALTER TABLE   '表名'  MODIFY ‘filed’  'VARCHAR('要修改的长度') ' NOT NULL DEFFAULT ' ' ;修改名字  CHANGE 'origin name'  'updated name'  'VARCHAR(32)'  (NOT NULL DEFFAULT ' ')  ;修改表字符集  CHARACTER SET  ‘utf8’

#### 表类型和存储引擎

表的类型由引擎决定，一个有6种，重点3种：InnoDm (默认)，支持事务。处理效果差，占磁盘空间；MyISAM：不支持事务和外键，访问速度快；MEMORY：使用的是内存空间，每个MEMORY表只实际对应一个磁盘文件，访问速度快，默认使用，HASH索引，服务关闭，表中的数据就会丢失，但表的结构还在；ALTER ‘table’  ENGIN = ‘MEMEORY’（"修改引擎"）；

### 对字段操作

#### 添加

INSERT INTO  '表名'  ('filed1', 'filed2'... )   VALUES('data1','data2'...) ,（’data3‘,'data4'）;   PS. 插入数据要符合要求,日期类型在单引号中，如果给表中所有字段添加数据，可以不写前面的字段名称，只有默认值时添加才不会报错，字段允许的话可以添加NULL,允许一次添加多条信息

#### 删除

DELETE FROM '表名'  WHERE ’field name‘ = ’要修改的名字‘  PS.WHERE是限定要修改字段(没有的话就对所有的进行修改),

#### 修改

UPDATE ’表名‘  SET '字段名a'  = ’data‘ ( +'a'  ) WHERE ’field name‘ = ’要修改的名字‘  PS.SET 指定更新列，WHERE是限定要修改字段(没有的话就对所有的进行修改)，可在原先基础上增加修改

### SELECT

韩%:表示开头为韩后面无要求；__O表示第3位为O前两位无要求

#### 基本语句

1.SELECT (DISTINCT)  */  'filed1','filed2'...(‘要显示的字段加 *为全部’) FROM ‘table’；2.SELECT  'filed1' (as) '别名' from 'table',  3.SELECT  'filed1' and/<(‘运算符’) 'filed2' FROM 'table1';4.SELECT  'filed1' FROM 'table' order by 'filed' Asc('默认')/Desc；PS.书写顺序 1>3>2>where>4, where后面是接运算符，比如where id > 5，排序可以多字段排序，如：order by deptno ASC ，sal DESC

#### 运算符

where语句常用运算符：<,>=,!=,=,<>...;between ... and ... ;in(...);like ' ...',not like '...',is null ;and,or,not; ps. in()是显示列表中的值   PS.可以在定义字段时在后面 + ('sex' 'IN' ('man', 'woman')),起到约束功能，mysql5.7暂不支持生效

#### 函数的使用

##### 分组统计函数

SELECT COUNT (*)/'filed'  FROM 'table1'  WHERE; SELECT sum('列名')/AVG('列名')/MAX('列名')/MIN('列名') fom 'table' where ;可以在统计函数的基础上的末尾加上GROUP BY   '一般flied'  HAVING  ‘表达式 ’； PS.可以用运算符和别名，having可要可不要，起到对分组的限制作用 ; cout(* * ) 与 group by 合用 会统计每组的数量  

##### 字符串函数

DUAL是系统表，可以作为测试表使用

charest('str'),concat('str1','str2'...),instr('str','substr'),ucase('str'),lcase('str'),left/right('str',lenth),length('str'),replace('str','replece','origin'),strcmp('str1','str2'),substring('str','position','length'),ltrim/rtrim/trim('str');     PS.返回字符集，返回连接的字符串，返回sub在str中首次出现的位置，没有则返回0，返回转换为大写，返回转换为小写，返回左/ 右起取lenth个字符，返回长度，返回str用replace替换origin的字符，返回比较结果，返回截取的字符串，去除左/右/左右的空格

##### 数学函数

floor('..') 向下取整；deiling(‘...’)向上取整，round(‘4舍5入’)，format('num','保留的位数 ') ； rand('')  

##### 日期函数

返回当前时间，可以返回将两个日期(时分秒)加减后的值和日期差;可以返回日期的指定部分,如YEAR(‘date’),unix_timestamp()返回当前时间到1970-1-1的秒数，from_unixtime('unix_timestamp()','%Y-%m-%d('%H:%i:%s')')通过秒数来转换为指定格式的日期(时间)  ; PS. 日期之间可以比较大小，返回真或者假

##### 加密和系统函数

USER()返回当前使用数据库的用户的ip地址；DATABASE()返回当前使用的数据库名称;MD5(‘str’) 返回加密后的字符串；PASSWORD('str')返回加密后的字符串 。 PS.一般密码都必须要加密，防止数据库被爆破密码泄露

##### 流程控制函数

判断为空为 is 判断不为空为 is not ，判断相等用 =  ;一般用来替换表中的显示

if('case1','case2','case3')  ; IFNULL('case4','case5'); SELECT CASE WHEN 'case1'  THEN 'case2' WHEN 'case3' THEN 'case4' END;   PS. 'case1' 为真 返回 ‘case2’ ，为假返回‘case3’ ； ‘case4’ 为空的化返回 case'4' ,  否则返回 ‘case5’

### 查询

#### 合并查询

一般指定具有相同字段的表来显示相同字段；UNION ( ALL )连接两个查询结果，去重(不去重)；/ / 一般用于把分别查询的相同的表进行合并显示

#### 增强查询

%，_的使用；order by 'a' acs 'b' decs ... ;  seclet '表名' limit 'start' rows ；cout(*)  cout('filed1')； PS.start从0开始，rows是指显示的行数，返回表中数据的个数,'filed1'为空的话不会统计在其中

#### 多表查询

SELECT ‘filed1’ ,'filed2'  FROM 'table1','table2'  WHERE ;笛卡尔积  ;'table'.'filed'  PS.避免出现笛卡尔积只有2表1个限制条件，3表2个限制条件 ... ;  显示具体某个表 . 列

#### 子查询

where中用子查询中的信息当约束条件；	FROM中当临时表使用；ALL('table')；	ANY('table');  多列子查询  ('salary' , 'empdo'...)  ''='' (select ...'where...')	  PS.all和any举例，where salary > all('tabel') 表示 大于'table'中所有的薪水，相反any是存在大于’table‘中的薪水；常把子查询取别名然后用 ‘ 别名 ’. ’ 字段名‘ 访问子查询中的字段信息

####  表复制和去重

INSERT INTO 'TABLE1'  ('filed1','filed2'...) SELECT 'file1'.. FROM 'table2' ；去重先用DISTINCT关键字后去重，在复制删除等操作 ；

### 自连接

一张表当成两张表来使用，需要  SELECT  ’worker.name‘   AS  ' '  'boss.name'  AS ' '    FROM ’table1‘  ’worker‘  ’table1‘ ’boss‘  WHERE  'worker.boss' = 'boss.name'; ps.例如一张表的员工和编号和对应的老板编号在同一个表中,表的别名用空格，表.列名

### 外连接

#### 完全显示

当在两个表中查询对应关系显示时，需要让‘table1’中在‘table2’ 没有出现的值也显示出来(完全显示) 

#### 主键

'id'  'INT'  PRIMARY KEY ；PRIMARY ('id', 'name')  ；DESC 'table' PS.主键不能重复(会报语法错误)，不能为空；一张表最多有一个主键，但可以有复合主键 (都相同才不能添加); 可以显示表的约束条件等信息，一般表都有主键

#### unique

字段后面加 unique not null 用法类似于主键 ，直接加unique 则 不能重复具体的值，但可以重复NULL值

#### 外键

table1：先要有一个主键或者unique ；table2：FOREIGN KEY('外键值') REFERENCES ‘table1’(' 主键') ； PS. table2中添加的数据的字段的外键必须在主键中出现过，或者主键允许添加NULL值，外键可以添加NULL进去表的类型是innodb ，这样的表才支持外键；外键类型和主键类型必须一致；一旦建立主外键的关系，数据就不能随意删除

#### 自增长

添加的是空值的话默认在上一个的基础上+1,如果有指定值则以指定值为准；字段后面定义 + AUTO INCREMENT  一般和主键配合使用，也可以和unique配合，不能单独使用；修改起始默认值 (默认为1)ALTER TABLE 'table' AUTO_INCREMENT = ‘100’ ;

### 索引

当有庞大的数据时，索引的速度就成了一个麻烦 ；这时就需要创建索引(本身也需要占一定空间)；CREATE (UNIQUE) INDEX 'id' ON 'emp' ('filed') ；索引不应该在唯一性差，更新频繁，没不是查询条件创建；PS.只对创建了索引的列有效

#### 索引代价和原理

增加磁盘占用空间，降低更新，删除，添加的速度；没有索引是全盘索引，索引是建立一颗二叉树进行查询

#### 索引类型和添加

类型：主键索引；unique索引；普通索引 ;全文索引 ； PS. 主键索引可以在定义字段时后面添加PRIMARY KEY自动创建；unique是为了保证数据没有重复；一般不适应mysql的全文索引（效率低），一般用java的Solr等框架

#### 添加和删除

ALTER TABLE ‘table’ ADD PRIMARY KET/ INDEX 'id_index'  (‘filed’) ;CREATE (UNIQUE) INDEX 'id_index' ON 'table' ('filed') ； SHOW INDEXES FROM ‘table’ ；DROP INDEX ‘id_index’ ON 'table' , ALTER  table ' table' drop  index 'id_index' ; alter table 'table' drop primary key;  PS. 删除主键索引有点特别 ，修改索引是先删除再添加新的索引

### 事务

为了使一系列相关联的操作提供安全保障，要么全部成功，要么全部失败；当进行事务操作时mysql会在表上加锁，防止其他用户修改

#### 基本使用

START TRANSACTION / SET AUTOCOMMIT=OFF; SAVAPOINT ‘保存点’ ；ROLLBACK （TO ‘保存点’ ); COMMIT ;  PS.  ROLLBACK 是 直接回溯到起始状态 ，可以不设置保存点，使用ROLLBACK ； 提交后就会删除锁，数据生效；

#### 事务隔离级别

当多个连接到一个数据库进行事务处理时，系统要负责隔离操作，来保证连接时数据的准确性(最好看到的数据和原始数据都是连接上来时的数据，操作数据时互相不受影响)，

##### 隔离级别

如果不考虑隔离性，可能引发 脏读，不可重复性，幻读；不同的隔离级别会造成不同的影响，有4种隔离级别（“加锁的意思是表没有提及就会一直暂停到那里”）；select  @@tx_isolation ; 

##### 设置隔离

### 视图

是虚拟表，内容由查询定义，和真实表(基表)是映射的关联关系，是相互影响的  PS. 使用视图有安全和分表的高性能以及更新升级的灵活

#### 基本使用

creat view '视图名' as select ’name‘  ’id‘   FROM ‘table1’ ；alter view ‘视图名’  as select ... ; SHOW CREATE VIEW '视图名'  ;  drop  view '视图1'  ‘视图2’

### mysql管理

root管理可以对其他登录到数据库的用户进行管理，例如修改密码给予，撤销权限等；SELECT * FROM admin WHERE NAME =  'tom' AND pwd = '123'  查询用户是否存在

#### 密码的管理

修改自己的密码：set password = password('1344') ; 修改他人密码 : set password for '用户名' @ ’登陆位置‘ = password('1234 ')      PS. password() 代表给密码进行加密

#### 创建删除用户

创建用户：create user ‘用户名’ @ ‘允许登录位置’  identified by ‘密码’  ；删除 ：drop user ‘用户名’  @ ’ 允许登录位置 ‘ ；  PS . 可以 % 表示任意的登录地址，例如 ’%‘ 表示任意地址， ’192.168.%‘ 表示后16位为任意，删除必须登录位置要写对，不写登录位置默认为’%‘

#### 授予撤销权限

GRANT select 'delete'  'create' ... on '库'.'对象名'  to '用户名'  @ '登陆位置'  (identified by '密码') ;    revoke  ’ 权限列表 ‘  on   '库'.'对象名'  to '用户名'  @ '登陆位置'；     PS. * . * 代表数据库中的所有对象 ，存在是修改密码，不存在则是创建用户，可以用FALASH PRIVILEGES 刷新权限生效

## JDBC

是java制定的一组接口，因为数据库的不同导致调用的方法不统一，需要数据库的厂商提供实现接口的驱动文件，来符合java的厂商制定的数据库管理规范，java程序员只需要面对这组接口编程

### 快速入门

记得把.jar文件加入到项目中去

#### 获取数据库连接

第一种：new Driver 再 new property 写入 user  和 password 再  diver.connect();第二种：反射动态加载 new Driver ；第三种 DriverManager来 注册得到连接 DriverManager.register('driver对象') DriverManager.getConnection('url',user,password);第四种利用反射动态加载Driver对象，不 new ，再 DriverManager.getConnection('url',user,password) ("Driver的加载有静态代码块注册操作") ；第5种：使用配置文件来得到user和password等信息

#### 执行增删改

String 'sql' =  " ’mysq的执行代码‘ " ；Statement  statement = connect.createSatement ; int 'rows' = statement .executeUpdate('sql');  PS.row返回受到影响的行数

#### 关闭相关连接

statement.close();connect.close();

#### 结果集

为了查看mysql中的数据，select语句的返回结果显示  ； ResultSet a = statement .executeQuery(' sql ') 得到 ResultSet 接口类型的对象，再 用 while ( a.next() ) 来循环遍历 ，get方法来获取不同数据类型的数据，可以通过索引，或者列名来获取 ；

### PreparedStatement和事务

#### 引入背景

是一个执行静态sql语句返回结果的接口，因为Statement会出现注入问题,而一般用PreparedStatement，提高了效率，减少拼接的语法错误

#### 使用方法

在sql语句中 要注入的信息先用？处理;再用Connection.PreparedStatement('sql')  得到PreparedStatement接口的对象;PreparedStatement.setString('tom')  赋值；再关闭PreparedStatement.close();                PS. 用 ？ 来提示用户输入，来操作数据库

#### 方法集

结果集ResultSet接口类：

next() ; previous()  ; getXxx('列名'  / ’索引‘) ; getObject('列名'  / ’索引‘)  ;  PS . 向下移动一行并返回True或者Faulse；向上移动一行；返回对应Xxx类型的值；返回值类型为Object

#### PreparedStatement接口类：

executeUpdate()  ; executeQuery() ; execute() ; setXxx('索引' ， ’值‘)；setObject(’索引‘， ’值‘)；PreparedStatement.close() ;          PS. 返回受影响行数 ； 返回结果集 ； 返回布尔类型 

#### 事务

Connection.setAutoCommit(false) ; Connection.commit() ; Connection.rollback() ;  PS.一般用try ... cach ... 来捕获两条语句执行中间的异常，捕获到了就回滚保证数据的安全

#### 批处理

原理是减少编译次数和发送给数据库的网络开销 ； url  + ?rewriteBatchedStatements=true ，addBatch('sql') , executeBatch() , clearBatch() ;  PS.  必须执行了再清空

### 连接池

背景：传统连接：当许多个用户一下子同时连接mysql时，而且每一次数据库连接使用完未能关闭，可能导致内存泄漏，mysql崩溃，而且频繁进行数据库连接占用很多系统资源，容易造成服务器崩溃

#### 原理

降低用户连接到数据库的次数，转变为把用户的数据放到连接池中，由连接池来连接数据库，Java程序直接往连接池得到链接来连接mysql，用完再放回到连接池中；超过最大连接数进入到等待队列，maxWait = 5000 ：等待列队的最长等待时间为5S，没得到则放弃

#### 使用方法

- c3p0 : 加入jar包 a = new  ComboPooledDataSource('user' / '为空')  ; 当不为空：connection = a.getConnection() 需自己配置文件c3p0-config.xml， 为空 ：需要设置相关参数 ;  connection.close();
- Druid : 加入jar包加入配置文件 druid.properties 到 src 目录下 ; 读取配置文件 , a = DruidDataSourceFactory.creatDataSource(properties) ; a.getConnection();

### ApDBUtils工具类

背景：关闭连接后，结果集无法使用，而且结果集不利于数据的管理；使用返回信息不方便，需要用getStrin()得到性别，而不是getSex() ;  该类是对JDBC的封装，简略了开发

#### 相关类介绍

QuryRunner类：执行SQL语句，线程安全，可实现批处理 ，query('connection', 'sql', new 'BeanListHandler<>(Xxx.class)', '?的参数') , 底层使用反射机制进行得到Xxx的字段封装，得到Xxx对象封装到List中； ResultSetHandler 接口处理ResultSet ；BeanHandler 和 BeanListHandler 处理一行，多行返回的数据 ；ColumnListHandler 处理一列的数据  ；Scalar Handler处理单行单列数据； PS .返回都是List 或者 List数组 ,  当其他没有返回值时会是null； 处理Result的对象都是和数据库的类型有一个映射关系

#### 基本使用

- 引入commons-dbutils-1.3.jar，利用Druid 得到连接
- 利用 QuryRunner. query('connection', 'sql', new 'BeanListHandler<>(Xxx.class)', '?的参数') 方法执行sql语句并返回, QuryRunner.update('connection', 'sql', '?的参数')  PS. Xxx类一定要有无参构造器(反射需要)和有参构造器和set和get方法

### BasicDAO

背景：apache-dbutils+Druid有一些不足，sql语句是固定的，无法通过参数传入，select操作返回类型无法固定，应该使用泛型，表多了就无法靠一个java类来完成

#### 结构

1.界面层，调用service层的类，得到数据显示结构 ；2. 业务层，组织sql，并可以调用多个XxxDAO，完成综合需求； 3. XxxDAO层 ，完成对数据库中的Xxx表的各种操作，继承BasicDAO，BasicDAO中完成各个DAO的共同操作  ；4. 数据库的Xxx表和javaXxx类的映射关系

#### 代码实现

先写BasicDAO类，定义接收一个泛型，通过Druid连接apache-dbutils返回操作数据库的结果，与前面操作的区别是select返回的是泛型以及参数要用Object... paramster  ;  再定义Xxx类，再写需要具体要求的XxxDAO； 再写业务层(可能需要 ) ； 最后写界面层 (可能需要)

## 正则表达式

处理文本利器，可以用来搜索，提取文本内容等； Regular Expression - regex

### 语法

| 选择匹配符 ；java是贪婪匹配，尽可能匹配多的 ； 边界可以是匹配的字符串最后，也可以是空格后子字符串的最后 ； ？跟到 * + 等后代表了非贪婪匹配

#### 字符匹配符

转义符 \\  \  当 查找 {,},+,*等字符时需要 ；    当写在[.]中不需要转义                                                                                  [ ] ，[^] , -  可接收 | 不可接收 字符列表，连字符；                                                                               . , \\ \d , \ \ D, \ \ w, \ \ W ，\ \ s, \ \ S；除 \n 任意字符，单个数字字符，单个非数字字符， 单个数字和字母字符，单个非 数字和字母字符 , 匹配任何空白字符；                                                           (?i) 写在字母字符的面前表示不区分大小写 

#### 限定符

都是作用于前面

*，+，？，{n}, {n,} , {n,m}   ;                                                                                                                              指定字符重复0次或n次 ， 至少1次，0次或1次，只能输入n个字符，至少n个，n-m个

#### 定位符

^ ，$ , \ \b,\ \B                                                                                                                                             指定起始字符(作用于后面)，指定结束字符，匹配边界，非边界

#### 分组和反向引用

##### 分组

()() , (?<'name'>), (?:), (?=), (?!)                                                                                                               非命名捕获，命名捕获，匹配但不捕获子表达式，匹配但不捕获，匹配但不捕获(匹配相反)

##### 反向引用

分组的位数的编号0，1，2 各表示找到的所有字符串，第一个()的字符串 和第二个() 的字符串 ；正则表达式内部用\ \ ' 编号' 外部用$ ' 编号 ' ；例如 (\ \d) \\ \ 1 表示两个数字相同

### 相关类

#### Pattern类

1. 整体匹配 Pattern.matches('regStr', content', ) ; 整体满足条件才返回true
2. Pattern.compile('regStr') 得到Pattern对象，pattern.match('content') ，可以得到Matcher对象

#### Matcher类

matcher.replaceAll(" '.' ") ; find() ; find('start') ; matches() ; .group('0') ; .group('1');.group('2')

将查找到的字符用.替换 ；查找匹配的下一个序列；从start开始匹配下一个序列；将整个区域与模式匹配 ; 查找的字符串 ;如果有分组，则返回第一个分组的结果；如果有分组，则返回第二个分组的结果

### 字符串的正则表达式

String.mathches('正则表达式') 匹配成功返回true ；String.replaceAll('正则表达式查找内容' ， ‘要替换的字符串’) ； String.split('正则表达式') 返回分割后的字符串数组





































