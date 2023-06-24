# Linux 基础

## 常用 sell 命令

q 退出当前查看; ctrl + c 打断;

ls (-l) ; cd ; pwd 显示当前路径 ; uname (-a) ; cat ; su - 'root' 切换用户 ; touch 创建 ; rm ' ' (-rf) 删除 ; cp 'a.c' 'b.c' 将 a.c 复制到 b.c 中 ; mkdir 创建文件夹 ; mv 'a.c' 'b.c' 移动到 (重命名) ; rmdir 删除目录 ; ifconfig (-a) ; reboot 重启 ; poweroff 关机 ; sync 数据写入磁盘 ; find '/home' (-name) 'a.c' ; / 主目录 . / 当前目录 ; grep (-nr) ' "linux" ' '/home' 查找' /home'目录下的包含内容的文件 ; ctrl + c 打断当前的操作 ; du '/home' (-sh) 查看'/home'目录大小 ; df 磁盘空间检测 ; gedit 'a.c' 记事本打开 ; ps (-a ) 查看进程 ; top 进程实时运行状态 ; file 'a.c' 查看文件类型 ;sudo apt-get update 升级命令; route -n打印网关地址和掩码地址

## 网络

route -n打印网关地址和掩码地址; sudo service ssh start/stop 打开和关闭ssh服务;

## 软件安装

安装的几种方法 : 1. APP Store , 2. sudo apt-get install 'git' ; deb 软件包文件 sudo dpkg -i '..'.deb ; 编译源码安装 ; tree 查看目录下的文件夹树

## 磁盘管理

文件系统格数为 FAT32 ; / dev / sd\* 为 u 盘目录; sudo vi /etc/profile, export PATH=$PATH:'/usr/local/arm/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/bin' 添加环境变量;

## 文件目录

