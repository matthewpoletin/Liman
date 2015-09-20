namespace LimanEditor
{
    partial class EditorForm
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
            ShutDown();
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(EditorForm));
            this.topMenuStrip = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openProjectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveProjectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveProjectAsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.closeProjectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.settingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.projectSettingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.fileStripSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.copyActorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.cutActorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pasteActorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteActorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.levelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openLevelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.createLevelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveLevelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.actorsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.createActorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadActorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.createComponentToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.transformToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.renderableToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.movableToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.collidableToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rectangleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.sphereToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.buildToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.runToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.runInWindowToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.saveStateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadStateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.viewSourceCodeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openDocumentationToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.statusStripLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.levelLoadingProgressBar = new System.Windows.Forms.ToolStripProgressBar();
            this.assetsActorsTreeLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this.tabControl = new System.Windows.Forms.TabControl();
            this.levelTabPage = new System.Windows.Forms.TabPage();
            this.levelTreeView = new System.Windows.Forms.TreeView();
            this.rightColomnPanel = new System.Windows.Forms.TableLayoutPanel();
            this.componentsTreeLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this.DisplayPanel = new System.Windows.Forms.Panel();
            this.topMenuStrip.SuspendLayout();
            this.statusStrip.SuspendLayout();
            this.assetsActorsTreeLayoutPanel.SuspendLayout();
            this.tabControl.SuspendLayout();
            this.levelTabPage.SuspendLayout();
            this.rightColomnPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // topMenuStrip
            // 
            this.topMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.levelToolStripMenuItem,
            this.actorsToolStripMenuItem,
            this.buildToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.topMenuStrip.Location = new System.Drawing.Point(0, 0);
            this.topMenuStrip.Name = "topMenuStrip";
            this.topMenuStrip.Size = new System.Drawing.Size(704, 24);
            this.topMenuStrip.TabIndex = 1;
            this.topMenuStrip.Text = "topMenuStrip";
            this.topMenuStrip.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.menuStrip1_ItemClicked);
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openProjectToolStripMenuItem,
            this.saveProjectToolStripMenuItem,
            this.saveProjectAsToolStripMenuItem,
            this.closeProjectToolStripMenuItem,
            this.settingsToolStripMenuItem,
            this.toolStripSeparator3,
            this.projectSettingsToolStripMenuItem,
            this.fileStripSeparator,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // openProjectToolStripMenuItem
            // 
            this.openProjectToolStripMenuItem.Enabled = false;
            this.openProjectToolStripMenuItem.Name = "openProjectToolStripMenuItem";
            this.openProjectToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.openProjectToolStripMenuItem.Text = "Open Project";
            // 
            // saveProjectToolStripMenuItem
            // 
            this.saveProjectToolStripMenuItem.Enabled = false;
            this.saveProjectToolStripMenuItem.Name = "saveProjectToolStripMenuItem";
            this.saveProjectToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.saveProjectToolStripMenuItem.Text = "Save Project";
            // 
            // saveProjectAsToolStripMenuItem
            // 
            this.saveProjectAsToolStripMenuItem.Enabled = false;
            this.saveProjectAsToolStripMenuItem.Name = "saveProjectAsToolStripMenuItem";
            this.saveProjectAsToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.saveProjectAsToolStripMenuItem.Text = "Save Project As...";
            // 
            // closeProjectToolStripMenuItem
            // 
            this.closeProjectToolStripMenuItem.Enabled = false;
            this.closeProjectToolStripMenuItem.Name = "closeProjectToolStripMenuItem";
            this.closeProjectToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.closeProjectToolStripMenuItem.Text = "Close Project";
            // 
            // settingsToolStripMenuItem
            // 
            this.settingsToolStripMenuItem.Enabled = false;
            this.settingsToolStripMenuItem.Name = "settingsToolStripMenuItem";
            this.settingsToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.settingsToolStripMenuItem.Text = "Settings";
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(160, 6);
            // 
            // projectSettingsToolStripMenuItem
            // 
            this.projectSettingsToolStripMenuItem.Enabled = false;
            this.projectSettingsToolStripMenuItem.Name = "projectSettingsToolStripMenuItem";
            this.projectSettingsToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.projectSettingsToolStripMenuItem.Text = "Project Settings";
            this.projectSettingsToolStripMenuItem.Click += new System.EventHandler(this.projectSettingsToolStripMenuItem_Click);
            // 
            // fileStripSeparator
            // 
            this.fileStripSeparator.Name = "fileStripSeparator";
            this.fileStripSeparator.Size = new System.Drawing.Size(160, 6);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.copyActorToolStripMenuItem,
            this.cutActorToolStripMenuItem,
            this.pasteActorToolStripMenuItem,
            this.deleteActorToolStripMenuItem});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
            this.editToolStripMenuItem.Text = "Edit";
            // 
            // copyActorToolStripMenuItem
            // 
            this.copyActorToolStripMenuItem.Enabled = false;
            this.copyActorToolStripMenuItem.Name = "copyActorToolStripMenuItem";
            this.copyActorToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.copyActorToolStripMenuItem.Text = "Copy Actor";
            // 
            // cutActorToolStripMenuItem
            // 
            this.cutActorToolStripMenuItem.Enabled = false;
            this.cutActorToolStripMenuItem.Name = "cutActorToolStripMenuItem";
            this.cutActorToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.cutActorToolStripMenuItem.Text = "Cut Actor";
            // 
            // pasteActorToolStripMenuItem
            // 
            this.pasteActorToolStripMenuItem.Enabled = false;
            this.pasteActorToolStripMenuItem.Name = "pasteActorToolStripMenuItem";
            this.pasteActorToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.pasteActorToolStripMenuItem.Text = "Paste Actor";
            // 
            // deleteActorToolStripMenuItem
            // 
            this.deleteActorToolStripMenuItem.Enabled = false;
            this.deleteActorToolStripMenuItem.Name = "deleteActorToolStripMenuItem";
            this.deleteActorToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.deleteActorToolStripMenuItem.Text = "Delete Actor";
            // 
            // levelToolStripMenuItem
            // 
            this.levelToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openLevelToolStripMenuItem,
            this.createLevelToolStripMenuItem,
            this.saveLevelToolStripMenuItem});
            this.levelToolStripMenuItem.Name = "levelToolStripMenuItem";
            this.levelToolStripMenuItem.Size = new System.Drawing.Size(46, 20);
            this.levelToolStripMenuItem.Text = "Level";
            // 
            // openLevelToolStripMenuItem
            // 
            this.openLevelToolStripMenuItem.Enabled = false;
            this.openLevelToolStripMenuItem.Name = "openLevelToolStripMenuItem";
            this.openLevelToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.openLevelToolStripMenuItem.Text = "Open Level";
            // 
            // createLevelToolStripMenuItem
            // 
            this.createLevelToolStripMenuItem.Enabled = false;
            this.createLevelToolStripMenuItem.Name = "createLevelToolStripMenuItem";
            this.createLevelToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.createLevelToolStripMenuItem.Text = "Create Level";
            // 
            // saveLevelToolStripMenuItem
            // 
            this.saveLevelToolStripMenuItem.Enabled = false;
            this.saveLevelToolStripMenuItem.Name = "saveLevelToolStripMenuItem";
            this.saveLevelToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.saveLevelToolStripMenuItem.Text = "Save Level";
            // 
            // actorsToolStripMenuItem
            // 
            this.actorsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.createActorToolStripMenuItem,
            this.loadActorToolStripMenuItem,
            this.toolStripSeparator2,
            this.createComponentToolStripMenuItem});
            this.actorsToolStripMenuItem.Name = "actorsToolStripMenuItem";
            this.actorsToolStripMenuItem.Size = new System.Drawing.Size(53, 20);
            this.actorsToolStripMenuItem.Text = "Actors";
            // 
            // createActorToolStripMenuItem
            // 
            this.createActorToolStripMenuItem.Enabled = false;
            this.createActorToolStripMenuItem.Name = "createActorToolStripMenuItem";
            this.createActorToolStripMenuItem.Size = new System.Drawing.Size(175, 22);
            this.createActorToolStripMenuItem.Text = "Create Actor";
            this.createActorToolStripMenuItem.Click += new System.EventHandler(this.createToolStripMenuItem_Click);
            // 
            // loadActorToolStripMenuItem
            // 
            this.loadActorToolStripMenuItem.Enabled = false;
            this.loadActorToolStripMenuItem.Name = "loadActorToolStripMenuItem";
            this.loadActorToolStripMenuItem.Size = new System.Drawing.Size(175, 22);
            this.loadActorToolStripMenuItem.Text = "Open Actor";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(172, 6);
            // 
            // createComponentToolStripMenuItem
            // 
            this.createComponentToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.transformToolStripMenuItem,
            this.renderableToolStripMenuItem,
            this.movableToolStripMenuItem,
            this.collidableToolStripMenuItem});
            this.createComponentToolStripMenuItem.Enabled = false;
            this.createComponentToolStripMenuItem.Name = "createComponentToolStripMenuItem";
            this.createComponentToolStripMenuItem.Size = new System.Drawing.Size(175, 22);
            this.createComponentToolStripMenuItem.Text = "Create Component";
            // 
            // transformToolStripMenuItem
            // 
            this.transformToolStripMenuItem.Name = "transformToolStripMenuItem";
            this.transformToolStripMenuItem.Size = new System.Drawing.Size(133, 22);
            this.transformToolStripMenuItem.Text = "Transform";
            // 
            // renderableToolStripMenuItem
            // 
            this.renderableToolStripMenuItem.Name = "renderableToolStripMenuItem";
            this.renderableToolStripMenuItem.Size = new System.Drawing.Size(133, 22);
            this.renderableToolStripMenuItem.Text = "Renderable";
            // 
            // movableToolStripMenuItem
            // 
            this.movableToolStripMenuItem.Name = "movableToolStripMenuItem";
            this.movableToolStripMenuItem.Size = new System.Drawing.Size(133, 22);
            this.movableToolStripMenuItem.Text = "Movable";
            // 
            // collidableToolStripMenuItem
            // 
            this.collidableToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.rectangleToolStripMenuItem,
            this.sphereToolStripMenuItem});
            this.collidableToolStripMenuItem.Name = "collidableToolStripMenuItem";
            this.collidableToolStripMenuItem.Size = new System.Drawing.Size(133, 22);
            this.collidableToolStripMenuItem.Text = "Collidable";
            // 
            // rectangleToolStripMenuItem
            // 
            this.rectangleToolStripMenuItem.Name = "rectangleToolStripMenuItem";
            this.rectangleToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.rectangleToolStripMenuItem.Text = "Rectangle";
            // 
            // sphereToolStripMenuItem
            // 
            this.sphereToolStripMenuItem.Name = "sphereToolStripMenuItem";
            this.sphereToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.sphereToolStripMenuItem.Text = "Circle";
            // 
            // buildToolStripMenuItem
            // 
            this.buildToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.runToolStripMenuItem,
            this.runInWindowToolStripMenuItem,
            this.toolStripSeparator5,
            this.saveStateToolStripMenuItem,
            this.loadStateToolStripMenuItem});
            this.buildToolStripMenuItem.Name = "buildToolStripMenuItem";
            this.buildToolStripMenuItem.Size = new System.Drawing.Size(46, 20);
            this.buildToolStripMenuItem.Text = "Build";
            this.buildToolStripMenuItem.Click += new System.EventHandler(this.buildToolStripMenuItem_Click);
            // 
            // runToolStripMenuItem
            // 
            this.runToolStripMenuItem.Enabled = false;
            this.runToolStripMenuItem.Name = "runToolStripMenuItem";
            this.runToolStripMenuItem.Size = new System.Drawing.Size(155, 22);
            this.runToolStripMenuItem.Text = "Run";
            // 
            // runInWindowToolStripMenuItem
            // 
            this.runInWindowToolStripMenuItem.Enabled = false;
            this.runInWindowToolStripMenuItem.Name = "runInWindowToolStripMenuItem";
            this.runInWindowToolStripMenuItem.Size = new System.Drawing.Size(155, 22);
            this.runInWindowToolStripMenuItem.Text = "Run In Window";
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(152, 6);
            // 
            // saveStateToolStripMenuItem
            // 
            this.saveStateToolStripMenuItem.Enabled = false;
            this.saveStateToolStripMenuItem.Name = "saveStateToolStripMenuItem";
            this.saveStateToolStripMenuItem.Size = new System.Drawing.Size(155, 22);
            this.saveStateToolStripMenuItem.Text = "Save State";
            // 
            // loadStateToolStripMenuItem
            // 
            this.loadStateToolStripMenuItem.Enabled = false;
            this.loadStateToolStripMenuItem.Name = "loadStateToolStripMenuItem";
            this.loadStateToolStripMenuItem.Size = new System.Drawing.Size(155, 22);
            this.loadStateToolStripMenuItem.Text = "Load State";
            this.loadStateToolStripMenuItem.Click += new System.EventHandler(this.startFromStateToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem,
            this.toolStripSeparator4,
            this.viewSourceCodeToolStripMenuItem,
            this.openDocumentationToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(189, 22);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(186, 6);
            // 
            // viewSourceCodeToolStripMenuItem
            // 
            this.viewSourceCodeToolStripMenuItem.Name = "viewSourceCodeToolStripMenuItem";
            this.viewSourceCodeToolStripMenuItem.Size = new System.Drawing.Size(189, 22);
            this.viewSourceCodeToolStripMenuItem.Text = "View Source Code";
            this.viewSourceCodeToolStripMenuItem.Click += new System.EventHandler(this.viewSourceCodeToolStripMenuItem_Click);
            // 
            // openDocumentationToolStripMenuItem
            // 
            this.openDocumentationToolStripMenuItem.Name = "openDocumentationToolStripMenuItem";
            this.openDocumentationToolStripMenuItem.Size = new System.Drawing.Size(189, 22);
            this.openDocumentationToolStripMenuItem.Text = "Open Documentation";
            this.openDocumentationToolStripMenuItem.Click += new System.EventHandler(this.openDocumentationToolStripMenuItem_Click);
            // 
            // statusStrip
            // 
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.statusStripLabel,
            this.levelLoadingProgressBar});
            this.statusStrip.Location = new System.Drawing.Point(0, 419);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(704, 22);
            this.statusStrip.SizingGrip = false;
            this.statusStrip.TabIndex = 5;
            this.statusStrip.Text = "levelLoadingStatusStrip";
            // 
            // statusStripLabel
            // 
            this.statusStripLabel.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.statusStripLabel.Enabled = false;
            this.statusStripLabel.Name = "statusStripLabel";
            this.statusStripLabel.Size = new System.Drawing.Size(587, 17);
            this.statusStripLabel.Spring = true;
            this.statusStripLabel.Text = "Level Loading";
            this.statusStripLabel.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // levelLoadingProgressBar
            // 
            this.levelLoadingProgressBar.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.levelLoadingProgressBar.Name = "levelLoadingProgressBar";
            this.levelLoadingProgressBar.Size = new System.Drawing.Size(100, 16);
            this.levelLoadingProgressBar.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            // 
            // assetsActorsTreeLayoutPanel
            // 
            this.assetsActorsTreeLayoutPanel.ColumnCount = 1;
            this.assetsActorsTreeLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.assetsActorsTreeLayoutPanel.Controls.Add(this.tabControl, 0, 0);
            this.assetsActorsTreeLayoutPanel.Location = new System.Drawing.Point(3, 3);
            this.assetsActorsTreeLayoutPanel.Name = "assetsActorsTreeLayoutPanel";
            this.assetsActorsTreeLayoutPanel.RowCount = 1;
            this.assetsActorsTreeLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.assetsActorsTreeLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.assetsActorsTreeLayoutPanel.Size = new System.Drawing.Size(242, 155);
            this.assetsActorsTreeLayoutPanel.TabIndex = 1;
            // 
            // tabControl
            // 
            this.tabControl.Controls.Add(this.levelTabPage);
            this.tabControl.Location = new System.Drawing.Point(3, 3);
            this.tabControl.Name = "tabControl";
            this.tabControl.SelectedIndex = 0;
            this.tabControl.Size = new System.Drawing.Size(236, 149);
            this.tabControl.TabIndex = 0;
            // 
            // levelTabPage
            // 
            this.levelTabPage.Controls.Add(this.levelTreeView);
            this.levelTabPage.Location = new System.Drawing.Point(4, 22);
            this.levelTabPage.Name = "levelTabPage";
            this.levelTabPage.Padding = new System.Windows.Forms.Padding(3);
            this.levelTabPage.Size = new System.Drawing.Size(228, 123);
            this.levelTabPage.TabIndex = 0;
            this.levelTabPage.Text = "Level";
            this.levelTabPage.UseVisualStyleBackColor = true;
            // 
            // levelTreeView
            // 
            this.levelTreeView.Location = new System.Drawing.Point(0, 0);
            this.levelTreeView.Name = "levelTreeView";
            this.levelTreeView.Size = new System.Drawing.Size(228, 120);
            this.levelTreeView.TabIndex = 0;
            // 
            // rightColomnPanel
            // 
            this.rightColomnPanel.ColumnCount = 1;
            this.rightColomnPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.rightColomnPanel.Controls.Add(this.assetsActorsTreeLayoutPanel, 0, 0);
            this.rightColomnPanel.Controls.Add(this.componentsTreeLayoutPanel, 0, 1);
            this.rightColomnPanel.Location = new System.Drawing.Point(456, 27);
            this.rightColomnPanel.Name = "rightColomnPanel";
            this.rightColomnPanel.RowCount = 2;
            this.rightColomnPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.rightColomnPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 228F));
            this.rightColomnPanel.Size = new System.Drawing.Size(248, 389);
            this.rightColomnPanel.TabIndex = 0;
            // 
            // componentsTreeLayoutPanel
            // 
            this.componentsTreeLayoutPanel.ColumnCount = 1;
            this.componentsTreeLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.componentsTreeLayoutPanel.Location = new System.Drawing.Point(3, 164);
            this.componentsTreeLayoutPanel.Name = "componentsTreeLayoutPanel";
            this.componentsTreeLayoutPanel.RowCount = 1;
            this.componentsTreeLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.componentsTreeLayoutPanel.Size = new System.Drawing.Size(242, 215);
            this.componentsTreeLayoutPanel.TabIndex = 2;
            // 
            // DisplayPanel
            // 
            this.DisplayPanel.Location = new System.Drawing.Point(0, 27);
            this.DisplayPanel.Name = "DisplayPanel";
            this.DisplayPanel.Size = new System.Drawing.Size(450, 389);
            this.DisplayPanel.TabIndex = 6;
            // 
            // EditorForm
            // 
            this.ClientSize = new System.Drawing.Size(704, 441);
            this.Controls.Add(this.topMenuStrip);
            this.Controls.Add(this.DisplayPanel);
            this.Controls.Add(this.rightColomnPanel);
            this.Controls.Add(this.statusStrip);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.topMenuStrip;
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(720, 480);
            this.MinimumSize = new System.Drawing.Size(720, 480);
            this.Name = "EditorForm";
            this.Text = "Liman Editor";
            this.Load += new System.EventHandler(this.EditorForm_Load);
            this.topMenuStrip.ResumeLayout(false);
            this.topMenuStrip.PerformLayout();
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            this.assetsActorsTreeLayoutPanel.ResumeLayout(false);
            this.tabControl.ResumeLayout(false);
            this.levelTabPage.ResumeLayout(false);
            this.rightColomnPanel.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.MenuStrip topMenuStrip;
        private System.Windows.Forms.ToolStripMenuItem actorsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.ToolStripStatusLabel statusStripLabel;
        private System.Windows.Forms.ToolStripMenuItem createActorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadActorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem levelToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem closeProjectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openLevelToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem createLevelToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveLevelToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem buildToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem runToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadStateToolStripMenuItem;
        private System.Windows.Forms.TableLayoutPanel assetsActorsTreeLayoutPanel;
        private System.Windows.Forms.ToolStripSeparator fileStripSeparator;
        private System.Windows.Forms.ToolStripProgressBar levelLoadingProgressBar;
        private System.Windows.Forms.TreeView levelTreeView;
        private System.Windows.Forms.TabPage levelTabPage;
        private System.Windows.Forms.TabControl tabControl;
        private System.Windows.Forms.TableLayoutPanel rightColomnPanel;
        private System.Windows.Forms.Panel DisplayPanel;
        private System.Windows.Forms.TableLayoutPanel componentsTreeLayoutPanel;
        private System.Windows.Forms.ToolStripMenuItem copyActorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem cutActorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pasteActorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewSourceCodeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openDocumentationToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem createComponentToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem projectSettingsToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem settingsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripMenuItem transformToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem renderableToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem movableToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem collidableToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem rectangleToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem sphereToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteActorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem runInWindowToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripMenuItem saveStateToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveProjectAsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveProjectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openProjectToolStripMenuItem;
    }
}