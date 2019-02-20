using System;
using System.IO;
using System.Threading;
using System.Windows.Forms;

namespace IceMemeUI
{
    class Functions
    {
        public static string exploitdll = "IceMeme.dll";//this is the name of your dll
        public static void Inject()
        {
            if (NamedPipes.NamedPipeExist(NamedPipes.luacpipename))//check if the pipe exist
            {
                MessageBox.Show("Already injected!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);//if the pipe exist that's mean that we don't need to inject
                return;
            }
            else if (!NamedPipes.NamedPipeExist(NamedPipes.luacpipename))//check if the pipe don't exist
            {
                switch (Injector.DllInjector.GetInstance.Inject("RobloxPlayerBeta", AppDomain.CurrentDomain.BaseDirectory + exploitdll))//Process name and dll directory
                {
                    case Injector.DllInjectionResult.DllNotFound://if can't find the dll
                        MessageBox.Show("Couldn't find " + exploitdll, "Dll was not found!", MessageBoxButtons.OK, MessageBoxIcon.Error);//display messagebox to tell that dll was not found
                        return;
                    case Injector.DllInjectionResult.GameProcessNotFound://if can't find the process
                        MessageBox.Show("Couldn't find RobloxPlayerBeta.exe!", "Target process was not found!", MessageBoxButtons.OK, MessageBoxIcon.Error);//display messagebox to tell that proccess was not found
                        return;
                    case Injector.DllInjectionResult.InjectionFailed://if injection fails(this don't work or only on special cases)
                        MessageBox.Show("Injection Failed!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);//display messagebox to tell that injection failed
                        return;
                }
                Thread.Sleep(3000);//pause the ui for 3 seconds
                if (!NamedPipes.NamedPipeExist(NamedPipes.luacpipename))//check if the pipe dont exist
                {
                    MessageBox.Show("Injection Failed!\nMaybe you are Missing something\nor took more time to check if was ready\nor other stuff", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);//display that the pipe was not found so the injection was unsuccessful
                }
            }
        }

        public static string[] TextToBox =
        {
            //Commands [0]
            "\n" +
            "Commands:\n" +
            "ff [p]\n" +
            "heaven [p]\n" +
            "ghost [p]\n" +
            "statchange [p] [stat] [#]\n" +
            "keemstar [p]\n" +
            "illuminati [p]\n" +
            "duck [p]\n" +
            "mlg [p]\n" +
            "pussy [p]\n" +
            "fog [#]\n" +
            "rfog\n" +
            "rhat [p]\n" +
            "ws [p] [#]\n" +
            "sit [p]\n" +
            "hipheight [p] [#]\n" +
            "jp [p] [#]\n" +
            "kill [p]\n" +
            "drivebloxmoney [p]\n" +
            "gravity [#]\n" +
            "btools [p]\n" +
            "god [p]\n" +
            "bigfire [p]\n" +
            "time [#]\n" +
            "select [p]\n" +
            "fencingr\n" +
            "forcechat [p] [blue/red/green]\n" +
            "charapp [p] [#]\n" +
            "noob [p]\n" +
            "fire [p]\n" +
            "smoke [p]\n" +
            "sethealth [p] [#]\n" +
            "addhealth [p] [#]\n" +
            "sparkles [p]\n" +
            "criminal\n" +
            "garage\n" +
            "bank\n" +
            "prison\n" +
            "nodoors\n" +
            "banklazers\n" +
            "jewelrycameras\n" +
            "jewelrylazers\n" +
            "jewelryflazers\n" +
            "jewelry\n" +
            "rickroll\n" +
            "ppap\n" +
            "billnye\n" +
            "illuminati\n" +
            "rage\n" +
            "cringe\n" +
            "clearws\n" +
            "unanchorall\n" +
            "fecheck\n" +
            "play [#]\n" +
            "stopmusic\n" +
            "insert [#]\n" +
            "Some Commands may not work",
            //Credits [1]
            "\n" +
            "Credits:\n" +
            "rakion99\n" +
            "Roblox\n" +
            "Jayden\n" +
            "louka for danghui\n" +
            "Africaus for pcall bypass\n" +
            "VOID for getobjects\n" +
            "tepig for Memehax\n" +
            "DOGGO bypass/workaround for setting values on non-fe games\n" +
            "Eternal for RetCheck\n" +
            "AutisticBobby\n" +
            "Powered by Lua\n" +
            "Powered by cURL\n" +
            "ICE By: Josh() and Cosmology"
        };

        public static OpenFileDialog openfiledialog = new OpenFileDialog
        {
            Filter = "LuaC/Lua Script Txt (*.txt)|*.txt|All files (*.*)|*.*",//add txt and all files filter
            FilterIndex = 1,//choose what filter will be the default
            RestoreDirectory = true,//restore the last used directory
            Title = "IceMeme Lua/LuaC Open Script"//OpenFileDialog Tittle
        };//Initialize OpenFileDialog

        public static void PopulateListBox(ListBox lsb, string Folder, string FileType)
        {
            DirectoryInfo dinfo = new DirectoryInfo(Folder);
            FileInfo[] Files = dinfo.GetFiles(FileType);
            foreach (FileInfo file in Files)
            {
                lsb.Items.Add(file.Name);
            }
        }

        public static bool UpdateUI = false;
        public static bool UpdateDLL = false;
    }
}
