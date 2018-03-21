using System;
using System.Diagnostics;
using System.IO;
using System.Net;
using System.Threading;
using System.Windows.Forms;

namespace IceMemeUI
{
    public partial class UpdaterForm : Form
    {
        public UpdaterForm()
        {
            InitializeComponent();
            DownloadStuff();
        }

        private async void DownloadStuff()
        {
            try
            {
                if (Functions.UpdateUI)
                {
                    using (WebClient WebC = new WebClient())
                    {
                        DownloadingLabel.Text = "Downloading: UI";
                        Directory.CreateDirectory("tmp");
                        WebC.DownloadProgressChanged += WebC_DownloadProgressChanged;
                        WebC.DownloadDataCompleted += new DownloadDataCompletedEventHandler(WebC_DownloadUICompleted);
                        string ExeDownloadLocation = WebC.DownloadString("https://rakion99.github.io/IceMeme/IceMemeUI.txt");
                        var data = await WebC.DownloadDataTaskAsync(new Uri(ExeDownloadLocation));
                        File.WriteAllBytes(@".\tmp\IceMemeUI.exe", data);
                    }
                }
                else if (Functions.UpdateDLL)
                {
                    using (WebClient WebC2 = new WebClient())
                    {
                        DownloadingLabel.Text = "Downloading: DLL";
                        Directory.CreateDirectory("tmp");
                        WebC2.DownloadProgressChanged += WebC_DownloadProgressChanged;
                        WebC2.DownloadDataCompleted += new DownloadDataCompletedEventHandler(WebC_DownloadDLLCompleted);
                        string DllDownloadLocation = WebC2.DownloadString("https://rakion99.github.io/IceMeme/IceMemeDLL.txt");
                        var data = await WebC2.DownloadDataTaskAsync(new Uri(DllDownloadLocation));
                        File.WriteAllBytes(@".\tmp\" + Functions.exploitdll, data);
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString(), "Exception", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Close();
            }
        }

        private void WebC_DownloadProgressChanged(object sender, DownloadProgressChangedEventArgs e) => DownloadingBar.Value = e.ProgressPercentage;

        private void WebC_DownloadUICompleted(object sender, DownloadDataCompletedEventArgs e)
        {
            if (!e.Cancelled && e.Error == null)
            {

                MessageBox.Show("Download Completed\nIceMemeUI Updater Will now Close and Open IceMemeUI", "Download Completed", MessageBoxButtons.OK, MessageBoxIcon.Information);
                new Thread(() =>
                {
                    Process.Start("cmd.exe",
                    "/C Del " + Application.ExecutablePath + @"& MOVE /Y .\tmp\IceMemeUI.exe .\ & rmdir .\tmp & start IceMemeUI.exe");
                    Environment.Exit(0);
                }).Start();
            }
        }

        private void WebC_DownloadDLLCompleted(object sender, DownloadDataCompletedEventArgs e)
        {
            if (!e.Cancelled && e.Error == null)
            {

                MessageBox.Show("Download Completed\nIceMemeUI Updater Will now Close and Open IceMemeUI", "Download Completed", MessageBoxButtons.OK, MessageBoxIcon.Information);
                new Thread(() =>
                {
                    Process.Start("cmd.exe",
                            @"/C MOVE /Y .\tmp\" + Functions.exploitdll + @" .\ & rmdir .\tmp");
                    Close(); 
                }).Start();
            }
        }
    }
}
