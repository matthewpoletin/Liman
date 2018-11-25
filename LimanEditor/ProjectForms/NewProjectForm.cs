using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LimanEditor
{
    public partial class NewProjectForm : Form
    {
        private string m_projectName;
        private string m_projectFolder;

        public NewProjectForm()
        {
            InitializeComponent();
        }

        private void UpdateForm()
        {
            m_projectName = projectNameTextBox.Text;
            m_projectFolder = projectFolderTextBox.Text;
        }

        private void browseButton_Click(object sender, EventArgs e)
        {
            if (folderBrowserDialog.ShowDialog() == DialogResult.OK)
            {
                m_projectFolder = folderBrowserDialog.SelectedPath;
                FormUtils.UpdateTextBoxValue(projectFolderTextBox, folderBrowserDialog.SelectedPath);
            }
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            UpdateForm();

            if(m_projectName.Length == 0)
            {

                const string message = "Enter project name!";
                const string caption = "Error";
                MessageBox.Show(message, caption, MessageBoxButtons.OK);
            }

            #if DEBUG
            string debugFormResult = "Project Name: " + m_projectName + "\n" + "Project Folder: " + m_projectFolder;
                MessageBox.Show(debugFormResult);
            #endif
        }

        private void projectNameTextBox_TextChanged(object sender, EventArgs e)
        {
            UpdateForm();
        }

        private void projectFolderTextBox_TextChanged(object sender, EventArgs e)
        {
            UpdateForm();
        }
    }
}
