using System;
using System.Drawing;
using System.IO;
using System.IO.Pipes;
using System.Runtime.InteropServices;
using System.Threading;
using System.Windows.Forms;

namespace IceSourceUI
{
    public partial class IceSourceForm : Form
    {
        public IceSourceForm()
        {
            InitializeComponent();
            //TopMost Enabled by default
            TopMost = true;
        }
        //change this strings to your taste
        string exploitdll = "IceSource.dll";//this is the name of your dll
        string cmdpipe = "IceSkidCmd";//name of command pipe
        string scriptpipe = "IceSkidC";// name of lua c pipe

        [DllImport("kernel32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        private static extern bool WaitNamedPipe(string name, int timeout);
        //function to check if the pipe exist
        public static bool NamedPipeExist(string pipeName)
        {
            bool result;
            try
            {
                int timeout = 0;
                if (!WaitNamedPipe(Path.GetFullPath(string.Format("\\\\\\\\.\\\\pipe\\\\{0}", pipeName)), timeout))
                {
                    int lastWin32Error = Marshal.GetLastWin32Error();
                    if (lastWin32Error == 0)
                    {
                        result = false;
                        return result;
                    }
                    if (lastWin32Error == 2)
                    {
                        result = false;
                        return result;
                    }
                }
                result = true;
            }
            catch (Exception)
            {
                result = false;
            }
            return result;
        }
        //command pipe function
        private void CommandPipe(string command)
        {
            if (NamedPipeExist(cmdpipe))
            {
                try
                {
                    using (NamedPipeClientStream namedPipeClientStream = new NamedPipeClientStream(".", cmdpipe, PipeDirection.Out))
                    {
                        namedPipeClientStream.Connect();
                        using (StreamWriter streamWriter = new StreamWriter(namedPipeClientStream))
                        {
                            streamWriter.Write(command);
                            streamWriter.Dispose();
                        }
                        namedPipeClientStream.Dispose();
                    }
                }
                catch (IOException)
                {
                    MessageBox.Show("Error occured connecting to the pipe.", "Connection Failed!", MessageBoxButtons.OK, MessageBoxIcon.Hand);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message.ToString());
                }
            }
            else
            {
                MessageBox.Show("Inject " + exploitdll + " before Using this!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }
        }
        //lua c pipe function
        private void LuaCPipe(string script)
        {
            if (NamedPipeExist(scriptpipe))
            {
                try
                {
                    using (NamedPipeClientStream namedPipeClientStream = new NamedPipeClientStream(".", scriptpipe, PipeDirection.Out))
                    {
                        namedPipeClientStream.Connect();
                        using (StreamWriter streamWriter = new StreamWriter(namedPipeClientStream))
                        {
                            streamWriter.Write(script);
                            streamWriter.Dispose();
                        }
                        namedPipeClientStream.Dispose();
                    }
                }
                catch (IOException)
                {
                    MessageBox.Show("Error occured connecting to the pipe.", "Connection Failed!", MessageBoxButtons.OK, MessageBoxIcon.Hand);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message.ToString());
                }
            }
            else
            {
                MessageBox.Show("Inject " + exploitdll + " before Using this!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }
        }
        //clear button click event
        private void Clear_Click(object sender, EventArgs e)
        {
            LuaCBox.Clear();//this clear all the text in luac richtextbox
        }
        //execute button click event
        private void Execute_Click(object sender, EventArgs e)
        {
            if (NamedPipeExist(scriptpipe))//check if the pipe exist
            {
                string[] array = LuaCBox.Text.Split("\r\n".ToCharArray());//array to store all and split the script
                for (int i = 0; i < array.Length; i++)//for loop to send all the lines
                {
                    string script = array[i];
                    try
                    {
                        LuaCPipe(script);//lua c pipe function to send the array
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message.ToString());//if there any error a messagebox will pop up with the error
                    }
                }
            }
            else
            {
                MessageBox.Show("Inject " + exploitdll + " before Using this!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);//if the pipe can't be found a messagebox will appear
                return;
            }
        }
        //send button click event
        private void Send_Click(object sender, EventArgs e)
        {
            if (CmdTextBox.Text.ToLower() == "cmds")//check if the user send cmds so we can display the commands
            {
                CmdBox.AppendText("\n" +//Append text to the command richtextbox
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
                    "Some Commands may not work");
                CmdTextBox.Clear();//clear the command textbox
            }
            else if (CmdTextBox.Text.ToLower() == "credits")//check if the user send credits so we can display the credits
            {
                CmdBox.AppendText("\n" +//Append text to the command richtextbox
                    "Credits;\n" +
                    "rakion99\n" +
                    "Roblox\n" +
                    "Eternal for RetCheck\n" +
                    "AutisticBobby\n" +
                    "Josh and their slaves Gems and Cosmology");
                CmdTextBox.Clear();//clear the command textbox
            }
            else
            {
                CommandPipe(CmdTextBox.Text);//command pipe function to send the text in the command textbox
                CmdTextBox.Clear();//clear the command textbox
            }
        }
        //command richtextbox textchanged event
        private void CmdBox_TextChanged(object sender, EventArgs e)
        {
            CmdBox.SelectionStart = CmdBox.Text.Length;//this get all the text
            CmdBox.ScrollToCaret();//so with this we can scroll to the bottom
        }
        //command textbox keydown event
        private void CmdTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)//if user pressed Key Enter
            {
                Send_Click(sender, e);//execute Send_click function
            }
        }
        //open button click event
        private void Open_Click(object sender, EventArgs e)
        {
            OpenFileDialog filedialog = new OpenFileDialog
            {
                Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*",//add txt and all files filter
                FilterIndex = 1,//choose what filter will be the default
                RestoreDirectory = true//restore the last used directory
            };//Initialize OpenFileDialog

            if (filedialog.ShowDialog() == DialogResult.OK)//check if the user clicked Ok/open
            {
                try
                {
                    LuaCBox.Text = File.ReadAllText(filedialog.FileName);//load all the text in the lua c rightextbox

                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not read file from disk. Original error: " + ex.Message);//display if got error
                }
            }
        }
        //inject button click event
        private void Inject_Click(object sender, EventArgs e)
        {
            if (NamedPipeExist(scriptpipe))//check if the pipe exist
            {
                MessageBox.Show("Already injected!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);//if the pipe exist that's mean that we don't need to inject
                return;
            }
            else if (!NamedPipeExist(scriptpipe))//check if the pipe don't exist
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
                Thread.Sleep(2000);//pause the ui for 2 seconds
                if (NamedPipeExist(scriptpipe))//check if the pipe exist
                {
                    MessageBox.Show("Injected!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);//display that the pipe was found so the injection was successful
                }
                else
                {
                    MessageBox.Show("Injection Failed!\nMaybe you are Missing something\nor took more time to check if was ready", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);//display that the pipe was not found so the injection was unsuccessful
                }
            }
        }

        private void Btools_Click(object sender, EventArgs e)
        {
            CommandPipe("btools me");
        }

        private void FF_Click(object sender, EventArgs e)
        {
            CommandPipe("ff me");
        }

        private void Ws_Click(object sender, EventArgs e)
        {
            CommandPipe("ws me " + WalkSpeedValue.Value);
        }

        private void Suicide_Click(object sender, EventArgs e)
        {
            CommandPipe("kill me");
        }

        private void Sit_Click(object sender, EventArgs e)
        {
            CommandPipe("sit me");
        }

        private void JP_Click(object sender, EventArgs e)
        {
            CommandPipe("jp me " + JumpPowerValue.Value);
        }

        private void TopCheck_CheckedChanged(object sender, EventArgs e)
        {
            if (TopCheck.Checked)
            {
                TopMost = true;
            }
            else
            {
                TopMost = false;
            }
        }

        private int thm;

        public void UpdateColorControls(Control theui)
        {
            Color Black = Color.FromName("Black");
            Color White = Color.FromName("White");
            
            switch (thm)
            {
                case 1:
                    theui.BackColor = Black;
                    theui.ForeColor = White;
                    this.BackColor = Black;
                    this.Text = "Ice Source UI Dark Theme";
                    break;
                case 0:
                    theui.BackColor = White;
                    theui.ForeColor = Black;
                    this.BackColor = White;
                    this.Text = "Ice Source UI Light Theme";
                    break;
            }

            foreach (Control subC in theui.Controls)
            {
                UpdateColorControls(subC);
            }
        }

        private void Theme_Click(object sender, EventArgs e)
        {
            foreach (Control c in this.Controls)
            {
                UpdateColorControls(c);
            }
            thm++;
            if (thm > 1) thm = 0;
        }
    }
}
