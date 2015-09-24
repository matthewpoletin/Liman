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

    public class MenuStripUtils
    {
        static public void OpenLink(string linkStr)
        {
            System.Diagnostics.Process myProcess = new System.Diagnostics.Process();
            try
            {
                // true is the default, but it is important not to set it to false
                myProcess.StartInfo.UseShellExecute = true;
                myProcess.StartInfo.FileName = linkStr;
                myProcess.Start();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }

    public class FormUtils
    {
        static public void UpdateTextBoxValue(TextBox textBox, string value)
        {
            textBox.Text = value;
        }
    }

}