# ARM

## Cortex-A7

### 共用寄存器和特殊寄存器

支持 1-4 核 ， 有 9 种运行模型，这几个运行模式可以通过软件进行任意切换，也可以通过中断或者异常来进行切换。当中断或者异常发生以后，处理器就会进入到相应的异常模式中，每一种模式都有一组寄存器供异常处理程序使用，这样的目的是为了保证在进入异常模式以后，用户模式下的寄存器不会被破坏。R0~R15 就是通用寄存器，通用寄存器可以分为以下三类：①、未备份寄存器，即 R0~R7。②、备份寄存器，即 R8~R14。③、程序计数器 PC，即 R15。程序状态寄存器 CPSR 和它的备份 SPSR

### IO 管脚:

**复用寄存器; 电气寄存器; 时钟寄存器; GPIO 寄存器**
**一个引脚对应 2 个寄存器,一个设置特性,一个设置复用功能** ; Cortex-A 需要用汇编初始化一些 SOC 外设, DDR 设置 sp 指针,一般指向 DDR, 设置好 c 语言运行环境  
**查看 IO 管脚复用**: 在 IMX6ULL 参考手册里面 的 chapter32 的 IOMUXC Memory Map 里面找到对应的查看 , 例 IOMUXC*SW_MUX_CTL_PAD_GPIO1_IO03  
**查看 IO 管脚设置电器特性** : 在 IMX6ULL 参考手册里面 的 chapter32 的 IOMUXC Memory Map 里面找到对应的查看 例 IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03; Drive Strength Field 驱动能力; Open Drain Enable Field 是否打开开路输出
GPIOx*寄存器 : 在 chapter 28，GDIP 设置输入输出，DR 是读或写的寄存器，PSR 是状态，ICR 是中断，IMR 是掩饰中断
ccm : 时钟寄存器
## ARM 汇编：
.global '_start' 伪指令设置全局变量; .text 表示代码段, .data 数据段, .bss 未初始化数据段, .rodata  只读段; .section 自定义段; _start 为汇编入口;
.byte 0x12; .short 0x11, .long 0x11; .equ num 0x11 (赋值语句); .align '4'(表示4字节对齐); .end (源文件结束); 函数名: 函数体 返回语句(非必须);
MOV r0, r1 (r0 = r1); MRS R0, CPSR (将特色寄存器CPSR的值写入R0); MSR CPSR, R0;LDR R0, =0X30 (R0读取); LDR R1, [R0] (R1读取) ; LDR R0, =0X20 ; STR R1, [R0] 数据保存到内存(R0 =R1);loop： b ; mrs r0, cpsr msr cpsr, r0 / /特殊寄存器用 cpsr;
PUSH{R0~R3, R12}, POP{R0~R3, R12},“STMFD SP！”和“LDMFD SP!”是PUSH, POP的另一种写法;
BL <label> 跳转到标号地址，并将返回地址保存在 LR 中所以可以通过将 LR 寄存器中的值重新加载到 PC 中来继续从跳转之前的代码处运行，这是子程序调用一个基本但常用的手段。。B <label> 跳转到 label; ADD ;SUB ; SBC; SDIV为 + - * / 法; AND; ORR; BIC; ORN; EOR; 为按位与, 按位或, 位清除, 按位或非, 按位异或;
 
bic r0, r0, #0x1f / / 令 r0 的低 5 位置为 0 ; orr r0, r0, #0x13 / / 令 r0 的低 5 位为 13 ; msr cpsr, r0 / / r0 写入 cpsr ; b 'main' ; # 表示立即寻址 ; stmia r0!, {r2} / / r2 赋值给 r0, r0 的值加 1 ; cmp r0, r1 ble bss_loop / / 比较 r0 和 r1,如果小于等于就跳转到 bss_loop；orr r0, r0, #0x13 r0 或上 0x13,表示使用 SVC 模式；打开和关闭全局中断 cpsie i cpsid i ；cps #0x13 进入 SVC 模式 ，cps #0x12 进入 IRQ 模式

### 编译步骤：

**1.预编译; 2.链接 ; 3.格式转换 ; 反汇编**
1.arm-linuxgcc -g -c 'leds.s' 'leds.o' -g 添加可调试信息 2.链接 : 将所有.o 文件链接在一起到指定的地方，要指定链接的起始地址，链接起始地址就是代码运行的起始地址，对于 6ULL 来说，链接起始地址一个指向 RAM 地址；6ULL 指向外部 的 DDR 的地址 0x87800000 ; arm-linux-gnueabihf-ld -Ttext 0X87800000 'led.o' -o 'led.elf' -ld 是链接生成.elfd 的可执行文件，-Ttext 是指定链接起始地址 3.格式转换 arm-linux-gnueabihf-objcopy -O binary -S -g led.elf led.bin 上述命令中，“-O”选项指定以什么格式输出，后面的“binary”表示以二进制格式输出，选项“-S”表示不要复制源文件中的重定位信息和符号信息，“-g”表示不复制源文件中的调试信. bin 文件的运行地址一定与链接起始地址一致，位置无关代码除外 4.反汇编 : arm-linux-gnueabihf-objdump -D led.elf > led.dis 上述代码中的“-D”选项表示反汇编所有的段，反汇编完成以后就会在当前目录下出现一个名为 led.dis 文件

