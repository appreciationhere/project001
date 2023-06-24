ping 'ip' 查看通信;  df 查看挂载点, mount /etc..; kill [参数] 进程号;killall [参数] 进程名称;
ufw disable 关闭防火墙; source /etc/profile; sudo dhclient -r 清除ip, sudo dhclient 重新获取ip; ctrl + l 清空





## 正点原子实例测试

### vscode连接虚拟机
1. 设置静态ip, 在有线设置中手动设置, 网关和DNS一样
2. 安装ssh和openssh-server, 在电脑应用上安装openssh客户端和服务器
3. 在win10上面 windows Powershell 上面输入 ssh [用户名]@[ip地址] 试试连接
4. vscode上面安装Remote - SSh, 并打开远程资源管理器设置ssh的config, 编辑登录用户名和地址完成连接
5. 配置网络的主机端的ip地址和网关，要去虚拟机上面的设置一致，保证可以ping通；
6. window配置免密登录: 分别在windows 和 Linux下面执行 ssh-keygen -t rsa命令生成公匙和私匙, 然后在Linux生成的.ssh目录下新建authorized_keys内容为windows的公匙

### qt配置交叉编译环境
1. 执行官方的.sh安装交叉编译器, 配置环境变量
2. qt脚本里写入设置使能环境变量的指令, 通过命令./qtcreator &(后台运行) 运行qt
3. 配置qt的kit, 将版本, 编译器添加为GCC. C++, 找到编译器路径
4. 添加kits, 选择刚刚添加的版本和编译器并将mkspac更改 

## 文件互传
### ssh服务器连接
可以使用filezilla或者samba 服务器
1. 关闭windows和sudo ufw disable关闭虚拟机防火墙
2. 回到 Windows 端，按下 Win 键和 R 键，弹出运行框，输入\\IP 地址，点击确定。
3. 然后输入连接凭据，即 Ubuntu 的用户名和密码即可连接到 Ubuntu
4. 如果连接成功会出现一个虚拟机的 IP 地址的网络。右键虚拟机网络，设置映射网络驱动器
### scp协议(需要同一局域网)
scp (-r) 文件 (文件夹) 用户名@ip 地址:路径;
#### wifi设置
1. cd /home/root/shell/wifi
2. 打开wlan0 : ifconfig wlan0 up
3. 查看附近wifi: wpa_cli -i wlan0 scan_result
4. 上网模式: source ./alientek_usb_wifi_setup.sh -m station -i 1234 -p 12345678 -d wlan0
#### 一根网线
1. windows设置静态ip
2. 虚拟机设置为桥接模式, 设置静态ip: sudo ifconfig eth0 192.168.1.3
3. scp互传


