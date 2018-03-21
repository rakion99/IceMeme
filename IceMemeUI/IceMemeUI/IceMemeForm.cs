using FastColoredTextBoxNS;
using System;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace IceMemeUI
{
    public partial class IceMemeForm : Form
    {
        public IceMemeForm()
        {
            InitializeComponent();
            TopMost = Properties.Settings.Default.TopMostSetting;//Get and Set TopMost Setting
            if (!Properties.Settings.Default.TopMostSetting)//If TopMost Setting is false uncheck the checkbox
                TopCheck.Checked = false;//Uncheck TopCheck
            if (!Properties.Settings.Default.CheckUpdates)//If CheckUpdates Setting is false uncheck the checkbox
                CheckUpdatesBox.Checked = false;//Uncheck CheckUpdatesBox
            Opacity = Properties.Settings.Default.OpacityValue / (double)10;//Get OpacityValue Setting and set Opacity Value
            if (Opacity == 0)//Check If Opacity value is 0
            {
                Opacity = 1;//Change Opacity to 1 so you can see again the Form
                Properties.Settings.Default.OpacityValue = OpacityBar.Value;//Set OpacityValue Setting value to OpacityBar Value
                Properties.Settings.Default.Save();//Save Settings
                MessageBox.Show("Opacity was 0 and has been reset to 1", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);//Tell the user that opacity has been reset
            }

            OpacityBar.Value = Properties.Settings.Default.OpacityValue;//Move OpacityBar to current value of OpacityValue setting
            if (Properties.Settings.Default.Theme)//if Theme setting is true change the theme to light
            {
                Theme_change();//call theme change
            }
            //Populate List boxes
            Functions.PopulateListBox(LuaScriptList, "./LuaScripts", "*.txt");//populate LuaScriptList with .txt files
            Functions.PopulateListBox(LuaScriptList, "./LuaScripts", "*.lua");//populate LuaScriptList with .lua files
            Functions.PopulateListBox(LuaCScriptList, "./LuaCScripts", "*.txt");//populate LuaCScriptList with .txt files
        }
        //clear button click event
        private void Clear_Click(object sender, EventArgs e) => LuaCBox.Clear();//this clear all the text in luac richtextbox
        //execute button click event
        private void Execute_Click(object sender, EventArgs e)
        {
            if (NamedPipes.NamedPipeExist(NamedPipes.luacpipename))//check if the pipe exist
            {
                NamedPipes.LuaCPipe(LuaCBox.Text);//lua c pipe function to send the script
            }
            else
            {
                MessageBox.Show("Inject " + Functions.exploitdll + " before Using this!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);//if the pipe can't be found a messagebox will appear
                return;
            }
        }
        //send button click event
        private void Send_Click(object sender, EventArgs e)
        {
            if (CmdTextBox.Text.ToLower() == "cmds")//check if the user send cmds so we can display the commands
            {
                CmdBox.AppendText(Functions.TextToBox[0]);//Append text to the command richtextbox
                CmdTextBox.Clear();//clear the command textbox
            }
            else if (CmdTextBox.Text.ToLower() == "credits")//check if the user send credits so we can display the credits
            {
                CmdBox.AppendText(Functions.TextToBox[1]);//Append text to the command richtextbox
                CmdTextBox.Clear();//clear the command textbox
            }
            else if (CmdTextBox.Text.ToLower() == "clear")//check if the user send clear so we can clear the CmdBox
            {
                CmdBox.Clear();//clear the CmdBox
                CmdTextBox.Clear();//Clear the command textbox
            }
            else
            {
                NamedPipes.CommandPipe(CmdTextBox.Text);//command pipe function to send the text in the command textbox
                CmdBox.AppendText("\n>" + CmdTextBox.Text);//add the used command to CmdBox
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
            if (Functions.openfiledialog.ShowDialog() == DialogResult.OK)//check if the user clicked Ok/open
            {
                try
                {
                    LuaCBox.Text = File.ReadAllText(Functions.openfiledialog.FileName);//load all the text in the lua c rightextbox

                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not read file from disk. Original error: " + ex.Message);//display if got error
                }
            }
        }
        public void Inject_Click(object sender, EventArgs e) => Functions.Inject();//Inject the dll to roblox

        private void Btools_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("btools me");//Send Command through CommandPipe

        private void FF_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("ff me");//Send Command through CommandPipe

        private void Ws_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("ws me " + WalkSpeedValue.Value);//Send Command through CommandPipe with the value of the WalkSpeedValue

        private void Suicide_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("kill me");//Send Command through CommandPipe

        private void Sit_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("sit me");//Send Command through CommandPipe

        private void JP_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("jp me " + JumpPowerValue.Value);//Send Command through CommandPipe with the value of the JumpPowerValue

        private void TopCheck_CheckedChanged(object sender, EventArgs e)
        {
            if (TopCheck.Checked)
            {
                TopMost = true;//Enable TopMost
                Properties.Settings.Default.TopMostSetting = true;//Set TopMostSetting to true
                Properties.Settings.Default.Save();//Save Settings
            }
            else
            {
                TopMost = false;//Disable TopMost
                Properties.Settings.Default.TopMostSetting = false;//Set TopMostSetting to false
                Properties.Settings.Default.Save();//Save Settings
            }
        }

        private int thm;//Create int variable

        public void UpdateColorControls(Control theui)
        {
            Color Black = Color.FromName("Black");//Store Color Black in variable for easy use
            Color White = Color.FromName("White");//Store Color White in variable for easy use
            
            switch (thm)
            {
                case 1:
                    theui.BackColor = Black;//Set BackColor to Black of current control
                    theui.ForeColor = White;//Set ForeColor to White of current control
                    BackColor = Black;//Set BackColor to Black for the current Form
                    Text = "IceMeme UI Dark Theme";//Set Title for the Current Form
                    break;
                case 0:
                    theui.BackColor = White;//Set BackColor to White of current control
                    theui.ForeColor = Black;//Set ForeColor to Black of current control
                    BackColor = White;//Set BackColor to White for the current Form
                    Text = "IceMeme UI Light Theme";//Set Title for the Current Form
                    break;
            }

            foreach (Control subC in theui.Controls)//Execute for every Control found
            {
                UpdateColorControls(subC);//Call UpdateColorControls with the current Control
            }
        }

        private void Theme_Click(object sender, EventArgs e)
        {
            foreach (Control c in Controls)//Execute for every Control found
            {
                UpdateColorControls(c);//Call UpdateColorControls with the current Control
            }
            thm++;//add +1 to the variable thm
            if (thm > 1) thm = 0;//if int thm is greater than 1 set it to 0
            if (Properties.Settings.Default.Theme)//Run code inside the block body if Theme Setting value is true
            {
                Properties.Settings.Default.Theme = false;//Set Theme Setting to false
                Properties.Settings.Default.Save();//Save Settings
            }
            else//Run this code inside the block body if Theme value is false
            {
                Properties.Settings.Default.Theme = true;//Set Theme Setting to true
                Properties.Settings.Default.Save();//Save Settings
            }
        }

        private void Theme_change()
        {
            foreach (Control c in Controls)//Execute for every Control found
            {
                UpdateColorControls(c);//Call UpdateColorControls with the current Control
            }
            thm++;//add +1 to the variable thm
            if (thm > 1) thm = 0;//if int thm is greater than 1 set it to 0
        }

        private void IceMemeForm_FormClosed(object sender, FormClosedEventArgs e) => Environment.Exit(0);//When the Form is closed Call Enviroment Exit to terminate the process

        private void Executelua_Click(object sender, EventArgs e)
        {
            if (NamedPipes.NamedPipeExist(NamedPipes.luapipename))//check if the pipe exist
            {
                NamedPipes.LuaPipe(LuaBox.Text);//lua c pipe function to send the script
            }
            else
            {
                MessageBox.Show("Inject " + Functions.exploitdll + " before Using this!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);//if the pipe can't be found a messagebox will appear
                return;
            }
        }

        private void Clearlua_Click(object sender, EventArgs e) => LuaBox.Clear();//Clear LuaBox

        private void Openlua_Click(object sender, EventArgs e)
        {
            if (Functions.openfiledialog.ShowDialog() == DialogResult.OK)//check if the user clicked Ok/open
            {
                try
                {
                    LuaBox.Text = File.ReadAllText(Functions.openfiledialog.FileName);//load all the text in the lua c rightextbox

                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not read file from disk. Original error: " + ex.Message);//display if got error
                }
            }
        }
        Style SalmonStyle = new TextStyle(Brushes.Salmon, null, FontStyle.Italic);//Store Text Style in a Variable for easy use 
        Style OrangeStyle = new TextStyle(Brushes.Orange, null, FontStyle.Italic);//Store Text Style in a Variable for easy use 
        Style LimeGreenStyle = new TextStyle(Brushes.LimeGreen, null, FontStyle.Italic);//Store Text Style in a Variable for easy use 
        Style CyanStyle = new TextStyle(Brushes.Cyan, null, FontStyle.Italic);//Store Text Style in a Variable for easy use 
        Style SpringGreenStyle = new TextStyle(Brushes.SpringGreen, null, FontStyle.Italic);//Store Text Style in a Variable for easy use 
        Style SkyBlueStyle = new TextStyle(Brushes.SkyBlue, null, FontStyle.Italic);//Store Text Style in a Variable for easy use 
        Style PaleGoldenrodStyle = new TextStyle(Brushes.PaleGoldenrod, null, FontStyle.Italic);//Store Text Style in a Variable for easy use 
        Style FirebrickStyle = new TextStyle(Brushes.Firebrick, null, FontStyle.Italic);//Store Text Style in a Variable for easy use 
        Style GoldBlueStyle = new TextStyle(Brushes.Gold, null, FontStyle.Italic);//Store Text Style in a Variable for easy use 
        Style CoralStyle = new TextStyle(Brushes.Coral, null, FontStyle.Italic);//Store Text Style in a Variable for easy use 

        private void LuaCBox_TextChanged(object sender, FastColoredTextBoxNS.TextChangedEventArgs e)//This Function is Called when LuaCBox Text is changed
        {
            e.ChangedRange.ClearStyle(SalmonStyle);//clear style for the current Text Style
            e.ChangedRange.ClearStyle(OrangeStyle);//clear style for the current Text Style
            e.ChangedRange.ClearStyle(LimeGreenStyle);//clear style for the current Text Style
            e.ChangedRange.ClearStyle(CyanStyle);//clear style for the current Text Style
            e.ChangedRange.ClearStyle(SpringGreenStyle);//clear style for the current Text Style
            e.ChangedRange.ClearStyle(SkyBlueStyle);//clear style for the current Text Style
            e.ChangedRange.ClearStyle(PaleGoldenrodStyle);//clear style for the current Text Style
            e.ChangedRange.ClearStyle(FirebrickStyle);//clear style for the current Text Style
            e.ChangedRange.ClearStyle(GoldBlueStyle);//clear style for the current Text Style
            e.ChangedRange.ClearStyle(CoralStyle);//clear style for the current Text Style
            e.ChangedRange.SetStyle(SalmonStyle, @"getglobal", RegexOptions.Multiline);//Set Style for the Word getglobal
            e.ChangedRange.SetStyle(OrangeStyle, @"getfield", RegexOptions.Multiline);//Set Style for the Word getfield
            e.ChangedRange.SetStyle(LimeGreenStyle, @"pushnumber", RegexOptions.Multiline);//Set Style for the Word pushnumber
            e.ChangedRange.SetStyle(CyanStyle, @"setfield", RegexOptions.Multiline);//Set Style for the Word setfield
            e.ChangedRange.SetStyle(SpringGreenStyle, @"pushvalue", RegexOptions.Multiline);//Set Style for the Word pushvalue
            e.ChangedRange.SetStyle(SkyBlueStyle, @"pushstring", RegexOptions.Multiline);//Set Style for the Word pushstring
            e.ChangedRange.SetStyle(PaleGoldenrodStyle, @"pushnumber", RegexOptions.Multiline);//Set Style for the Word pushnumber
            e.ChangedRange.SetStyle(FirebrickStyle, @"emptystack", RegexOptions.Multiline);//Set Style for the Word emptystack
            e.ChangedRange.SetStyle(GoldBlueStyle, @"getservice", RegexOptions.Multiline);//Set Style for the Word getservice
            e.ChangedRange.SetStyle(CoralStyle, @"pushboolean", RegexOptions.Multiline);//Set Style for the Word pushboolean
        }

        private void RefreshLuaList_Click(object sender, EventArgs e)
        {
            LuaScriptList.Items.Clear();//Clear Items in the LuaScriptList
            Functions.PopulateListBox(LuaScriptList, "./LuaScripts", "*.txt");//populate LuaScriptList with .txt files
            Functions.PopulateListBox(LuaScriptList, "./LuaScripts", "*.lua");//populate LuaScriptList with .lua files
        }

        private void LuaScriptList_SelectedIndexChanged(object sender, EventArgs e) => LuaBox.Text = File.ReadAllText($"./LuaScripts/{LuaScriptList.SelectedItem}");//Function called when the Selected item in LuaScriptList is changed, then get and read the file and send to LuaBox

        private void RefreshLuaCList_Click(object sender, EventArgs e)
        {
            LuaCScriptList.Items.Clear();//Clear Items in the LuaScriptList
            Functions.PopulateListBox(LuaCScriptList, "./LuaCScripts", "*.txt");//populate LuaCScriptList with .txt files
        }

        private void LuaCScriptList_SelectedIndexChanged(object sender, EventArgs e) => LuaCBox.Text = File.ReadAllText($"./LuaCScripts/{LuaCScriptList.SelectedItem}");//Function called when the Selected item in LuaCScriptList is changed, then get and read the file and send to LuaCBox

        private void PPAP_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("ppap");//Send Command through CommandPipe

        private void Rickrolll_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("rickroll");//Send Command through CommandPipe

        private void CRINGE_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("cringe");//Send Command through CommandPipe

        private void BILLNYE_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("billnye");//Send Command through CommandPipe

        private void InsertBtn_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("insert " + ModelID.Text);//Send Command through CommandPipe With ModelID text

        private void KillR_Click(object sender, EventArgs e)
        {
            if (Process.GetProcessesByName("RobloxPlayerBeta").Length == 0)//If Process not found run the code in the block body
            {
                MessageBox.Show("Roblox is already Closed.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);//Show Message Box to tell that Roblox Process is not running
                return;
            }
            else//Process is found so run the code in the block body
            {
                try
                {
                    Process[] proc = Process.GetProcessesByName("RobloxPlayerBeta");//Store Process in a variable for easy use
                    proc[0].Kill();//Kill Process
                    MessageBox.Show("Killed Roblox!", "Yay!", MessageBoxButtons.OK, MessageBoxIcon.Warning);//Show Message box to tell that Roblox Process got terminated
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message.ToString());//Show Message Box with the Exception
                }
            }
        }

        private void CheckerTimer_Tick(object sender, EventArgs e)//Timer interval is at 500 ms
        {
            if (NamedPipes.NamedPipeExist(NamedPipes.cmdpipename))//Check if the Command Pipe exist
            {
                InjectStatus.Text = "Injected";//Set Text to InjectStatus
                InjectStatus.ForeColor = Color.Green;//Set ForeColor Color
            }
            else
            {
                InjectStatus.Text = "Not Injected";//Set Text to InjectStatus
                InjectStatus.ForeColor = Color.Red;//Set ForeColor Color
            }
        }

        private void Credits_Click(object sender, EventArgs e) => MessageBox.Show(Functions.TextToBox[1], "Credits");//Show Message Box With the Credits

        private void ClickTpCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (ClickTpCheckBox.Checked)//If the ClickTpCheckBox is checked run the code in the block body
            {
                NamedPipes.CommandPipe("clicktpon");//Send Command through CommandPipe
            }
            else
            {
                NamedPipes.CommandPipe("offclicktp");//Send Command through CommandPipe
            }
        }

        private void SiteLabel_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e) => Process.Start("https://github.com/rakion99/IceMeme");//Go to rakion99 github when the link label is clicked

        private void PrintLuaCBtn_Click(object sender, EventArgs e) => NamedPipes.LuaCPipe(QuickExecution.printluac);//Send Script to LuaCPipe

        private void PrintLuaBtn_Click(object sender, EventArgs e) => NamedPipes.LuaPipe(QuickExecution.printlua);//Send Script to LuaPipe

        private void LuaCDayBtn_Click(object sender, EventArgs e) => NamedPipes.LuaCPipe(QuickExecution.luacday);//Send Script to LuaCPipe

        private void LuaCNightBtn_Click(object sender, EventArgs e) => NamedPipes.LuaCPipe(QuickExecution.luacnight);//Send Script to LuaCPipe

        private void LuaCIlluminatiBtn_Click(object sender, EventArgs e) => NamedPipes.LuaCPipe(QuickExecution.luacilluminati);//Send Script to LuaCPipe

        private void LuaCDKitBtn_Click(object sender, EventArgs e) => NamedPipes.LuaCPipe(QuickExecution.luacdkit);//Send Script to LuaCPipe

        private void LuaWSJPBtn_Click(object sender, EventArgs e)
        {
            NamedPipes.LuaPipe(QuickExecution.luajp);//Send Script to LuaPipe
            NamedPipes.LuaPipe(QuickExecution.luaws);//Send Script to LuaPipe
        }

        private void LuaBSODBtn_Click(object sender, EventArgs e)
        {
            NamedPipes.LuaPipe(QuickExecution.luabsod1);//Send BOSD part 1 Script to LuaPipe
            NamedPipes.LuaPipe(QuickExecution.luabsod2);//Send BOSD part 2 Script to LuaPipe
            NamedPipes.LuaPipe(QuickExecution.luabsod3);//Send BOSD part 3 Script to LuaPipe
            NamedPipes.LuaPipe(QuickExecution.luabsod4);//Send BOSD part 4 Script to LuaPipe
        }

        private void Opacity_Scroll(object sender, EventArgs e)
        {
            Opacity = OpacityBar.Value / (double)10;//Set Opacity value from OpacityBar value
            Properties.Settings.Default.OpacityValue = OpacityBar.Value;//Set OpacityValue Setting value to OpacityBar Value
            Properties.Settings.Default.Save();//Save Settings
        }

        private void CheckUpdatesBox_CheckedChanged(object sender, EventArgs e)
        {
            if (CheckUpdatesBox.Checked)
            {
                Properties.Settings.Default.CheckUpdates = true;//Set CheckUpdates Setting to true
                Properties.Settings.Default.Save();//Save Settings
            }
            else
            {
                Properties.Settings.Default.CheckUpdates = false;//Set CheckUpdates Setting to false
                Properties.Settings.Default.Save();//Save Settings
            }
        }
    }
}
