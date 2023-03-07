using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double[] temperature = new double[5];
            double sum = 0.0;
            temperature[0] = double.Parse(textBox1.Text);
            temperature[1] = double.Parse(textBox2.Text);
            temperature[2] = double.Parse(textBox3.Text);
            temperature[3] = double.Parse(textBox4.Text);
            temperature[4] = double.Parse(textBox5.Text);
            foreach(double i in temperature)
            {
                sum += i;
            }
            double avg = sum / 5.0;
            label3.Text = avg.ToString();
            textBox1.Text = avg.ToString();

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
