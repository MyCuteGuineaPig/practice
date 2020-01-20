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

## 3.  

新建一个 cleantest.sh 脚本运行实现清空 test.sh 里的内容

```bash
$ touch /home/shiyanlou/cleantest.sh
$ cat > /home/shiyanlou/cleantest.sh << EOF
#!/bin/bash
cat /dev/null > test.sh
EOF
```


## 4. 

写一个Bash脚本

(1) 提示用户输入一个字符串；

(2) 判断：

如果输入的是quit，则退出脚本；

否则，则显示其输入的字符串内容；

```bash
#!/bin/bash

read -t 10 -p "Please enter string: " inputStr #-t time out
# -p  表示继续那行输入 不开启新一行, 
# 如果没有 -p 会
# Please enter string
#  输入值

case $inputStr in
quit) 
  exit 1
  ;; 
*)
  echo "$inputStr"
  ;;
esac
```

## 5 三角输出

写一个Bash脚本, 画出
```
    *
   * *
  * * *
 * * * *
* * * * *
```

Solution 1: 

```bash
line=15
for(( i=1; i<=$line; i++ ))
do 
    for(( j=1; j<$line; j++ ))
    do 
        echo -n " "
    done
    for (( j=1; j<=2*i-1; j++ ))
    do 
        eho -n "*'
    done
    echo 
done 

```



Solution 2

```bash
for((i=1;i<=5;i++))
do

  spaceNum=$((5-$i))
  num=$((2*$i-1))

  for ((j=1; j<=$spaceNum; j++))
  do
    echo -n ' '
  done

  for ((k=1; k<=$num; k++))
  do
    echo -n '*'
  done

  for ((l=1; j<=$spaceNum; l++))
  do
    echo -n ' '
  done

  echo ''
done
```

## 6. 三个数中最大数

```bash
a=8
b=4
c=5
maxn=$a
for i in $b $c
do 
  if [[ $i>$maxn ]]
  then 
    maxn=$i #maxn 不加$
  fi
done
```

Solution 2:

```bash
#!/bin/bash
max=0
a=8
b=4
c=5
for i in $a $b $c
do 
  if [ $i -gt $max ]
  then 
    max=$i
  fi
done
echo $max
```

## 7.求 100 以内所有偶数之和

Solution 1:

```bash
sum=0
for(( i=2; i<=100; i+=2 ))
do 
     sum=`expr $sum + $i` #注意sum=`expr 之间都不能有空格，否则报错 
done
echo "sum for all even numbers from 2 to 100 is $sum"
```

Solution 2:

```bash
#!/bin/bash
cnt=0
sum=0
for cnt in `seq 2 2 100`
do
  sum=$((cnt+sum))
done 

echo $sum
```

```seq 2 2 100``` 表示列出 1 到 100 的所有偶数
