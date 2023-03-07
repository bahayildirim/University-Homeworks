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
    /// Interaction logic for Window2.xaml
    /// </summary>
    public partial class Window2 : Window
    {
        public List<string> bookList = new List<string>();
        public Window2(List<string> books)
        {
            InitializeComponent();
            Category.Items.Add("Adventure");
            Category.Items.Add("Classics");
            Category.Items.Add("Science Fiction");
            bookList = books;
        }
        public Window2()
        {
            InitializeComponent();
            Category.Items.Add("Adventure");
            Category.Items.Add("Classics");
            Category.Items.Add("Science Fiction");
        }

        private void AddBook_Click(object sender, RoutedEventArgs e)
        {
            string bookName = Convert.ToString(Book.SelectedItem);
            bookList.Add(bookName);
            MessageBox.Show("Book added!");
        }

        private void Category_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (Category.SelectedItem.Equals("Adventure"))
            {
                Book.Items.Clear();
                Book.Items.Add("Don Quixote");
                Book.Items.Add("The Three Musketeers");
                Book.Items.Add("Journey to the Center of the Earth");
            }
            else if (Category.SelectedItem.Equals("Classics"))
            {
                Book.Items.Clear();
                Book.Items.Add("The Great Gatsby");
                Book.Items.Add("1984");
                Book.Items.Add("To Kill A Mockingbird");
            }
            else if (Category.SelectedItem.Equals("Science Fiction"))
            {
                Book.Items.Clear();
                Book.Items.Add("Brave New World");
                Book.Items.Add("Hitchhiker's Guide to the Galaxy");
                Book.Items.Add("Ender's Game");
            }
        }

        private void Confirm_Checked(object sender, RoutedEventArgs e)
        {
            Next.IsEnabled = true;
        }

        private void Confirm_Unchecked(object sender, RoutedEventArgs e)
        {
            Next.IsEnabled = false;
        }

        private void Next_Click(object sender, RoutedEventArgs e)
        {
            Window3 window3 = new Window3(bookList);
            window3.Show();
            this.Close();
        }
    }
}
