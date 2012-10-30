rem E:\program\Common7\IDE\devenv.exe "bgcc.sln" /build Debug /project "bgcc.vcproj" 
"C:/Program Files/Microsoft Visual Studio .NET 2003/Common7/IDE/Devenv.exe" "bgcc.sln" /build Debug /project "bgcc.vcproj" 
mkdir output\lib
copy Debug\bgcc.lib output\lib\bgcc.lib
mkdir output\include
copy  bgcc\*.h output\include

rem E:\program\Common7\IDE\devenv.exe "bgcc.sln" /build Debug /project "adapter\java\bgcc4j\bgcc4j\bgcc4j.vcproj"
"C:/Program Files/Microsoft Visual Studio .NET 2003/Common7/IDE/Devenv.exe" "bgcc.sln" /build Debug /project "adapter\java\bgcc4j\bgcc4j\bgcc4j.vcproj"
copy adapter\java\bgcc4j\bgcc4j\Debug\bgcc4j.dll output\lib\bgcc4j.dll

ant -f adapter\java\bgcc\build.xml
