
[Setup]
AppName=6�l�̗����l�ƐǊ�̏����`FullCourse�`
AppVerName=6�l�̗����l�ƐǊ�̏����`FullCourse�`
VersionInfoVersion=1.0.0.0
AppCopyright=�Ō�̔ӎ`
AppPublisher=�Ō�̔ӎ`
AppPublisherURL=http://the-last-dinner.club
AppVersion=1.0
UsePreviousAppDir=no
DefaultDirName={pf}\6chefs_full
DefaultGroupName=6�l�̗����l�ƐǊ�̏����`FullCourse�`
UninstallDisplayIcon={app}\6chefs_full.exe
Compression=lzma
SolidCompression=yes

;�E�B�U�[�h�y�[�W�ɕ\�������O���t�B�b�N�i*.bmp: 164 x 314�j
WizardImageFile=C:\Users\LastDinner\Desktop\6chefs_full\installer.bmp
;�E�B�U�[�h�y�[�W�ɕ\�������O���t�B�b�N���g�傳��Ȃ�
WizardImageStretch=no
;���̌��ԐF
WizardImageBackColor=$ffffff

[Files]Source: "C:\Users\LastDinner\Desktop\6chefs_full\src\*"; DestDir: "{app}"

;Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\common\*"; DestDir: "{app}\common"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\common\BGM\*"; DestDir: "{app}\common\BGM"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\common\img\*"; DestDir: "{app}\common\img"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\common\save\*"; DestDir: "{app}\common\save"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\common\se\*"; DestDir: "{app}\common\se"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\common\config\*"; DestDir: "{app}\common\config"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\common\fonts\*"; DestDir: "{app}\common\fonts"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\common\voice\*"; DestDir: "{app}\common\voice"

;Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs\*"; DestDir: "{app}\6chefs"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs\character\*"; DestDir: "{app}\6chefs\character"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs\csv\*"; DestDir: "{app}\6chefs\csv"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs\event\*"; DestDir: "{app}\6chefs\event"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs\img\disp\*"; DestDir: "{app}\6chefs\img\disp"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs\img\*"; DestDir: "{app}\6chefs\img"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs\map\*"; DestDir: "{app}\6chefs\map"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs\save\*"; DestDir: "{app}\6chefs\save"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs\config\*"; DestDir: "{app}\6chefs\config"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs\effect\*"; DestDir: "{app}\6chefs\effect"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs\detection\*"; DestDir: "{app}\6chefs\detection"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs\video\OPmovie\*"; DestDir: "{app}\6chefs\video\OPmovie"

;Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs2\*"; DestDir: "{app}\6chefs2"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs2\character\*"; DestDir: "{app}\6chefs2\character"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs2\csv\*"; DestDir: "{app}\6chefs2\csv"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs2\event\*"; DestDir: "{app}\6chefs2\event"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs2\img\disp\*"; DestDir: "{app}\6chefs2\img\disp"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs2\img\*"; DestDir: "{app}\6chefs2\img"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs2\map\*"; DestDir: "{app}\6chefs2\map"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs2\save\*"; DestDir: "{app}\6chefs2\save"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs2\config\*"; DestDir: "{app}\6chefs2\config"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs2\effect\*"; DestDir: "{app}\6chefs2\effect"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs2\detection\*"; DestDir: "{app}\6chefs2\detection"
Source: "C:\Users\LastDinner\Desktop\6chefs_full\Resources\6chefs2\video\OPmovie\*"; DestDir: "{app}\6chefs2\video\OPmovie"

[Dirs]
Name: {app}\common\save;Permissions: everyone-modify
Name: {app}\6chefs\save;Permissions: everyone-modify
Name: {app}\6chefs2\save;Permissions: everyone-modify
Name: {app};Permissions: everyone-modify

[Tasks]
Name: desktopicon; Description: "�f�X�N�g�b�v�ɃV���[�g�J�b�g���쐬����"

[Icons]
Name: "{group}\6�l�̗����l�ƐǊ�̏���2"; Filename: "{app}\6chefs_full.exe"
Name: "{commondesktop}\6�l�̗����l�ƐǊ�̏���2"; Filename: "{app}\6chefs_full.exe"; WorkingDir: "{app}"; Tasks: desktopicon

[Languages]
Name:"jp";MessagesFile:"C:\Program Files (x86)\Inno Setup 5\Languages\Japanese.isl";

[Run]
Filename: "{app}\6chefs_full.exe"; Description: "�C���X�g�[���I�����ɃQ�[�����N������"; Flags: postinstall
