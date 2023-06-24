QtCreator的3个类的关系和应用 ；return  ... 进入消息循环 ; QApplication a 应用程序对象，有且只有一个 ；QString 转成char *  .toUtf8() . data() ； 格式化字符串 QString("%1  %2 ").arg('111').arg(' "222" ');

快捷键： 

整行移动 ctrl + shift + pgup/ pgdn ； 同名之间的 . h 和  . cpp  切换 F4 ; 帮助文档 F1

qmake ：需要包含的模块

widget类： 

resize('600','400')；setWindowTitle() ；设置固定窗口大小 setFixedSize() ;

QPushButton类： 

move();     QPushButton('显示文本', '放置在的类')

对象树：父类被释放，基类也会被释放 ，setParent() 来设置父类；      PS.当创建一个对象时，可以提供一个其父对象，创建这个对象时就会自动添加到其父对象的children()列表。 当父对象析构时，这个列表的所有对象都会被析构    QObjet 类会自动释放

P14   P21-22 P30  P34-42

QDebug的使用：

 包含头文件QDebug.h   可以通过  qDebug() << 打印到控制台中

链接信号和槽函数：

connect(‘信号的发送者’，'发送的信号','信号的接收者','处理的槽函数') ； 松散耦合；先链接，再触发信号 ； 用 emit ‘signal 函数’ 来触发信号 ； disconnect（）断开链接 ; 因为槽函数和信号参数有传递，所以信号函数的的参数必须与槽函数的参数类型一一对应参数个数并大于等于槽函数

自定义信号

写到signals下，返回值是void，只需要声明，不需要实现; 可以有参，重载

自定义槽函数

返回值是void，需要声明和实现，可以有参数，可以发送重载

重载信号和槽函数

必须用 void ('重载信号/ 槽函数的类 ' :: * 'name') (‘参数列表’) = & '重载信号/ 槽函数的类 ' :: '信号/槽函数';

信号链接信号 

菜单栏和工具栏以及状态栏：

菜单栏和状态栏最多只有一个 ; 工具栏可以有多个；添加分割线 'file'->addSeprator();

菜单栏

创建菜单栏  QMenuBar * 'bar' = menuBar() ; 放入窗口 setMenuBar(bar) ;  创建菜单  QMenu * 'file' = 'bar'->addMenu( '  "文件" ') ; 创建菜单项 'file ' ->addAction(' " 新建" ') ;   

工具栏

创建工具栏 QToolBar * 'toolBar' = new QToolBar(this);  设置放置的位置 addToolBar('' ,'toolBar'); 设置停靠范围  'toolBar'->setAllowedAreas('可以用  | 设置多个') ；添加项 Qaction ’new‘ =  'file ' ->addAction(' " 新建" ') ，'toolBar'->addAction('new') ；也可以添加其他控件，比如Button

状态栏

创建状态栏 QStatusBar * 'sbar' = statusBar() ; 放入窗口 setMenuBar(sbar) ；添加标签控件  QLabel * 'label1' = new QLabel('提示信息', this) , 'sbar'->addWidget(label1) / 'sbar'->addPermanentWidget(label1) ;  浮动窗口(可以有多个)  QDockWidget * 'dockWidget' = new QDockWidget ('浮动' ，this) , addDockWidget() ;  设置中心部件(只有一个)    setCentralWidget('')

资源文件添加：

将图片文件拷贝到项目位置下 ；右键项目-》添加新文件-》Qt-》Qt recourse File -》给资源文件起名 ； 'res' 生成 'res'.qrc ; open in editor 编辑资源 ； 添加前缀 添加文件 ； 使用 ": '前缀名' '图片名 '  " ;  ui->'acctionOpen' -> setIcon( ": '前缀名' '图片名 '  ")

对话框：

模态和非模态

一般是在connection中，用connect (ui->'actionNew', &'QAction::triggered ', [ = ] () ) { ... } 匿名内部类来使用；模态是不可以对其他窗口进行操作 ，QDialog 'dlg'( this ) , 'dlg'.exec()  ; 非模态是可以对其他状态框进行操作 QDialog * 'dig2' = new QDialog (this)  ,   'dig2'.show()  为了不点击一次重新创建一个对象  需要添加属性 'dig2'->setAttribute() ; 

布局：

可以打破布局来重新布局 ； 实现登录界面

containers->Widget    然后将需要进行水平或者垂直布局的几个控件放在一起并点击上方的水平或者垂直布局 ；spacers 弹簧 可以固定控件的相对位置，可以设定弹簧的固定值 ； 栅格布局可以对几行几列对齐

按钮控件：

一般几个按钮放在一个 Group Box 里面

QPushButton

常用按钮

工具按钮

用于显示图片，想显示文字，需修改风格

多选按钮 

0 是关闭，2 是选中  1 是半选 (要给tristate打勾)    要监听它的状态

3种常用控件：

QListWidget

放置单个tem    'listWidget' ->addItem(item)  ； 放置多个item，先声明一个QStringList 'list'，再利用重载符 << 将“锄禾日当午”  等添加到list中 ， 在addItems('list')

 QTreeWidget 

设置头  'treeWidget'->setHeaderLabels(QStringList()<<""<<"") ;  创建根节点  QTreeWidgetItem * 'Item' = new QTreeWidgetItem(QStringList()<<"") ; 添加根节点到树控件上 'treeWidget'->addTopLevelItem('Item') ; 添加子节点   'Item'->addChild(new  QTreeWidgetItem(QStringList(<<" "<< "")));

QTableWidget

设置列数 'tableWidget'->setColumnCount('3') ;  设置水平表头  'tableWidget'-> setHorizontalHeaderLabels (QstringList()<<" "<<" ") ; 设置水平行数 'tableWidget'->setRowCount('5') ;  设置正文'tableWidget'->setItem('0','0', new QTableWidgetItem("亚索"));

其他控件：

stackedWidget

 切换所在的Index  'stackedWidget'->setCurrentIndex('1') ;     PS. 一般和按钮配合使用，点击按钮切换Index ;

下拉框

'comBox'->addItem("奔驰") ;

QLabel 

显示图片  'lb_Image'->setPixmap(QPixmap(":/Image/butterfly.png")) ; 显示动图  Qmovie * movie = new Qmovie(" 路径")  'lb_Image'->setMovie('movie')   movie->start() ;

鼠标和定时器事件：

鼠标

进入事件 enterEvent ；离开事件 leaveEvent ；按下，释放，移动 等等；x坐标 ev->x()，y坐标 ex->y() ；判断按下的按键(组合按键)  ex->button() ；

定时器

1.在ui中添加一个 Label ；2. 启动并得到唯一标志符  int 'id' = startTimer('1000'(1s)) ; 3.重写 void  timeEvent(QTimerEvent * ev) ；4. 通过 ev->timeId() == 'id' 来判断当前是哪个定时器 ；另外一种 1.创建定时器对象 QTimer * 'timer' = new QTimer(this) ; 2. 启动定时器 'timer'->start() ; 3. 利用发出的信号&QTimer::timeout进行connect ;







 





