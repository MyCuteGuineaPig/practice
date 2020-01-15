1. 处理文本，得到最频繁使用的3个命令

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
