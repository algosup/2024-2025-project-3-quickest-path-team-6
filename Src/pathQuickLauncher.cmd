@echo off
rem Get the directory of the current script
set SCRIPT_DIR=%~dp0

rem Open a new command prompt for the Server script
start cmd /k "cd /d %SCRIPT_DIR%\Server && startServer.cmd"
rem Open a new command prompt for the Client script
start cmd /k "cd /d %SCRIPT_DIR%\Client && startClient.cmd"