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

namespace WpfApp3
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

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Page1 p1 = new Page1();
            Mainframe.Navigate(p1);
        }

        private void Button_Click2(object sender, RoutedEventArgs e)
        {
            Page2 p2 = new Page2();
            Mainframe.Navigate(p2);
        }

        private void Button_Click3(object sender, RoutedEventArgs e)
        {
            Mainframe.NavigationService.Navigate(new Uri("https://www.google.com/"));
        }
    }
}
