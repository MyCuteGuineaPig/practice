
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
PS> vcpkg install cpprestsdk cpprestsdk:x64-windows
```