## 启动头文件

内部 boot 启动 : boot rom 内部代码 + IVT + Boot data + DCD + 'leds'.bin

### 硬件启动方式选择

启动方式选择; 启动设备选择;
LED 灯实验，是从 SD 卡读取 bin 文件并启动，说明 6UL 支持从 SD 卡启动。6ULL 支持多种启动方式。6ULL 是怎么支持从多种外置 flash 启动程序的。
启动方式选择 : BOOT_MODE0 和 BOOT_MODE1，这两个是两个 IO 来控制的。选择从 USB 启动还是内部 BOOT 启动。如果要烧写系统到开发板中可以选择从 USB 下载，下载到 SD 卡，EMMC、NADN 等外置存储中。烧写完成设置从内部 BOOT 启动，然后从相应的外置存储中启动。
启动设备选择 ：前提是，你设置 MODE1 和 MODE0 是从内部 BOOT 启动的，也就是 MODE1=1，MODE0=0。支持哪些设备：NOR flash，oneNAND、NAND Flash、QSPI flash、SD/EMMC、EEPROM。我们最常用的就是 NAND、SD、EMMC 甚至 QSPI Flash。如何选择启动设备。通过 BOOT_CFG 选择,有 BOOT_CFG1,2,4，每个 8 位。一般是用 GPIO 控制的 ; BOOT_CFG 是由 LCD_DATA0~23 来设置的。在 ALPHA 开发板上，大部分默认都 47K 下拉电阻接地。BOOT_CFG4 的 8 根线全部接地。BOOT_CFG2 全部接地，除了 BOOT_CFG2[3]，此位用来选择 SD 卡启动接口。BOOT_CFG1，0，1，2 都是顶死的。3，4，5，6，7 是可以设置的。正点原子开发板 BOOT 电路设置。核心板 LCD_DATA0~23 基本 47K 下拉

### BOOT ROM 初始化内容

**初始化顺序**
在此模式下，芯片会执行内部的 boot ROM 代码，这段 boot ROM 代码会进行硬件初始化(一部分外设)，然后从 boot 设备(就是存放代码的设备、比如 SD/EMMC、NAND)中将代码拷贝出来复制到指定的 RAM 中，一般是 DDR 先初始化时钟为了加快执行速度会打开 MMU 和 Cache，下载镜像的时候 L1 ICache 会打开，验证镜像的时候 L1 DCache、L2 Cache 和 MMU 都会打开。一旦镜像验证完成，boot ROM 就会关闭 , 为了加快初始化 ; L1 DCache、L2 Cache 和 MMU, 中断向量偏移指向 boot rom, 执行了用户代码后就可以设置中断向量偏移

### IVT 和 Boot Data 数据

IVT ; Boot Data 镜像数据 IVT 包含了镜像程序的入口点、指向 DCD 的指针和一些用作其它用途的指针。 Bin 文件前面要添加头部。可以得到，我们烧写到 SD 卡中的 load.imx 文件在 SD 卡中的起始地址是 0x400，也就是 1024。头部大小为 3KB，加上偏移的 1KB，一共是 4KB，因此在 SD 卡中 bin 文件起始地址为 4096.IVT 大小为 32B/4=8 条。IVT+Boot Data 的数据，很多是我从 NXP 官方 u-boot.imx 文件里面提取出来的。Boot Data 包含了镜像的数据,比如镜像在 sd 卡的位置和最大的大小

### DCD 数据

配置时钟外设和 DDR Device configuration data，DCD 数据就是 配置 6ULL 内部寄存器的。首先，将 CCRG0~CCGR6 全部写为 0XFFFFFFFF,表示打开所有外设时钟。然后就是 DDR 初始化参数。设置 DDR 控制器，也就是初始化 DDR。其他数据都属于 DDR,比如 检查数据命令、NOP 命令、解锁命令。这些其实也都属于 DCD

### 烧写 bin 文件

