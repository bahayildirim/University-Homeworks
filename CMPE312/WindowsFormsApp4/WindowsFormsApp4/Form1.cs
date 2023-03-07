using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (radioButton1.Checked == true)
            {
                MessageBox.Show("You have selected C","", MessageBoxButtons.OK);
                Application.Exit();
            }
            if (radioButton2.Checked == true)
            {
                MessageBox.Show("You have selected C++","", MessageBoxButtons.OK);
                Application.Exit();
            }
            if (radioButton3.Checked == true)
            {
                MessageBox.Show("You have selected C#","", MessageBoxButtons.OK);
                Application.Exit();
            }
            if (radioButton4.Checked == true)
            {
                MessageBox.Show("You have selected Phyton","", MessageBoxButtons.OK);
                Application.Exit();
            }
            if (radioButton5.Checked == true)
            {
                MessageBox.Show("You have selected Java","",MessageBoxButtons.OK);
                Application.Exit();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form2 DeptForm = new Form2();
            DeptForm.Show();
        }
    }
}
