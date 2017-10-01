using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.IO.Pipes;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IceSourceUI
{
    public partial class IceSourceForm : Form
    {
        public IceSourceForm()
        {
            InitializeComponent();
        }

        string exploitdll = "IceSource.dll";
        string cmdpipe = "IceCmd";
        string scriptpipe = "IceLuaC";

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

        private void Clear_Click(object sender, EventArgs e)
        {
            LuaCBox.Clear();
        }

        private void Execute_Click(object sender, EventArgs e)
        {
            if (NamedPipeExist(scriptpipe))
            {
                string[] array = LuaCBox.Text.Split("\r\n".ToCharArray());
                for (int i = 0; i < array.Length; i++)
                {
                    string script = array[i];
                    try
                    {
                        LuaCPipe(script);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message.ToString());
                    }
                }
            }
            else
            {
                MessageBox.Show("Inject " + exploitdll + " before Using this!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }
        }

        private void Send_Click(object sender, EventArgs e)
        {
            if (CmdTextBox.Text == "cmds")
            {
                CmdBox.AppendText("\n" +
                    "Commands:\n" +
                    "ff [p]\n" +
                    "ws [p] [#]\n" +
                    "jp [p] [#]\n" +
                    "sit [p]\n" +
                    "kill [p]\n" +
                    "and others");
                CmdTextBox.Clear();
            }
            else if (CmdTextBox.Text == "credits")
            {
                CmdBox.AppendText("\n" +
                    "Credits;\n" +
                    "rakion99\n" +
                    "Roblox\n" +
                    "Eternal for RetCheck\n" +
                    "AutisticBobby\n" +
                    "Josh and their slaves Gems and Cosmology");
                CmdTextBox.Clear();
            }
            else
            {
                CommandPipe(CmdTextBox.Text.ToLower());
                CmdTextBox.Clear();
            }
        }

        private void CmdBox_TextChanged(object sender, EventArgs e)
        {
            CmdBox.SelectionStart = CmdBox.Text.Length;
            CmdBox.ScrollToCaret();
        }

        private void CmdTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                Send_Click(sender, e);
            }
        }

        private void Open_Click(object sender, EventArgs e)
        {
            OpenFileDialog filedialog = new OpenFileDialog();

            filedialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            filedialog.FilterIndex = 1;
            filedialog.RestoreDirectory = true;

            if (filedialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    LuaCBox.Text = File.ReadAllText(filedialog.FileName);

                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not read file from disk. Original error: " + ex.Message);
                }
            }
        }

        private void Inject_Click(object sender, EventArgs e)
        {
            if (NamedPipeExist(scriptpipe))
            {
                MessageBox.Show("Already injected!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                return;
            }
            else if (!NamedPipeExist(scriptpipe))
            {
                switch (Injector.DllInjector.GetInstance.Inject("RobloxPlayerBeta", AppDomain.CurrentDomain.BaseDirectory + exploitdll))
                {
                    case Injector.DllInjectionResult.DllNotFound:
                        MessageBox.Show("Couldn't find " + exploitdll, "Dll was not found!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                        //break;
                    case Injector.DllInjectionResult.GameProcessNotFound:
                        MessageBox.Show("Couldn't find RobloxPlayerBeta.exe!", "Target process was not found!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    case Injector.DllInjectionResult.InjectionFailed:
                        MessageBox.Show("Injection Failed!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                }
                Thread.Sleep(2000);
                if (NamedPipeExist(scriptpipe))
                {
                    MessageBox.Show("Injected!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                }
                else
                {
                    MessageBox.Show("Injection Failed!\nMaybe you are Missing something\nor took more time to check if was ready", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }
    }
}
