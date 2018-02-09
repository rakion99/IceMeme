using System;
using System.IO;
using System.Net;
using System.Windows.Forms;

namespace IceMemeUI
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            VersionCheck();
            Checks();
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new IceMemeForm());
        }

        private static void Checks()
        {
            try
            {
                if (!Directory.Exists("./LuaScripts"))
                {
                    Directory.CreateDirectory("LuaScripts");
                }
                if (!Directory.Exists("./LuaCScripts"))
                {
                    Directory.CreateDirectory("LuaCScripts");
                }
                if (!File.Exists("./IceMeme.dll"))
                {
                    MessageBox.Show("IceMeme.dll not found", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    Environment.Exit(0);
                }
                if (!File.Exists("./FastColoredTextBox.dll"))
                {
                    MessageBox.Show("FastColoredTextBox.dll not found", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    Environment.Exit(0);
                }
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message.ToString());
            }
        }

        private static void VersionCheck()
        {
            try
            {
                using (WebClient client = new WebClient())
                {
                    string WebVersion = client.DownloadString("https://rakion99.github.io/IceMeme/Version.txt");
                    string CurrentVerion = Application.ProductVersion;
                    string UpdateFound = string.Format("An update is available\nYour Current version is: {0}\nNew Version is: {1}\n\nDo you want to update?", CurrentVerion, WebVersion);
                    if (WebVersion != CurrentVerion)
                    {
                        DialogResult UpdaterChecker = MessageBox.Show(UpdateFound, "New Update Found", MessageBoxButtons.YesNo, MessageBoxIcon.Warning, MessageBoxDefaultButton.Button1);
                        if (UpdaterChecker == DialogResult.Yes)
                        {
                            System.Diagnostics.Process.Start("https://github.com/rakion99/IceMeme");
                            Environment.Exit(0);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString(), "Exception");
            }
        }
    }
}
