@echo on
call vcvars32
pause
::�����ļ�
cl /EHsc F:\xampp\htdocs\CodeBattle\Public\Home\file\ticktacktoe\0_code.cpp
pause
::ִ���ļ���д���ļ�
call 0_code.exe > result.txt
pause
exit