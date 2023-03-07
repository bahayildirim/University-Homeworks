using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BMI
{
    /// <summary>
    /// Interaction logic for UserControl1.xaml
    /// </summary>
    public partial class UserControl1 : UserControl
    {
        public UserControl1()
        {
            InitializeComponent();
        }

        private void Calculate_Click(object sender, RoutedEventArgs e)
        {
            //Calculates the BMI from given inputs at Height and Weight textboxes and displays the output
            //in BMI textbox at the bottom. According to the BMI value, the textbox is colored green or red.
            BMI.Text = "";
            double m = Convert.ToDouble(Height.Text);
            double kg = Convert.ToDouble(Weight.Text);
            double bmi = kg / (m * m);
            bmi = Math.Round(bmi, 2);
            if ((18.5 < bmi) & (bmi < 25.0))
            {
                BMI.Background = new SolidColorBrush(Colors.Green);
                BMI.Text = Convert.ToString(bmi);
            }
            else
            {
                BMI.Background = new SolidColorBrush(Colors.Red);
                BMI.Text = Convert.ToString(bmi);
            }
        }
    }
}
