组合逻辑的右边的值都要添加到always的敏感列表里面一般直接写(*)；非阻塞赋值只能在initial何always块等过程块中使用，0,x,z都按假处理; case语句中所有表达式的位宽必须相等，casez不用考虑表达式中的高阻值，casex既不考虑高阻值也不考虑不定值；状态机最后一级可以加一个时序逻辑的寄存器，可以有效滤去组合逻辑输出的毛刺，进行时序计算与约束，容易使得总线数据对齐

