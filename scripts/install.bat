echo "Hi!"

xcopy /E /Y ..\cfg\*.* %RRS_DEV_ROOT%\cfg\
xcopy /E /Y ..\data\*.* %RRS_DEV_ROOT%\data\
xcopy /E /Y ..\..\modules\*.* %RRS_DEV_ROOT%\modules