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
using System.Windows.Shapes;

namespace BMI
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }

        private void Back_Click(object sender, RoutedEventArgs e)
        {
            //Navigates back to the main menu and closes current window
            MainWindow mainWindow = new MainWindow();
            mainWindow.Show();
            this.Close();
        }

        private void Result_Click(object sender, RoutedEventArgs e)
        {
            //Counts the amount of activities chosen and if the chosen activity amount is 2 or higher,
            //it displays that you are healthy along with the activity count. If not, it displays
            //"Not Enough Activity!"
            int count = PhysAct.SelectedItems.Count;
            if (count > 1)
            {
                MessageBox.Show("You have done " + count + " activities. You are healthy!");
            }
            else
            {
                MessageBox.Show("Not Enough Activity!");
            }
        }

        private void Webpage_Click(object sender, RoutedEventArgs e)
        {
            //Navigates to the webpage window and closes current window
            Window2 window2 = new Window2();
            window2.Show();
            this.Close();
        }
    }
}