指定运行级别 一般用 3 和 5；帮助指令 man [命令] / help [命令] ; cd ~ ，cd .. ； mkdir (-p //创建多级目录 ) '目录' ，rmdir (rm -rf // 非空目录) '目录' , touch 创建空文件 ; cp 拷贝，rm 移除， mv 移动， cat 查看内容 ； more / less 文本过滤器 方便查看; echo 输出到控制台， head (-n '5') '文件' 默认查看文件前 10 行内容， tail (-n '5') (-f) '文件' -f 可见实时监控 , 查看末 10 行内容 ； > 重覆盖内容， >> 追加内容; In / rm '原目录' ‘连接名’ 创建和删除软连接； history (10) 显示最近使用的(10) 个指令 ，！5 执行历史编号为 5 的指令 ； data cal 2020 ; find '要查找的目录及其子目录' '文件名' (+ / - 200M); locate ‘搜索文件’ 使用前要建立数据库 可快速定义文件路径

## 压缩和解压缩

几种常见格式 .tar , .tar.bz2 , .tar.gz ; gzip 负责压缩和解压 .gz 格式 , 压缩 gzip 'jdd' gzip -r // 压缩文件夹 '...' , 解压 gzip -d '..' gpiz -rd // 解压缩文件夹'...' ; bzip2 -z 'h.c' , bzip2 -d 'h.bzz' ; tar 工具参数 -f 使用打包文件 -c 打包 -x 解压缩 -j 使用 bzip2 压缩格式 -z 使用 gzip 压缩格式 -v 打印出命令执行过程 例如: tar -vcjf 'xxx.tar.bz2' 'xxx' 压缩成 .tar.bz2 格式 tar -vxjf 'xxx.tar.bz2' 解压缩 或者-vxzf -vczf ; 其他 rar zip unzip

## 用户和用户组

用户记录在 /etc/passwd 中 , 用户密码记录在 /etc/shadow ,每个用户都有一个 ID 叫做 UID 每个用户组都有一个 ID 叫 GID ; 每个用户可以属于多个不同的组 , 用户和用户的存在是为了控制文件的访问权限 , 用户组信息存储在 /etc/ group 中 ; adduser 'zzk' , finger 'zzk' , passwd 'zzk' , deluser 'zzk' ; addgroup 'lzq' groups 'lzq' delgroup 'lzq' ;

## 用户管理

xshell 登录后可以 su - 用户名 来切换管理员身份，logout 即可注销当前用户，返回到上一级用户；pwd 显示当前在哪个目录下； 查询用户信息 id ‘用户名’ ；who am i 返回第一次登录的用户的信息；useradd (-d '指定目录') '用户名' ; userdel (-r //慎用)'用户名' ； 用户组：系统可以对多个用户进行统一的管理 groupadd （-g ‘组类’）‘组名’

## 文件权限管理

r (4), w (2) , x (执行 1) 三个权限 ; ls 'a.c' -l 可查看权限 依次为所属用户 组内 组外 ; 修改文件权限 chmod '777' 'hellow' ; 修改所属用户 chown 'root' 'hellow' 修改所属用户组 chown .'root' 'hellow' 或 chown 'root' .'root' 'hellow'

## 连接文件

软连接 创建快捷方式 可跨系统 连接到目录 必须给出连接的绝对路径(否则复制会出问题) ; ln -s '/home/linzq/hellow' 'hellow1' ; 拷贝软连接 cp -d 'hellow1' 'test/' 硬连接 通过 inode 标识, 多个文件指向同一个 inode . 只有删除了源文件和所有连接文件实体才被删除 不能跨文件系统和连接到目录 修改一个另外一个也会改变; 默认创建硬连接 ln 'hellow' 'hellow1' ; 查看 inode ll -i 'hellow' ;
 
## vim

i , a 进入插入模式 ; : / ? 进入命令行模式 vim 快捷键：5yy 拷贝当前 5 行 输入 p 粘贴；5dd 删除当前 5 行；命令行下/‘find’ 回车 查找，输入 n 就是下一个；命令模式下 :set nu 和 :set nonu 设置行号； G 最末行，gg 首行； u 撤销上一个动作； 编辑第 20 行：输入 20 再输入 shift + g

## c 编程

gcc 'main.c' 生成可执行的 .out 文件 ; gcc -c 'main.c' 生成 .o 文件 ; gcc 'main.c' -o 'main' 自定义生成的文件名 ; gcc -v 'main.c' 可查看详细的编译信息 ;

## make 基础

make 工具可以自动完成编译工作 ; make 工具通过一个称为 Makefile 的文件来完成并自动维护编译工作, Makefile 文件描述了整个工程的编译,链接规则 ; make 的执行过程 ; 基本规则 : 目标: 依赖文件 命令 main: 'main.o' 'input.o' gcc 'input.o' 'main.o' -o main , 结尾有 clear 命令 clear: rm 'main' '\*.o' 命令键以 TAB 开始; 用法 在该目录下 make , make clear ;

## make 进阶

变量都是字符串类型的 变量的使用 'object' = ''main.o' 'input.o' gcc 'input.o' 'main.o' -o main ' main: $('object') ; gcc -o 'main' $('object') 伪目标: make 执行 Makefile 里面的目标命令 make 'printf' 'printf': '@echo curname: $(curname)' 加上@不会打印'echo curname:' 这一行 make 'printf' make 'clear' 当文件中有和 'clear' 'printf' 重名的要加上 .PHONY : 'clear' 赋值符 = : 给其他变量赋值左值是右值在文件中最后一次赋值 := : 给其他变量赋值左值是右值顺序上最后一次赋值 ?= : 左值如果没有赋值就等于右值 += : 追加 自动化变量 : '%.o : %.c' $@ 匹配模式中定义的目标集合 , $< 依赖文件集合的第一个文件, 以%开头则依赖全部文件 $^ 所有依赖文件的集合使用空格隔开; 模式匹配: %.o: %.c   $(CC) -c %< -o %@; $(patsubst 'patten', 'replace', 'target'), 如果target中符合patten的话就返回将所有target替换成replace的字符串, 如$(patsubst %, -I %, $(INCDIRS))将所有$(INCDIRS)加上-I; $(wildcard '.c', ./src/*.c) 获取指定目录下的文件列表;
## shell 脚本入门

定义 ; 执行过程和原理 ; 第一行必须为 #!/bin/bash 交互 : 使用 read (-p) ("input you name and age :") 'name' 'height' ; 引用变量用 $'name' ;运算符 : 仅支持整型 total = $(($'name' + $'age')) test命令 : 查看文件是否存在, 权限等信息, 可以进行数值, 字符, 文件三方面的测试 ;  test -e 'main.c' ; test '$a==$b';存在则返回1否则返回0 ; A && B   A正确则执行B A || B A错误则执行B; []: [ "$a==$b" ] 只能有 == 或者 != shell 的参数 : $0 ~ $n 表示 shell 脚本的参数 #表示最后一个参数的标号 ./'my.sh' 'a' 'b' 'c' ...

## shell 脚本进阶

条件判断 : if [ ] ( || [ ] ) ; then '...' else if [...] ; then '...' else '...'  fi 可以用逻辑判断语句&&|| ; case $'a' in 'a') ;; 'b') ;; 'c') ;; ... esac ; 函数 : function 'fact()' {...} ; 调用 'fact' '$1' '$2'.. 循环 : while [ ] do ... done ; for 'var' in 'v1' 'v2' 'v3' 循环 3 次 ; for(('i = 0'; 'i <= 100'; 'i = i + 1')) do done;