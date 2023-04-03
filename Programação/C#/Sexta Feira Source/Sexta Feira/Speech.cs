using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Speech.Synthesis;
using System.Windows.Forms;

namespace Sexta_Feira
{


    internal class Speech
    {
        private static SpeechSynthesizer READ = new SpeechSynthesizer();

        public static void FL(string text)
        {
            if (READ.State == SynthesizerState.Speaking)
                READ.SpeakAsyncCancelAll();
                READ.SpeakAsync(text);
        }


    }
}
