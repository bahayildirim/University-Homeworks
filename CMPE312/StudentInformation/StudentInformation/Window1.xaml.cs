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
using System.Configuration;
using System.Data;
using System.Data.SqlClient;

namespace StudentInformation
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        SqlConnection sqlConnection;
        public Window1()
        {
            InitializeComponent();
            string connectionString = ConfigurationManager.ConnectionStrings["StudentInformation.Properties.Settings.StudentReportDBConnectionString"].ConnectionString;
            sqlConnection = new SqlConnection(connectionString);
        }

        private void addCourse_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string query = "insert into Courses values (@code,@name)";
                SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
                sqlConnection.Open();
                sqlCommand.Parameters.AddWithValue("@code", textbox_code.Text);
                sqlCommand.Parameters.AddWithValue("@name", textbox_name.Text);
                sqlCommand.ExecuteScalar();
                MessageBox.Show("A new course has been added.");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
            finally
            {
                sqlConnection.Close();
            }

        }

        private void back_Click(object sender, RoutedEventArgs e)
        {
            MainWindow mainWindow = new MainWindow();
            mainWindow.Show();
            this.Close();
        }
    }
}
