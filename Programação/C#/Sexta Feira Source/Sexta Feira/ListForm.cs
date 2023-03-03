using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sexta_Feira
{
    public partial class ListForm : Form
    {
        public ListForm()
        {
            InitializeComponent();
            Update_();

        }
      

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {


        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void groupBox7_Enter(object sender, EventArgs e)
        {

        }

        private void ListForm_Load(object sender, EventArgs e)
        {
            groupBox7.Text = "\"" + Environment.UserName + " --- " + Dns.GetHostEntry(Environment.MachineName).HostName + " --- " + Environment.OSVersion + "\"";

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void Update_()
        {

            

        }

        private void ListForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            ListForm F2 = new ListForm();
            F2.Close();
        }
    }
}