./imxdownload <.bin file> < SD Card > ; 烧录的文件组成 1, 7 sd 卡启动模式 ；烧录需要准备一张新的 sd 卡，并且文件是 FTA32 格式，烧录可能会格式化；需要软件 imxdownload 烧录，./imxdownload <.bin file> < SD Card >；烧录会在 .bin 文件的基础上添加数据头生成(IVT + Boot data + DCD)load.imx ，最终 sd 卡里面会有 load.imx 这个文件；

## C 语言环境配置

### c 语言预设置

**设置处理器模式; 清除 BSS 段; 设置 sp 指针; 跳转到 C 语言;**
结构体访问寄存器 设置 6ULL 处于 SVC 模式(超级用户) 下。设置 CPSR 寄存器的 bit4-0，也就是 M[4:0]为 10011=0X13。读写状态寄存器需要用到 MRS 和 MSR 指令。MRS 将 CPSR 寄存器数据读出到通用寄存器里面，MSR 指令将通用寄存器的值写入到 CPSR 寄存器里面去; 设置 sp 指针之前一定要初始化 ddr, 其他处理器可能需要自己设置 ddr 指针 Sp 可以指向内部 RAM，也可以指向 DDR，我们将其指向 DDR。DD3 的起始地址是 0x80000000 Sp 设置到哪里？512MB 的范围 0x80000000~0x9FFFFFFF。栈大小，0x200000=2MB。处理器栈增长方式，对于 A7 而言是向下增长的。设置 sp 指向 0x80200000。

### 链接脚本文件

**自由指定段地址;**
PS. 文件名为 _ .lds 指定汇编文件的段的起始地址 用于链接; SECTIONS { ... } ; . 是定位计数器,默认为 0; .text : {_(.text)} 所有以.text 结尾的文件都放入.text 段 ; .text ALIGN(4) 4 字节对齐

## 主频和时钟配置

**时钟树; 主频(pll1_sw_clk)设置; PFD 时钟设置; AHB，IPG 和 PERCLK 根时钟设置**
**时钟树**:Chapter 10 Clock and Power Management”和“Chapter 18 Clock Controller Module (CCM) 7 路 PLL 和多路 PFD 由 3 部分组成，CLOCK_SWITCHER、CLOCK ROOT GENERATOR 和 SYSTEM CLOCKS 中间的一部分来控制左边的部分输出给右边;
**主频(pll1_sw_clk)设置** : 主频有两路来源，PLL1 和 step_clk ，在设置 PLL1 的时候要将主频设置为 step_clk 模式，设置完后再变为 PLL1;
**PFD 时钟设置**：PLL1 已经设置，由几路 PLL 是固定的，只有 PLL2 和 PLL3 需要手动设置 ，PLL2 和 PLL3 各有一个寄存器设置 PFD;
**AHB，IPG 和 PERCLK 根时钟设置**：因为大量外设要用 IPG 和 PERCLK 时钟，CBCDR 寄存器配置 AHB，IPG 的时钟源和分频数，CCM_CBCMR 和 CCM_CSCMR1 设置 perclk 的时钟源和分频 ， 修改某些时钟源会发生握手，并保存着握手是否成功的消息；

## 中断

### 中断向量表

一共有 8 个异常中断，向量地址依次在程序最前面，一般只编写 Rest 和 IRQ 中断，其他都是死循环，用汇编在程序前面 ldr pc**, =**IRQ_Handler ，再在后面 IRQ_Handler： 编写函数，因为起始地址是 0x0，但是程序起始地址是 0x8...所以需要配置向量偏移; pc 是指向代码的指针

### GIC

armv7 架构的用的 GICv2，最多支持 8 核，GIC 将中断分为了 3 种，共享，私有和软件 ；每个特定的中断都会被分配一个 ID，一个 CPU 最多有 1024 个 ID，按照特定给 3 种中断分配 ；可分为两个逻辑块 Distributor 和 CPU Interface 通过 CP15 得到 GIC 的基地址再 + 1000 和 +2000 访问两个逻辑块的各自寄存器 接收中断 ID 发送 IRQ 信号(或者其他 3 种信号)给内核 ;该芯片一共 128 个 ID

### CP15

CP15 协处理器一般用于存储系统管理，但是在中断中也会使用到，CP15 协处理器一共有 16 个 32 位寄存器 ，通过 MRC/ MCR p15, <opc1>, <Rt>, <CRn>, <CRm>, <opc2> 分别对协处理器 CRn 寄存器读写到 Rt 的 ARM 源寄存器 ；arm 很多源寄存器的读写都要通过 cp15；

### 中断使能和优先级

总中断使能 IRQ 设置总优先级数 GICC_PMR 一般为 32 ；抢占优先级和子优先级位数设置 GICC_BPR 一般为 2，代表[7:3]是设置子优先级[2:0]为抢占优先级，设置中断 ID 的优先 GICD_IPRIORITYR[40] = 5 << 3 为 5;

