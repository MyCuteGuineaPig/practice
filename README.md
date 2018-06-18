
## Auto Linked Library for C++ Visual Studio



1. Install, [vcpkg](https://github.com/Microsoft/vcpkg) 
Open Github desktop
  
```PS
> git clone https://github.com/Microsoft/vcpkg
> cd vcpkg
```
2. Then, to hook up user-wide integration(让以后的library都可以通过vcpkg安装), run (note: requires admin on first use), Use PowerShell
```
PS> .\vcpkg integrate install

```
</li>
<li> Install library via vcpkg


```
> cd vcpkg
PS> vcpkg install cpprestsdk cpprestsdk:x64-windows
```
</li>
</ol>
