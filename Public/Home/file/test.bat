@echo on
call vcvars32
pause
::编译文件
cl /EHsc F:\xampp\htdocs\CodeBattle\Public\Home\file\ticktacktoe\0_code.cpp
pause
::执行文件、写入文件
call 0_code.exe > result.txt
pause
exit