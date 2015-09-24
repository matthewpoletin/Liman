namespace LimanEditor
{
    partial class NewProjectForm
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
            this.newProjectTableLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this.projectNameTableLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this.projectNameLabel = new System.Windows.Forms.Label();
            this.projectNameTextBox = new System.Windows.Forms.TextBox();
            this.okButton = new System.Windows.Forms.Button();
            this.projectFolderTableLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this.projectFolderTextBox = new System.Windows.Forms.TextBox();
            this.browseButton = new System.Windows.Forms.Button();
            this.projectFolderLabel = new System.Windows.Forms.Label();
            this.folderBrowserDialog = new System.Windows.Forms.FolderBrowserDialog();
            this.newProjectTableLayoutPanel.SuspendLayout();
            this.projectNameTableLayoutPanel.SuspendLayout();
            this.projectFolderTableLayoutPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // newProjectTableLayoutPanel
            // 
            this.newProjectTableLayoutPanel.ColumnCount = 1;
            this.newProjectTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 167F));
            this.newProjectTableLayoutPanel.Controls.Add(this.projectNameTableLayoutPanel, 0, 0);
            this.newProjectTableLayoutPanel.Controls.Add(this.okButton, 0, 2);
            this.newProjectTableLayoutPanel.Controls.Add(this.projectFolderTableLayoutPanel, 0, 1);
            this.newProjectTableLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.newProjectTableLayoutPanel.Location = new System.Drawing.Point(0, 0);
            this.newProjectTableLayoutPanel.Name = "newProjectTableLayoutPanel";
            this.newProjectTableLayoutPanel.RowCount = 3;
            this.newProjectTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 55.23013F));
            this.newProjectTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 44.76987F));
            this.newProjectTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 92F));
            this.newProjectTableLayoutPanel.Size = new System.Drawing.Size(517, 357);
            this.newProjectTableLayoutPanel.TabIndex = 1;
            // 
            // projectNameTableLayoutPanel
            // 
            this.projectNameTableLayoutPanel.ColumnCount = 2;
            this.projectNameTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 26.0274F));
            this.projectNameTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 73.9726F));
            this.projectNameTableLayoutPanel.Controls.Add(this.projectNameLabel, 0, 0);
            this.projectNameTableLayoutPanel.Controls.Add(this.projectNameTextBox, 1, 0);
            this.projectNameTableLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.projectNameTableLayoutPanel.Location = new System.Drawing.Point(3, 3);
            this.projectNameTableLayoutPanel.Name = "projectNameTableLayoutPanel";
            this.projectNameTableLayoutPanel.RowCount = 1;
            this.projectNameTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 140F));
            this.projectNameTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 140F));
            this.projectNameTableLayoutPanel.Size = new System.Drawing.Size(511, 140);
            this.projectNameTableLayoutPanel.TabIndex = 29;
            // 
            // projectNameLabel
            // 
            this.projectNameLabel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.projectNameLabel.AutoSize = true;
            this.projectNameLabel.Location = new System.Drawing.Point(30, 63);
            this.projectNameLabel.Name = "projectNameLabel";
            this.projectNameLabel.Size = new System.Drawing.Size(71, 13);
            this.projectNameLabel.TabIndex = 27;
            this.projectNameLabel.Text = "Project Name";
            // 
            // projectNameTextBox
            // 
            this.projectNameTextBox.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.projectNameTextBox.Location = new System.Drawing.Point(138, 60);
            this.projectNameTextBox.Name = "projectNameTextBox";
            this.projectNameTextBox.Size = new System.Drawing.Size(367, 20);
            this.projectNameTextBox.TabIndex = 26;
            this.projectNameTextBox.TextChanged += new System.EventHandler(this.projectNameTextBox_TextChanged);
            // 
            // okButton
            // 
            this.okButton.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.okButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.okButton.Location = new System.Drawing.Point(221, 300);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(74, 20);
            this.okButton.TabIndex = 25;
            this.okButton.Text = "&OK";
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // projectFolderTableLayoutPanel
            // 
            this.projectFolderTableLayoutPanel.ColumnCount = 3;
            this.projectFolderTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.projectFolderTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 286F));
            this.projectFolderTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 93F));
            this.projectFolderTableLayoutPanel.Controls.Add(this.projectFolderTextBox, 1, 0);
            this.projectFolderTableLayoutPanel.Controls.Add(this.browseButton, 2, 0);
            this.projectFolderTableLayoutPanel.Controls.Add(this.projectFolderLabel, 0, 0);
            this.projectFolderTableLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.projectFolderTableLayoutPanel.Location = new System.Drawing.Point(3, 149);
            this.projectFolderTableLayoutPanel.Name = "projectFolderTableLayoutPanel";
            this.projectFolderTableLayoutPanel.RowCount = 1;
            this.projectFolderTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.projectFolderTableLayoutPanel.Size = new System.Drawing.Size(511, 112);
            this.projectFolderTableLayoutPanel.TabIndex = 30;
            // 
            // projectFolderTextBox
            // 
            this.projectFolderTextBox.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.projectFolderTextBox.Location = new System.Drawing.Point(136, 46);
            this.projectFolderTextBox.Name = "projectFolderTextBox";
            this.projectFolderTextBox.Size = new System.Drawing.Size(277, 20);
            this.projectFolderTextBox.TabIndex = 28;
            this.projectFolderTextBox.TextChanged += new System.EventHandler(this.projectFolderTextBox_TextChanged);
            // 
            // browseButton
            // 
            this.browseButton.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.browseButton.Location = new System.Drawing.Point(427, 44);
            this.browseButton.Name = "browseButton";
            this.browseButton.Size = new System.Drawing.Size(75, 23);
            this.browseButton.TabIndex = 1;
            this.browseButton.Text = "Browse";
            this.browseButton.UseVisualStyleBackColor = true;
            this.browseButton.Click += new System.EventHandler(this.browseButton_Click);
            // 
            // projectFolderLabel
            // 
            this.projectFolderLabel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.projectFolderLabel.AutoSize = true;
            this.projectFolderLabel.Location = new System.Drawing.Point(30, 49);
            this.projectFolderLabel.Name = "projectFolderLabel";
            this.projectFolderLabel.Size = new System.Drawing.Size(72, 13);
            this.projectFolderLabel.TabIndex = 29;
            this.projectFolderLabel.Text = "Project Folder";
            // 
            // folderBrowserDialog
            // 
            this.folderBrowserDialog.Description = "Chose the folder for your new project";
            // 
            // NewProjectForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(517, 357);
            this.Controls.Add(this.newProjectTableLayoutPanel);
            this.Name = "NewProjectForm";
            this.Text = "New Project";
            this.newProjectTableLayoutPanel.ResumeLayout(false);
            this.projectNameTableLayoutPanel.ResumeLayout(false);
            this.projectNameTableLayoutPanel.PerformLayout();
            this.projectFolderTableLayoutPanel.ResumeLayout(false);
            this.projectFolderTableLayoutPanel.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.TableLayoutPanel newProjectTableLayoutPanel;
        private System.Windows.Forms.Button browseButton;
        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog;
        private System.Windows.Forms.Button okButton;
        private System.Windows.Forms.Label projectNameLabel;
        private System.Windows.Forms.TableLayoutPanel projectNameTableLayoutPanel;
        private System.Windows.Forms.TextBox projectFolderTextBox;
        private System.Windows.Forms.TableLayoutPanel projectFolderTableLayoutPanel;
        private System.Windows.Forms.Label projectFolderLabel;
        private System.Windows.Forms.TextBox projectNameTextBox;
    }
}