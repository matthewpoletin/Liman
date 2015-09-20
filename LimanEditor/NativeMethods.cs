using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace LimanEditor
{
    class NativeMethods
    {
        const string editorDllName = "LimanEditorDLL.dll";

        [DllImport(editorDllName, CallingConvention = CallingConvention.Cdecl)]
        public unsafe static extern int EditorMain(IntPtr instancePtrAddress, IntPtr hPrevInstancePtrAddress, IntPtr hWndPtrAddress, int nCmdShow, int screenWidth, int screenHeight);

        [DllImport(editorDllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RenderFrame();

        [DllImport(editorDllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Shutdown();

    }
}
