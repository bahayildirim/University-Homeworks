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
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Activities_Click(object sender, RoutedEventArgs e)
        {
            ////Navigates to the BMI-Activities window and closes current window
            Window1 window1 = new Window1();
            window1.Show();
            this.Close();
        }

        private void Exit_Click(object sender, RoutedEventArgs e)
        {
            //Exits the program
            Application.Current.Shutdown();
        }

        private void BeHealthy_Click(object sender, RoutedEventArgs e)
        {
            //Navigates to the webpage window and closes current window
            Window2 window2 = new Window2();
            window2.Show();
            this.Close();
        }
    }
}
