namespace IceSourceUI
{
    partial class IceSourceForm
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
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.LuaC = new System.Windows.Forms.TabPage();
            this.Open = new System.Windows.Forms.Button();
            this.Clear = new System.Windows.Forms.Button();
            this.Execute = new System.Windows.Forms.Button();
            this.LuaCBox = new System.Windows.Forms.RichTextBox();
            this.CMDS = new System.Windows.Forms.TabPage();
            this.CmdBox = new System.Windows.Forms.RichTextBox();
            this.Send = new System.Windows.Forms.Button();
            this.CmdTextBox = new System.Windows.Forms.TextBox();
            this.Inject = new System.Windows.Forms.Button();
            this.tabControl1.SuspendLayout();
            this.LuaC.SuspendLayout();
            this.CMDS.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.CMDS);
            this.tabControl1.Controls.Add(this.LuaC);
            this.tabControl1.Location = new System.Drawing.Point(12, 12);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(260, 237);
            this.tabControl1.TabIndex = 0;
            // 
            // LuaC
            // 
            this.LuaC.BackColor = System.Drawing.SystemColors.MenuText;
            this.LuaC.Controls.Add(this.Open);
            this.LuaC.Controls.Add(this.Clear);
            this.LuaC.Controls.Add(this.Execute);
            this.LuaC.Controls.Add(this.LuaCBox);
            this.LuaC.ForeColor = System.Drawing.SystemColors.Window;
            this.LuaC.Location = new System.Drawing.Point(4, 22);
            this.LuaC.Name = "LuaC";
            this.LuaC.Padding = new System.Windows.Forms.Padding(3);
            this.LuaC.Size = new System.Drawing.Size(252, 211);
            this.LuaC.TabIndex = 0;
            this.LuaC.Text = "Lua C";
            // 
            // Open
            // 
            this.Open.BackColor = System.Drawing.SystemColors.MenuText;
            this.Open.ForeColor = System.Drawing.SystemColors.Window;
            this.Open.Location = new System.Drawing.Point(11, 169);
            this.Open.Name = "Open";
            this.Open.Size = new System.Drawing.Size(56, 36);
            this.Open.TabIndex = 3;
            this.Open.Text = "Open";
            this.Open.UseVisualStyleBackColor = false;
            this.Open.Click += new System.EventHandler(this.Open_Click);
            // 
            // Clear
            // 
            this.Clear.BackColor = System.Drawing.SystemColors.MenuText;
            this.Clear.ForeColor = System.Drawing.SystemColors.Window;
            this.Clear.Location = new System.Drawing.Point(165, 169);
            this.Clear.Name = "Clear";
            this.Clear.Size = new System.Drawing.Size(81, 36);
            this.Clear.TabIndex = 2;
            this.Clear.Text = "Clear";
            this.Clear.UseVisualStyleBackColor = false;
            this.Clear.Click += new System.EventHandler(this.Clear_Click);
            // 
            // Execute
            // 
            this.Execute.BackColor = System.Drawing.SystemColors.MenuText;
            this.Execute.ForeColor = System.Drawing.SystemColors.Window;
            this.Execute.Location = new System.Drawing.Point(84, 169);
            this.Execute.Name = "Execute";
            this.Execute.Size = new System.Drawing.Size(64, 36);
            this.Execute.TabIndex = 1;
            this.Execute.Text = "Execute";
            this.Execute.UseVisualStyleBackColor = false;
            this.Execute.Click += new System.EventHandler(this.Execute_Click);
            // 
            // LuaCBox
            // 
            this.LuaCBox.BackColor = System.Drawing.SystemColors.MenuText;
            this.LuaCBox.ForeColor = System.Drawing.SystemColors.Window;
            this.LuaCBox.Location = new System.Drawing.Point(6, 6);
            this.LuaCBox.Name = "LuaCBox";
            this.LuaCBox.Size = new System.Drawing.Size(240, 157);
            this.LuaCBox.TabIndex = 0;
            this.LuaCBox.Text = "";
            // 
            // CMDS
            // 
            this.CMDS.BackColor = System.Drawing.SystemColors.MenuText;
            this.CMDS.Controls.Add(this.CmdBox);
            this.CMDS.Controls.Add(this.Send);
            this.CMDS.Controls.Add(this.CmdTextBox);
            this.CMDS.Location = new System.Drawing.Point(4, 22);
            this.CMDS.Name = "CMDS";
            this.CMDS.Padding = new System.Windows.Forms.Padding(3);
            this.CMDS.Size = new System.Drawing.Size(252, 211);
            this.CMDS.TabIndex = 1;
            this.CMDS.Text = "CMDS";
            // 
            // CmdBox
            // 
            this.CmdBox.BackColor = System.Drawing.SystemColors.MenuText;
            this.CmdBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CmdBox.ForeColor = System.Drawing.SystemColors.Window;
            this.CmdBox.Location = new System.Drawing.Point(6, 6);
            this.CmdBox.Name = "CmdBox";
            this.CmdBox.ReadOnly = true;
            this.CmdBox.Size = new System.Drawing.Size(240, 156);
            this.CmdBox.TabIndex = 2;
            this.CmdBox.Text = "Welcome to Ice\nType cmds to see the commands\ncredits to see the credits\n[p] = pla" +
    "yer, [#] = number";
            this.CmdBox.TextChanged += new System.EventHandler(this.CmdBox_TextChanged);
            // 
            // Send
            // 
            this.Send.BackColor = System.Drawing.SystemColors.MenuText;
            this.Send.ForeColor = System.Drawing.SystemColors.Window;
            this.Send.Location = new System.Drawing.Point(171, 174);
            this.Send.Name = "Send";
            this.Send.Size = new System.Drawing.Size(75, 29);
            this.Send.TabIndex = 1;
            this.Send.Text = "Send";
            this.Send.UseVisualStyleBackColor = false;
            this.Send.Click += new System.EventHandler(this.Send_Click);
            // 
            // CmdTextBox
            // 
            this.CmdTextBox.BackColor = System.Drawing.SystemColors.MenuText;
            this.CmdTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CmdTextBox.ForeColor = System.Drawing.SystemColors.Window;
            this.CmdTextBox.Location = new System.Drawing.Point(6, 174);
            this.CmdTextBox.Name = "CmdTextBox";
            this.CmdTextBox.Size = new System.Drawing.Size(159, 29);
            this.CmdTextBox.TabIndex = 0;
            this.CmdTextBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.CmdTextBox_KeyDown);
            // 
            // Inject
            // 
            this.Inject.BackColor = System.Drawing.SystemColors.MenuText;
            this.Inject.ForeColor = System.Drawing.SystemColors.Window;
            this.Inject.Location = new System.Drawing.Point(100, 251);
            this.Inject.Name = "Inject";
            this.Inject.Size = new System.Drawing.Size(75, 23);
            this.Inject.TabIndex = 1;
            this.Inject.Text = "Inject";
            this.Inject.UseVisualStyleBackColor = false;
            this.Inject.Click += new System.EventHandler(this.Inject_Click);
            // 
            // IceSourceForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.MenuText;
            this.ClientSize = new System.Drawing.Size(284, 280);
            this.Controls.Add(this.Inject);
            this.Controls.Add(this.tabControl1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.MaximizeBox = false;
            this.Name = "IceSourceForm";
            this.ShowIcon = false;
            this.Text = "Ice Source UI";
            this.tabControl1.ResumeLayout(false);
            this.LuaC.ResumeLayout(false);
            this.CMDS.ResumeLayout(false);
            this.CMDS.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage LuaC;
        private System.Windows.Forms.TabPage CMDS;
        private System.Windows.Forms.Button Clear;
        private System.Windows.Forms.Button Execute;
        private System.Windows.Forms.RichTextBox LuaCBox;
        private System.Windows.Forms.RichTextBox CmdBox;
        private System.Windows.Forms.Button Send;
        private System.Windows.Forms.TextBox CmdTextBox;
        private System.Windows.Forms.Button Open;
        private System.Windows.Forms.Button Inject;
    }
}

