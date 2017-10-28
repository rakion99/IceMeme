using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MaterialSkin;
using MaterialSkin.Controls;
using System.Runtime.InteropServices;
using System.IO;
using System.IO.Pipes;
using System.Diagnostics;

namespace ICERoblox_UI
{
    public partial class Form1 : MaterialForm
    {
        public Form1()
        {
            InitializeComponent();
            this.KeyPreview = true;
            var materialSkinManager = MaterialSkinManager.Instance;
            materialSkinManager.AddFormToManage(this);
            materialSkinManager.Theme = MaterialSkinManager.Themes.DARK;
            materialSkinManager.ColorScheme = new ColorScheme(Primary.LightBlue400, Primary.LightBlue500, Primary.LightBlue500, Accent.LightBlue100, TextShade.WHITE);

        }

        [DllImport("kernel32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        private static extern bool WaitNamedPipe(string name, int timeout);

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




        private void ICELUACPIPE(string script)
        {
            if (NamedPipeExist("IceLuaC"))
            {
                try
                {
                    using (NamedPipeClientStream namedPipeClientStream = new NamedPipeClientStream(".", "FoxLUAC", PipeDirection.Out))
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
                MessageBox.Show("Attach ICE!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }
        }

     

        private void ICECOMMANDPIPE(string script)
        {
            if (NamedPipeExist("IceCmd"))
            {
                try
                {
                    using (NamedPipeClientStream namedPipeClientStream = new NamedPipeClientStream(".", "FoxCMD", PipeDirection.Out))
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
                MessageBox.Show("Attach ICE!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }
        }

        [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        public static extern IntPtr SendMessage(IntPtr hWnd, int msg, IntPtr wParam, IntPtr lParam);

        private const int WM_SETTEXT = 0x000C;
        [DllImport("user32.dll")]
        private static extern IntPtr FindWindow(
            string lpClassName,
            string lpWindowName);

        [DllImport("User32.dll")]
        private static extern IntPtr FindWindowEx(
            IntPtr hwndParent,
            IntPtr hwndChildAfter,
            string lpszClass,
        string lpszWindows);
        [DllImport("User32.dll")]
        private static extern Int32 SendMessage(
            IntPtr hWnd,
            int Msg,
            IntPtr wParam,
        StringBuilder lParam);
        [DllImport("user32.dll")]
        static extern bool HideCaret(IntPtr hWnd);


        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        [return: MarshalAs(UnmanagedType.Bool)]
        private static extern bool SetForegroundWindow(IntPtr hWnd);

        [DllImport("kernel32")]
        public static extern IntPtr CreateRemoteThread(
     IntPtr hProcess,
     IntPtr lpThreadAttributes,
     uint dwStackSize,
     UIntPtr lpStartAddress,
     IntPtr lpParameter,
     uint dwCreationFlags,
     out IntPtr lpThreadId
   );

        [DllImport("kernel32.dll")]
        public static extern IntPtr OpenProcess(
            UInt32 dwDesiredAccess,
            Int32 bInheritHandle,
            Int32 dwProcessId
            );

        [DllImport("kernel32.dll")]
        public static extern Int32 CloseHandle(
        IntPtr hObject
        );

        [DllImport("kernel32.dll", SetLastError = true, ExactSpelling = true)]
        static extern bool VirtualFreeEx(
            IntPtr hProcess,
            IntPtr lpAddress,
            UIntPtr dwSize,
            uint dwFreeType
            );

        [DllImport("kernel32.dll", CharSet = CharSet.Ansi, ExactSpelling = true)]
        public static extern UIntPtr GetProcAddress(
            IntPtr hModule,
            string procName
            );

        [DllImport("kernel32.dll", SetLastError = true, ExactSpelling = true)]
        static extern IntPtr VirtualAllocEx(
            IntPtr hProcess,
            IntPtr lpAddress,
            uint dwSize,
            uint flAllocationType,
            uint flProtect
            );

        [DllImport("kernel32.dll")]
        static extern bool WriteProcessMemory(
            IntPtr hProcess,
            IntPtr lpBaseAddress,
            string lpBuffer,
            UIntPtr nSize,
            out IntPtr lpNumberOfBytesWritten
        );

        [DllImport("kernel32.dll", CharSet = CharSet.Auto)]
        public static extern IntPtr GetModuleHandle(
            string lpModuleName
            );

        [DllImport("kernel32", SetLastError = true, ExactSpelling = true)]
        internal static extern Int32 WaitForSingleObject(
            IntPtr handle,
            Int32 milliseconds
            );

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern bool ReadProcessMemory(
            IntPtr hProcess,
            IntPtr lpBaseAddress,
            [Out] byte[] lpBuffer,
            int dwSize,
            out int lpNumberOfBytesRead);

        public Int32 GetProcessId(String proc)
        {
            Process[] ProcList;
            ProcList = Process.GetProcessesByName(proc);
            return ProcList[0].Id;
        }

        public void InjectDLL(IntPtr hProcess, String strDLLName)
        {
            IntPtr bytesout;

            Int32 LenWrite = strDLLName.Length + 1;
            IntPtr AllocMem = (IntPtr)VirtualAllocEx(hProcess, (IntPtr)null, (uint)LenWrite, 0x1000, 0x40);

            WriteProcessMemory(hProcess, AllocMem, strDLLName, (UIntPtr)LenWrite, out bytesout);
            UIntPtr Injector = (UIntPtr)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

            if (Injector == null)
            {
                MessageBox.Show(" Injector Error! \n ");
                return;
            }

            IntPtr hThread = (IntPtr)CreateRemoteThread(hProcess, (IntPtr)null, 0, Injector, AllocMem, 0, out bytesout);
            if (hThread == null)
            {
                MessageBox.Show(" hThread [ 1 ] Error! \n ");
                return;
            }
            int Result = WaitForSingleObject(hThread, 10 * 1000);
            if (Result == 0x00000080L || Result == 0x00000102L || Result == 0xFFFFFFFF)
            {
                if (hThread != null)
                {
                    CloseHandle(hThread);
                }
                return;
            }
            VirtualFreeEx(hProcess, AllocMem, (UIntPtr)0, 0x8000);
            if (hThread != null)
            {
                CloseHandle(hThread);
            }
            return;
        }

        string[] COMMANDS = new string[]
       {
            "\nff - give [p] forcefield",
            "\nfire - give [p] fire",
            "\njp" //You have to put your commands
       };

        void cmds()
        {
            foreach (string cmd in COMMANDS)
            {
                Console.Text = Console.Text + cmd;
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Console.Text = "";
            ICECOLOR("Welcome to ICE", Color.CornflowerBlue, false);
            ICECOLOR("Type 'cmds' for a list of commands", Color.CornflowerBlue, true);
            ICECOLOR("Type 'cmds' for a list of commands", Color.CornflowerBlue, true);
            ICECOLOR("Type 'clr' to clear the console", Color.CornflowerBlue, true);
        }

        private void ICECOLOR(string text, Color color, bool newline)
        {
            Console.SelectionColor = color;
            if (newline == true)
                Console.SelectedText = Environment.NewLine + text;
            else Console.SelectedText = text;
            Console.ScrollToCaret();
        }

        private void materialSingleLineTextField1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (CommandLine.Text == "cmds")
                {
                    cmds();
                }

                else if (CommandLine.Text == "clr")
                {
                    Console.Text = "";
                    ICECOLOR("Welcome to ICE", Color.CornflowerBlue, false);
                    ICECOLOR("Type 'cmds' for a list of commands", Color.CornflowerBlue, true);
                    ICECOLOR("Type 'cmds' for a list of commands", Color.CornflowerBlue, true);
                    ICECOLOR("Type 'clr' to clear the console", Color.CornflowerBlue, true);
                }

                else 
                {
                    ICECOMMANDPIPE(CommandLine.Text);
                    ICECOLOR("Command Executed : " + CommandLine.Text, Color.CornflowerBlue, true);
                }
            }
        }

        private void Execute_Click(object sender, EventArgs e)
        {
            if (NamedPipeExist("IceLuaC"))
            {
                string[] array = SCRIPTBOX.Text.Split("\r\n".ToCharArray());
                for (int i = 0; i < array.Length; i++)
                {
                    string script = array[i];
                    try
                    {
                        ICELUACPIPE(script);
                        ICECOLOR("Script Executed :", Color.CornflowerBlue, true);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message.ToString());
                    }
                }
            }
        }

        private void CommandLine_Enter(object sender, EventArgs e)
        {
            CommandLine.Text = "";
        }

        private void CommandLine_Leave(object sender, EventArgs e)
        {
            CommandLine.Text = "Enter Command Here...";
        }

        private void Inject_Click(object sender, EventArgs e)
        {
            Process[] Roblox = Process.GetProcessesByName("RobloxPlayerBeta");

            if (Roblox.Length == 0)
            {
                MessageBox.Show("Roblox is not running", "Attachment", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                String paths = AppDomain.CurrentDomain.BaseDirectory + "IceSource.dll";
                paths += "resources\\IceSource.dll";
                String strDLLName = AppDomain.CurrentDomain.BaseDirectory + "IceSource.dll";
                String strProcessName = "RobloxPlayerBeta";


                Int32 ProcID = GetProcessId(strProcessName);
                if (ProcID >= 0)
                {
                    IntPtr hProcess = (IntPtr)OpenProcess(0x1F0FFF, 1, ProcID);
                    if (hProcess == null)
                    {
                        MessageBox.Show("Injection Failed!");
                        return;
                    }

                    else
                    {
                        InjectDLL(hProcess, strDLLName);
                    }

                }

            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true)
            {
                TopMost = true;
            }

            else
            {
                TopMost = false;
            }
        }

        private void Browse_Click(object sender, EventArgs e)
        {
            ICE.ShowDialog();
        }

        private void Clear_Click(object sender, EventArgs e)
        {
            SCRIPTBOX.Text = "";
        }

        private void ICE_FileOk(object sender, CancelEventArgs e)
        {
            string script = File.ReadAllText(ICE.FileName);

            SCRIPTBOX.Text = script;
        }
    }
}


