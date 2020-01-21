
## Auto Linked Library for C++ Visual Studio



__1__. Install, [vcpkg](https://github.com/Microsoft/vcpkg) 
Open Github desktop

```PS
> git clone https://github.com/Microsoft/vcpkg
> cd vcpkg
``` 

__2__. Then, to hook up user-wide integration(让以后的library都可以通过vcpkg安装), run (note: requires admin on first use), Use PowerShell
```
PS> .\vcpkg integrate install

```

__3__. Install library via vcpkg

```
> cd vcpkg
PS> .\vcpkg install cpprestsdk cpprestsdk:x64-windows
PS> .\vcpkg install boost:x86-windows
```


## Linux No Wifi Adaptor 解决办法

插网线！

**1.** 打开terminal 

**2.** ```sudo su```

**3.** ```sudo apt-get update```

**4.** ```sudo apt-get --reinstall install bcmwl-kernel-source```
