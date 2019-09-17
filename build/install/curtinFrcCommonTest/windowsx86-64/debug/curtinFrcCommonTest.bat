
@echo off
SETLOCAL

CALL "%~dp0lib\curtinFrcCommonTest.exe" %*
EXIT /B %ERRORLEVEL%
ENDLOCAL
