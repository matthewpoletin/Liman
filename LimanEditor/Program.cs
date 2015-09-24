// Program.cs - entry point for the C# Editor

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LimanEditor
{
    class Program
    {
        [STAThread] static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            EditorForm form = new EditorForm();
            Application.Run(form);
        }
    }
}