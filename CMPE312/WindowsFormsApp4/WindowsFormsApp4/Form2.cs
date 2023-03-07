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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            comboBox1.Items.Add("Computer Engineering");
            comboBox1.Items.Add("Software Engineering");
            comboBox1.Items.Add("IT");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(comboBox1.SelectedIndex == 0)
            {
                MessageBox.Show("You have selected Computer Engineering", "", MessageBoxButtons.OK);
                Application.Exit();
            }
            if (comboBox1.SelectedIndex == 1)
            {
                MessageBox.Show("You have selected Software Engineering", "", MessageBoxButtons.OK);
                Application.Exit();
            }
            if (comboBox1.SelectedIndex == 2)
            {
                MessageBox.Show("You have selected IT", "", MessageBoxButtons.OK);
                Application.Exit();
            }
        }
    }
}
