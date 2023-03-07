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
using System.Collections.ObjectModel;

namespace CMPE312_Lab_Work_Q2
{
    /// <summary>
    /// Interaction logic for Window3.xaml
    /// </summary>
    public partial class Window3 : Window
    {
        public List<string> bookList = new List<string>();
        public Window3(List<string> books)
        {
            InitializeComponent();
            foreach(string i in books)
            {
                Books.Items.Add(i);
            }
            bookList = books;
        }

        private void AddAnother_Click(object sender, RoutedEventArgs e)
        {
            Window2 window2 = new Window2(bookList);
            window2.Show();
            this.Close();
        }

        private void Close_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void Delete_Click(object sender, RoutedEventArgs e)
        {
            bookList.RemoveAt(Books.SelectedIndex);
            Books.Items.Remove(Books.SelectedItem);
        }
    }
}
