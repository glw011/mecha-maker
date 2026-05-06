@echo off
REM Remy, change 'ENGINE_PATH' to your UE install on your machine (if it isn't in default install location below) 

SET ENGINE_PATH=C:\Program Files\Epic Games\UE_5.7
SET UAT=%ENGINE_PATH%\Engine\Build\BatchFiles\RunUAT.bat
SET PROJECT=%~dp0MechaMaker.uproject
SET ARCHIVE_DIR=%~dp0Packaged\Win64

IF NOT EXIST "%UAT%" (
    echo ERROR: RunUAT.bat not found at %UAT%
    echo Update ENGINE_PATH to match local install location of UE 5.7
    pause
    exit /b 1
)

IF NOT EXIST "%PROJECT%" (
    echo ERROR: MechaMaker.uproject not at %PROJECT%
    pause
    exit /b 1
)

echo === MechaMaker Windows-64 Build ===
echo   Engine : %ENGINE_PATH%
echo   Project: %PROJECT%
echo   Output : %ARCHIVE_DIR%
echo.

call "%UAT%" BuildCookRun ^
    -project="%PROJECT%" ^
    -noP4 ^
    -platform=Win64 ^
    -clientconfig=Shipping ^
    -cook ^
    -allmaps ^
    -build ^
    -stage ^
    -pak ^
    -compressed ^
    -archive ^
    -archivedirectory="%ARCHIVE_DIR%"

IF %ERRORLEVEL% NEQ 0 (
    echo.
    echo ERROR: Packaging failed... Logs in: %~dp0Saved\Logs\
    pause
    exit /b 1
)

echo.
echo === BUILD COMPLETED SUCCESSFULLY! Archived to: %ARCHIVE_DIR% ===
pause
