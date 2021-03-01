@echo off

set compiler_flags=-FC -MD -Gm- -nologo -GR- -EHa- -Oi  -W4 -wd4201 -wd4100 -wd4127 -wd4505 -wd4189 -fp:fast -Z7 -Od -EHsc

if not exist build\. mkdir build
pushd build

cl %defines% %compiler_flags% %include_dirs%   ..\main.cpp /link -incremental:no 

popd