@echo on
::调用编译器
call vcvars32
pause
::编译文件
cl /EHsc %1
pause
::执行文件、写入文件
call %2>%3
pause
exit