## 1. 处理文本，得到最频繁使用的3个命令

下载数据
```shell
$ wget http://labfile.oss.aliyuncs.com/courses/1/data1
```

data1 文件里记录是一些命令的操作记录，现在需要你从里面找出**出现频率次数前3**的命令并保存在 /home/shiyanlou/result。

1. 处理文本文件 /home/shiyanlou/data1
2. 将结果写入 /home/shiyanlou/result
3. 结果包含三行内容，每行内容都是出现的次数和命令名称，如“100 ls”

Answer: 
```shell
cat data1 |cut -c 8-|sort|uniq -dc|sort -rn -k1 |head -3 > /home/shiyanlou/result

#or
cut data1 -c 8-|sort|uniq -dc|sort -rn -k1 |head -3 > /home/shiyanlou/result
```

来源： 2016 年百度校招面试题


## 2. 挑战：数据提取

小明在做数据分析的时候需要提取文件中关于数字的部分，同时还要提取用户的邮箱部分，但是有的行不是数组也不是邮箱，现在需要你在 data2 这个文件中帮助他用正则表达式匹配出数字部分和邮箱部分。

数据文件可以使用以下命令下载：
```shell
$ cd /home/shiyanlou
$ wget http://labfile.oss.aliyuncs.com/courses/1/data2
```
下载后的数据文件路径为 ```/home/shiyanlou/data2```

目标
- 在文件 ```/home/shiyanlou/data2``` 中匹配数字开头的行，将所有以数字开头的行都写入 ```/home/shiyanlou/num``` 文件。
- 在文件 ```/home/shiyanlou/data2``` 中匹配出正确格式的邮箱，将所有的邮箱写入 ```/home/shiyanlou/mail``` 文件，注意该文件中每行为一个邮箱。

提示: 邮箱的格式匹配 注意符号 . 的处理

来源: 2016 年 TapFun 校招面试题

参考答案
```shell
grep '^[0-9]' /home/shiyanlou/data2 > /home/shiyanlou/num
#or 
cat /home/shiyanlou/data2  | grep '^[0-9]'  > /home/shiyanlou/num

grep -E '^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(.[a-zA-Z0-9_-]+)+$' /home/shiyanlou/data2 > /home/shiyanlou/mail

```
