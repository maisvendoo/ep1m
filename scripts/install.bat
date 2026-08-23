echo "Hi!"

xcopy /E /Y ..\cfg\*.* %RRS_DEV_ROOT%\cfg\
xcopy /E /Y ..\data\animations\*.* %RRS_DEV_ROOT%\data\animations\
xcopy /E /Y ..\data\models_ktx\*.* %RRS_DEV_ROOT%\data\models\
xcopy /E /Y ..\data\sounds\*.* %RRS_DEV_ROOT%\data\sounds\
xcopy /E /Y ..\..\modules\*.* %RRS_DEV_ROOT%\modules