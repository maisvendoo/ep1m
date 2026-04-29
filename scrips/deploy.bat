set ADDON_NAME=ep1m
set VERSION=v2.0.5
set DIR_NAME=%ADDON_NAME%-%VERSION%

set PKG_DIR=..\..\package

rem Создаем каталог для пакета
mkdir %PKG_DIR%
mkdir %PKG_DIR%\%DIR_NAME%

rem Создаем структуру каталогов
mkdir %PKG_DIR%\%DIR_NAME%\cfg
mkdir %PKG_DIR%\%DIR_NAME%\docs
mkdir %PKG_DIR%\%DIR_NAME%\data
mkdir %PKG_DIR%\%DIR_NAME%\data\animations
mkdir %PKG_DIR%\%DIR_NAME%\data\models
mkdir %PKG_DIR%\%DIR_NAME%\data\sounds
mkdir %PKG_DIR%\%DIR_NAME%\modules\
mkdir %PKG_DIR%\%DIR_NAME%\modules\%ADDON_NAME%

rem Копируем модули
xcopy /E /Y ..\..\modules\%ADDON_NAME%\*.dll %PKG_DIR%\%DIR_NAME%\modules\%ADDON_NAME%

rem Копируем конфиги
xcopy /E /Y ..\cfg\*.* %PKG_DIR%\%DIR_NAME%\cfg\

rem Копируем ресурсы
xcopy /E /Y ..\data\animations\*.* %PKG_DIR%\%DIR_NAME%\data\animations
xcopy /E /Y ..\data\models_ktx\*.* %PKG_DIR%\%DIR_NAME%\data\models
xcopy /E /Y ..\data\sounds\*.* %PKG_DIR%\%DIR_NAME%\data\sounds

rem Копируем документацию
xcopy /E /Y ..\docs\*.pdf %PKG_DIR%\%DIR_NAME%\docs\

rem Архифируем в 7zip
cd %PKG_DIR%\%DIR_NAME%
7z a -r ..\%DIR_NAME%.7z 
cd ..\..\%ADDON_NAME%\scripts