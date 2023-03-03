using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.Speech.Recognition;

namespace Sexta_Feira
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private SpeechRecognitionEngine MATRIX;



        private void Form1_Load(object sender, EventArgs e)
        {

            Logic();

        }
        private void Logic()
        {
            try
            {
                MATRIX = new SpeechRecognitionEngine();
                MATRIX.SetInputToDefaultAudioDevice();
                MATRIX.SpeechRecognized += new EventHandler<SpeechRecognizedEventArgs>(GFUN);
                MATRIX.AudioLevelUpdated += new EventHandler<AudioLevelUpdatedEventArgs>(CALL);

                Choices alternateChoices = new Choices();
                //alternateChoices.Add(); add func
                




                GrammarBuilder builder = new GrammarBuilder();
                builder.Append(alternateChoices);

                MATRIX.LoadGrammar(new Grammar(builder){ Name = "sys" });

                MATRIX.RecognizeAsync(RecognizeMode.Multiple);
                Speech.FL("O reconhecimento de voz foi iniciado");




            }
            catch (Exception ERROR)
            {
                MessageBox.Show(ERROR.Message);
            }


        }
        private void GFUN(object s, SpeechRecognizedEventArgs e)
        {
            string test = @"c:/";
           
            string scp = e.Result.Text;
            MessageBox.Show(scp);
            if ((double)e.Result.Confidence <= 0.349999994039536)
                return;
            switch (e.Result.Grammar.Name)
            {
                case "sys":
                    try
                    {
                        if (/*classe de fala*/.Any<string>(x => x == scp).Equals(false))
                        {
                             //task a fazer
                        }
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message);
                    }
                    break;
            }
        }
        private void CALL(object s, AudioLevelUpdatedEventArgs e)
        {
            progressBar1.Maximum = 100;
            progressBar1.Value = e.AudioLevel;
        }

        private void progressBar1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            ListForm F2 = new ListForm();
            F2.Show();

        }
    }
}
