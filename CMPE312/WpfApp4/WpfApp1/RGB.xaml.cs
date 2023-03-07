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

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for Login.xaml
    /// </summary>
    public partial class Login : UserControl
    {
        public Login()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            byte red = Convert.ToByte(r.Text.ToString());
            byte green = Convert.ToByte(g.Text.ToString());
            byte blue = Convert.ToByte(b.Text.ToString());
            rgb_grid.Background = new SolidColorBrush(Color.FromRgb(red, blue, green));
        }
    }
}