### 中断模式编写

#### 复位中断函数

关闭中断，关闭 Dcache，MMU 等 SCTLR 寄存器，设置中断向量表的偏移 VBAR 寄存器 ，再进入各个模式配置 sp 指针，最后打开中断进入 main 中； dsb,isb 指令保证前面全部正常运行；DDR 范围:0X80000000~0X9FFFFFFF 或者 0X8FFFFFFF

#### IRQ 中断函数

进入先保存现场，再得到 CPU 接口端基地址后找到中断号，进入 SVC 模式 传入 ID 的参数来运行中断处理函数再进入 IRQ 模式，还原现场并写 GICC_EOIR 表示中断完成，再将 subs pc**,** lr**,** #4 ，因为指向一条语句要 8 个字节，0 进行执行，4 进行译指，8 进行取值，在 4 的时候会进入中断，保存 pc 的时候会保存到 8，所以要减 4

#### system_irqhandler 编写

定义中断服务函数 typedef void (*system_irq_handler_t) (unsigned int giccIar, void *param); 定义 160 大小的向量表结构体 ，结构体有函数和 void \* ；初始化 GIC 和向量表 ；初始化向量表，将各个中断 ID 的中断函数写入向量表中

### 中断函数编写

#### GPIO 触发设置

GPIOx_ICR1/2 来设置触发方式；IMR 使能中断 ；ISR 中断标志位的清除 ；边沿触发 设置 GPIOGPIOx_EDGE_SEL

#### 中断初始化

GIC_Init() 初始化 GIC , 初始化 GPIO，设置中断优先级，GIC_EnableIRQ()开启对应中断，将向量表的对应中断的函数注册，传递参数；编写对应中断函数

## 定时器

### EPIT

周期中断定时器 ，32 位向下计数器，12 位分频；设置时钟源，分频值和工作模式，设置计数器的初始值来源和使能比较中断，设置加载值和比较值来决定周期，配置中断 ，需要手动清除中断标志位；可以用中断来实现不延时的消抖

### GPT

32 位向上可选时钟源精准计数器，可选时钟源, 内部 12 为分频器, 2 输入捕获，3 输出捕获可生成捕获中断和比较中断(只有通道 1 可以在重新启动模式下使用)以及溢出中断，2 种工作模式，一般用来高精度的延时;

## 串口通信
串口有TTL电平和RS-232电平; 一个8个UART, CCM_CSCDR1设置时钟源和分频, 8的UART的寄存器是分开的, 几个寄存器控制一个UART; 如果要重写printf函数需要移植相应的输出文件

## DDR3

### DDR3介绍
SRAM: 静态随机存储寄存器,适合做高速缓存区; SDRAM: 比起SRAM多了clk的始终线来刷新保证数据不丢失, 因为地址线不够, 还有BANK区的选择线 适合做内存条; DDR 在SDRAM的基础上在clk的上升沿和下降沿都传输数据, 所以有预取(2bit), 传输速率加了一倍; DDR3预取了8bit所以速率加了8倍, 有8个BANK和16根数据线; DDR3 关键参数: 1.传输速率. 2.tRCD 指发出行激活命令和列命令发出到读写命令的时间. 3.CL 数据从存储单元到IO口的时间. 4.AL 为读指令发出到执行的时间, RL为读潜伏期为AL + CL; 5.tRC 两个 ACTIVE 命令，或者 ACTIVE 命令到 REFRESH 命令之间的周期. 6.tRAS ACTIVE 命令到 PRECHARGE 命令之间的最小时间.
### MMDC 控制器
MMDC 就是 I.MX6U的内存控制器，MMDC 是一个多模的 DDR 控制器，可以连接 16 位宽的 DDR3/DDR3L、16 位宽的 LPDDR2，MMDC 是一个可配置、高性的 DDR 控制器。MMDC 外设包含一个内核(MMDC_CORE)和 PHY(MMDC_PHY)，内核和 PHY 的功能如下：MMDC 内核：内核负责通过 AXI 接口与系统进行通信、DDR 命令生成、DDR 命令优化、读/写数据路径。MMDC PHY：PHY 负责时序调整和校准，使用特殊的校准机制以保障数据能够在 400MHz被准确捕获; 
### DDR3 初始化与测试
1. ddr_stress_tester 配置文件根据手册上面找到DDR3L 1866版本的参数用官网的xlsx文件进行配置, 生成配置的.inc文件;
2. 测试: ddr_stress_tester软件 通过usb将生成的.inc文件下载到板子里面进行测试, 开关拨到usb启动; 先校准, 将校准后的寄存器值进行修改后再进行压力测试; 最后得到的.inc的值即为初始化DDR寄存器的初始值, 为启动头文件的值, 加入到DCD当中