using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            comboBox1.Items.Clear();
            comboBox1.Items.Add("Shopping");
            comboBox1.Items.Add("Visiting Friends");
            comboBox1.Items.Add("Cooking");
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            comboBox1.Items.Clear();
            comboBox1.Items.Add("Sports");
            comboBox1.Items.Add("Play Games");
            comboBox1.Items.Add("TV");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DateTime bdate = Convert.ToDateTime(dateTimePicker1.Text);
            int age = DateTime.Now.Year - bdate.Year;
            string name = textBox1.Text;
            string gender = "";
            if (radioButton1.Checked)
                gender = "Female";
            if (radioButton2.Checked)
                gender = "Male";
            string activity = comboBox1.Text;
            MessageBox.Show("Name:" + name+"\nGender:" + gender+"\nAge:"+age+"\nFavourite Activity:"+activity);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
