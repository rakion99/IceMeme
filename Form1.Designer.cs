namespace ICERoblox_UI
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.materialTabSelector1 = new MaterialSkin.Controls.MaterialTabSelector();
            this.materialTabControl1 = new MaterialSkin.Controls.MaterialTabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.Console = new System.Windows.Forms.RichTextBox();
            this.CommandLine = new MaterialSkin.Controls.MaterialSingleLineTextField();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.Clear = new MaterialSkin.Controls.MaterialRaisedButton();
            this.Browse = new MaterialSkin.Controls.MaterialRaisedButton();
            this.Execute = new MaterialSkin.Controls.MaterialRaisedButton();
            this.SCRIPTBOX = new System.Windows.Forms.RichTextBox();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.Inject = new MaterialSkin.Controls.MaterialRaisedButton();
            this.label1 = new System.Windows.Forms.Label();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.ICE = new System.Windows.Forms.OpenFileDialog();
            this.materialTabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.tabPage4.SuspendLayout();
            this.SuspendLayout();
            // 
            // materialTabSelector1
            // 
            this.materialTabSelector1.BaseTabControl = this.materialTabControl1;
            this.materialTabSelector1.Depth = 0;
            this.materialTabSelector1.Location = new System.Drawing.Point(0, 67);
            this.materialTabSelector1.MouseState = MaterialSkin.MouseState.HOVER;
            this.materialTabSelector1.Name = "materialTabSelector1";
            this.materialTabSelector1.Size = new System.Drawing.Size(507, 23);
            this.materialTabSelector1.TabIndex = 0;
            this.materialTabSelector1.Text = "materialTabSelector1";
            // 
            // materialTabControl1
            // 
            this.materialTabControl1.Controls.Add(this.tabPage1);
            this.materialTabControl1.Controls.Add(this.tabPage2);
            this.materialTabControl1.Controls.Add(this.tabPage3);
            this.materialTabControl1.Controls.Add(this.tabPage4);
            this.materialTabControl1.Depth = 0;
            this.materialTabControl1.Location = new System.Drawing.Point(0, 98);
            this.materialTabControl1.MouseState = MaterialSkin.MouseState.HOVER;
            this.materialTabControl1.Name = "materialTabControl1";
            this.materialTabControl1.SelectedIndex = 0;
            this.materialTabControl1.Size = new System.Drawing.Size(521, 233);
            this.materialTabControl1.TabIndex = 3;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.White;
            this.tabPage1.Controls.Add(this.Console);
            this.tabPage1.Controls.Add(this.CommandLine);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(513, 207);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "CONSOLE";
            // 
            // Console
            // 
            this.Console.BackColor = System.Drawing.Color.White;
            this.Console.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.Console.Font = new System.Drawing.Font("Consolas", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Console.Location = new System.Drawing.Point(8, 6);
            this.Console.Name = "Console";
            this.Console.ReadOnly = true;
            this.Console.Size = new System.Drawing.Size(482, 162);
            this.Console.TabIndex = 2;
            this.Console.Text = "Welcome to ICE\n";
            // 
            // CommandLine
            // 
            this.CommandLine.Depth = 0;
            this.CommandLine.Hint = "";
            this.CommandLine.Location = new System.Drawing.Point(8, 174);
            this.CommandLine.MouseState = MaterialSkin.MouseState.HOVER;
            this.CommandLine.Name = "CommandLine";
            this.CommandLine.PasswordChar = '\0';
            this.CommandLine.SelectedText = "";
            this.CommandLine.SelectionLength = 0;
            this.CommandLine.SelectionStart = 0;
            this.CommandLine.Size = new System.Drawing.Size(482, 23);
            this.CommandLine.TabIndex = 1;
            this.CommandLine.Text = "Enter Command Here...";
            this.CommandLine.UseSystemPasswordChar = false;
            this.CommandLine.Enter += new System.EventHandler(this.CommandLine_Enter);
            this.CommandLine.KeyDown += new System.Windows.Forms.KeyEventHandler(this.materialSingleLineTextField1_KeyDown);
            this.CommandLine.Leave += new System.EventHandler(this.CommandLine_Leave);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.Clear);
            this.tabPage2.Controls.Add(this.Browse);
            this.tabPage2.Controls.Add(this.Execute);
            this.tabPage2.Controls.Add(this.SCRIPTBOX);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(513, 207);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "LUA C";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // Clear
            // 
            this.Clear.Depth = 0;
            this.Clear.Location = new System.Drawing.Point(349, 173);
            this.Clear.MouseState = MaterialSkin.MouseState.HOVER;
            this.Clear.Name = "Clear";
            this.Clear.Primary = true;
            this.Clear.Size = new System.Drawing.Size(141, 23);
            this.Clear.TabIndex = 3;
            this.Clear.Text = "Clear";
            this.Clear.UseVisualStyleBackColor = true;
            this.Clear.Click += new System.EventHandler(this.Clear_Click);
            // 
            // Browse
            // 
            this.Browse.Depth = 0;
            this.Browse.Location = new System.Drawing.Point(189, 173);
            this.Browse.MouseState = MaterialSkin.MouseState.HOVER;
            this.Browse.Name = "Browse";
            this.Browse.Primary = true;
            this.Browse.Size = new System.Drawing.Size(154, 23);
            this.Browse.TabIndex = 2;
            this.Browse.Text = "Browse";
            this.Browse.UseVisualStyleBackColor = true;
            this.Browse.Click += new System.EventHandler(this.Browse_Click);
            // 
            // Execute
            // 
            this.Execute.Depth = 0;
            this.Execute.Location = new System.Drawing.Point(8, 173);
            this.Execute.MouseState = MaterialSkin.MouseState.HOVER;
            this.Execute.Name = "Execute";
            this.Execute.Primary = true;
            this.Execute.Size = new System.Drawing.Size(175, 23);
            this.Execute.TabIndex = 1;
            this.Execute.Text = "Execute";
            this.Execute.UseVisualStyleBackColor = true;
            this.Execute.Click += new System.EventHandler(this.Execute_Click);
            // 
            // SCRIPTBOX
            // 
            this.SCRIPTBOX.BackColor = System.Drawing.Color.White;
            this.SCRIPTBOX.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.SCRIPTBOX.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SCRIPTBOX.ForeColor = System.Drawing.Color.CornflowerBlue;
            this.SCRIPTBOX.Location = new System.Drawing.Point(8, 6);
            this.SCRIPTBOX.Name = "SCRIPTBOX";
            this.SCRIPTBOX.Size = new System.Drawing.Size(482, 153);
            this.SCRIPTBOX.TabIndex = 0;
            this.SCRIPTBOX.Text = "getglobal print\npushstring ICE\npcall 1 0 0\nemptystack";
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.Inject);
            this.tabPage3.Controls.Add(this.label1);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(513, 207);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "INJECT";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // Inject
            // 
            this.Inject.Depth = 0;
            this.Inject.Location = new System.Drawing.Point(21, 155);
            this.Inject.MouseState = MaterialSkin.MouseState.HOVER;
            this.Inject.Name = "Inject";
            this.Inject.Primary = true;
            this.Inject.Size = new System.Drawing.Size(448, 23);
            this.Inject.TabIndex = 1;
            this.Inject.Text = "Inject";
            this.Inject.UseVisualStyleBackColor = true;
            this.Inject.Click += new System.EventHandler(this.Inject_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Agency FB", 72F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.label1.Location = new System.Drawing.Point(174, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(146, 116);
            this.label1.TabIndex = 0;
            this.label1.Text = "ICE";
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add(this.label6);
            this.tabPage4.Controls.Add(this.label5);
            this.tabPage4.Controls.Add(this.label4);
            this.tabPage4.Controls.Add(this.label3);
            this.tabPage4.Controls.Add(this.label2);
            this.tabPage4.Location = new System.Drawing.Point(4, 22);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage4.Size = new System.Drawing.Size(513, 207);
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "ICE CREDITS";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Impact", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.label6.Location = new System.Drawing.Point(170, 150);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(98, 29);
            this.label6.TabIndex = 4;
            this.label6.Text = "Cptdarth";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Impact", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.label5.Location = new System.Drawing.Point(170, 118);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(106, 29);
            this.label5.TabIndex = 3;
            this.label5.Text = "Rakion99";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Impact", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.label4.Location = new System.Drawing.Point(170, 85);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(121, 29);
            this.label4.TabIndex = 2;
            this.label4.Text = "Cosmology";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Impact", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.label3.Location = new System.Drawing.Point(170, 53);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(145, 29);
            this.label3.TabIndex = 1;
            this.label3.Text = "Josh/Tetenus";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Impact", 20F);
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.label2.Location = new System.Drawing.Point(40, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(145, 34);
            this.label2.TabIndex = 0;
            this.label2.Text = "ICE Credits :";
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.BackColor = System.Drawing.Color.Transparent;
            this.checkBox1.ForeColor = System.Drawing.Color.SteelBlue;
            this.checkBox1.Location = new System.Drawing.Point(2, 3);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(68, 17);
            this.checkBox1.TabIndex = 4;
            this.checkBox1.Text = "TopMost";
            this.checkBox1.UseVisualStyleBackColor = false;
            this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // ICE
            // 
            this.ICE.FileName = "SKIDDED EXPLOIT";
            this.ICE.Filter = "|*.txt";
            this.ICE.FileOk += new System.ComponentModel.CancelEventHandler(this.ICE_FileOk);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(506, 323);
            this.Controls.Add(this.checkBox1);
            this.Controls.Add(this.materialTabControl1);
            this.Controls.Add(this.materialTabSelector1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "ICE || ROBLOX";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.materialTabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage2.ResumeLayout(false);
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.tabPage4.ResumeLayout(false);
            this.tabPage4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private MaterialSkin.Controls.MaterialTabSelector materialTabSelector1;
        private MaterialSkin.Controls.MaterialSingleLineTextField CommandLine;
        private System.Windows.Forms.RichTextBox Console;
        private MaterialSkin.Controls.MaterialTabControl materialTabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.TabPage tabPage4;
        private MaterialSkin.Controls.MaterialRaisedButton Clear;
        private MaterialSkin.Controls.MaterialRaisedButton Browse;
        private MaterialSkin.Controls.MaterialRaisedButton Execute;
        private System.Windows.Forms.RichTextBox SCRIPTBOX;
        private MaterialSkin.Controls.MaterialRaisedButton Inject;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.OpenFileDialog ICE;
    }
}

