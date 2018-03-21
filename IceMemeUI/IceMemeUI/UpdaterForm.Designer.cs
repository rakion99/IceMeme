namespace IceMemeUI
{
    partial class UpdaterForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(UpdaterForm));
            this.DownloadingBar = new System.Windows.Forms.ProgressBar();
            this.DownloadingLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // DownloadingBar
            // 
            this.DownloadingBar.Location = new System.Drawing.Point(22, 103);
            this.DownloadingBar.Name = "DownloadingBar";
            this.DownloadingBar.Size = new System.Drawing.Size(315, 23);
            this.DownloadingBar.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.DownloadingBar.TabIndex = 0;
            // 
            // DownloadingLabel
            // 
            this.DownloadingLabel.AutoSize = true;
            this.DownloadingLabel.Font = new System.Drawing.Font("Jing Jing", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DownloadingLabel.Location = new System.Drawing.Point(16, 39);
            this.DownloadingLabel.Name = "DownloadingLabel";
            this.DownloadingLabel.Size = new System.Drawing.Size(232, 32);
            this.DownloadingLabel.TabIndex = 1;
            this.DownloadingLabel.Text = "Downloading:";
            // 
            // UpdaterForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(355, 143);
            this.Controls.Add(this.DownloadingLabel);
            this.Controls.Add(this.DownloadingBar);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "UpdaterForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "IceMemeUI Updater";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ProgressBar DownloadingBar;
        private System.Windows.Forms.Label DownloadingLabel;
    }
}