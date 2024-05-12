@echo off
set BasePath=C:\Users\jswee\Desktop\Sweetsir Technologies\Projects\tales-of-krendor-text-based\

echo Base path is set to: %BasePath%
set /p SubDirectory="Enter the subdirectory (relative to the base path) where you want to create the file: "
set FullPath=%BasePath%%SubDirectory%

if not exist "%FullPath%" (
    echo The specified directory %FullPath% does not exist.
    pause
    exit /b
)

cd /d "%FullPath%"
set /p FileName="Enter the name of the file to create: "
echo Creating an empty file named %FileName% in %FullPath%
type nul > "%FileName%"
echo File created successfully.
pause
