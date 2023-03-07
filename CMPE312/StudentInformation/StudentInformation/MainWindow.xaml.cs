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
using System.Configuration;
using System.Data;
using System.Data.SqlClient;

namespace StudentInformation
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        SqlConnection sqlConnection;
        public MainWindow()
        {
            InitializeComponent();
            string connectionString = ConfigurationManager.ConnectionStrings["StudentInformation.Properties.Settings.StudentReportDBConnectionString"].ConnectionString;
            sqlConnection = new SqlConnection(connectionString);
            ShowStudentList();
            ShowCourseList();
        }
        private void ShowStudentList()
        {
            try
            {
                string query = "select * from students";
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(query, sqlConnection);
                using (sqlDataAdapter)
                {
                    DataTable stuTable = new DataTable();
                    sqlDataAdapter.Fill(stuTable);

                    sList.DisplayMemberPath = "name";
                    sList.SelectedValuePath = "Id";
                    sList.ItemsSource = stuTable.DefaultView;
                }
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
        }
        private void ShowCourseList()
        {
            try
            {
                string query = "select * from courses";
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(query, sqlConnection);
                using (sqlDataAdapter)
                {
                    DataTable courseTable = new DataTable();
                    sqlDataAdapter.Fill(courseTable);

                    cList.DisplayMemberPath = "name";
                    cList.SelectedValuePath = "code";
                    cList.ItemsSource = courseTable.DefaultView;
                }
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
        }
        
        private void ShowRegisteredCourses()
        {
            try
            {
                string query = "select c.name,r.stu_id from Courses c,RegisteredCourses r where c.code=r.c_id and r.stu_id=@stu_id";
                SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(sqlCommand);
                using (sqlDataAdapter)
                {
                    sqlCommand.Parameters.AddWithValue("@stu_id", sList.SelectedValue);
                    DataTable courseTable = new DataTable();
                    sqlDataAdapter.Fill(courseTable);

                    rList.DisplayMemberPath = "name";
                    rList.SelectedValuePath = "code";
                    rList.ItemsSource = courseTable.DefaultView;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void edit_Click(object sender, RoutedEventArgs e)
        {
            Window1 window1 = new Window1();
            window1.Show();
            this.Close();
        }

        private void sList_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ShowRegisteredCourses();
        }

        private void assign_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string query = "Insert into RegisteredCourses values (@stu_id,@c_id)";
                SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
                sqlConnection.Open();
                sqlCommand.Parameters.AddWithValue("@stu_id", sList.SelectedValue);
                sqlCommand.Parameters.AddWithValue("@c_id", cList.SelectedValue);
                sqlCommand.ExecuteScalar();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                sqlConnection.Close();
                ShowRegisteredCourses();
            }
        }
    }
}
