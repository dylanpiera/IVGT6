# remove the temporary directory if it still exists
rd /s /q temp

# cleanup binaries, they will be rebuild during the process
rmdir /s /q "%WORKSPACE%\PGTProject\Binaries"

# cleanup intermediates, they will be rebuild during the process
rmdir /s /q "%WORKSPACE%\PGTProject\Intermediate"

ECHO "-Step 1 completed-"

cd "%ENGINE_ROOT%\%ENGINE_VERSION%\Engine\Binaries\DotNET\"
.\UnrealBuildTool.exe -projectfiles -project="%WORKSPACE%\PGTProject\%PROJECT_NAME%.uproject" -game -rocket -progress

# Rebuild our binaries
"%ENGINE_ROOT%/%ENGINE_VERSION%/Engine/Binaries/DotNET/UnrealBuildTool.exe" %PROJECT_NAME% %BUILD_CONFIGURATION% Win64 -project="%WORKSPACE%/%PROJECT_NAME%/%PROJECT_NAME%.uproject" -rocket -editorrecompile -progress -noubtmakefiles -NoHotReloadFromIDE -2017

# Create a folder to store our build in
if not exist "%WORKSPACE%/temp/x64" mkdir "%WORKSPACE%/temp/x64"

"%ENGINE_ROOT%\%ENGINE_VERSION%\Engine\Build\BatchFiles\RunUAT.bat" BuildCookRun -project="%WORKSPACE%\%PROJECT_NAME%\%PROJECT_NAME%.uproject" -noP4 -platform=Win64 -clientconfig=%BUILD_CONFIGURATION% -cook -allmaps -build -stage %USE_PAK% -archive -archivedirectory="%WORKSPACE%/temp/x64"

"%ARCHIVE_ROOT%/7z.exe" a -t7z %WORKSPACE%\builds\%BUILD_CONFIGURATION%\%PROJECT_NAME%_%BUILD_CONFIGURATION%_%P4_CHANGELIST%_x64.rar "%WORKSPACE%\temp\x64\%PROJECT_NAME%_%BUILD_CONFIGURATION%_%P4_CHANGELIST%_x64"