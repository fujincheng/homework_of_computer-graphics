#bash shell

### 概述
- 用户和Linux内核交互的工具

### 配置
 
#####变量
  - 可以通过变量来设置shell或其他程序
  - 变量存在于内存中
  - Linux有自定义变量（local）和环境变量（environment），二者作用范围不同
  
  - set查看所有的变量
  - env可以查看所有的环境变量
  
#####设置
  1. 通过自定义变量来设置
    - VARIABLE = value
    - echo $VARIABLE 获取变量值
    - 变量名不能以数字或特殊字符开头
    - 单引号和双引号的区别
    - 通过自定义PATH可以快速到达路径
    - 使用unset删除
    - 常见的变量
      1. HISTFILESIZE： 记录历史指令保存的最大值
      2. COLUMNS：终端窗口显示的宽度
      3. LINES：终端窗口显示的高度
      4. PS1：设置提示符号前面的内容样式  
  2. 通过别名（Aliases）设置
  	- $ alias lss= 'ls-la'
  	- 使用alias自身查看所有的alias
  	- 使用alias和alias名称查看alias值
  	- type -a alias名称查看
  	- 使用unalias删除
  3. 通过（set）指令设置
  4. 通过环境变量设置