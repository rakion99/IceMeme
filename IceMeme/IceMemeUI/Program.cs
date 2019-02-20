using System;
using System.IO;
using System.Net;
using System.Security.Cryptography;
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
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Checks();
            VersionCheck();
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
                if (!File.Exists("./" + Functions.exploitdll))
                {
                    MessageBox.Show(Functions.exploitdll + " not found", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
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
                Environment.Exit(0);
            }
        }

        private static void VersionCheck()
        {
            try
            {
                if (Properties.Settings.Default.CheckUpdates)
                {
                    using (WebClient client = new WebClient())
                    {
                        string UIWebVersion = client.DownloadString("https://rakion99.github.io/IceMeme/Version.txt");
                        string UICurrentVerion = Application.ProductVersion;
                        if (UIWebVersion != UICurrentVerion)
                        {
                            string UIUpdateFound = string.Format("An update is available\nYour Current version is: {0}\nNew Version is: {1}\n\nDo you want to update?", UICurrentVerion, UIWebVersion);
                            DialogResult UIUpdaterChecker = MessageBox.Show(UIUpdateFound, "New Update Found", MessageBoxButtons.YesNo, MessageBoxIcon.Warning, MessageBoxDefaultButton.Button1);
                            if (UIUpdaterChecker == DialogResult.Yes)
                            {
                                Functions.UpdateUI = true;
                                new UpdaterForm().ShowDialog();
                            }
                        }
                        string DLLCurrentHASH = Getsha256("./" + Functions.exploitdll);
                        string DLLWebHASH = client.DownloadString("https://rakion99.github.io/IceMeme/DLLHash.txt");
                        if (DLLWebHASH != DLLCurrentHASH)
                        {
                            DialogResult DLLUpdaterChecker = MessageBox.Show("An update for the dll is available\n\nDo you want to update?", "New Update Found", MessageBoxButtons.YesNo, MessageBoxIcon.Warning, MessageBoxDefaultButton.Button1);
                            if (DLLUpdaterChecker == DialogResult.Yes)
                            {
                                Functions.UpdateDLL = true;
                                new UpdaterForm().ShowDialog();
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString(), "Exception", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            Application.Run(new IceMemeForm());
        }

        private static string Getsha256(string filepath)
        {
            FileStream filestream;
            filestream = new FileStream(filepath, FileMode.Open)
            {
                Position = 0
            };

            return BitConverter.ToString(SHA256.Create().ComputeHash(filestream)).Replace("-", string.Empty);
        }
    }
}
